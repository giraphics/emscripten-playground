#ifndef ENUMS_H
#define ENUMS_H

#include "IncludeHeaders.h"

enum Enum { ONE, TWO };

Enum emval_test_take_and_return_Enum(Enum e) {
    return e;
}

enum class EnumClass : char { ONE, TWO };

EnumClass emval_test_take_and_return_EnumClass(EnumClass e) {
    return e;
}

#endif
