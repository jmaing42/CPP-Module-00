#include "Contact.hpp"

const std::string &Contact::getName() const { return this->name; }
const std::string &Contact::getNumber() const { return this->number; }
void Contact::setName(std::string name) { this->name = name; }
void Contact::setNumber(std::string number) { this->number = number; }
