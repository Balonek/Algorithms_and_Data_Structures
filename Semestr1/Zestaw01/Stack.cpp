#include <iostream>
#include <string>
#include <stdexcept>
#include "ArrayStack.hpp"  

int main() {
    int n; 
    std::cin >> n;  
    if (n <= 0 || n > 1000000) { 
        std::cerr << "Niepoprawna liczba operacji" << std::endl;
        return 1;
    }

    ArrayStack stack; 
    std::string str;

    for (int i = 0; i < n; ++i) {
        std::cin >> str;  
        if (str == "A") {  
            int x;
            std::cin >> x; 
            stack.push(x);  
        } 
        else if (str == "D") {  
            try {
                int poppedValue = stack.pop();  
                std::cout << poppedValue << std::endl;  
            } 
            catch (const std::out_of_range& e) {
                std::cout << "EMPTY" << std::endl; 
            }
        } 
        else if (str == "S") {  
            std::cout << stack.size() << std::endl;
        }
    }

    return 0;
}
