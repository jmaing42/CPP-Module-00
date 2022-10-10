#include <cstdlib>
#include <iostream>
#include <string>

#include "Contact.hpp"
#include "PhoneBook.hpp"

static void fill(Contact &contact) {
  std::string line;

  std::cout << "Enter name" << std::endl;
  std::getline(std::cin, line);
  contact.setName(line);
  std::cout << "Enter number" << std::endl;
  std::getline(std::cin, line);
  contact.setNumber(line);
}

int main() {
  PhoneBook phoneBook;
  std::string line;

  do {
    std::getline(std::cin, line);
    if (line == "ADD") {
      fill(phoneBook.newContact());
    }
  } while (line != "EXIT");
}
