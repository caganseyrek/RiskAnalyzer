#include "display_tables.hpp"

#include <iostream>
#include <iomanip>

namespace DisplayTables {
	void PossibilityTable() {
		std::cout << std::setw(30) << std::left << "Riskin Olasiligi" << "|" << std::setw(10) << std::left << "Puan" << std::endl;
		std::cout << std::setw(30) << std::left << "------------------------------" << "+" << std::setw(13) << "----------" << std::endl;
		std::cout << std::setw(30) << std::left << "Neredeyse imkansiz" << "|" << std::setw(10) << std::left << "0.1" << std::endl;
		std::cout << std::setw(30) << std::left << "Pratik olarak imkansiz" << "|" << std::setw(10) << std::left << "0.2" << std::endl;
		std::cout << std::setw(30) << std::left << "Mumkun ancak beklenmeyen" << "|" << std::setw(10) << std::left << "0.5" << std::endl;
		std::cout << std::setw(30) << std::left << "Mumkun ancak dusuk ihtimal" << "|" << std::setw(10) << std::left << "1" << std::endl;
		std::cout << std::setw(30) << std::left << "Mumkun" << "|" << std::setw(10) << std::left << "3" << std::endl;
		std::cout << std::setw(30) << std::left << "Oldukca mumkun" << "|" << std::setw(10) << std::left << "6" << std::endl;
		std::cout << std::setw(30) << std::left << "Kesin, beklenir" << "|" << std::setw(10) << std::left << "10" << std::endl;
		std::cout << std::endl;
	};

	void FrequencyTable() {
		std::cout << std::setw(40) << std::left << "Riskin Sikligi" << "|" << std::setw(10) << std::left << "Puan" << std::endl;
		std::cout << std::setw(40) << std::left << "----------------------------------------" << "+" << std::setw(13) << "----------" << std::endl;
		std::cout << std::setw(40) << std::left << "Cok Seyrek (Yilda bir veya daha az)" << "|" << std::setw(10) << std::left << "0.5" << std::endl;
		std::cout << std::setw(40) << std::left << "Seyrek (Yilda birkac defa)" << "|" << std::setw(10) << std::left << "1" << std::endl;
		std::cout << std::setw(40) << std::left << "Nadiren (Ayda bir veya birkac defa)" << "|" << std::setw(10) << std::left << "2" << std::endl;
		std::cout << std::setw(40) << std::left << "Ara Sira (Haftada bir veya birkac defa)" << "|" << std::setw(10) << std::left << "3" << std::endl;
		std::cout << std::setw(40) << std::left << "Sik (Gunde bir veya birkac defa)" << "|" << std::setw(10) << std::left << "6" << std::endl;
		std::cout << std::setw(40) << std::left << "Surekli (Saate birkac defa)" << "|" << std::setw(10) << std::left << "10" << std::endl;
		std::cout << std::endl;
	};

	void EffectTable() {
		std::cout << std::endl;
		std::cout << std::setw(70) << std::left << "Riskin Etkisi" << "|" << std::setw(10) << std::left << "Puan" << std::endl;
		std::cout << std::setw(70) << std::left << "---------------------------------------------------------------------" << "+" << std::setw(13) << "----------" << std::endl;
		std::cout << std::setw(70) << std::left << "Ramak Kala (Cevresel zarar yok)" << "|" << std::setw(10) << std::left << "1" << std::endl;
		std::cout << std::setw(70) << std::left << "Kucuk Hasar, Yaralanma, Ilkyardim (Sinirli cevresel etki)" << "|" << std::setw(10) << std::left << "3" << std::endl;
		std::cout << std::setw(70) << std::left << "Onemli Hasar, Yaralanma, Tibbi Tedavi (Genis cevresel etki) " << "|" << std::setw(10) << std::left << "7" << std::endl;
		std::cout << std::setw(70) << std::left << "Kalici Hasar, Sakatlik, Uzun Sureli Tedavi (Onemli Cevresel Etki)" << "|" << std::setw(10) << std::left << "15" << std::endl;
		std::cout << std::setw(70) << std::left << "Olum (Ciddi cevresel etki)" << "|" << std::setw(10) << std::left << "40" << std::endl;
		std::cout << std::setw(70) << std::left << "Birden Fazla Olum (Cevresel felaket)" << "|" << std::setw(10) << std::left << "100" << std::endl;
		std::cout << std::endl;
	};

	void ClassificationTable() {
		std::cout << std::setw(25) << std::left << "Risk Degeri" << "|" << std::setw(70) << std::left << "Risk Siniflandirmasi" << std::endl;
		std::cout << std::setw(25) << std::left << "------------------------" << "+" << std::setw(91) << std::left << "------------------------------------------------------------------------------------------" << std::endl;
		std::cout << std::setw(25) << std::left << "20'den az (...-20]" << "|" << std::setw(70) << std::left << "Onemsiz risk - Kabul edilebilir" << std::endl;
		std::cout << std::setw(25) << std::left << "20-70 arasi (20-70]" << "|" << std::setw(70) << std::left << "Olasi risk - Gozetim altinda tutulmalidir" << std::endl;
		std::cout << std::setw(25) << std::left << "70-200 arasi (70-200]" << "|" << std::setw(70) << std::left << "Onemli risk - Uzun donemde iyilestirilmelidir" << std::endl;
		std::cout << std::setw(25) << std::left << "200-400 arasi (200-400]" << "|" << std::setw(70) << std::left << "Ciddi risk - Kisa surede iyilestirilmelidir" << std::endl;
		std::cout << std::setw(25) << std::left << "400'den fazla (400-..]" << "|" << std::setw(70) << std::left << "Kabul edilemez risk - Iyilesene kadar ise ara verilmelidir" << std::endl;
		std::cout << std::endl;
	};
};