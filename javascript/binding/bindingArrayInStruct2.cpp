#include <string>

#include "ArrayInStruct2.h"
#include "emscripten/bind.h"
#include <functional>

using namespace emscripten;
using namespace std;

EMSCRIPTEN_BINDINGS(c) {
    // Parminder: Why we commented out 'array_int_2' because its already defined in ArrayInStruct1.

    // value_array<std::array<int, 2>>("array_int_2")
    //     .element(emscripten::index<0>())
    //     .element(emscripten::index<1>())
    //     ;
    
    value_array<std::array<NestedStruct, 2>>("array_NestedStruct_2")
        .element(emscripten::index<0>())
        .element(emscripten::index<1>())
        ;
    
    value_object<NestedStruct>("NestedStruct")
        .field("x", &NestedStruct::x)
        .field("y", &NestedStruct::y)
        ;

    value_object<ArrayInStruct2>("ArrayInStruct")
        .field("field1", &ArrayInStruct2::field1)
        .field("field2", &ArrayInStruct2::field2)
        ;

    emscripten::function("emval_test_take_and_return_ArrayInStruct", &emval_test_take_and_return_ArrayInStruct);
    emscripten::function("emval_test_take_and_return_ArrayInStructNoArg", &emval_test_take_and_return_ArrayInStructNoArg);
}
    
