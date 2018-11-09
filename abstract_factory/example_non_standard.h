#ifndef __EXAMPLE_NON_STANDARD_H_
#define __EXAMPLE_NON_STANDARD_H_

#include<iostream>
#include<vector>
#include<string>
#include<map>


template<class T> class CreatorImpl;

class Base {
public:
    virtual void foo() = 0;
};

class Child1 : public Base {
public:
    virtual void foo() {
        std::cout << "Child 1" << std::endl;
    }
private:
    static const CreatorImpl<Child1> creator;
};

class Child2 : public Base {
public:
    virtual void foo() {
        std::cout << "Child 2" << std::endl;
    }
private:
    static const CreatorImpl<Child2> creator;
};

class Child3 : public Base {
public:
    virtual void foo() {
        std::cout << "Child 3" << std::endl;
    }
private:
    static const CreatorImpl<Child3> creator;
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

/**
 * all method is static
 */
class Factory
{
public:
   static Base* create(const std::string& classname);
   static void registerit(const std::string& classname, Creator* creator);
private:
   static std::map<std::string, Creator*>& get_table();
};

Base* Factory::create(const std::string& classname)
{
   std::map<std::string, Creator*>::iterator i;
   i = get_table().find(classname);

   if (i != get_table().end())
      return i->second->create();
   else
      return (Base*)NULL;
}

void Factory::registerit(const std::string& classname, Creator* creator)
{
   get_table()[classname] = creator;
}

std::map<std::string, Creator*>& Factory::get_table()
{
   static std::map<std::string, Creator*> table;
   return table;
}

const CreatorImpl<Child1> Child1::creator("Child1");
const CreatorImpl<Child2> Child2::creator("Child2");
const CreatorImpl<Child3> Child3::creator("Child3");

#endif
