#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <string>

#include "Contact.hpp"
#include "PhoneBook.hpp"

static Contact newContact() {
  std::string line;
  Contact contact;

  std::cout << "Enter first name" << std::endl;
  std::getline(std::cin, line);
  contact.setFirstName(line);
  std::cout << "Enter last name" << std::endl;
  std::getline(std::cin, line);
  contact.setLastName(line);
  std::cout << "Enter nick name" << std::endl;
  std::getline(std::cin, line);
  contact.setNickName(line);
  std::cout << "Enter number" << std::endl;
  std::getline(std::cin, line);
  contact.setNumber(line);
  return contact;
}

static void printSimpleContact(Contact contact, std::size_t index) {
  std::cout << '|' << std::right << std::setw(10) << index << '|';
  if (contact.getFirstName().length() > 9) {
    std::cout << contact.getFirstName().substr(0, 9) << ".|";
  } else {
    std::cout << std::right << std::setw(10) << contact.getFirstName() << '|';
  }
  if (contact.getLastName().length() > 9) {
    std::cout << contact.getLastName().substr(0, 9) << ".|";
  } else {
    std::cout << std::right << std::setw(10) << contact.getLastName() << '|';
  }
  if (contact.getNickName().length() > 9) {
    std::cout << contact.getNickName().substr(0, 9) << ".|";
  } else {
    std::cout << std::right << std::setw(10) << contact.getNickName() << '|';
  }
  std::cout << std::endl;
}

static void printDetailContact(Contact contact) {
  std::cout << "First name: " << contact.getFirstName() << std::endl;
  std::cout << "Last name: " << contact.getLastName() << std::endl;
  std::cout << "Nick name: " << contact.getNickName() << std::endl;
  std::cout << "Number: " << contact.getNumber() << std::endl;
}

int main() {
  PhoneBook phoneBook;

  while (std::cin) {
    std::cout << "Enter command (ADD, SEARCH, EXIT)" << std::endl;
    std::string line;
    std::getline(std::cin, line);
    if (line == "ADD") {
      phoneBook.putContact(newContact());
    } else if (line == "SEARCH") {
      std::size_t index;
      std::size_t length = phoneBook.length();
      for (std::size_t i = 0; i < length; i++) {
        printSimpleContact(phoneBook.getContact(i), i);
      }
      std::cout << "Enter index to search" << std::endl;
      std::cin >> index;
      if (!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input" << std::endl;
      } else {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (index < length) {
          printDetailContact(phoneBook.getContact(index));
        } else {
          std::cout << "Out of range" << std::endl;
        }
      }
    } else if (line == "EXIT") {
      break;
    }
  }
}
