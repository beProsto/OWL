#pragma once

#include <OWL/Utility/Config.hpp>

#include <OWL/System/Info.hpp>

#include "../Window.hpp"

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
		
		case WM_SYSKEYDOWN:
		case WM_SYSKEYUP:
		case WM_SYSCHAR:
			return (LRESULT)1;
		
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

class OWL_API WinAPIWindow: public Window {
public:
	WinAPIWindow(Vec2ui _size, std::string _title) {
		m_isRunning = true;
		m_isFullScreen = false;
		m_hwnd = nullptr;
		m_contextImpl = nullptr;

		m_className = "WinAPI_Window_ClassName";
		m_window.cbSize = sizeof(WNDCLASSEX);
		m_window.style = 0;
		m_window.lpfnWndProc = WndProc;
		m_window.cbClsExtra = 0;
		m_window.cbWndExtra = 0;
		m_window.hInstance = OSInfo::get()->instanceHandle;
		m_window.hIcon = LoadIcon(m_window.hInstance, MAKEINTRESOURCE(460));
		m_window.hCursor = LoadCursor(NULL, IDC_ARROW);
		m_window.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
		m_window.lpszMenuName = nullptr;
		m_window.lpszClassName = m_className;
		m_window.hIconSm = nullptr;
	
		if(!RegisterClassEx(&m_window)) {
			printf("Error registering the window!\n");
			return;
		}

		create(Vec2i(0), _size, _title, false);
	}
	virtual ~WinAPIWindow() {
		destroy();
	}

	virtual bool create(Vec2i _pos, Vec2ui _size, std::string _title, bool _fullScreen) {
		m_title = _title;
		m_isFullScreen = false;

		destroy();

		m_hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, m_className, m_title.c_str(), WS_OVERLAPPEDWINDOW, 0, 0, _size.x, _size.y, NULL, NULL, OSInfo::get()->instanceHandle, NULL);

		if(m_hwnd == NULL) {
			printf("Error creating the window!\n");
			return false;
		}

		ShowWindow(m_hwnd, SW_SHOWNORMAL);
		UpdateWindow(m_hwnd);

		setSize(_size);
		setPosition(_pos);
		setFullScreen(_fullScreen);

		return true;
	}
	virtual void destroy() {
		if(m_hwnd != nullptr) {
			if(m_contextImpl != nullptr) {
				m_contextImpl->destroy();
				m_contextImpl = nullptr;
			}

			DestroyWindow(m_hwnd);
			m_hwnd = nullptr;
		}
	}

	virtual void setContext(Context& _context) {
		// // THIS IS THE PROPER WAY TO GO ABOUT THIS
		// // BUT IT LOOKS BAD
		// // SO ONLY USE THIS IMPLEMENTATION
		// // IF REQUIRED BY DIRECT3D
		// // (VULKAN DOESN'T AS FAR AS I'M AWARE)
		// Vec2ui winSize = getSize();
		// Vec2i winPosition = getPosition();
		// bool winFullScreen = isFullScreen();
		// destroy();
		// m_contextImpl = &_context;
		// m_contextImpl->m_windowImpl = this;
		// m_contextImpl->create();
		// create(winPosition, winSize, m_title, winFullScreen);
		// m_contextImpl->validate();

		// This is an improper, but good looking
		// implementation of context switching.
		if(m_contextImpl != nullptr) {
			m_contextImpl->destroy();
			m_contextImpl = nullptr;
		}
		m_contextImpl = &_context;
		m_contextImpl->m_windowImpl = this;

		m_contextImpl->create();
		m_contextImpl->validate();
	}

	virtual void pollEvents() {
		m_mouseImpl->pollPreparation();
		m_keyboardImpl->pollPreparation();
		m_gamepadsImpl->pollPreparation();

		while(PeekMessage(&m_event, 0, 0, 0, PM_REMOVE)) {
			if(m_event.message == WM_QUIT) {
				close();
			}
			TranslateMessage(&m_event);
			DispatchMessage(&m_event);

			m_mouseImpl->pollSpecificEvents();
			m_keyboardImpl->pollSpecificEvents();
			// m_gamepadsImpl->pollSpecificEvents(); // No need
		}
	}

	virtual void setPosition(const Vec2i& _position) {
		SetWindowPos(m_hwnd, 0, _position.x, _position.y, 0, 0, SWP_NOSIZE);
	}
	virtual Vec2i getPosition() const {
		RECT rect;
		GetWindowRect(m_hwnd, &rect);
		return Vec2i(rect.left, rect.top);
	}

	virtual void setSize(Vec2ui _size) {
		SetWindowPos(m_hwnd, 0, 0, 0, _size.x, _size.y, SWP_NOMOVE);

		OWL::Vec2ui finalSize = getSize();
		if(finalSize != _size) {
			finalSize = _size + (_size - finalSize);
			SetWindowPos(m_hwnd, 0, 0, 0, finalSize.x, finalSize.y, SWP_NOMOVE);
		}
	}
	virtual Vec2ui getSize() const {
		RECT rect;
		GetClientRect(m_hwnd, &rect);
		return Vec2ui(rect.right - rect.left, rect.bottom - rect.top);
	}
	virtual float getAspect() const {
		Vec2f size = getSize(); 
		return size.x / size.y;
	}

	virtual void setTitle(std::string _title) {
		if(m_title != _title) {
			m_title = _title;
			SetWindowTextA(m_hwnd, &m_title[0]);
		}
	}
	virtual std::string getTitle() const {
		return m_title;
	}

	virtual void close() {
		m_isRunning = false;
	}
	virtual bool isRunning() const {
		return m_isRunning;
	}

	virtual bool isFocused() const {
		return GetFocus() == m_hwnd;
	}

	virtual void setFullScreen(bool _fullScreen) {
		if(m_isFullScreen != _fullScreen) {
			m_isFullScreen = _fullScreen;

			if(m_isFullScreen) {
				m_wasMaximized = IsZoomed(m_hwnd);

				LONG style = GetWindowLong(m_hwnd, GWL_STYLE);
				LONG exStyle = GetWindowLong(m_hwnd, GWL_EXSTYLE);
				
				SetWindowLong(m_hwnd, GWL_STYLE, style & ~(WS_CAPTION | WS_THICKFRAME));
				SetWindowLong(m_hwnd, GWL_EXSTYLE, exStyle & ~(WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE));

				SendMessage(m_hwnd, WM_SYSCOMMAND, SC_RESTORE, 0);
				SendMessage(m_hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
			}
			else {
				LONG style = GetWindowLong(m_hwnd, GWL_STYLE);
				LONG exStyle = GetWindowLong(m_hwnd, GWL_EXSTYLE);
				
				SetWindowLong(m_hwnd, GWL_STYLE, style | (WS_CAPTION | WS_THICKFRAME));
				SetWindowLong(m_hwnd, GWL_EXSTYLE, exStyle | (WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE));

				SendMessage(m_hwnd, WM_SYSCOMMAND, SC_RESTORE, 0);
				if(m_wasMaximized) {
					SendMessage(m_hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
				}
			}
		}
	}
	virtual bool isFullScreen() const {
		return m_isFullScreen;
	}

public:
	std::string m_title;
	bool m_isRunning;
	bool m_isFullScreen;
	bool m_wasMaximized;

	const char* m_className;
	WNDCLASSEX m_window;
	HWND m_hwnd;
	MSG m_event;
};

}
}