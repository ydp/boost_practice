#include"example_non_standard.h"

Creator::Creator(const std::string& classname) {
    Factory::registerit(classname, this);
};

/**
 * 1. use C++ template to reduce creator code
 * 2. use factory to register class and get creator
 * 3. call factory.registerit in Creator's constructor
 * 4. Factory is static class
 */
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

