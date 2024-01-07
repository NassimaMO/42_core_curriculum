#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>

class A;
class B;
class C;

class   Base
{
    private:
    public:

    virtual ~Base();
};

/*It randomly instanciates A, B or C and returns the instance as a Base pointer.*/
Base*   generate(void);
/*It prints the actual type of the object pointed to by p: "A", "B" or "C".*/
void    identify(Base* p);
/*It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer inside this function is forbidden.*/
void    identify(Base& p);

#endif