#include "base.h"

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::vector<std::string> names{"Child3", "Child2"};
    Base* p;

    for (std::vector<std::string>::iterator i = names.begin();
            i != names.end(); ++i) {
        p = Factory::create(*i);
        // TODO: do something with p
        if (p != nullptr)
            p->foo();
        else
            std::cout << "class not registered" << std::endl;
    }
    return 0;
}
