#include <cctype>
#include <cstddef>
#include <iostream>

int main(int argc, char **argv) {
  if (argc < 2)
    return EXIT_FAILURE;
  std::string s = argv[1];
  for (std::size_t i = 0; i < s.length(); i++)
    std::cout << static_cast<char>(std::toupper(s[i]));
  std::cout << std::endl;
}
