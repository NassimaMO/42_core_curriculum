#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    /*Animal test;*/
    Dog   ani;
    Dog   mal = ani;

    ani.setBrainIdea("lololol", 0);
    mal.setBrainIdea("eyeyey", 0);
    std::cout << ani.getBrainIdea(0) << std::endl;
    std::cout << mal.getBrainIdea(0) << std::endl;
    std::cout << std::endl;


    const Animal* tab[4] =  {new Dog(), new Dog(), new Cat(), new Cat()};

    for (int i = 0; i < 4; i++)
        delete tab[i];

    return ( 0 );


    /*const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    return 0;*/

}