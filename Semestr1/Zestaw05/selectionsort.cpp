#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

// selection_sort przez wybór
template <class T> 
void sort(std::vector<T>& v) {
    for (auto ptr = v.begin(); ptr != v.end();++ptr){
        std::swap(*ptr, *std::min_element(ptr, v.end()));
    }
}

int main() {

    std::vector<int> v(std::istream_iterator<int>(std::cin), std::istream_iterator<int>());
    sort(v);
    for(const auto& i : v){
        std::cout << i << std::endl;
    }

}
/*
    for (auto ptr = v.begin(); ptr != v.end(); ++ptr) {
        if ( *ptr == *std::min_element(ptr, v.end()) )
    }

*/