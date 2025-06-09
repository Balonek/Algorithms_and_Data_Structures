#include <iostream>
#include <random>

int main(int argc, char **argv) {
	if (argc != 3) {
		std::cerr << "Nie poprawna liczba arugmentów (wymagana liczba: 2)";
		return 1;
	}
	int n = std::stoi(argv[1]);
	int max = std::stoi(argv[2]);

	auto const seed = std::random_device{}();
	auto rng = std::mt19937{seed};
	auto distro = std::uniform_int_distribution(1, max); 

	while (n-- > 0) {
		std::cout << distro(rng) << '\n';
	}
}
