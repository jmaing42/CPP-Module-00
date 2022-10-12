#include <ctime>
#include <iomanip>
#include <ios>
#include <iostream>

#include "Account.hpp"

static int nbAccounts = 0;
static int totalAmount = 0;
static int nbDeposits = 0;
static int nbWithdrawals = 0;

int Account::getNbAccounts(void) { return nbAccounts; }
int Account::getTotalAmount(void) { return totalAmount; }
int Account::getNbDeposits(void) { return nbDeposits; }
int Account::getNbWithdrawals(void) { return nbWithdrawals; }
void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::getNbAccounts() << ";";
  std::cout << "total:" << Account::getTotalAmount() << ";";
  std::cout << "deposits:" << Account::getNbDeposits() << ";";
  std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit) {
  this->_displayTimestamp();
  this->_accountIndex = nbAccounts++;
  totalAmount += this->_amount = initial_deposit;
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
  std::cout << "created" << std::endl;
}

void Account::makeDeposit(int deposit) {
  nbDeposits += deposit;
  this->_nbDeposits += deposit;
}
bool Account::makeWithdrawal(int withdrawal) {
  if (this->checkAmount() < withdrawal)
    return false;
  nbWithdrawals += withdrawal;
  this->_nbWithdrawals += withdrawal;
  return true;
}
int Account::checkAmount(void) const {
  return this->_amount - this->_nbWithdrawals;
}
void Account::displayStatus(void) const {
  this->_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "deposits:" << this->_nbDeposits << ";";
  std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
  std::time_t now = std::time(nullptr);
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
