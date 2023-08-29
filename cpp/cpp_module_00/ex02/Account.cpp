#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
    //test
    time_t now	= time(0);
	tm *ltm		= localtime(&now);

	std::cout << "[";
	std::cout << 1900 + ltm->tm_year;
	ltm->tm_mon < 10 ? std::cout << "0" << 1 + ltm->tm_mon : std::cout << 1 + ltm->tm_mon;
	ltm->tm_mday < 10 ? std::cout << "0" << ltm->tm_mday : std::cout <<  ltm->tm_mday;
	std::cout << "_";
	ltm->tm_hour < 10 ? std::cout << "0" << ltm->tm_hour : std::cout << ltm->tm_hour;
	ltm->tm_min < 10 ? std::cout << "0" << ltm->tm_min : std::cout <<  ltm->tm_min;
	ltm->tm_sec < 10 ? std::cout << "0" << ltm->tm_sec : std::cout <<  ltm->tm_sec;
	std::cout << "] ";
}

Account::Account( void )
{
    this->_amount = 0;
    this->_accountIndex = _nbAccounts++;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::Account( int initial_deposit )
{
    _totalAmount += initial_deposit;
    this->_amount = initial_deposit;
    this->_accountIndex = _nbAccounts++;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account( void )
{
    _nbAccounts--;
	_totalAmount -= _amount;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int  Account::getNbAccounts( void )
{
    return ( _nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit << std::flush;
    _totalNbDeposits++;
    this->_nbDeposits++;
    _totalAmount += deposit;
    this->_amount += deposit;
    std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << std::flush;
    if (this->_amount < withdrawal)
        return (std::cout << "refused" << std::endl, false);
    _totalNbWithdrawals++;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    this->_amount -= withdrawal;
    std::cout << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}


