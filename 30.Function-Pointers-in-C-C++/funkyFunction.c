#include <stdio.h>

//function prototypes
void add(char *name, int x, int y);

// add x + y
void add(char *name, int x, int y) {
printf("%s gives: %d\n", name, x + y);
}

// calling from main
int main() {

// some funky function pointer assignment
void (*add1Ptr)(char*, int, int) = add;
void (*add2Ptr)(char*, int, int) = *add;
void (*add3Ptr)(char*, int, int) = &add;
void (*add4Ptr)(char*, int, int) = **add;
void (*add5Ptr)(char*, int, int) = ***add;

// execution still works
(*add1Ptr)("add1Ptr", 10, 2);
(*add2Ptr)("add2Ptr", 10, 2);
(*add3Ptr)("add3Ptr", 10, 2);
(*add4Ptr)("add4Ptr", 10, 2);
(*add5Ptr)("add5Ptr", 10, 2);

// this works too
add1Ptr("add1PtrFunc", 10, 2);
add2Ptr("add2PtrFunc", 10, 2);
add3Ptr("add3PtrFunc", 10, 2);
add4Ptr("add4PtrFunc", 10, 2);
add5Ptr("add5PtrFunc", 10, 2);
}
