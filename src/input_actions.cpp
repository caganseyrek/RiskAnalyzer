#include "input_actions.hpp"

#include <iostream>
#include <limits>
#include <string>

namespace InputActions {
	void ClearTerminal() {
	#ifdef _WIN32
		std::system("CLS");
	#else
		std::system("clear");
	#endif
	};

	std::string GetStringInput(const std::string& Prompt) {
		std::string Input;
		while (true) {
			std::cout << Prompt;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (getline(std::cin, Input)) {
				break;
			};
			std::cin.clear();
			std::cout << "\033[31mLutfen gecerli bir deger giriniz\n\033[0m" << std::endl;
		};
		return Input;
	};
};