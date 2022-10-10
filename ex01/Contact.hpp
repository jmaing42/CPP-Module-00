#ifndef EX01_CONTACT_HPP_INCLUDED
#define EX01_CONTACT_HPP_INCLUDED

#include <string>

class Contact {
private:
  std::string name;
  std::string number;

public:
  const std::string &getName() const;
  const std::string &getNumber() const;
  void setName(std::string name);
  void setNumber(std::string number);
};

#endif
