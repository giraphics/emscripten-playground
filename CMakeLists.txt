cmake_minimum_required(VERSION 3.10)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#CMAKE_TOOLCHAIN_FILE=path/to/emscripten/emscripten/version/cmake/Modules/Platform/Emscripten.cmake

set(PROJECT_NAME my-dog)

project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

#file(GLOB SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/include/cereal/*.*)

#message(STATUS "source...........")
#message(${SOURCE})

set(DOG_SOURCES 
  ${CMAKE_CURRENT_SOURCE_DIR}/cpp/dog.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/cpp/ArrayInStruct1.h
  ${CMAKE_CURRENT_SOURCE_DIR}/cpp/ArrayInStruct2.h
)

set(BIND_SOURCES 
${CMAKE_CURRENT_SOURCE_DIR}/javascript/binding/binding.cpp
${CMAKE_CURRENT_SOURCE_DIR}/javascript/binding/bindingArrayInStruct1.cpp
${CMAKE_CURRENT_SOURCE_DIR}/javascript/binding/bindingArrayInStruct2.cpp
)

add_executable(${PROJECT_NAME} 
  ${DOG_SOURCES}
  ${BIND_SOURCES}
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS
	"-s DEMANGLE_SUPPORT=1 --bind -s WASM=1 \
	 -s EXTRA_EXPORTED_RUNTIME_METHODS=\"['ccall', 'cwrap', 'addOnPostRun']\" ")

