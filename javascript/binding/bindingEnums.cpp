#include <string>

#include "Enums.h"

using namespace emscripten;
using namespace std;

EMSCRIPTEN_BINDINGS(c) {
    enum_<Enum>("Enum")
        .value("ONE", ONE)
        .value("TWO", TWO)
        ;
    emscripten::function("emval_test_take_and_return_Enum", &emval_test_take_and_return_Enum);

    enum_<EnumClass>("EnumClass")
        .value("ONE", EnumClass::ONE)
        .value("TWO", EnumClass::TWO)
        ;
    emscripten::function("emval_test_take_and_return_EnumClass", &emval_test_take_and_return_EnumClass);
}
    
