#ifndef __REGISTRY_H_
#define __REGISTRY_H_

#include <string>
#include <map>

class Base {
 public:
     virtual void foo() = 0;
};

class Creator {
public:
    Creator(const std::string& classname);

    virtual Base* create() = 0;
};

template<class T>
class CreatorImpl : public Creator {
public:
    CreatorImpl(const std::string& classname) : Creator(classname) {}

    virtual Base* create() { return new T; }
};

class Factory
{
public:
   static Base* create(const std::string& classname);
   static void registerit(const std::string& classname, Creator* creator);
private:
   static std::map<std::string, Creator*>& get_table();
};

#define REGISTER(classname) \
private: \
   static const CreatorImpl<classname> creator;

#define REGISTERIMPL(classname) \
   const CreatorImpl<classname> classname::creator(#classname);

#endif

