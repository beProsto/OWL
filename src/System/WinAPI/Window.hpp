#pragma once

#include <OWL/Utility/Config.hpp>

#include <OWL/System/Info.hpp>

#include "../Window.hpp"
#include "../../Input/WinAPI/Mouse.hpp"

/* This will include WinAPI */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winuser.h>

/* Debug */
#include <stdio.h>

namespace OWL {
namespace Impl {

inline LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch(msg) {
		case WM_CLOSE:
			PostQuitMessage(0);
			break;
			
		case WM_DESTROY:
			break;
			
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}


class OWL_API WinAPIWindow: public Window {
public:
	WinAPIWindow(Vec2ui _size, std::string _title, Mouse& _mouseRef) {
		m_Title = _title;
		m_IsRunning = true;
		m_Size = _size;
		m_IsFullScreen = false;
		m_Mouse = (WinAPIMouse*)&_mouseRef;

		m_ClassName = "WinAPI_Window_ClassName";

		m_Window.cbSize = sizeof(WNDCLASSEX);
		m_Window.style = 0;
		m_Window.lpfnWndProc = WndProc;
		m_Window.cbClsExtra = 0;
		m_Window.cbWndExtra = 0;
		m_Window.hInstance = OSInfo::Get()->InstanceHandle;
		m_Window.hIcon = LoadIcon(m_Window.hInstance, MAKEINTRESOURCE(460));
		m_Window.hCursor = LoadCursor(NULL, IDC_ARROW);
		m_Window.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		m_Window.lpszMenuName = nullptr;
		m_Window.lpszClassName = m_ClassName;
		m_Window.hIconSm = nullptr;
	
		if(!RegisterClassEx(&m_Window)) {
			printf("Error registering the window!\n");
			return;
		}

		m_Hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, m_ClassName, m_Title.c_str(), WS_OVERLAPPEDWINDOW, 0, 0, _size.x, _size.y, NULL, NULL, OSInfo::Get()->InstanceHandle, NULL);

		if(m_Hwnd == NULL) {
			printf("Error creating the window!\n");
			return;
		}
	
		ShowWindow(m_Hwnd, SW_SHOWNORMAL);
		UpdateWindow(m_Hwnd);

		m_Mouse->m_Hwnd = m_Hwnd;
	}
	virtual ~WinAPIWindow() {
		DestroyWindow(m_Hwnd);
	}

	virtual void PollEvents() {
		while(PeekMessage(&m_Event, 0, 0, 0, PM_REMOVE)) {
			if(m_Event.message == WM_QUIT) {
				Close();
			}
			TranslateMessage(&m_Event);
			DispatchMessage(&m_Event);

			// PollEventsStandard(_self);
		}

		// PollEventsGamepad(_self);
	}

	virtual void SetPosition(const Vec2i& _position) {
		SetWindowPos(m_Hwnd, 0, _position.x, _position.y, 0, 0, SWP_NOSIZE);
	}
	virtual Vec2i GetPosition() const {
		RECT rect;
		GetWindowRect(m_Hwnd, &rect);
		return Vec2i(rect.left, rect.top);
	}

	virtual void SetSize(const Vec2ui& _size) {
		if(m_Size != _size) {
			SetWindowPos(m_Hwnd, 0, 0, 0, _size.x, _size.y, SWP_NOMOVE);

			OWL::Vec2ui finalSize = GetSize();
			if(finalSize != _size) {
				finalSize = _size + (_size - finalSize);
				SetWindowPos(m_Hwnd, 0, 0, 0, finalSize.x, finalSize.y, SWP_NOMOVE);
			}

			m_Size = _size;
		}
	}
	virtual Vec2ui GetSize() const {
		RECT rect;
		GetClientRect(m_Hwnd, &rect);
		return Vec2ui(rect.right - rect.left, rect.bottom - rect.top);
	}
	virtual float GetAspect() const {
		return (float)m_Size.x / (float)m_Size.y;
	}

	virtual void SetTitle(std::string _title) {
		if(m_Title != _title) {
			m_Title = _title;
			SetWindowTextA(m_Hwnd, &m_Title[0]);
		}
	}
	virtual std::string GetTitle() const {
		return m_Title;
	}

	virtual void Close() {
		m_IsRunning = false;
	}
	virtual bool IsRunning() const {
		return m_IsRunning;
	}

	virtual bool IsFocused() const {
		return GetFocus() == m_Hwnd;
	}

	virtual void SetFullScreen(bool _fullScreen) {
		if(m_IsFullScreen != _fullScreen) {
			m_IsFullScreen = _fullScreen;

			if(m_IsFullScreen) {
				m_WasMaximized = IsZoomed(m_Hwnd);

				LONG style = GetWindowLong(m_Hwnd, GWL_STYLE);
				LONG exStyle = GetWindowLong(m_Hwnd, GWL_EXSTYLE);
				
				SetWindowLong(m_Hwnd, GWL_STYLE, style & ~(WS_CAPTION | WS_THICKFRAME));
				SetWindowLong(m_Hwnd, GWL_EXSTYLE, exStyle & ~(WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE));

				SendMessage(m_Hwnd, WM_SYSCOMMAND, SC_RESTORE, 0);
				SendMessage(m_Hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
			}
			else {
				LONG style = GetWindowLong(m_Hwnd, GWL_STYLE);
				LONG exStyle = GetWindowLong(m_Hwnd, GWL_EXSTYLE);
				
				SetWindowLong(m_Hwnd, GWL_STYLE, style | (WS_CAPTION | WS_THICKFRAME));
				SetWindowLong(m_Hwnd, GWL_EXSTYLE, exStyle | (WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE));

				SendMessage(m_Hwnd, WM_SYSCOMMAND, SC_RESTORE, 0);
				if(m_WasMaximized) {
					SendMessage(m_Hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
				}
			}
		}
	}
	virtual bool IsFullScreen() const {
		return m_IsFullScreen;
	}

public:
	WinAPIMouse* m_Mouse;

	std::string m_Title;
	Vec2ui m_Size;
	bool m_IsRunning;
	bool m_IsFullScreen;
	bool m_WasMaximized;

	// Context* m_Context;

	const char* m_ClassName;
	WNDCLASSEX m_Window;
	HWND m_Hwnd;
	MSG m_Event;
};

}
}