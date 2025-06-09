#include <iostream>
#include <list>
#include "A.hpp"
#define nl cout<<endl;

using namespace std;

int main() {
    std::cout << "Test 1: integers()\n";
    std::cout << "integers(5) = " << integers(5) << "\n";
    std::cout << "integers(-5) = " << integers(-5) << "\n";
    std::cout << "integers(50) = " << integers(50) << "\n";
    std::cout << "integers(60) = " << integers(60) << "\n";

    std::cout << "\nTest 2: evenNumber()\n";
    std::cout << "evenNumber(6) = " << evenNumber(6) << "\n";
    std::cout << "evenNumber(-6) = " << evenNumber(-6) << "\n";
    std::cout << "evenNumber(5) = " << evenNumber(5) << "\n";
    std::cout << "evenNumber(102) = " << evenNumber(102) << "\n";

    std::cout << "\nTest 3: characters()\n";
    std::cout << "characters('a') = " << characters('a') << "\n";
    std::cout << "characters('z') = " << characters('z') << "\n";
    std::cout << "characters('A') = " << characters('A') << "\n";
    std::cout << "characters('1') = " << characters('1') << "\n";

    std::cout << "\nTest 4: characters_reversed()\n";
    std::cout << "characters_reversed(0) = " << characters_reversed(0) << "\n";
    std::cout << "characters_reversed(25) = " << characters_reversed(25) << "\n";
    std::cout << "characters_reversed(26) = " << characters_reversed(26) << "\n";

    std::string input = "ab";
    int index = hash2Letters(input);
    std::cout << "Hasz slowa \"" << input << "\": " << index << std::endl;

    std::string back = unhashIndex(index);
    std::cout << "Slowo z indeksu " << index << ": " << back << std::endl;

    std::string input2 = "pl";
    int index2 = hash2Letters(input2);
    std::cout << "Hasz slowa \"" << input2 << "\": " << index2 << std::endl;

    std::string back2 = unhashIndex(index2);
    std::cout << "Slowo z indeksu " << index2 << ": " << back2 << std::endl;




    return 0;
}