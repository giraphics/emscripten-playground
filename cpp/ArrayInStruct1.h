#ifndef ARRAYINSTRUCT1_H
#define ARRAYINSTRUCT1_H

class Point2f {
public:
    float x;
    float y;
};

class PersonRecord {
public:
    std::string name;
    int age;
};

// Array fields are treated as if they were std::array<type,size>
class ArrayInStruct1 {
public:
    int field[2];
};

PersonRecord findPersonAtLocation(Point2f){
  PersonRecord a;
  a.age  = 30;
  a.name = "Parminder";
  return a;
}

#endif
