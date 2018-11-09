#include "base.h"

Creator::Creator(const std::string& classname) {
    Factory::registerit(classname, this);
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

