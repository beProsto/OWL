CC = clang
CXX = clang++
AR = llvm-ar

CXX_FLAGS = -std=c++17 -Wall -Wpedantic -O3

ifeq ($(OS),Windows_NT)
EXE = .exe
LINK_OWL = -lopengl32 -lglu32 -lgdi32 -luser32 -lcomctl32 -lkernel32 -lshell32 -lxinput
LIB_FILE = OWL.lib
else
EXE = 
LINK_OWL = -lX11 -lGL -lGLX
LIB_FILE = libOWL.a
endif
OWL_INCLUDE = -I../include
OWL_FLAGS = $(OWL_INCLUDE) $(LINK_OWL)

everything: GUIApplicationExample$(EXE) ModernOpenGLExample$(EXE) SimpleWindowExample$(EXE)

GUIApplicationExample$(EXE): ../examples/GUIApplicationExample/main.cpp $(LIB_FILE)
	$(CXX) ../examples/GUIApplicationExample/main.cpp $(LIB_FILE) $(OWL_FLAGS) $(CXX_FLAGS) -o GUIApplicationExample$(EXE)

ModernOpenGLExample$(EXE): ../examples/ModernOpenGLExample/main.cpp $(LIB_FILE)
	$(CXX) ../examples/ModernOpenGLExample/main.cpp $(LIB_FILE) $(OWL_FLAGS) $(CXX_FLAGS) -o ModernOpenGLExample$(EXE)

SimpleWindowExample$(EXE): ../examples/SimpleWindowExample/main.cpp $(LIB_FILE)
	$(CXX) ../examples/SimpleWindowExample/main.cpp $(LIB_FILE) $(OWL_FLAGS) $(CXX_FLAGS) -o SimpleWindowExample$(EXE)


justlibrary: $(LIB_FILE)

$(LIB_FILE): OWL.o
	$(AR) rcs $(LIB_FILE) OWL.o
OWL.o: ../src/OWL.cpp
	$(CXX) ../src/OWL.cpp $(OWL_INCLUDE) $(CXX_FLAGS) -c -o OWL.o