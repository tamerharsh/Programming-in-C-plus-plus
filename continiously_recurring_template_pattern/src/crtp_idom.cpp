#ifndef CRTP_IDOM
#define CRTP_IDOM

#include <iostream>
#define HEADER std::cout<<"\n ===================="<<__FUNCTION__<<"===============\n";

template <typename Derived>
struct Base {
    void interface() {
        static_cast<Derived*>(this)->implementation();
    }
    void implementation() {
        std::cout << "Implementation Base" << std::endl;
    }
};

struct Derived1 : Base<Derived1> {
    void implementation() {
        std::cout << "Implementation Derived1" << std::endl;
    }
};

struct Derived2 : Base<Derived2> {
    void implementation() {
        std::cout << "Implementation Derived2" << std::endl;
    }
};

struct Derived3 : Base<Derived3> {};

template <typename T>
void execute(T& base) {
    base.interface();
}

void run_crtp_idom() {
    HEADER;
    std::cout << std::endl;

    Derived1 d1;
    execute(d1);
}
#endif