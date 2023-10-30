class AMateria
{
    protected:

    std::string type;

    public:

    AMateria( std::string const & type );
    AMateria( const AMateria& cp );
    AMateria&           operator=( const AMateria& cp );
    std::string const & getType( void ) const;
    virtual AMateria*   clone( void ) const = 0;
    virtual void        use( ICharacter& target );
    ~AMateria( void );
};
