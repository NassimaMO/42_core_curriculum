#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
    public:
    Brain( void );
    Brain( const Brain& cp );
    Brain& operator=( const Brain& cp );
    virtual ~Brain();

    std::string getIdea( int index );
    void        setIdea( std::string idea, int index );

    private:
        std::string _ideas[100];
};

#endif
