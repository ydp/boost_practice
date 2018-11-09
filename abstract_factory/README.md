# 抽象工厂

最终版本
```
base.h
base.cc

child1.h
child1.cc

child2.h
child2.cc

child3.h
child3.cc

main.cc
```

对每个子类，只需要

* 包含 `base.h`
* 在类的开头调用宏 `REGISTER`
* 在类实现后调用宏 `REGISTERIMPL`

main函数中用法

```
#include "base.h"

int main(int argc, char* argv[]) {
    Base* p = Factory::create(string(argv[1]));
    if (p != nullptr)
        p->foo();
    else
        std::cout << "class not registered" << std::endl;
    return 0;
}
```
