#include "PmergeMe.hpp"

template <typename T>
std::string getContainerName();

template <>
std::string getContainerName<std::deque<int> >( void )
{
    return ("deque<int>");
}

template <>
std::string getContainerName<std::list<int> >( void )
{
    return ("list<int>");
}

std::string trim( std::string str )
{
    size_t start = 0;
    size_t end = str.length();

    while (start < end && isspace(str[start]))
        start++;
    while (end > start && isspace(str[end - 1]))
        end--;
    return str.substr(start, end - start);
}

int   strtoi( std::string line )
{
    int             num;
    std::stringstream ss(line);
    if (!(ss >> num))
        return (std::numeric_limits<float>::quiet_NaN());
    return (num);
}

template<typename T>
void        PmergeMe<T>::validArgs( char **data )
{
    size_t  i = 0;
    while ( data[i] && is_num( data[i] ) )
        i++;
    if ( data[i] )
        throw PmergeMe<T>::WrongArguments();
}

template<typename T>
int         PmergeMe<T>::is_num( std::string str )
{
    int i = 0;

    str = trim( str );
    if ( str[i] && str[i] == '+' )
        i++;
    while ( str[i] )
        isdigit( str[i]) ? i++ : throw PmergeMe<T>::WrongArguments();
    if ( strtoi( str ) == -2147483648)
        throw PmergeMe<T>::WrongArguments();
    return ( 1 );
}

template<typename T>
void        PmergeMe<T>::merge( it start, it mid, it end )
{
    T   mergedList;
    it  i = start;
    it  j = mid;

    while (i != mid && j != end) {
        if (*i <= *j) {
            mergedList.push_back(*i);
            ++i;
        } else {
            mergedList.push_back(*j);
            ++j;
        }
    }
    while (i != mid) {
        mergedList.push_back(*i);
        ++i;
    }
    while (j != end) {
        mergedList.push_back(*j);
        ++j;
    }
    it k = start;
    it m = mergedList.begin();
    for ( size_t i = 0; i < mergedList.size(); i++)
        *k = *m, ++k, ++m;
}

template<typename T>
void        PmergeMe<T>::mergeInsert(  it startIt, it endIt )
{
    size_t len = std::distance(startIt, endIt);
    if ( len > 1 )
    {
        it midIt = startIt;
        std::advance(midIt, len / 2);
        mergeInsert(startIt, midIt);
        mergeInsert(midIt, endIt);
        merge(startIt, midIt, endIt);
    }
}

template<typename T>
PmergeMe<T>::PmergeMe() : _data(),  _time(0) {}

template<typename T>
PmergeMe<T>::PmergeMe( char **data )
{
    std::clock_t start = std::clock();
    validArgs( data );
    for ( size_t i = 0; data[i]; i++ )
        _data.insert(_data.begin(), strtoi(data[i]) );
    _time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}

template<typename T>
PmergeMe<T>::PmergeMe( const PmergeMe &p )
{
    *this = p;
}

template<typename T>
PmergeMe<T>    &PmergeMe<T>::operator=( const PmergeMe &other )
{
    if (this != &other)
    {
        for (size_t i = 0; i < _data.size(); i++ )
            _data.erase(--_data.end());
        const_it  ite = other._data.begin();
        for (size_t i = 0; i < other._data.size(); i++ )
            _data.push_back( *ite ), ite++;
    }
    return *this;
}

template<typename T>
PmergeMe<T>::~PmergeMe(){}

template<typename T>
void        PmergeMe<T>::sort()
{
    std::clock_t start = std::clock();

    mergeInsert(_data.begin(), _data.end() );

    _time += static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}

template<typename T>
void        PmergeMe<T>::benchmark() const
{
    std::cout << "Time to process a range of " << _data.size();
    std::cout << " elements with std::" << getContainerName<T>();
    std::cout << " : " << std::fixed << std::setprecision(5) << _time << " us" << std::endl;
}

template<typename T>
void        PmergeMe<T>::printContainer()
{
    typename T::const_iterator   it = _data.begin();
    while (it != _data.end())
        std::cout << *it << " ", it++;
    std::cout << std::endl;
}

template class PmergeMe< std::list<int> >;
template class PmergeMe< std::deque<int> >;
