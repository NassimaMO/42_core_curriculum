#include "RPN.hpp"

RPN::RPN( void )
{
}

RPN::RPN( const RPN& r )
{
    *this = r;
}

RPN&    RPN::operator=( const RPN& r )
{
    (void)r;
    return ( *this );
}

RPN::~RPN()
{}

int   strtoi( std::string line )
{
    int               num;
    std::stringstream ss(line);
    ss >> num;
    return (num);
}

void    RPN::calculate( std::string expression )
{
    size_t index = 0;
    int one;
    int two;

    if ( !isExpressionValid( expression ) )
        throw RPN::BadExpression();
    while ( !expression.empty() )
    {
        //stock_operations( expression );
        expression = expression.substr(expression.find_first_not_of("0123456789 "), expression.length());
        while ( index < expression.length() && !isspace(expression[index]) && isdigit( expression[index] ))
            nums.push(strtoi(expression.substr(index, expression.find(' ')))), index++;
        expression = expression.substr(expression.find_first_not_of("0123456789 "), expression.length());
        std::cout << expression << "    " << expression.length() << std::endl;
        for ( size_t i = expression.find_first_not_of("/ *-+"); i > 0 && !isspace(expression[i - 1]) && !isdigit( expression[i - 1] ); i--)
            ops.push(expression[i - 1]);
        one = nums.top();
        nums.pop();
        if ( !nums.empty() )
        {two = nums.top();
        nums.pop();}
        //std::cout << "operation: (" << two << ")"<< ops.top() << "(" << one << ")" << std::endl;
        switch ( ops.top() )
        {
            case '+':
                two += one;
                break;
            case '-':
                two -= one;
                break;
            case '/':
                two /= one;
                break;
            case '*':
                two *= one;
        }
        ops.pop();
        nums.push(two);
    }
    std::cout << two << std::endl;
}

int RPN::isExpressionValid( std::string expression ) // The numbers used in this operation and passed as arguments will always be less than 10 ???
{
    int num = 0;
    int op = 0;

    for ( int i = 0; expression[i]; i++ )
    {
        if ( !isspace( expression[i] ) && isdigit( expression[i] ) && (num++, strtoi(expression.substr(i, expression.find(' ') ) ) ) >= 10 )
            return ( 0 );
        else if ( !isspace( expression[i] ) && !isdigit( expression[i] ) )
        {
            switch ( expression[i] )
            {
                case '+':
                case '-':
                case '/':
                case '*':
                    break;
                default:
                    return ( 0 );
            }
            op++;
        }
    }
    switch ( expression[expression.length() - 1] )
    {
        case '+':
        case '-':
        case '/':
        case '*':
            break;
        default:
            return ( 0 );
    }
    if ( op != num - 1 )
        return ( 0 );
    return ( 1 );
}

void    RPN::stock_operations( std::string& expression )
{
    size_t index = 0;
    while ( index < expression.length() && !isspace(expression[index]) && isdigit( expression[index] ))
        nums.push(strtoi(expression.substr(index, expression.find(' ')))), index++;
    expression = expression.substr(expression.find_first_not_of("0123456789 "), expression.length());
    //std::cout << expression << "     " << expression.substr(0, expression.find_first_not_of("+-/* ")).length() << std::endl;
    for ( size_t i = expression.length() - expression.substr(0, expression.find_first_not_of("+-/* ")).length(); i > 0 && !isspace(expression[i - 1]) && !isdigit( expression[i - 1] ); i--)
        ops.push(expression[i - 1]);
    /*for ( size_t i = 0; i < expression.length(); i++)
    {
        if ( !isspace(expression[i]) && isdigit( expression[i] ) )
            nums.push(strtoi(expression.substr(i, expression.find(' '))));
    }
    for ( size_t i = expression.length(); i > 0; i--)
    {
        if ( !isspace(expression[i - 1]) && !isdigit( expression[i - 1] ) )
            ops.push(expression[i - 1]);
    }*/
}

const char * RPN::BadExpression::what() const throw()
{
    return ( "Error" );
}