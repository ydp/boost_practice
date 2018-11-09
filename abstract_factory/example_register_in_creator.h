#ifndef __EXAMPLE_REGISTER_IN_CREATOR_H_
#define __EXAMPLE_REGISTER_IN_CREATOR_H_

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
    Creator(const std::string& classname);

    virtual Base* create() = 0;
};

/**
 * C++ template to reduce Child Creator code
 */
template<class T>
class CreatorImpl : public Creator {
public:
    CreatorImpl(const std::string& classname) : Creator(classname) {}

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

#endif
