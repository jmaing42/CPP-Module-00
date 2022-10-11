#include "Contact.hpp"

const std::string Contact::getFirstName() const { return this->firstName; }
const std::string Contact::getLastName() const { return this->lastName; }
const std::string Contact::getNickName() const { return this->nickName; }
const std::string Contact::getNumber() const { return this->number; }

void Contact::setFirstName(std::string firstName) {
  this->firstName = firstName;
}
void Contact::setLastName(std::string lastName) { this->lastName = lastName; }
void Contact::setNickName(std::string nickName) { this->nickName = nickName; }
void Contact::setNumber(std::string number) { this->number = number; }
