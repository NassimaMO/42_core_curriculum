#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class IMateriaSource;

class MateriaSource : public IMateriaSource
{
    private:
    
    AMateria    *tab[4];
    int         m_num;

    public:

    MateriaSource( void );
    MateriaSource( const IMateriaSource& cp );
    MateriaSource& operator=( const MateriaSource& cp );
    ~MateriaSource();
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

#endif