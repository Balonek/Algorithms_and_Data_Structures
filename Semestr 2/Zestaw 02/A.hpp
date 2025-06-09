#include <iostream>
#include <algorithm>
#include <cstring>

#define SIZE 100

 int integers(int number){
    int index;

    if(number > 0){
        index = 2 * number;
        return index < SIZE ? index: -1;
    }
    index = (-2) * number + 1;
     return index < SIZE ? index: -1;
}

int evenNumber(int number){
    if(number % 2 != 0){
        return -1;
    }
    int index;

    if( number < 0 ){
        index = (-1) * number +1;
        return index < SIZE ? index: -1;

    }
    index = number;
    return index < SIZE ? index: -1;
}

int characters(char character){
    if(character < 97 || character> 122){
        return -1;
    }
    int index = (int)character - 97;

    return index < SIZE ? index: -1;
}

int characters_reversed(int index){
    int indexToReturn = index + 97;
    if(indexToReturn > 122 || indexToReturn < 97){
        return -1;
    }
    return indexToReturn < SIZE ? indexToReturn: -1;
}

int hash2Letters(const std::string& word) {
    if (word.length() != 2 || !isalpha(word[0]) || !isalpha(word[1])) {
        throw std::invalid_argument("Input must be exactly 2 alphabetic characters.");
    }
    char c1 = tolower(word[0]);
    char c2 = tolower(word[1]);
    int index = (c1 - 'a') * 26 + (c2 - 'a');
    return index;
}

std::string unhashIndex(int index) {
    if (index < 0 || index >= 26 * 26) {
        throw std::out_of_range("Index must be between 0 and 675.");
    }
    char first = 'a' + (index / 26);
    char second = 'a' + (index % 26);
    return std::string() + first + second;
}