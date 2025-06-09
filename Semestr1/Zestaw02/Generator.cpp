#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number_of_operations>" << std::endl;
        return 1;
    }

    int n = std::atoi(argv[1]);
    if (n <= 0 || n > 1000000) {
        std::cerr << "Liczba operacji musi być w zakresie 1 do 1000000." << std::endl;
        return 1;
    }
    std::srand(static_cast<unsigned int>(std::time(nullptr))); 
    std::cout << n << std::endl;
    for (int i = 0; i < n; ++i) {
        int action = std::rand() % 3; 

        if (action == 0) {
            int x = std::rand() % 1000001;  
            std::cout << "A " << x << std::endl;
        } else if (action == 1) {
            std::cout << "D" << std::endl; 
        } else {
            std::cout << "S" << std::endl;  
        }
    }

    return 0;
}
