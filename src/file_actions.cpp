#include "file_actions.hpp"
#include "risk_factor.hpp"
#include "input_actions.hpp"
#include "display_tables.hpp"

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

int CSVLineCount = 0;

namespace FileActions {
	void CheckFile(const std::string& FileName) {
		std::ifstream File(FileName);
		if (!File.good()) {
			std::ofstream NewFile(FileName);
			if (NewFile.is_open()) {
				std::string FileHeaders = "RiskinIsmi,RiskinGerceklesmeOlasiligi,RiskinSikligi,RiskinEtkisi,RiskDegeri";
				NewFile << FileHeaders;
				return;
			}
			else {
				std::cerr << "\033[31mKayit dosyasi olusturulamadi.\033[0m" << std::endl;
				return;
			};
		};
		return;
	};

	void ReadCSV(const std::string& FileName) {
		std::ifstream File;
		File.open(FileName);
		if (!File.is_open()) {
			std::cerr << "\033[31mDosya acilamadi\033[0m" << std::endl;
			return;
		};
		std::cout << std::endl;
		std::cout << std::setw(5)  << std::left << "No" << "|"
				  << std::setw(30) << std::left << "Riskin Ismi" << "|"
				  << std::setw(30) << std::left << "Riskin Gerceklesme Olasiligi" << "|"
				  << std::setw(15) << std::left << "Riskin Sikligi" << "|"
				  << std::setw(15) << std::left << "Riskin Etkisi" << "|"
				  << std::setw(15) << std::left << "Riskin Degeri" << "|" << std::endl;
		std::cout << std::setw(5)  << std::left << "-----" << "+"
				  << std::setw(30) << std::left << "------------------------------" << "+"
				  << std::setw(30) << std::left << "------------------------------" << "+"
				  << std::setw(15) << std::left << "---------------" << "+"
				  << std::setw(15) << std::left << "---------------" << "+"
				  << std::setw(15) << std::left << "---------------" << "+" << std::endl;

		std::string Line = "";
		std::getline(File, Line);
		Line = "";
		std::vector<RiskFaktoru::RiskFaktoruStruct> OkunanRiskFaktorleri;

		while (getline(File, Line)) {
			RiskFaktoru::RiskFaktoruStruct OkunanRiskFaktoru;
			std::string TempString;
			std::stringstream InputString(Line);

			std::getline(InputString, OkunanRiskFaktoru.RiskinIsmi, ',');
			std::getline(InputString, TempString, ',');
			OkunanRiskFaktoru.RiskinGerceklesmeOlasiligi = std::stof(TempString.c_str());
			std::getline(InputString, TempString, ',');
			OkunanRiskFaktoru.RiskinSikligi = std::stof(TempString.c_str());
			std::getline(InputString, TempString, ',');
			OkunanRiskFaktoru.RiskinEtkisi = std::stof(TempString.c_str());
			std::getline(InputString, TempString, ',');
			OkunanRiskFaktoru.RiskDegeri = std::stof(TempString.c_str());
			OkunanRiskFaktorleri.push_back(OkunanRiskFaktoru);
			Line = "";
		};

		int LineNo = 1;
		for (auto& OkunanRiskFaktoru : OkunanRiskFaktorleri) {
			RiskFaktoru::DisplayAsTable(LineNo, OkunanRiskFaktoru);
			LineNo++;
		};
		CSVLineCount = LineNo;
		std::cout << std::endl;
		File.close();
	};

	void AddNewLine(const std::string& FileName, const std::string& NewLine) {
		std::ofstream File;
		File.open(FileName, std::ofstream::app);
		if (!File.is_open()) {
			std::cerr << "\033[31mDosya acilamadi\033[0m" << std::endl;
			return;
		};
		File << "\n" << NewLine;
		File.close();
		return;
	};

	void UpdateLine(const std::string& FileName) {
		int LineToBeEdited = InputActions::GetNumberInput<int>("Guncellemek istediginiz satir numarasini giriniz: ", 1, CSVLineCount);
		std::ifstream FileRead;
		FileRead.open(FileName);
		if (!FileRead.is_open()) {
			std::cerr << "\033[31mDosya acilamadi\033[0m" << std::endl;
			return;
		};

		std::string Line = "";
		std::getline(FileRead, Line);
		std::string FileHeaders = Line;
		RiskFaktoru::RiskFaktoruStruct GuncellenecekRiskFaktoru;
		std::vector<std::string> OncekiSatirlar;
		std::vector<std::string> SonrakiSatirlar;

		int LineCount = 1;
		while (getline(FileRead, Line)) {
			if (LineCount < LineToBeEdited) {
				OncekiSatirlar.push_back(Line);
			};
			if (LineCount > LineToBeEdited) {
				SonrakiSatirlar.push_back(Line);
			};
			if (LineCount == LineToBeEdited) {
				std::string TempString;
				std::stringstream InputString(Line);
				std::getline(InputString, GuncellenecekRiskFaktoru.RiskinIsmi, ',');
				std::getline(InputString, TempString, ',');
				GuncellenecekRiskFaktoru.RiskinGerceklesmeOlasiligi = std::stof(TempString.c_str());
				std::getline(InputString, TempString, ',');
				GuncellenecekRiskFaktoru.RiskinSikligi = std::stof(TempString.c_str());
				std::getline(InputString, TempString, ',');
				GuncellenecekRiskFaktoru.RiskinEtkisi = std::stof(TempString.c_str());
				std::getline(InputString, TempString, ',');
				GuncellenecekRiskFaktoru.RiskDegeri = std::stof(TempString.c_str());
			};
			LineCount++;
		};
		FileRead.close();
		RiskFaktoru::RiskFaktoruStruct GuncellenmisRiskFaktoru;

		InputActions::ClearTerminal();
		std::cout << "Mevcut deger: " << GuncellenecekRiskFaktoru.RiskinIsmi << std::endl;
		GuncellenmisRiskFaktoru.RiskinIsmi = InputActions::GetStringInput("Risk faktorunun yeni ismi: ");
		InputActions::ClearTerminal();

		DisplayTables::PossibilityTable();
		std::cout << "Mevcut deger: " << GuncellenecekRiskFaktoru.RiskinGerceklesmeOlasiligi << std::endl;
		GuncellenmisRiskFaktoru.RiskinGerceklesmeOlasiligi = InputActions::GetNumberInput<float>("Riskin yeni gerceklesme olasiligi: ", 0.1, 10);
		InputActions::ClearTerminal();

		DisplayTables::FrequencyTable();
		std::cout << "Mevcut deger: " << GuncellenecekRiskFaktoru.RiskinSikligi << std::endl;
		GuncellenmisRiskFaktoru.RiskinSikligi = InputActions::GetNumberInput<float>("Riskin yeni sikligi: ", 0.5, 10);
		InputActions::ClearTerminal();

		DisplayTables::EffectTable();
		std::cout << "Mevcut deger: " << GuncellenecekRiskFaktoru.RiskinEtkisi << std::endl;
		GuncellenmisRiskFaktoru.RiskinEtkisi = InputActions::GetNumberInput<float>("Riskin yeni etkisi: ", 1, 100);
		InputActions::ClearTerminal();

		float RiskDegeri = GuncellenmisRiskFaktoru.RiskinGerceklesmeOlasiligi * GuncellenmisRiskFaktoru.RiskinSikligi * GuncellenmisRiskFaktoru.RiskinEtkisi;
		GuncellenmisRiskFaktoru.RiskDegeri = RiskDegeri;

		std::ofstream FileReset;
		FileReset.open(FileName);
		if (!FileReset.is_open()) {
			std::cerr << "\033[31mDosya acilamadi\033[0m" << std::endl;
			return;
		};
		FileReset << FileHeaders;
		FileReset.close();

		std::ofstream FileOverwrite;
		FileOverwrite.open(FileName, std::ofstream::app);
		if (!FileOverwrite.is_open()) {
			std::cerr << "\033[31mDosya acilamadi\033[0m" << std::endl;
			return;
		};

		std::stringstream StringStream;
		StringStream << GuncellenmisRiskFaktoru.RiskinIsmi << ","
					 << std::to_string(GuncellenmisRiskFaktoru.RiskinGerceklesmeOlasiligi) << ","
					 << std::to_string(GuncellenmisRiskFaktoru.RiskinSikligi) << ","
					 << std::to_string(GuncellenmisRiskFaktoru.RiskinEtkisi) << ","
					 << std::to_string(GuncellenmisRiskFaktoru.RiskDegeri);
		std::string NewValues = StringStream.str();
		for (auto& MevcutSatir : OncekiSatirlar) { FileOverwrite << "\n" << MevcutSatir; };
		FileOverwrite << "\n" << NewValues;
		for (auto& MevcutSatir : SonrakiSatirlar) { FileOverwrite << "\n" << MevcutSatir; };
		InputActions::ClearTerminal();

		std::cout << "\033[1;32m" << LineToBeEdited << " numarali satir guncellendi.\033[0m" << std::endl;
		std::cout << "Yeni risk degeri " << GuncellenmisRiskFaktoru.RiskDegeri << " olarak hesaplandi." << std::endl;
		return;
	};

	void DeleteLine(const std::string& FileName) {
		int LineToBeDeleted = InputActions::GetNumberInput<int>("Silmek istediginiz satir numarasini giriniz: ", 1, CSVLineCount);
		std::ifstream FileRead;
		FileRead.open(FileName);
		if (!FileRead.is_open()) {
			std::cerr << "\033[31mDosya acilamadi\033[0m" << std::endl;
			return;
		};

		std::string Line = "";
		std::getline(FileRead, Line);
		std::string FileHeaders = Line;
		std::vector<std::string> OncekiSatirlar;
		std::vector<std::string> SonrakiSatirlar;

		int LineCount = 1;
		while (getline(FileRead, Line)) {
			if (LineCount < LineToBeDeleted) { OncekiSatirlar.push_back(Line); };
			if (LineCount > LineToBeDeleted) { SonrakiSatirlar.push_back(Line); };
			LineCount++;
		};
		FileRead.close();

		std::ofstream FileReset;
		FileReset.open(FileName);
		if (!FileReset.is_open()) {
			std::cerr << "\033[31mDosya acilamadi\033[0m" << std::endl;
			return;
		};
		FileReset << FileHeaders;
		FileReset.close();

		std::ofstream FileOverwrite;
		FileOverwrite.open(FileName, std::ofstream::app);
		if (!FileOverwrite.is_open()) {
			std::cerr << "\033[31mDosya acilamadi\033[0m" << std::endl;
			return;
		};

		for (auto& MevcutSatir : OncekiSatirlar) {
			FileOverwrite << "\n" << MevcutSatir;
		};
		for (auto& MevcutSatir : SonrakiSatirlar) {
			FileOverwrite << "\n" << MevcutSatir;
		};
		InputActions::ClearTerminal();

		std::cout << "\033[1;32m" << LineToBeDeleted << " numarali satir silindi.\033[0m\n" << std::endl;
		return;
	};

	void NewRiskFactorInput(const std::string& FileName) {
		RiskFaktoru::RiskFaktoruStruct YeniRiskFaktoru;
		InputActions::ClearTerminal();
		YeniRiskFaktoru.RiskinIsmi = InputActions::GetStringInput("Risk faktorunun ismi: ");
		InputActions::ClearTerminal();

		DisplayTables::PossibilityTable();
		YeniRiskFaktoru.RiskinGerceklesmeOlasiligi = InputActions::GetNumberInput<float>("Riskin gerceklesme olasiligi: ", 0.1, 10);
		InputActions::ClearTerminal();

		DisplayTables::FrequencyTable();
		YeniRiskFaktoru.RiskinSikligi = InputActions::GetNumberInput<float>("Riskin sikligi: ", 0.5, 10);
		InputActions::ClearTerminal();

		DisplayTables::EffectTable();
		YeniRiskFaktoru.RiskinEtkisi = InputActions::GetNumberInput<float>("Riskin etkisi: ", 1, 100);
		InputActions::ClearTerminal();

		float RiskDegeri = YeniRiskFaktoru.RiskinGerceklesmeOlasiligi * YeniRiskFaktoru.RiskinSikligi * YeniRiskFaktoru.RiskinEtkisi;
		YeniRiskFaktoru.RiskDegeri = RiskDegeri;
		DisplayTables::ClassificationTable();
		std::cout << "\033[1;32m\"" << YeniRiskFaktoru.RiskinIsmi << "\"" << " isimli risk faktoru"
				  	  << " (Olasilik:" << YeniRiskFaktoru.RiskinGerceklesmeOlasiligi
				  	  << " - Etki:" << YeniRiskFaktoru.RiskinSikligi
				  	  << " - Etki:" << YeniRiskFaktoru.RiskinEtkisi
				  	  << ") kaydedildi.\033[0m" << std::endl;
		std::cout << "Bu faktorun risk degeri " << YeniRiskFaktoru.RiskDegeri << " olarak hesaplandi.\n" << std::endl;
		std::cout << "--------------------------------------------------------------------------------------------------------------------";

		std::stringstream StringStream;
		StringStream << YeniRiskFaktoru.RiskinIsmi << ","
					 			 << std::to_string(YeniRiskFaktoru.RiskinGerceklesmeOlasiligi) << ","
					 			 << std::to_string(YeniRiskFaktoru.RiskinSikligi) << ","
					 			 << std::to_string(YeniRiskFaktoru.RiskinEtkisi) << ","
					 			 << std::to_string(YeniRiskFaktoru.RiskDegeri);
		std::string NewValues = StringStream.str();
		AddNewLine(FileName, NewValues);
		return;
	};
};
