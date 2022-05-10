./build.sh

pushd third-party/emsdk
source emsdk_env.sh
popd

mkdir build
cd build

emcmake cmake -DMODULE=1 -DCMAKE_TOOLCHAIN_FILE=../third-party/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake ..
make 
