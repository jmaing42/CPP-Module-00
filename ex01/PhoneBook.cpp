#include "PhoneBook.hpp"

std::size_t PhoneBook::length() const { return this->itemCount; }

Contact &PhoneBook::getContact(std::size_t index) {
  return this
      ->contacts[(this->offset + index) % EX01_PHONEBOOK_HPP_MAXIMUM_CONTACTS];
}

const Contact &PhoneBook::getContact(std::size_t index) const {
  return this
      ->contacts[(this->offset + index) % EX01_PHONEBOOK_HPP_MAXIMUM_CONTACTS];
}

Contact &PhoneBook::newContact() {
  if (this->itemCount == EX01_PHONEBOOK_HPP_MAXIMUM_CONTACTS) {
    this->offset = (this->offset + 1) % EX01_PHONEBOOK_HPP_MAXIMUM_CONTACTS;
  } else {
    this->itemCount++;
  }
  return this->getContact(this->itemCount - 1);
}
