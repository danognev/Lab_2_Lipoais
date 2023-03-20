#include "Menu.h"
void Greeting() {
	bool flagagain = true;
	while (flagagain)
	{
		WriteInformationText("Выполнил студент 494 группы Огнев Даниил. Вариант 13");
		WriteInformationText("Задача: Реализация игры \"Жизнь\"\n");
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
	std::string text = "Выберите способ ввода расположения живых клеток:";
	std::string variantanswer[countanswer];
	variantanswer[0] = "загрузить из файла";
	variantanswer[1] = "ввести с клавиатуры";
	variantanswer[2] = "выход";
	int answ = WriteQuestionandTakeAnswer(text, variantanswer, countanswer);
	if (answ == 1) {
		ReadFromFile(playfield);
		WriteInformationText("Полученная из файла колония:\n" + ConvertingPlaintFieldInText(playfield));
	}
	else if (answ == 2) {
		int countlivelypoints = 0;
		countlivelypoints = GettingLivelyPointsAndCountTheir(playfield);
		std::string heading = "Сохранить изначальные данные в файл?";
		variantanswer[0] = "Да";
		variantanswer[1] = "Нет";
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
	std::string heading = "Выводить каждый ход?";
	const int countanswer = 2;
	std::string variantanswer[countanswer];
	variantanswer[0] = "Да";
	variantanswer[1] = "Нет";
	int answ = WriteQuestionandTakeAnswer(heading, variantanswer, countanswer);
	if (answ == 1)
		writeeverystep = true;
	EvolutionPlayingField(plaingfield, countevolution, writeeverystep);
	std::string textrezult = "Колония после " + std::to_string(countevolution) + " ходов:\n", textsaverezult = "Изначальная колония:\n";
	textrezult += ConvertingPlaintFieldInText(plaingfield);
	textsaverezult += ConvertingPlaintFieldInText(initialfield) + textrezult;
	if (!writeeverystep)
		WriteInformationText(textrezult);
	heading = "Сохранить результат в файл?";
	variantanswer[0] = "Да";
	variantanswer[1] = "Нет";
	answ = WriteQuestionandTakeAnswer(heading, variantanswer, countanswer);
	if (answ == 1)
		WriteInFile(textsaverezult);
}

bool TryAgain() {
	std::string text = "Попробовать снова?";
	const int countanswer = 2;
	std::string variantanswer[countanswer];
	bool tryagain = false;
	variantanswer[0] = "Да";
	variantanswer[1] = "Нет";
	int answ = WriteQuestionandTakeAnswer(text, variantanswer, countanswer);
	if (answ == 1) {
		system("cls");
		tryagain = true;
	}
	return tryagain;
}
