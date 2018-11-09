#include "child1.h"
#include <iostream>

void Child1::foo() {
    std::cout << "child 1..." << std::endl;
}

REGISTERIMPL(Child1);

