#include <cctype>
#include <cstddef>
#include <iostream>

#define DEFAULT_MESSAGE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << DEFAULT_MESSAGE << std::endl;
  } else {
    std::string s = argv[1];
    for (std::size_t i = 0; i < s.length(); i++)
      std::cout << static_cast<char>(std::toupper(s[i]));
    std::cout << std::endl;
  }
}
