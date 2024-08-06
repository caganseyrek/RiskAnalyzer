#include "risk_factor.hpp"

#include <string>
#include <iostream>
#include <iomanip>

namespace RiskFaktoru {
	RiskFaktoruStruct RiskFaktoru;

	void DisplayAsTable(const int& LineNo, RiskFaktoruStruct RiskFaktoruToDisplay) {
		std::cout << std::setw(5)  << std::left << LineNo << "|"
				  << std::setw(30) << std::left << RiskFaktoruToDisplay.RiskinIsmi << "|"
				  << std::setw(30) << std::left << RiskFaktoruToDisplay.RiskinGerceklesmeOlasiligi << "|"
				  << std::setw(15) << std::left << RiskFaktoruToDisplay.RiskinSikligi << "|"
				  << std::setw(15) << std::left << RiskFaktoruToDisplay.RiskinEtkisi << "|"
				  << std::setw(15) << std::left << RiskFaktoruToDisplay.RiskDegeri << "|" << std::endl;
	};
};