#ifndef FILE_ACTIONS_HPP
#define FILE_ACTIONS_HPP

#include <string>

namespace FileActions {
	void CheckFile(const std::string& FileName);
	void ReadCSV(const std::string& FileName);

	void AddNewLine(const std::string& FileName, const std::string& NewLine);
	void UpdateLine(const std::string& FileName);
	void DeleteLine(const std::string& FileName);

	void NewRiskFactorInput(const std::string& FileName);
};

#endif // !FILE_ACTIONS_HPP
