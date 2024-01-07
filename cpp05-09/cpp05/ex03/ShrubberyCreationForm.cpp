#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm( "Shrubbery Creation Form", 145, 137 ), m_target( target )
{
    std::cout << "ShrubberyCreationForm created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& f ) : AForm( "Shrubbery Creation Form", 145, 137 )
{
    *this = f;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=( const ShrubberyCreationForm& f )
{
    if ( this != &f )
        m_target = f.m_target;
    return ( *this );
}

void ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
    if ( getSignature() == false )
        throw AForm::NotSignedException();
    if ( executor.getGrade() > getGradeRequiredExec() )
        throw AForm::GradeTooLowException();
    std::string     filename = m_target + "_shrubbery";
    std::ofstream   shrubberyFile( filename.c_str() );

    if ( shrubberyFile.is_open() )
    {
        shrubberyFile << "            .        +          .      .          ." << std::endl;
        shrubberyFile << "     .            _        .                    ." << std::endl;
        shrubberyFile << "  ,              /;-._,-.____        ,-----.__" << std::endl;
        shrubberyFile << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
        shrubberyFile << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
        shrubberyFile << "                      ,    `./  \\:. `.   )==-'  ." << std::endl;
        shrubberyFile << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
        shrubberyFile << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
        shrubberyFile << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
        shrubberyFile << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
        shrubberyFile << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
        shrubberyFile << "              \\:  `  X` _| _,\\/'   .-'" << std::endl;
        shrubberyFile << ".               \":._:`\\____  /:'  /      .           ." << std::endl;
        shrubberyFile << "                    \\::.  :\\/:'  /              +" << std::endl;
        shrubberyFile << "   .                 `.:.  /:'  }      ." << std::endl;
        shrubberyFile << "           .           ):_(:;   \\           ." << std::endl;
        shrubberyFile << "                      /:. _/ ,  |" << std::endl;
        shrubberyFile << "                   . (|::.     ,`                  ." << std::endl;
        shrubberyFile << "     .                |::.    {" << std::endl;
        shrubberyFile << "                      |::.\\  \\ `." << std::endl;
        shrubberyFile << "                      |:::(\\    |" << std::endl;
        shrubberyFile << "              O       |:::/{ }  |                  (o" << std::endl;
        shrubberyFile << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
        shrubberyFile << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
        shrubberyFile << "      ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~" << std::endl;
        shrubberyFile.close();
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destroyed." << std::endl;
}