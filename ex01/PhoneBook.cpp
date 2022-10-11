#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
  this->offset = 0;
  this->itemCount = 0;
}

std::size_t PhoneBook::length() const { return this->itemCount; }

Contact PhoneBook::getContact(std::size_t index) const {
  return this
      ->contacts[(this->offset + index) % EX01_PHONEBOOK_HPP_MAXIMUM_CONTACTS];
}

void PhoneBook::putContact(Contact contact) {
  if (this->itemCount == EX01_PHONEBOOK_HPP_MAXIMUM_CONTACTS) {
    this->offset = (this->offset + 1) % EX01_PHONEBOOK_HPP_MAXIMUM_CONTACTS;
  } else {
    this->itemCount++;
  }
  this->contacts[(this->offset + this->itemCount - 1) %
                 EX01_PHONEBOOK_HPP_MAXIMUM_CONTACTS] = contact;
}
