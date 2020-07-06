Purpose is to perform single task  in multiple ways.
Example can be using a function having same name but diiferent parameters, or same  name  with same paramters refined in one of its derive
d class.

Real life example 
You are same person but with have different  relationships , depending upon the context  you are brother , sister etc.

Fundementally  
Polymorpihsm is of two types:-

1.Static polymophism 
2. Dynamic Polymorphism 
3.F Bound Polymoriphsm 
Inshort ,
Dynamic Polymorphism  has virtual member function and is usaully overriden in dervied class. Every is accompanied  with vtable which stores the address of the virtual function.
and every object of the class has v_ptr called virtual pointer through which call resolution happens  this is virtual dispatch mechanism .

But this vptr has some extra cost asscoaited with it.
i.e. evalaution at run time  and size of class incresease due to vptr.

Instead to save from these problems we have still achieve the same using static polymorphism namely F bound Polymorphism.
called CRTP Continioulsy recurring template pattern.

It also uses lazy initialziation which means evaluating the expression whenever it is needed .

// crtp.cpp

#include <iostream>

template <typename Derived>
struct Base{
  void interface(){
    static_cast<Derived*>(this)->implementation();
  }
  void implementation(){
    std::cout << "Implementation Base" << std::endl;
  }
};

struct Derived1: Base<Derived1>{
  void implementation(){
    std::cout << "Implementation Derived1" << std::endl;
  }
};

struct Derived2: Base<Derived2>{
  void implementation(){
    std::cout << "Implementation Derived2" << std::endl;
  }
};

struct Derived3: Base<Derived3>{};

template <typename T>
void execute(T& base){
    base.interface();
}


int main(){
  
  std::cout << std::endl;
  
  Derived1 d1;
  execute(d1);
 return 0;
 }