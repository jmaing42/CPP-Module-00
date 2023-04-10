#include <cstddef>
#include <ctime>
#include <iomanip>
#include <ios>
#include <iostream>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return Account::_nbAccounts; }
int Account::getTotalAmount(void) { return Account::_totalAmount; }
int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }
int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }
void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::getNbAccounts() << ";";
  std::cout << "total:" << Account::getTotalAmount() << ";";
  std::cout << "deposits:" << Account::getNbDeposits() << ";";
  std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit) {
  this->_displayTimestamp();
  this->_accountIndex = Account::_nbAccounts++;
  Account::_totalAmount += this->_amount = initial_deposit;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "created" << std::endl;
}
Account::~Account(void) {
  this->_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
  this->_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << this->_amount << ";";
  std::cout << "deposit:" << deposit << ";";
  std::cout << "amount:" << this->_amount + deposit << ";";
  std::cout << "nb_deposits:" << this->_nbDeposits + 1 << std::endl;
  this->_nbDeposits += 1;
  Account::_totalNbDeposits += 1;
  this->_amount += deposit;
  Account::_totalAmount += deposit;
}
bool Account::makeWithdrawal(int withdrawal) {
  if (this->checkAmount() < withdrawal) {
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "withdrawal:refused" << std::endl;
    return false;
  } else {
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << this->_amount - withdrawal << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals + 1 << std::endl;
    this->_nbWithdrawals += 1;
    Account::_totalNbWithdrawals += 1;
    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    return true;
  }
}
int Account::checkAmount(void) const { return this->_amount; }
void Account::displayStatus(void) const {
  this->_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "deposits:" << this->_nbDeposits << ";";
  std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
  std::time_t now = std::time(NULL);
  struct tm t = *localtime(&now);
  std::cout << '[';
  std::cout << std::setw(4) << std::setfill('0') << std::right
            << t.tm_year + 1900;
  std::cout << std::setw(2) << std::setfill('0') << std::right << t.tm_mon + 1;
  std::cout << std::setw(2) << std::setfill('0') << std::right << t.tm_mday;
  std::cout << '_';
  std::cout << std::setw(2) << std::setfill('0') << std::right << t.tm_hour;
  std::cout << std::setw(2) << std::setfill('0') << std::right << t.tm_min;
  std::cout << std::setw(2) << std::setfill('0') << std::right << t.tm_sec;
  std::cout << "] ";
}
Account::Account(void) { throw "Not implemented"; }
