#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <vector>
#include "dictionarySimple.h"

using namespace std;
using namespace std::chrono;


constexpr int REPEATS = 100;
constexpr int N0 = 1;
constexpr int N1 = 500;

void log_result(ofstream& out, int n, const string& opName, double time) {
    out << n << "," << opName << "," << time << "\n";
}

string random_word(mt19937& gen) {
    static uniform_int_distribution<> lenDist(3, 8);
    static uniform_int_distribution<> charDist('a', 'z');

    int len = lenDist(gen);
    string s;
    s.reserve(len);
    for (int i = 0; i < len; ++i) {
        s.push_back(static_cast<char>(charDist(gen)));
    }
    return s;
}

void test_dict_operations() {
    mt19937 gen(123);   
    ofstream out("results_dict.csv");
    out << "n,operation,time_ns\n"; 

    // Testujemy n od N0 do N1-1
    for (int n = N0; n < N1; ++n) {
        double time_insert = 0.0;
        double time_remove = 0.0;
        double time_contains = 0.0;

        for (int r = 0; r < REPEATS; ++r) {
            dictionarySimple<string> dict;
            vector<string> words;
            words.reserve(n);

            for (int i = 0; i < n; ++i) {
                string w = random_word(gen);
                dict.insert(w);
                words.push_back(w);
            }

            string w_insert = random_word(gen);
            auto start = high_resolution_clock::now();
            dict.insert(w_insert);
            auto end = high_resolution_clock::now();
            time_insert += duration_cast<nanoseconds>(end - start).count();

            if (!words.empty()) {
                // Usuwamy słowo, które istnieje w słowniku
                // (wybieramy je np. bazując na indeksie r % words.size())
                string w_remove = words[r % words.size()];
                start = high_resolution_clock::now();
                dict.remove(w_remove);
                end = high_resolution_clock::now();
                time_remove += duration_cast<nanoseconds>(end - start).count();

                start = high_resolution_clock::now();
                dict.contains(w_remove);
                end = high_resolution_clock::now();
                time_contains += duration_cast<nanoseconds>(end - start).count();
            }
        }

        log_result(out, n, "insert_dict", time_insert / REPEATS);
        log_result(out, n, "remove_dict", time_remove / REPEATS);
        log_result(out, n, "contains_dict", time_contains / REPEATS);
    }

    out.close();
}

int main() {

    dictionarySimple<string> dict;
    dict.insert("Apple");
    dict.insert("Banana");
    dict.insert("Cherry");

    dict.display();
    cout << "Czy 'Apple' nalezy do zbioru: "
         << (dict.contains("Apple") ? "Tak" : "Nie") << endl;

    dict.remove("Apple");
    dict.display();
    cout << "Czy 'Apple' nalezy do zbioru: "
         << (dict.contains("Apple") ? "Tak" : "Nie") << endl;

    test_dict_operations();

    return 0;
}
