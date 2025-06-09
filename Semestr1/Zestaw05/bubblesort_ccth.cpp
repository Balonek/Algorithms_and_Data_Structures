#include <iostream>
#include <chrono>
#include <vector>
#include <iterator>
#include <algorithm>

// bubble_sort
template <class T> 
void sort(std::vector<T>& v) {
    size_t comparisons = 0;
    size_t swaps = 0;
    size_t iterations = 0;
    bool vector_sorted;
    for (size_t i = 0; i < v.size(); ++i){
        vector_sorted = true;
        for(size_t j = v.size() -1 ; j> i ; --j){
            comparisons++;
            if (v[j-1] > v[j]) {
                swaps++;
                std::swap(v[j-1],v[j]);
                vector_sorted = false;
            }
        iterations++;    
    }
    if (vector_sorted)
        break;
    }
    std::clog << "Comparisons: " << comparisons << std::endl;
    std::clog << "Swaps: " << swaps << std::endl;
    std::clog << "Total iterations: " << iterations << std::endl;
};

int main() {

    std::vector<int> v(std::istream_iterator<int>(std::cin), std::istream_iterator<int>());

    auto start = std::chrono::high_resolution_clock::now();
    sort(v);
    auto end = std::chrono::high_resolution_clock::now();
    for(const auto& i : v){
        std::cout << i << std::endl;
    }
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;

    std::cout << "\nWyniki dla posortowanego vectora tych samych danych wejsciowych:\n";
    auto start1 = std::chrono::high_resolution_clock::now();
    sort(v);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = end1 - start1;
    std::cerr << "Elapsed time[s] = " << elapsed1.count() << std::endl;
    }
