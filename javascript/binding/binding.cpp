#include <string>

#include "dog.h"
#include "emscripten/bind.h"
#include <functional>

using namespace emscripten;
using namespace std;


// struct Vector {
//     Vector() = delete;

//     Vector(float x_, float y_, float z_, float w_)
//         : x(x_)
//         , y(y_)
//         , z(z_)
//         , w(w_)
//     {}

//     float x, y, z, w;

//     float& operator[](int i) {
//         return (&x)[i];
//     }

//     const float& operator[](int i) const {
//         return (&x)[i];
//     }

//     float getY() const {
//         return y;
//     }
//     void setY(float _y) {
//         y = _y;
//     }
// };

// struct DummyDataToTestPointerAdjustment {
//     std::string dummy;
// };

// struct TupleVector : DummyDataToTestPointerAdjustment, Vector {
//     TupleVector(): Vector(0, 0, 0, 0) {}
//     TupleVector(float x, float y, float z, float w): Vector(x, y, z, w) {}
// };

// struct StructVector : DummyDataToTestPointerAdjustment, Vector {
//     StructVector(): Vector(0, 0, 0, 0) {}
//     StructVector(float x, float y, float z, float w): Vector(x, y, z, w) {}
// };

// float readVectorZ(const Vector& v) {
//     return v.z;
// }

// void writeVectorZ(Vector& v, float z) {
//     v.z = z;
// }

// struct TupleVectorTuple {
//     TupleVector v = TupleVector(0, 0, 0, 0);
// };

// TupleVector emval_test_return_TupleVector() {
//     return TupleVector(1, 2, 3, 4);
// }

// TupleVector emval_test_take_and_return_TupleVector(TupleVector v) {
//     return v;
// }

// TupleVectorTuple emval_test_return_TupleVectorTuple() {
//     TupleVectorTuple cvt;
//     cvt.v = emval_test_return_TupleVector();
//     return cvt;
// }

// StructVector emval_test_return_StructVector() {
//     return StructVector(1, 2, 3, 4);
// }

// StructVector emval_test_take_and_return_StructVector(StructVector v) {
//     return v;
// }

// struct CustomStruct {
//     CustomStruct()
//         : field(10)
//     {}

//     const int& getField() const {
//         return field;
//     }

//     int field;
// };

// struct TupleInStruct {
//     TupleVector field;
// };

// TupleInStruct emval_test_take_and_return_TupleInStruct(TupleInStruct cs) {
//     return cs;
// }


// enum Enum { ONE, TWO };

// Enum emval_test_take_and_return_Enum(Enum e) {
//     return e;
// }

// enum class EnumClass : char { ONE, TWO };

// EnumClass emval_test_take_and_return_EnumClass(EnumClass e) {
//     return e;
// }

// void emval_test_call_function(val v, int i, float f, TupleVector tv, StructVector sv) {
//     v(i, f, tv, sv);
// }

/////////////////////////////////////


EMSCRIPTEN_BINDINGS(c) {
    class_<Dog>("Dog")
    .constructor<string>()
    .function("makeSound", &Dog::makeSound)
    .function("getGreeting", &Dog::getGreeting);
}
