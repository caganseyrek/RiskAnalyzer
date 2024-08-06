#include "file_actions.hpp"
#include "input_actions.hpp"

#include <iostream>

int main() {
	bool ExitInnerLoop = false;
	std::string FileName = "RiskFaktorleri.csv";
	FileActions::CheckFile(FileName);

	std::cout << "------------------------------------" << std::endl;
	std::cout << "Risk analizi programina hosgeldiniz." << std::endl;
	std::cout << "------------------------------------" << std::endl;
	while (true) {
		std::cout << "Secenekler:" << std::endl
				  << "   1 > Risk faktorlerini listele" << std::endl
				  << "   2 > Programdan cik" << std::endl;
		switch (InputActions::GetNumberInput<int>("\nSecenek: ")) {
		case 1:
			InputActions::ClearTerminal();
			while (true) {
				FileActions::ReadCSV(FileName);
				std::cout << "Secenekler:" << std::endl
						  << "   1 > Yeni satir ekle" << std::endl
						  << "   2 > Satir guncelle" << std::endl
						  << "   3 > Satir sil" << std::endl
						  << "   4 > Ana menuye don" << std::endl;
				switch (InputActions::GetNumberInput<int>("\nSecenek: ")) {
				case 1:
					FileActions::NewRiskFactorInput(FileName);
					break;
				case 2:
					FileActions::UpdateLine(FileName);
					break;
				case 3:
					FileActions::DeleteLine(FileName);
					break;
				case 4:
					InputActions::ClearTerminal();
					ExitInnerLoop = true;
					goto EndInnerLoop;
					break;
				default:
					InputActions::ClearTerminal();
					std::cout << "\033[31mYanlis bir secenek girdiniz." << std::endl;
					std::cout << "\033[0m" << std::endl;
					break;
				};
			EndInnerLoop:
				if (ExitInnerLoop) {
					break;
				};
			};
			break;
		case 2:
			exit(0);
		default:
			InputActions::ClearTerminal();
			std::cout << "\033[31mYanlis bir secenek girdiniz." << std::endl;
			std::cout << "\033[0m" << std::endl;
			break;
		};
	};
	return 0;
};