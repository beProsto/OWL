CC = clang
CXX = clang++

CXX_FLAGS = -std=c++17 -Wall -Wpedantic

ifeq ($(OS),Windows_NT)
EXE = .exe
LINK_OWL = -lopengl32 -lglu32 -lgdi32 -luser32 -lcomctl32 -lkernel32 -lshell32 -lxinput
else
EXE = 
LINK_OWL = -lX11 -lGL -lGLX
endif

OWL_FLAGS = -I../include $(LINK_OWL)

everything: GUIApplicationExample$(EXE) ModernOpenGLExample$(EXE)

GUIApplicationExample$(EXE): ../examples/GUIApplicationExample/main.cpp
	$(CXX) ../examples/GUIApplicationExample/main.cpp $(OWL_FLAGS) $(CXX_FLAGS) -o GUIApplicationExample$(EXE)

ModernOpenGLExample$(EXE): ../examples/ModernOpenGLExample/main.cpp
	$(CXX) ../examples/ModernOpenGLExample/main.cpp $(OWL_FLAGS) $(CXX_FLAGS) -o ModernOpenGLExample$(EXE)