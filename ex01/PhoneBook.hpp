#ifndef EX01_PHONEBOOK_HPP_INCLUDED
#define EX01_PHONEBOOK_HPP_INCLUDED

#include "Contact.hpp"

#define EX01_PHONEBOOK_HPP_MAXIMUM_CONTACTS 8

class PhoneBook {
  Contact contacts[EX01_PHONEBOOK_HPP_MAXIMUM_CONTACTS];
};

#endif
