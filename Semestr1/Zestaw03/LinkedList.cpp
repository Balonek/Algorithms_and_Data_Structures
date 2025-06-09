#include "LinkedList.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); 
    std::cout.tie(NULL);

    LinkedList<int> list;
    char op;
    int n;
    std::cin >> n;
    while(n--) {
        std::cin >> op;
        if (op == 'F') {
            int x;
            std::cin >> x;
            try {
                list.push_front(x);
            } catch (const std::out_of_range& e) {
                std::cerr << e.what() << "\n";
            }
        }
        else if (op == 'B') {
            int x;
            std::cin >> x;
            try {
                list.push_back(x);
            } catch (const std::out_of_range& e) {
                std::cerr << e.what() << "\n";
            }
        }
        else if (op == 'f') {
            try {
                std::cout << list.pop_front() << "\n";
            } catch (const std::out_of_range& e) {
                std::cout << "EMPTY" << "\n";
            }
        }
        else if (op == 'b') {
            try {
                std::cout << list.pop_back() << "\n";
            } catch (const std::out_of_range& e) {
                std::cout << "EMPTY" << "\n";
            }
        }
        else if (op == 'R') {
            int x, y;
            std::cin >> x >> y;
            if (list.replace(x, y)) {
                std::cout << "TRUE" << "\n";
            }
            else {
                std::cout << "FALSE" << "\n";
            }
        }
        else if (op == 'S') {
            std::cout << list.size() << "\n";
        }
    }
    return 0;
}