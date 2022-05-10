#ifndef ARRAYINSTRUCT2_H
#define ARRAYINSTRUCT2_H

struct NestedStruct {
    int x;
    int y;
};
struct ArrayInStruct2 {
    int field1[2];
    NestedStruct field2[2];
};

ArrayInStruct2 emval_test_take_and_return_ArrayInStruct(ArrayInStruct2 cs) {
    return cs;
}

ArrayInStruct2 emval_test_take_and_return_ArrayInStructNoArg() {

    ArrayInStruct2 cs;
    cs.field1[0] = 99;
    cs.field1[1] = 11;
    
    cs.field2[0].x = 123;
    cs.field2[0].y = 321;
    
    cs.field2[1].x = 1111;
    cs.field2[1].y = 2222;
    
    return cs;
}

#endif
