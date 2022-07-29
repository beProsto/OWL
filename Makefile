CC  = gcc
CXX = g++
G = Ninja
J = 16
LT = SHARED
BE = YES

compile:
	cmake -B ./build "-DCMAKE_C_COMPILER:FILEPATH=$(CC)" "-DCMAKE_CXX_COMPILER:FILEPATH=$(CXX)" "-DLIBTYPE=$(LT)" "-DBUILD_EXAMPLES=$(BE)" -G "$(G)" & cmake --build ./build -j $(J)

emscripten:
	emcmake cmake -B ./build "-DBUILD_EXAMPLES=$(BE)" -G "$(G)" & cmake --build ./build -j $(J)

clean:
	cd build & git clean -d -f -x