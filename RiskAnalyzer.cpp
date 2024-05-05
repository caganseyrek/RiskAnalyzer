#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;
int CSVLineCount = 0;
struct RiskFaktoru {
public:
	string RiskinIsmi = "";
	float RiskinGerceklesmeOlasiligi = 0.0f;
	float RiskinSikligi = 0.0f;
	float RiskinEtkisi = 0.0f;
	float RiskDegeri = 0.0f;
	void DisplayAsTable(const int& LineNo ) {
		cout << setw(5)  << left << LineNo << "|"
			 << setw(30) << left << RiskinIsmi << "|"
			 << setw(30) << left << RiskinGerceklesmeOlasiligi << "|"
			 << setw(15) << left << RiskinSikligi << "|"
			 << setw(15) << left << RiskinEtkisi << "|"
			 << setw(15) << left << RiskDegeri << "|" << endl;
	};
};
namespace DisplayTables {
	void PossibilityTable() {
		cout << setw(30) << left << "Riskin Olasiligi" << "|" << setw(10) << left << "Puan" << endl;
		cout << setw(30) << left << "------------------------------" << "+" << setw(13) << "----------" << endl;
		cout << setw(30) << left << "Neredeyse imkansiz" << "|" << setw(10) << left << "0.1" << endl;
		cout << setw(30) << left << "Pratik olarak imkansiz" << "|" << setw(10) << left << "0.2" << endl;
		cout << setw(30) << left << "Mumkun ancak beklenmeyen" << "|" << setw(10) << left << "0.5" << endl;
		cout << setw(30) << left << "Mumkun ancak dusuk ihtimal" << "|" << setw(10) << left << "1" << endl;
		cout << setw(30) << left << "Mumkun" << "|" << setw(10) << left << "3" << endl;
		cout << setw(30) << left << "Oldukca mumkun" << "|" << setw(10) << left << "6" << endl;
		cout << setw(30) << left << "Kesin, beklenir" << "|" << setw(10) << left << "10" << endl;
		cout << endl;
	};
	void FrequencyTable() {
		cout << setw(40) << left << "Riskin Sikligi" << "|" << setw(10) << left << "Puan" << endl;
		cout << setw(40) << left << "----------------------------------------" << "+" << setw(13) << "----------" << endl;
		cout << setw(40) << left << "Cok Seyrek (Yilda bir veya daha az)" << "|" << setw(10) << left << "0.5" << endl;
		cout << setw(40) << left << "Seyrek (Yilda birkac defa)" << "|" << setw(10) << left << "1" << endl;
		cout << setw(40) << left << "Nadiren (Ayda bir veya birkac defa)" << "|" << setw(10) << left << "2" << endl;
		cout << setw(40) << left << "Ara Sira (Haftada bir veya birkac defa)" << "|" << setw(10) << left << "3" << endl;
		cout << setw(40) << left << "Sik (Gunde bir veya birkac defa)" << "|" << setw(10) << left << "6" << endl;
		cout << setw(40) << left << "Surekli (Saate birkac defa)" << "|" << setw(10) << left << "10" << endl;
		cout << endl;
	};
	void EffectTable() {
		cout << endl;
		cout << setw(70) << left << "Riskin Etkisi" << "|" << setw(10) << left << "Puan" << endl;
		cout << setw(70) << left << "---------------------------------------------------------------------" << "+" << setw(13) << "----------" << endl;
		cout << setw(70) << left << "Ramak Kala (Cevresel zarar yok)" << "|" << setw(10) << left << "1" << endl;
		cout << setw(70) << left << "Kucuk Hasar, Yaralanma, Ilkyardim (Sinirli cevresel etki)" << "|" << setw(10) << left << "3" << endl;
		cout << setw(70) << left << "Onemli Hasar, Yaralanma, Tibbi Tedavi (Genis cevresel etki) " << "|" << setw(10) << left << "7" << endl;
		cout << setw(70) << left << "Kalici Hasar, Sakatlik, Uzun Sureli Tedavi (Onemli Cevresel Etki)" << "|" << setw(10) << left << "15" << endl;
		cout << setw(70) << left << "Olum (Ciddi cevresel etki)" << "|" << setw(10) << left << "40" << endl;
		cout << setw(70) << left << "Birden Fazla Olum (Cevresel felaket)" << "|" << setw(10) << left << "100" << endl;
		cout << endl;
	};
	void ClassificationTable() {
		cout << setw(25) << left << "Risk Degeri" << "|" << setw(70) << left << "Risk Siniflandirmasi" << endl;
		cout << setw(25) << left << "------------------------" << "+" << setw(91) << left << "------------------------------------------------------------------------------------------" << endl;
		cout << setw(25) << left << "20'den az (...-20]" << "|" << setw(70) << left << "Onemsiz risk - Kabul edilebilir" << endl;
		cout << setw(25) << left << "20-70 arasi (20-70]" << "|" << setw(70) << left << "Olasi risk - Gozetim altinda tutulmalidir" << endl;
		cout << setw(25) << left << "70-200 arasi (70-200]" << "|" << setw(70) << left << "Onemli risk - Uzun donemde iyilestirilmelidir" << endl;
		cout << setw(25) << left << "200-400 arasi (200-400]" << "|" << setw(70) << left << "Ciddi risk - Kisa surede iyilestirilmelidir" << endl;
		cout << setw(25) << left << "400'den fazla (400-..]" << "|" << setw(70) << left << "Kabul edilemez risk - Iyilesene kadar ise ara verilmelidir" << endl;
		cout << endl;
	};
};
namespace IOActions {
	void ClearTerminal() { system("CLS"); };
	template <typename T>
	T GetNumberInput(const string& Prompt) {
		T Number{};
		while (true) {
			cout << Prompt;
			if (cin >> Number) { break; };
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\033[31mLutfen gecerli bir sayi giriniz\n\033[0m" << endl;
		};
		return Number;
	};
	template <typename T>
	T GetNumberInput(const string& Prompt, T Min, T Max) {
		T Number{};
		while (true) {
			cout << Prompt;
			if (cin >> Number && Number >= Min && Number <= Max) { break; };
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\033[31mLutfen gecerli bir sayi giriniz\n\033[0m" << endl;
		};
		return Number;
	};
	string GetStringInput(const string& Prompt) {
		string Input;
		while (true) {
			cout << Prompt;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (getline(cin, Input)) { break; };
			cin.clear();
			cout << "\033[31mLutfen gecerli bir deger giriniz\n\033[0m" << endl;
		};
		return Input;
	};
};
namespace RiskAnalyzer {
	void CheckFile(const string& FileName) {
		ifstream File(FileName);
		if (!File.good()) {
			ofstream NewFile(FileName);
			if (NewFile.is_open()) {
				string FileHeaders = "RiskinIsmi,RiskinGerceklesmeOlasiligi,RiskinSikligi,RiskinEtkisi,RiskDegeri";
				NewFile << FileHeaders;
				return;
			} else {
				cerr << "\033[31mKayit dosyasi olusturulamadi.\033[0m" << endl;
				return;
			};
		};
		return;
	};
	void ReadCSV(const string& FileName) {
		ifstream File;
		File.open(FileName);
		if (!File.is_open()) {
			cerr << "\033[31mDosya acilamadi\033[0m" << endl;
			return;
		};
		cout << endl;
		cout << setw(5) << left << "No" << "|"
			<< setw(30) << left << "Riskin Ismi" << "|"
			<< setw(30) << left << "Riskin Gerceklesme Olasiligi" << "|"
			<< setw(15) << left << "Riskin Sikligi" << "|"
			<< setw(15) << left << "Riskin Etkisi" << "|"
			<< setw(15) << left << "Riskin Degeri" << "|" << endl;
		cout << setw(5) << left << "-----" << "+"
			<< setw(30) << left << "------------------------------" << "+"
			<< setw(30) << left << "------------------------------" << "+"
			<< setw(15) << left << "---------------" << "+"
			<< setw(15) << left << "---------------" << "+"
			<< setw(15) << left << "---------------" << "+" << endl;
		string Line = "";
		getline(File, Line);
		Line = "";
		vector<RiskFaktoru> OkunanRiskFaktorleri;
		while (getline(File, Line)) {
			RiskFaktoru OkunanRiskFaktoru;
			string TempString;
			stringstream InputString(Line);
			getline(InputString, OkunanRiskFaktoru.RiskinIsmi, ',');
			getline(InputString, TempString, ',');
			OkunanRiskFaktoru.RiskinGerceklesmeOlasiligi = stof(TempString.c_str());
			getline(InputString, TempString, ',');
			OkunanRiskFaktoru.RiskinSikligi = stof(TempString.c_str());
			getline(InputString, TempString, ',');
			OkunanRiskFaktoru.RiskinEtkisi = stof(TempString.c_str());
			getline(InputString, TempString, ',');
			OkunanRiskFaktoru.RiskDegeri = stof(TempString.c_str());
			OkunanRiskFaktorleri.push_back(OkunanRiskFaktoru);
			Line = "";
		};
		int LineNo = 1;
		for (auto& OkunanRiskFaktoru : OkunanRiskFaktorleri) {
			OkunanRiskFaktoru.DisplayAsTable(LineNo);
			LineNo++;
		};
		CSVLineCount = LineNo;
		cout << endl;
		File.close();
	};
	void AddNewLine(const string& FileName, const string& NewLine) {
		ofstream File;
		File.open(FileName, ofstream::app);
		if (!File.is_open()) {
			cerr << "\033[31mDosya acilamadi\033[0m" << endl;
			return;
		};
		File << "\n" << NewLine;
		File.close();
		return;
	};
	void UpdateLine(const string& FileName) {
		int LineToBeEdited = IOActions::GetNumberInput<int>("Guncellemek istediginiz satir numarasini giriniz: ", 1, CSVLineCount);
		ifstream FileRead;
		FileRead.open(FileName);
		if (!FileRead.is_open()) {
			cerr << "\033[31mDosya acilamadi\033[0m" << endl;
			return;
		};
		string Line = "";
		getline(FileRead, Line);
		string FileHeaders = Line;
		RiskFaktoru GuncellenecekRiskFaktoru;
		vector<string> OncekiSatirlar;
		vector<string> SonrakiSatirlar;
		int LineCount = 1;
		while (getline(FileRead, Line)) {
			if (LineCount < LineToBeEdited) { OncekiSatirlar.push_back(Line); };
			if (LineCount > LineToBeEdited) { SonrakiSatirlar.push_back(Line); };
			if (LineCount == LineToBeEdited) {
				string TempString;
				stringstream InputString(Line);
				getline(InputString, GuncellenecekRiskFaktoru.RiskinIsmi, ',');
				getline(InputString, TempString, ',');
				GuncellenecekRiskFaktoru.RiskinGerceklesmeOlasiligi = stof(TempString.c_str());
				getline(InputString, TempString, ',');
				GuncellenecekRiskFaktoru.RiskinSikligi = stof(TempString.c_str());
				getline(InputString, TempString, ',');
				GuncellenecekRiskFaktoru.RiskinEtkisi = stof(TempString.c_str());
				getline(InputString, TempString, ',');
				GuncellenecekRiskFaktoru.RiskDegeri = stof(TempString.c_str());
			};
			LineCount++;
		};
		FileRead.close();
		RiskFaktoru GuncellenmisRiskFaktoru;
		IOActions::ClearTerminal();
		cout << "Mevcut deger: " << GuncellenecekRiskFaktoru.RiskinIsmi << endl;
		GuncellenmisRiskFaktoru.RiskinIsmi = IOActions::GetStringInput("Risk faktorunun yeni ismi: ");
		IOActions::ClearTerminal();
		DisplayTables::PossibilityTable();
		cout << "Mevcut deger: " << GuncellenecekRiskFaktoru.RiskinGerceklesmeOlasiligi << endl;
		GuncellenmisRiskFaktoru.RiskinGerceklesmeOlasiligi = IOActions::GetNumberInput<float>("Riskin yeni gerceklesme olasiligi: ", 0.1, 10);
		IOActions::ClearTerminal();
		DisplayTables::FrequencyTable();
		cout << "Mevcut deger: " << GuncellenecekRiskFaktoru.RiskinSikligi << endl;
		GuncellenmisRiskFaktoru.RiskinSikligi = IOActions::GetNumberInput<float>("Riskin yeni sikligi: ", 0.5, 10);
		IOActions::ClearTerminal();
		DisplayTables::EffectTable();
		cout << "Mevcut deger: " << GuncellenecekRiskFaktoru.RiskinEtkisi << endl;
		GuncellenmisRiskFaktoru.RiskinEtkisi = IOActions::GetNumberInput<float>("Riskin yeni etkisi: ", 1, 100);
		IOActions::ClearTerminal();
		float RiskDegeri = GuncellenmisRiskFaktoru.RiskinGerceklesmeOlasiligi * GuncellenmisRiskFaktoru.RiskinSikligi * GuncellenmisRiskFaktoru.RiskinEtkisi;
		GuncellenmisRiskFaktoru.RiskDegeri = RiskDegeri;
		ofstream FileReset;
		FileReset.open(FileName);
		if (!FileReset.is_open()) {
			cerr << "\033[31mDosya acilamadi\033[0m" << endl;
			return;
		};
		FileReset << FileHeaders;
		FileReset.close();
		ofstream FileOverwrite;
		FileOverwrite.open(FileName, ofstream::app);
		if (!FileOverwrite.is_open()) {
			cerr << "\033[31mDosya acilamadi\033[0m" << endl;
			return;
		};
		stringstream StringStream;
		StringStream << GuncellenmisRiskFaktoru.RiskinIsmi << ","
			<< to_string(GuncellenmisRiskFaktoru.RiskinGerceklesmeOlasiligi) << ","
			<< to_string(GuncellenmisRiskFaktoru.RiskinSikligi) << ","
			<< to_string(GuncellenmisRiskFaktoru.RiskinEtkisi) << ","
			<< to_string(GuncellenmisRiskFaktoru.RiskDegeri);
		string NewValues = StringStream.str();
		for (auto& MevcutSatir : OncekiSatirlar) { FileOverwrite << "\n" << MevcutSatir; };
		FileOverwrite << "\n" << NewValues;
		for (auto& MevcutSatir : SonrakiSatirlar) { FileOverwrite << "\n" << MevcutSatir; };
		IOActions::ClearTerminal();
		cout << "\033[1;32m" << LineToBeEdited << " numarali satir guncellendi.\033[0m" << endl;
		cout << "Yeni risk degeri " << GuncellenmisRiskFaktoru.RiskDegeri << " olarak hesaplandi." << endl;
		return;
	};
	void DeleteLine(const string& FileName) {
		int LineToBeDeleted = IOActions::GetNumberInput<int>("Silmek istediginiz satir numarasini giriniz: ", 1, CSVLineCount);
		ifstream FileRead;
		FileRead.open(FileName);
		if (!FileRead.is_open()) {
			cerr << "\033[31mDosya acilamadi\033[0m" << endl;
			return;
		};
		string Line = "";
		getline(FileRead, Line);
		string FileHeaders = Line;
		vector<string> OncekiSatirlar;
		vector<string> SonrakiSatirlar;
		int LineCount = 1;
		while (getline(FileRead, Line)) {
			if (LineCount < LineToBeDeleted) { OncekiSatirlar.push_back(Line); };
			if (LineCount > LineToBeDeleted) { SonrakiSatirlar.push_back(Line); };
			LineCount++;
		};
		FileRead.close();
		ofstream FileReset;
		FileReset.open(FileName);
		if (!FileReset.is_open()) {
			cerr << "\033[31mDosya acilamadi\033[0m" << endl;
			return;
		};
		FileReset << FileHeaders;
		FileReset.close();
		ofstream FileOverwrite;
		FileOverwrite.open(FileName, ofstream::app);
		if (!FileOverwrite.is_open()) {
			cerr << "\033[31mDosya acilamadi\033[0m" << endl;
			return;
		};
		for (auto& MevcutSatir : OncekiSatirlar) { FileOverwrite << "\n" << MevcutSatir; };
		for (auto& MevcutSatir : SonrakiSatirlar) { FileOverwrite << "\n" << MevcutSatir; };
		IOActions::ClearTerminal();
		cout << "\033[1;32m" << LineToBeDeleted << " numarali satir silindi.\033[0m\n" << endl;
		return;
	};
	void NewRiskFactorInput(const string& FileName) {
		RiskFaktoru YeniRiskFaktoru;
		IOActions::ClearTerminal();
		YeniRiskFaktoru.RiskinIsmi = IOActions::GetStringInput("Risk faktorunun ismi: ");
		IOActions::ClearTerminal();
		DisplayTables::PossibilityTable();
		YeniRiskFaktoru.RiskinGerceklesmeOlasiligi = IOActions::GetNumberInput<float>("Riskin gerceklesme olasiligi: ", 0.1, 10);
		IOActions::ClearTerminal();
		DisplayTables::FrequencyTable();
		YeniRiskFaktoru.RiskinSikligi = IOActions::GetNumberInput<float>("Riskin sikligi: ", 0.5, 10);
		IOActions::ClearTerminal();
		DisplayTables::EffectTable();
		YeniRiskFaktoru.RiskinEtkisi = IOActions::GetNumberInput<float>("Riskin etkisi: ", 1, 100);
		IOActions::ClearTerminal();
		float RiskDegeri = YeniRiskFaktoru.RiskinGerceklesmeOlasiligi * YeniRiskFaktoru.RiskinSikligi * YeniRiskFaktoru.RiskinEtkisi;
		YeniRiskFaktoru.RiskDegeri = RiskDegeri;
		DisplayTables::ClassificationTable();
		cout << "\033[1;32m\"" << YeniRiskFaktoru.RiskinIsmi << "\"" << " isimli risk faktoru"
			<< " (Olasilik:" << YeniRiskFaktoru.RiskinGerceklesmeOlasiligi
			<< " - Etki:" << YeniRiskFaktoru.RiskinSikligi
			<< " - Etki:" << YeniRiskFaktoru.RiskinEtkisi
			<< ") kaydedildi.\033[0m" << endl;
		cout << "Bu faktorun risk degeri " << YeniRiskFaktoru.RiskDegeri << " olarak hesaplandi.\n" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------";
		stringstream StringStream;
		StringStream << YeniRiskFaktoru.RiskinIsmi << ","
			<< to_string(YeniRiskFaktoru.RiskinGerceklesmeOlasiligi) << ","
			<< to_string(YeniRiskFaktoru.RiskinSikligi) << ","
			<< to_string(YeniRiskFaktoru.RiskinEtkisi) << ","
			<< to_string(YeniRiskFaktoru.RiskDegeri);
		string NewValues = StringStream.str();
		AddNewLine(FileName, NewValues);
		return;
	};
};
int main() {
	bool ExitInnerLoop = false;
	string FileName = "RiskFaktorleri.csv";
	RiskAnalyzer::CheckFile(FileName);
	cout << "------------------------------------" << endl;
	cout << "Risk analizi programina hosgeldiniz." << endl;
	cout << "------------------------------------" << endl;
	while (true) {
		cout << "Secenekler:" << endl <<
			"   1 > Risk faktorlerini listele" << endl <<
			"   2 > Programdan cik" << endl;
		switch (IOActions::GetNumberInput<int>("\nSecenek: ")) {
		case 1:
			IOActions::ClearTerminal();
			while (true) {
				RiskAnalyzer::ReadCSV(FileName);
				cout << "Secenekler:" << endl
					<< "   1 > Yeni satir ekle" << endl
					<< "   2 > Satir guncelle" << endl
					<< "   3 > Satir sil" << endl
					<< "   4 > Ana menuye don" << endl;
				switch (IOActions::GetNumberInput<int>("\nSecenek: ")) {
				case 1:
					RiskAnalyzer::NewRiskFactorInput(FileName);
					break;
				case 2:
					RiskAnalyzer::UpdateLine(FileName);
					break;
				case 3:
					RiskAnalyzer::DeleteLine(FileName);
					break;
				case 4:
					IOActions::ClearTerminal();
					ExitInnerLoop = true;
					goto EndInnerLoop;
					break;
				default:
					IOActions::ClearTerminal();
					cout << "\033[31mYanlis bir secenek girdiniz." << endl;
					cout << "\033[0m" << endl;
					break;
				};
			EndInnerLoop:
				if (ExitInnerLoop) { break; };
			};
			break;
		case 2:
			exit(0);
		default:
			IOActions::ClearTerminal();
			cout << "\033[31mYanlis bir secenek girdiniz." << endl;
			cout << "\033[0m" << endl;
			break;
		};
	};
	return 0;
};