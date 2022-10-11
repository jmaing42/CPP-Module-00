#ifndef EX01_PHONEBOOK_HPP_INCLUDED
#define EX01_PHONEBOOK_HPP_INCLUDED

#include <cstddef>

#include "Contact.hpp"

#define EX01_PHONEBOOK_HPP_MAXIMUM_CONTACTS 8

class PhoneBook {
private:
  Contact contacts[EX01_PHONEBOOK_HPP_MAXIMUM_CONTACTS];
  std::size_t offset;
  std::size_t itemCount;

public:
  PhoneBook();
  std::size_t length() const;
  Contact getContact(std::size_t index) const;
  void putContact(Contact contact);
};

#endif
