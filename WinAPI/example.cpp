/* This code isn't mine (i got it quickly from http://cpp0x.pl/kursy/Kurs-WinAPI-C++/Podstawy/Podstawy-WinAPI/168) nor should it be compiled. It's just a starting point for me */

#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    LPSTR ClassName = "WinClassName";

    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = ClassName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
   
    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Cannot register window", MB_ICONEXCLAMATION);
        return 1;
    }

    HWND hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, ClassName, "Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 240, 120, NULL, NULL, hInstance, NULL);
   
    if(hwnd == NULL)
    {
        MessageBox(NULL, "Can't create window", MB_ICONEXCLAMATION);
        return 1;
    }
   
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
   
    MSG Message;
    while(GetMessage(&Message, NULL, 0, 0))
    {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
    }
    return Message.wParam;
}
