#ifndef EX01_CONTACT_HPP_INCLUDED
#define EX01_CONTACT_HPP_INCLUDED

#include <string>

class Contact {
private:
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string number;

public:
  const std::string getFirstName() const;
  const std::string getLastName() const;
  const std::string getNickName() const;
  const std::string getNumber() const;
  void setFirstName(std::string firstName);
  void setLastName(std::string firstName);
  void setNickName(std::string firstName);
  void setNumber(std::string firstName);
};

#endif
