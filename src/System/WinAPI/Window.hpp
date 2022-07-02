#pragma once

#include <OWL/Utility/Config.hpp>

#include <OWL/System/Info.hpp>

#include "../Window.hpp"

/* This will include WinAPI */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winuser.h>
#include <xinput.h>

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
	WinAPIWindow(Vec2ui _size, std::string _title) {
		m_Title = _title;
		m_IsRunning = true;
		m_Size = _size;
		m_IsFullScreen = false;

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
	}
	virtual ~WinAPIWindow() {
	}

	virtual void PollEvents() {

	}

	virtual void SetPosition(const Vec2i& _position) {

	}
	virtual Vec2i GetPosition() const {
		return Vec2i{};
	}

	virtual void SetSize(const Vec2ui& _size) {
		if(m_Size != _size) {
			//...
			m_Size = _size;
		}
	}
	virtual Vec2ui GetSize() const {
		return m_Size;
	}
	virtual float GetAspect() const {
		return (float)m_Size.x / (float)m_Size.y;
	}

	virtual void SetTitle(const std::string& _title) {
		if(m_Title != _title) {
			//...
			m_Title = _title;
		}
	}
	virtual const std::string& GetTitle() const {
		return m_Title;
	}

	virtual void Close() {
		m_IsRunning = false;
	}
	virtual bool IsRunning() const {
		return m_IsRunning;
	}

	virtual bool IsFocused() const {
		return false;
	}

	virtual void SetFullScreen(bool _fullScreen) {

	}
	virtual bool IsFullScreen() const {
		return m_IsFullScreen;
	}

public:
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