#include"example_register_in_creator.h"

Factory factory;

Creator::Creator(const std::string& classname) {
        factory.registerit(classname, this);
};

/**
 * 1. use C++ template to reduce creator code
 * 2. use factory to register class and get creator
 * 3. call factory.registerit in Creator's constructor
 * 4. factory as a global variable
 */
int main(int argc, char* argv[]) {
    CreatorImpl<Child1> creator1("Child1");
    CreatorImpl<Child2> creator2("Child2");
    CreatorImpl<Child3> creator3("Child3");

    std::vector<std::string> names{"Child3", "Child2"};
    Base* p;

    for (std::vector<std::string>::iterator i = names.begin();
            i != names.end(); ++i) {
        p = factory.create(*i);
        // TODO: do something with p
        if (p != nullptr)
            p->foo();
        else
            std::cout << "class not registered" << std::endl;
    }
    return 0;
}

