#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number_of_operations>" << std::endl;
        return 1;
    }

    int n = std::atoi(argv[1]);
    if (n <= 0 || n > 1000) {
        std::cerr << "Liczba operacji musi być w zakresie 1 do 1000." << std::endl;
        return 1;
    }
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    const char* actions[] = {"F", "B", "f", "b", "R", "S"};

    std::cout << n << std::endl; 
    
    for (int i = 0; i < n; ++i) {
        int action = std::rand() % 6;  
        if (action == 0 || action == 1) {
            int x = std::rand() % 1001;  
            std::cout << actions[action] << " " << x << std::endl;
        } 
        else if (action == 4) {
            int x = std::rand() % 1001;
            int y = std::rand() % 1001;
            std::cout << actions[action] << " " << x << " " << y << std::endl;
        }
        else {
            std::cout << actions[action] << std::endl;
        }
    }
    return 0;
}