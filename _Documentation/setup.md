# Setup
A quick tutorial on how to setup OWL.
1. If you have `git`:
- `git copy https://github.com/beProsto/OWL.git`
2. If you don't have `git`:
- go to https://github.com/beProsto/OWL
- `Clone or download`
	- `Download ZIP`
3. copy one of the examples from `OWL/_Examples/` directory
4. compile with flags:
- `-std=c++17`
- If on linux:
	- `-lX11`
	- If using OpenGL
		- `-lGL -lGLX`
- If on windows:
	- `-lgdi32`
	- `-luser32`
	- `-lcomctl32`
	- `-lkernel32`
	- I found out, that if you are using mingw-w64 compiler with msys2, you don't have to use these flags
	- If using OpenGL
		- (For now unsupported)
- If on mac:
	- (For now unsupported)