#include <OWL/OWL.hpp>

#ifdef _WIN32

#include <shellapi.h>

/* WinAPI */
WinAPI_Data* WinAPI_Data::m_Instance = nullptr;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WinAPI_Data* wdata = WinAPI_Data::get();
	wdata->hInstance = hInstance;
	wdata->nCmdShow = nCmdShow;

	std::vector<std::string> passed;
	
	{ /* Scope, so that variables created here will be freed when they are not needed */
		int cnt = 0;
		wchar_t** cmdl = CommandLineToArgvW(GetCommandLineW(), &cnt);
		if(cnt > 0) {
			unsigned int count = cnt;
			for(unsigned int i = 0; i < count; i++) {
				int strsize = WideCharToMultiByte(CP_UTF8, 0, cmdl[i], -1, 0, 0, NULL, NULL); //CP_ACP
				char* strstr = new char[strsize];
				WideCharToMultiByte(CP_UTF8, 0, cmdl[i], -1, strstr , strsize, NULL, NULL);
				passed.push_back(strstr);
				delete[] strstr;
			}
		}
		LocalFree(cmdl);
	}

	return Main(passed);
	/* No need for cleaning after allocating the WinAPI_Data::get(), as the kernel will do it itself. */
}


#elif defined __linux__
/* X11 */
int main(int argc, char** argv) {
	std::vector<std::string> passed;
	for(unsigned int i = 0; i < argc; i++) {
		passed.push_back(argv[i]);
	}
	return Main(passed);
}

#else

#error OWL: Unsupported platform! (Only linux and windows supported currently!)

#endif