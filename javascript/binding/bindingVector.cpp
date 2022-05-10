#include <string>

#include "Vector.h"

using namespace emscripten;
using namespace std;

EMSCRIPTEN_BINDINGS(c) {
    value_array<TupleVector>("TupleVector")
        .element(&TupleVector::x)
        .element(&Vector::getY, &Vector::setY)
        .element(&readVectorZ, &writeVectorZ)
        .element(emscripten::index<3>())
        ;

    emscripten::function("emval_test_return_TupleVector", &emval_test_return_TupleVector);
    emscripten::function("emval_test_take_and_return_TupleVector", &emval_test_take_and_return_TupleVector);

    value_array<TupleVectorTuple>("TupleVectorTuple")
        .element(&TupleVectorTuple::v)
        ;

    emscripten::function("emval_test_return_TupleVectorTuple", &emval_test_return_TupleVectorTuple);

    value_object<StructVector>("StructVector")
        .field("x", &StructVector::x)
        .field("y", &Vector::getY, &Vector::setY)
        .field("z", &readVectorZ, &writeVectorZ)
        .field("w", emscripten::index<3>())
        ;

    emscripten::function("emval_test_return_StructVector", &emval_test_return_StructVector);
    emscripten::function("emval_test_take_and_return_StructVector", &emval_test_take_and_return_StructVector);

    value_object<TupleInStruct>("TupleInStruct")
        .field("field", &TupleInStruct::field)
        ;

    emscripten::function("emval_test_take_and_return_TupleInStruct", &emval_test_take_and_return_TupleInStruct);
    emscripten::function("emval_test_call_function", &emval_test_call_function);
}
    
