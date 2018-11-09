#include<iostream>
#include<vector>
#include<string>
#include<map>

class Base {
public:
    virtual void foo() = 0;
};

class Child1 : public Base {
public:
    virtual void foo() {
        std::cout << "Child 1" << std::endl;
    }
};

class Child2 : public Base {
public:
    virtual void foo() {
        std::cout << "Child 2" << std::endl;
    }
};

class Child3 : public Base {
public:
    virtual void foo() {
        std::cout << "Child 3" << std::endl;
    }
};

class Creator {
public:
    virtual Base* create() = 0;
};

/*
class Child1Creator : public Creator {
public:
    virtual Base* create() { return new Child1; }
};

class Child2Creator : public Creator {
public:
    virtual Base* create() { return new Child2; }
};

class Child3Creator : public Creator {
public:
    virtual Base* create() { return new Child3; }
};
*/

/**
 * C++ template the same as above 3 seprate classes
 */
template<class T>
class CreatorImpl : public Creator {
public:
    virtual Base* create() { return new T; }
};

class Factory {
public:
    Base* create(const std::string& classname) {
        std::map<std::string, Creator*>::iterator i;
        i = table.find(classname);
        if (i != table.end())
            return i->second->create();
        else
            return (Base*)nullptr;
    }

    void registerit(const std::string& classname,
            Creator* creator) {
        table[classname] = creator;
    }

private:
    std::map<std::string, Creator*> table;
};


/**
 * 1. use C++ template to reduce creator code
 * 2. use factory to register class and get creator
 * 3. actually, the code seems to be more...
 */
int main(int argc, char* argv[]) {
    Factory factory;

    CreatorImpl<Child1> creator1;
    CreatorImpl<Child2> creator2;
    CreatorImpl<Child3> creator3;

    factory.registerit("Child1", &creator1);
    factory.registerit("Child2", &creator2);
    factory.registerit("Child3", &creator3);

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

