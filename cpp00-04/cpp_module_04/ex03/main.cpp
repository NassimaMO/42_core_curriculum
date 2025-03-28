#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main( void )
{
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    /*Ice * tmp = new Ice();
    AMateria * test = tmp;
    std::cout << test->getType() << std::endl;
    delete tmp;*/


    /*IMateriaSource* src = new MateriaSource();
    AMateria * test = new Ice();
    src->learnMateria(test);
    src->learnMateria(new Cure());
    delete src;*/

    /*IMateriaSource* src = new MateriaSource();
    ICharacter* me = new Character("me");
    AMateria * tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    delete me;
    delete src;*/

    return 0;

}
