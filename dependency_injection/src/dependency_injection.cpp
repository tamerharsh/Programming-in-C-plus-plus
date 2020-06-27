#include <iostream>
#include <memory>

//Abstract
class Abstract{
public:
virtual int display(const int& num)=0;
};

//Concerte from abstract
class Concrete:public Abstract
{
public:
int display(const int& num) const override
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
void show(const int& num)const
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