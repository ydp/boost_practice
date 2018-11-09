#include "child3.h"
#include <iostream>

void Child3::foo() {
    std::cout << "child 3..." << std::endl;
}

REGISTERIMPL(Child3);

