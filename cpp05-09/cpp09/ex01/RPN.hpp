#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstring>
# include <cstdlib>
# include <sstream>
# include <limits.h>

class RPN
{

    private:

        std::stack<int>     nums;
        std::stack<char>    ops;
        int                 isExpressionValid( std::string expression );

    public:

        RPN( void );
        RPN( const RPN& r );
        RPN&            operator=( const RPN& r );
        ~RPN();

        void            calculate( std::string expression );

        class   BadExpression : public std::exception
        {
            public:

                const char * what() const throw();
        };
};

#endif