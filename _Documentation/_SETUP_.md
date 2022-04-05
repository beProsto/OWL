# Setup
A quick tutorial on how to setup OWL.
1. If you have `git`:
- `git copy https://github.com/beProsto/OWL.git`
2. If you don't have `git`:
- go to https://github.com/beProsto/OWL
- `Clone or download`
	- `Download ZIP`
3. copy one of the examples from `OWL/_Examples/` directory
4. compile with flags (in the exact same order):
- If on linux:
	- `-lX11`
	- If using OpenGL
		- `-lGL` 
		- `-lGLX`
- If on windows:
	- If using OpenGL
		- `-lopengl32`
		- `-lglu32`
	- `-lgdi32`
	- `-luser32`
	- `-lcomctl32`
	- `-lkernel32`
	- `-lshell32`
	- `-lxinput`
- If on mac:
	- (For now unsupported)
- `-std=c++17`

## How it should look on linux:
`g++ main.cpp -lX11 -lGL -lGLX -std=c++17 -o app`
## How it should look on windows:
`g++ main.cpp -lopengl32 -lglu32 -lgdi32 -luser32 -lcomctl32 -lkernel32 -lshell32 -lxinput -std=c++17 -o app.exe`
