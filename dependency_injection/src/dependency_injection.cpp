#include <iostream>
#include <memory>

//Abstract
class Abstract{
public:
virtual int display(int num)=0;
};

//Concerte from abstract
class Concrete:public Abstract
{
public:
int display(int num) override
{
return num;
}
};

//Dependent
class Dependent
{
public:
Dependent(std::shared_ptr<Abstract> ptr):m_ptr(ptr)
{
}
void show(int num)
{
std::cout<<"This is from Dependecy "<<m_ptr->display(num);
}
private:
std::shared_ptr<Abstract>m_ptr;
};

int main() {
  Dependent d_obj(std::make_shared<Concrete>());
  d_obj.show(45);
}