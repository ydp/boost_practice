#include "child2.h"
#include <iostream>

void Child2::foo() {
    std::cout << "child 2..." << std::endl;
}

REGISTERIMPL(Child2);

