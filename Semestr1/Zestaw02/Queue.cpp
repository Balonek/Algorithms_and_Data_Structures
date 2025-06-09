#include <iostream>
#include <string>
#include <stdexcept>
#include "ArrayQueue.hpp"  

int main() {
    int n; 
    std::cin >> n;  
    if (n <= 0 || n > 1000000) { 
        std::cerr << "Niepoprawna liczba operacji" << std::endl;
        return 1;
    }
    Queue Queue(n); 
    std::string str;
    for (int i = 0; i < n; ++i) {
        std::cin >> str;  
        if (str == "A") {  
            int x;
            std::cin >> x; 
            Queue.push(x);  
        } 
        else if (str == "D") {  
            try {
                int poppedValue = Queue.pop();  
                std::cout << poppedValue << std::endl;  
            } 
            catch (const std::out_of_range& e) {
                std::cout << "EMPTY" << std::endl; 
            }
        } 
        else if (str == "S") {  
            std::cout << Queue.size() << std::endl;
        }
    }

    return 0;
}
