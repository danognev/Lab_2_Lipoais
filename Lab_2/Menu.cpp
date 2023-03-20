#include "Menu.h"
void Greeting() {
	bool flagagain = true;
	while (flagagain)
	{
		WriteInformationText("�������� ������� 494 ������ ����� ������. ������� 13");
		WriteInformationText("������: ���������� ���� \"�����\"\n");
		if (InputMethod())
			flagagain = TryAgain();
		else
			flagagain = false;
	}
}
bool InputMethod() {
	int countevolution = 0;
	bool playfield[widthfield][widthfield];
	for (size_t i = 0; i < widthfield; i++)
		for (size_t j = 0; j < widthfield; j++)
			playfield[i][j] = false;
	const int countanswer = 3;
	std::string text = "�������� ������ ����� ������������ ����� ������:";
	std::string variantanswer[countanswer];
	variantanswer[0] = "��������� �� �����";
	variantanswer[1] = "������ � ����������";
	variantanswer[2] = "�����";
	int answ = WriteQuestionandTakeAnswer(text, variantanswer, countanswer);
	if (answ == 1) {
		ReadFromFile(playfield);
		WriteInformationText("���������� �� ����� �������:\n" + ConvertingPlaintFieldInText(playfield));
	}
	else if (answ == 2) {
		int countlivelypoints = 0;
		countlivelypoints = GettingLivelyPointsAndCountTheir(playfield);
		std::string heading = "��������� ����������� ������ � ����?";
		variantanswer[0] = "��";
		variantanswer[1] = "���";
		answ = WriteQuestionandTakeAnswer(heading, variantanswer, 2); 
		if (answ == 1){
			text = std::to_string(countlivelypoints) + '\n';
			for (size_t i = 0; i < widthfield; i++)
			{
				for (size_t j = 0; j < widthfield; j++)
				{
					if (playfield[i][j]) {
						text += std::to_string(i+1) + '\n' + std::to_string(j+1) + '\n';
					}
				}
			}
			WriteInFile(text); 
		}
	}
	else
		return false;
	countevolution = GettingCountEvolution();
	WriteResult(playfield, countevolution);
	return true;
}
void WriteResult(bool(&plaingfield)[widthfield][widthfield], int countevolution) {
	bool initialfield[widthfield][widthfield], writeeverystep = false;
	for (size_t i = 0; i < widthfield; i++)
		for (size_t j = 0; j < widthfield; j++)
			initialfield[i][j] = plaingfield[i][j];
	std::string heading = "�������� ������ ���?";
	const int countanswer = 2;
	std::string variantanswer[countanswer];
	variantanswer[0] = "��";
	variantanswer[1] = "���";
	int answ = WriteQuestionandTakeAnswer(heading, variantanswer, countanswer);
	if (answ == 1)
		writeeverystep = true;
	EvolutionPlayingField(plaingfield, countevolution, writeeverystep);
	std::string textrezult = "������� ����� " + std::to_string(countevolution) + " �����:\n", textsaverezult = "����������� �������:\n";
	textrezult += ConvertingPlaintFieldInText(plaingfield);
	textsaverezult += ConvertingPlaintFieldInText(initialfield) + textrezult;
	if (!writeeverystep)
		WriteInformationText(textrezult);
	heading = "��������� ��������� � ����?";
	variantanswer[0] = "��";
	variantanswer[1] = "���";
	answ = WriteQuestionandTakeAnswer(heading, variantanswer, countanswer);
	if (answ == 1)
		WriteInFile(textsaverezult);
}

bool TryAgain() {
	std::string text = "����������� �����?";
	const int countanswer = 2;
	std::string variantanswer[countanswer];
	bool tryagain = false;
	variantanswer[0] = "��";
	variantanswer[1] = "���";
	int answ = WriteQuestionandTakeAnswer(text, variantanswer, countanswer);
	if (answ == 1) {
		system("cls");
		tryagain = true;
	}
	return tryagain;
}
