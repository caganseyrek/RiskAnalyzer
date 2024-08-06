#ifndef RISK_FACTOR_HPP
#define RISK_FACTOR_HPP

#include <string>

namespace RiskFaktoru {
	struct RiskFaktoruStruct {
		std::string RiskinIsmi;
		float RiskinGerceklesmeOlasiligi;
		float RiskinSikligi;
		float RiskinEtkisi;
		float RiskDegeri;
	};

	void DisplayAsTable(const int& LineNo, RiskFaktoruStruct RiskFaktoruToDisplay);
};

#endif // !RISK_FACTOR_HPP
