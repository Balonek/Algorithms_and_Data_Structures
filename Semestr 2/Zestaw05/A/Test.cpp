#include <iostream>
#include <vector>
#include <algorithm>
#include "KnightTour.hpp"

int main() {
    int size;
    std::cout << "Podaj rozmiar szachownicy:";
    std::cin >> size;

    int start_x, start_y;
    std::cout << "Podaj pozycje poczatkowa skoczka (0-" << size-1 << "): " << std::endl;
    std::cout << "Wiersz: ";
    std::cin >> start_x;
    std::cout << "Kolumna: ";
    std::cin >> start_y;

    KnightTour tour(size);

    if (tour.solve(start_x, start_y)) {
        std::cout << "\nNumeracja pol oznacza kolejne ruchy skoczka:" << std::endl;
        tour.print_solution();
    } else {
        std::cout << "Nie znaleziono rozwiazania dla podanej pozycji startowej. Sproboj ponownie" << std::endl;
    }

    return 0;
}