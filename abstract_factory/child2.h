#ifndef __CHILD_2_H_
#define __CHILD_2_H_

#include "base.h"

class Child2 : public Base {
REGISTER(Child2);
public:
    virtual void foo();
};

#endif
