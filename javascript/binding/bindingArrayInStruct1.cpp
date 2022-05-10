#include <string>

#include "ArrayInStruct1.h"
#include "emscripten/bind.h"
#include <functional>

using namespace emscripten;
using namespace std;

EMSCRIPTEN_BINDINGS(c) {
    value_array<Point2f>("Point2f")
        .element(&Point2f::x)
        .element(&Point2f::y)
        ;

    value_object<PersonRecord>("PersonRecord")
        .field("name", &PersonRecord::name)
        .field("age", &PersonRecord::age)
        ;

    value_object<ArrayInStruct1>("ArrayInStruct1")
        .field("field", &ArrayInStruct1::field) // Need to register the array type
        ;

    // Register std::array<int, 2> because ArrayInStruct::field is interpreted as such
    value_array<std::array<int, 2>>("array_int_2")
        .element(emscripten::index<0>())
        .element(emscripten::index<1>())
        ;

    emscripten::function("findPersonAtLocation", &findPersonAtLocation);
}
