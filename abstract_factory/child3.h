#ifndef __CHILD_3_H_
#define __CHILD_3_H_

#include "base.h"

class Child3 : public Base {
REGISTER(Child3);
public:
    virtual void foo();
};

#endif
