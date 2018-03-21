#include "Account.class.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void pad(int t) {
    std::cout <<  std::setw(2) << std::setfill('0') << t;
}

void Account::displayStatus(void) const {
    Account::_displayTimestamp(); 
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";deposits:" << this->_nbDeposits;
    std::cout << ";withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
}

void Account::_displayTimestamp(void) {
    time_t t = time(NULL);
	tm* timePtr = localtime(&t);
    // std::cout << "[20150406_153629] ";
    std::cout << "[";
    std::cout << timePtr->tm_year + 1900;
    pad(timePtr->tm_mon + 1);
    pad(timePtr->tm_mday);
    std::cout << "_";
    pad(timePtr->tm_hour);
    pad(timePtr->tm_min);
    pad(timePtr->tm_sec);
    std::cout << "] ";
}

void Account::makeDeposit(int deposit) {
     Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    std::cout << ";deposit:" << deposit;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";nb_deposits:1" << std::endl;
}

int Account::checkAmount(void) const {
    return this->_amount;
}

bool Account::makeWithdrawal(int withdrawal) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    std::cout << ";withdrawal:";
    if (withdrawal > checkAmount())
        {
            std::cout << "refused" << std::endl;
            return false;
        }
    std::cout << withdrawal;
    this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals += 1;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";nb_withdrawals:1" << std::endl;
    return true;
}

void Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts;
    std::cout << ";total:" << Account::_totalAmount;
    std::cout << ";deposits:" << Account::_totalNbDeposits;
    std::cout << ";withdrawals:" << Account::_totalNbWithdrawals;
    std::cout << std::endl;
}

Account::Account() {
    // std::cout << "Private" << std::endl;
}

Account::Account(int inital_deposit) {
    Account::_displayTimestamp();
    std::cout << "index:" << t::_nbAccounts;
    std::cout << ";amount:" << inital_deposit;
    std::cout << ";created" << std::endl;

    this->_accountIndex = t::_nbAccounts;
    this->_amount = inital_deposit;
    Account::_nbDeposits = 0;
     Account::_nbWithdrawals = 0;
    Account::_totalAmount += inital_deposit;
    // Account::_listContacts[Account::_index] = this;
    t::_nbAccounts += 1;
}

Account::~Account(void) {
    Account::_displayTimestamp(); 
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";closed" << std::endl;
}
