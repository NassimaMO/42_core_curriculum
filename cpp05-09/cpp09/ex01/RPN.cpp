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

std::string    trim( std::string str )
{
    size_t start = 0;
    size_t end = str.length();

    while (start < end && isspace(str[start]))
        start++;
    while (end > start && isspace(str[end - 1]))
        end--;
    return str.substr(start, end - start);
}

void    RPN::calculate( std::string expression )
{
    int one;
    int two;

    if ( !isExpressionValid( expression ) )
        throw RPN::BadExpression();
    while ( !expression.empty() )
    {
        while ( expression.find_first_not_of("0123456789 ") )
        {
            if ( !isspace(expression[0]) )
                nums.push(strtoi(expression.substr(0, expression.find(' '))));
            expression = expression.substr(1, expression.length());
        }
        for ( size_t i = expression.find_first_not_of("/*-+ "); i > 0 && i < INT_MAX ; i--)
                isspace(expression[i - 1]) ? (void)42 : ops.push(expression[i - 1]);
        if ( expression.find_first_not_of("/*-+ ") > INT_MAX )
        {
            for ( size_t i = expression.length(); i > 0; i--)
                isspace(expression[i - 1]) ? (void)42 : ops.push(expression[i - 1]);
            expression = "";
        }
        else
            expression = expression.substr(expression.find_first_not_of("/*-+ "), expression.length());
        while ( !ops.empty() )
        {
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
    }
    std::cout << two << std::endl;
    ops = std::stack<char>();
    nums = std::stack<int>();
}

int RPN::isExpressionValid( std::string expression )
{
    int num = 0;
    int op = 0;

    expression = trim( expression );
    for ( int i = 0; expression[i]; i++ )
    {
        if ( !isspace( expression[i] ) && isdigit( expression[i] ) && ((num++, strtoi(expression.substr(i, expression.find(' ') ) ) ) >= 10  || (i += expression.substr(i, expression.size()).find_first_not_of("0123456789") ), 0))
            return ( 0 );
        else if ( expression[i] && !isspace( expression[i] ) && !isdigit( expression[i] ) )
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
            if ( expression[i + 1] && isdigit(expression[i + 1]) )
                return ( 0 );
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

const char * RPN::BadExpression::what() const throw()
{
    return ( "Error" );
}