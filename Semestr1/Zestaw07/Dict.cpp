#include "Dict.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char const* argv[]) {
    if (argc != 2) {
		std::cerr << "Nie poprawna liczba arugmentów";
		return 1;
	}
    std::fstream file(argv[1]);
    Dict<std::string, std::string> dict;
    std::string key, value;
    while (file >> key >> value) {
        dict.insert({key, value}); 
    }
    while (std::cin >> key) {
    if (dict.find(key)) {
        std::cout << dict[key];
    } else {
        std::cout << "-";
    }
    if (!std::cin.eof()) { 
        std::cout << '\n';
    }
}
    return 0;
}
