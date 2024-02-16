#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <deque>
# include <ctime>
# include <iomanip>
# include <sstream>
# include <limits>
# include <cstring>

template<typename T>
class PmergeMe
{

    private:
        typedef typename T::iterator it;
        typedef typename T::const_iterator const_it;
        T           _data;
        double      _time;
        void        validArgs( char **data );
        int         is_num( std::string str );
        void        merge( it start, it mid, it end );
        void        mergeInsert(  it startIt, it endIt );

    public:
        PmergeMe();
        explicit PmergeMe( char **data );
        PmergeMe( const PmergeMe &p );
        PmergeMe    &operator=( const PmergeMe &other );

        ~PmergeMe();

        void        sort();
        void        benchmark() const;
        void        printContainer();

        class WrongArguments : public std::exception
        {
            public:

            const char *what() const throw(){ return ("Wrong arguments."); }
        };
};

#endif