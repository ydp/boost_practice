#include<iostream>
#include<vector>
#include<string>

class Base {};

class Child1 : public Base {};

class Child2 : public Base {};

class Child3 : public Base {};

/**
 * every add a new Child, update the if statements and rebuild code
 */
int main(int argc, char* argv[]) {
    std::vector<std::string> names{"Child3", "Child2"};
    Base* p;
    for (std::vector<std::string>::iterator i = names.begin();
            i != names.end(); ++i) {
        if (*i == "Child1")
            p = new Child1;
        if (*i == "Child2")
            p = new Child2;
        if (*i == "Child3")
            p = new Child3;

        // TODO: do something with p
    }
    return 0;
}

