#ifndef INPUT_ACTIONS_HPP
#define INPUT_ACTIONS_HPP

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include <string>
#include <limits>
#include <iostream>

namespace InputActions {
	void ClearTerminal();

	template <typename T>
	T GetNumberInput(const std::string& Prompt);

	template <typename T>
	T GetNumberInput(const std::string& Prompt, T Min, T Max);

	std::string GetStringInput(const std::string& Prompt);
};

template <typename T>
T InputActions::GetNumberInput(const std::string& Prompt) {
	T Number{};
	while (true) {
		std::cout << Prompt;
		if (std::cin >> Number) {
			break;
		};
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\033[31mLutfen gecerli bir sayi giriniz\n\033[0m" << std::endl;
	};
	return Number;
};

template <typename T>
T InputActions::GetNumberInput(const std::string& Prompt, T Min, T Max) {
	T Number{};
	while (true) {
		std::cout << Prompt;
		if (std::cin >> Number && Number >= Min && Number <= Max) {
			break;
		};
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\033[31mLutfen gecerli bir sayi giriniz\n\033[0m" << std::endl;
	};
	return Number;
};

#endif // !INPUT_ACTIONS_HPP
