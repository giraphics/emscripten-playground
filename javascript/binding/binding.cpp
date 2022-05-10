#include <string>

#include "dog.h"
#include "emscripten/bind.h"
#include <functional>

using namespace emscripten;
using namespace std;

EMSCRIPTEN_BINDINGS(c) {
    class_<Dog>("Dog")
    .constructor<string>()
    .function("makeSound", &Dog::makeSound)
    .function("getGreeting", &Dog::getGreeting);
}
