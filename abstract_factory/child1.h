#ifndef __CHILD_1_H_
#define __CHILD_1_H_

#include "base.h"

class Child1 : public Base {
REGISTER(Child1);
public:
    virtual void foo();
};

#endif
