CC  = gcc
CXX = g++
G = Ninja
J = 16
LT = SHARED
BE = YES

usual: build-usual
	cmake --build ./build -j $(J)

emscripten: build-emscripten
	cmake --build ./build -j $(J)

build-usual:
	cmake -B ./build "-DCMAKE_C_COMPILER:FILEPATH=$(CC)" "-DCMAKE_CXX_COMPILER:FILEPATH=$(CXX)" "-DLIBTYPE=$(LT)" "-DBUILD_EXAMPLES=$(BE)" -G "$(G)"

build-emscripten:
	emcmake cmake -B ./build "-DBUILD_EXAMPLES=$(BE)" -G "$(G)"

clean:
	git clean -d -f -x ./build