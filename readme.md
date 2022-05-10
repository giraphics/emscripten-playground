./build.sh

pushd third-party/emsdk
source emsdk_env.sh
popd

mkdir build
cd build

emcmake cmake -DCMAKE_TOOLCHAIN_FILE=<emsdk>/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake ..
make 

cd ..
python3 -m http.server
