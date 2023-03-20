#include "WorkWithFile.h"
using namespace std::filesystem;

void ReadFromFile(bool(&playingfield)[widthfield][widthfield])
{
	char ch;
	bool tempfield[widthfield][widthfield];
	for (size_t i = 0; i < widthfield; i++)
		for (size_t j = 0; j < widthfield; j++)
			tempfield[i][j] = playingfield[i][j];
	std::cin.ignore();
	std::string pathfile = GetPathFile(), readtext = "";
	std::ifstream fin;
	bool fileerorr = false;
	while (true) {
		if (!CheckPathOncon(pathfile) || !fileerorr) {
			if (is_regular_file(pathfile))
				fin.open(pathfile);
			if (!fin.is_open())
				WriteInformationText("�� ������� ����� ���� �� ��������� ���� ��� �� �������������� ��� ������ ����!");
		}
		while (!fin.is_open() || CheckPathOncon(pathfile) || fileerorr) {
			fin.close();
			if (fileerorr) {
				WriteInformationText("���� �� ����� ��������!");
				readtext = "";
				fileerorr = false;
			}
			pathfile = GetPathFile();
			if (!CheckPathOncon(pathfile)) {
				if (is_regular_file(pathfile)) {
					fin.open(pathfile);
					break;
				}
				else
					WriteInformationText("�� ������� ����� ���� �� ��������� ���� ��� �� �������������� ��� ������ ����!");
			}
		}
		while (fin.get(ch))
			readtext += ch;
		fin.close();
		std::string tempstr, tempstr2;
		std::stringstream input_stringstream(readtext);
		std::getline(input_stringstream, tempstr, '\n');
		int countpoints = 0, x = 0, y = 0;
		try {
			for (size_t i = 0; i < tempstr.length(); i++)
				if (!std::isdigit(tempstr[i]) && !(i == 0 && tempstr[0] == '-'))
					throw(tempstr);
			countpoints = std::stoi(tempstr);
			if (countpoints < 1 || countpoints > widthfield*widthfield) {
				fileerorr = true;
				continue;
			}
		}
		catch (std::string errorstr) {
			fileerorr = true;
			continue;
		}
		while (std::getline(input_stringstream, tempstr, '\n')) {
			std::getline(input_stringstream, tempstr2, '\n');
			try {
				for (size_t i = 0; i < tempstr.length(); i++)
					if (!std::isdigit(tempstr[i]) && !(i == 0 && tempstr[0] == '-'))
						throw(tempstr);
				for (size_t i = 0; i < tempstr2.length(); i++)
					if (!std::isdigit(tempstr2[i]) && !(i == 0 && tempstr2[0] == '-'))
						throw(tempstr2);
				if (tempstr == "" || tempstr2 == "")
					throw(tempstr + tempstr2);
				x = std::stoi(tempstr);
				y = std::stoi(tempstr2);
				if ((x < 0 || x > widthfield - 1) && (y < 0 || y > widthfield - 1)) {
					fileerorr = true;
					break;
				}
				else
					playingfield[x-1][y-1] = true;
			}
			catch (std::string errorstr) {
				fileerorr = true;
				continue;
			}
			countpoints--;
		}
		if (countpoints > 0)
			fileerorr = true;
		if(!fileerorr)
			return ;
	}
}
bool CheckPathOncon(std::string path) {
	bool flag = false;
	std::string temppath = "";
	for (int i = 0; i < path.length(); i++)
		temppath += path[i];
	if (temppath == "con") {
		WriteInformationText("con ������ ������������ ��� ���������� ��� ������! ��������� ����.");
		flag = true;
	}
	return flag;
}

void WriteInFile(std::string text)
{
	bool isDataSaved = false;
	std::string pathfile = "";
	std::cin.ignore();
	WriteInformationText("������� ���� � �����.");
	do {
		std::getline(std::cin, pathfile);

		if (CheckPathOncon(pathfile))
			continue;

		if (std::ifstream(pathfile)) {
			text = "������������ ����?";
			const int countanswer = 2;
			std::string variantanswer[countanswer];
			variantanswer[0] = "��";
			variantanswer[1] = "���";
			int answ = WriteQuestionandTakeAnswer(text, variantanswer, countanswer);
			if (answ == 2) {
				WriteInformationText("������� ������ ��� �����!");
				continue;
			}
		}

		std::ofstream myFile(pathfile, std::ofstream::app);

		std::error_code ec;
		if (!is_regular_file(pathfile, ec)) {
			WriteInformationText("����� �������� ������������ ��������! ��������� ����.");
			continue;
		}

		if (!myFile) {
			WriteInformationText("������ ���������. ��������� ����.");
			myFile.close();
			continue;
		}

		myFile.close();
		myFile.open(pathfile, std::ofstream::trunc);
		myFile << text;
		myFile.close();
		isDataSaved = true;
	} while (!isDataSaved);
}
