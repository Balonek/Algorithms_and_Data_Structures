#include <iostream>
#include "ArrayList.hpp"

int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); 
    std::cout.tie(NULL);

    ArrayList list;
    char op;
    int n; 
    std::cin >> n;  
    while(n--) {
        std::cin >> op;
        if (op == 'F') { 
            int x;  
            std::cin >> x;
            list.push_front(x);
        } else if (op == 'B') { 
            int x;
            std::cin >> x;
            list.push_back(x);
        } else if (op == 'f') { 
            try {
                std::cout << list.pop_front() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "EMPTY" << std::endl; 
            }
        } else if (op == 'b') { 
            try {
                std::cout << list.pop_back() << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "EMPTY" << std::endl; 
            }
        } else if (op == 'R') {
            int x, y;
            std::cin >> x >> y;
            int index = list.find(x);
            if (index != -1) {  
                list.erase(index);  
                list.insert(index, y); 
                std::cout << "TRUE\n"; 
            } else {
                std::cout << "FALSE\n";  
            }
        } else if (op == 'S') { 
            std::cout << list.size() << std::endl;
        }
    }
    return 0;
}
