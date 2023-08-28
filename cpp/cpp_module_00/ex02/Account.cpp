#include <iostream>
#include "Account.hpp"

Account::Account( int initial_deposit )
{
    //this->makeDeposit(initial_deposit);
    _nbAccounts++;
    _totalAmount += initial_deposit;
    this->_amount = initial_deposit;
    this->_accountIndex = this->_nbAccounts;
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account( void )
{
    _nbAccounts--;
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int  Account::getNbAccounts( void )
{
    return (_nbAccounts);
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
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _totalNbDeposits++;
    this->_nbDeposits++;
    _totalAmount += deposit;
    this->_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _totalNbWithdrawals++;
    this->_nbWithdrawals++;
    if (this->_amount < withdrawal)
        return (false);
    _totalAmount -= withdrawal;
    this->_amount -= withdrawal;
    return (true);
}

int		Account::checkAmount( void ) const
{
    //
}

void	Account::displayStatus( void ) const
{
    //
}
