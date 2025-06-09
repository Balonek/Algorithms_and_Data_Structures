#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

    template <class T> 
    void sort(std::vector<T>& v) {
        for (size_t i = 0; i < v.size() - 1; ++i){
            for (size_t j = v.size() -1 ; j > i ; --j){
                if (v[j-1] > v[j]) {
                    std::swap(v[j-1],v[j]);
                }
        }
    }
    };

    int main() {
        std::vector<int> v(std::istream_iterator<int>(std::cin), std::istream_iterator<int>());
        sort(v);
        for(const auto& i : v){
            std::cout << i << std::endl;
        }
    }

