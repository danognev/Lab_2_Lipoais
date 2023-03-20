#include "FunctionsMenu.h"

void WriteInformationText(std::string text) {
	std::cout << text << std::endl;
}
int WriteQuestionandTakeAnswer(std::string textquestion, std::string* variantsanswer, const int countanswer) {
	int answernumber = -1;
	if (countanswer > 0) {
		std::cout << textquestion << std::endl;
		for (int i = 0; i < countanswer; i++) {
			std::cout << std::to_string(i + 1) + ". " + variantsanswer[i] << std::endl;
		}
		answernumber = TakeIntNumber(1, countanswer);
	}
	return answernumber;
}
int TakeIntNumber(int min, int max) {
	if (min > max)
		std::swap(min, max);
	int takednum = min - 1;
	while (takednum < min || takednum > max) {
		std::string tempstr = "";
		std::cin >> tempstr;
		try {
			for (size_t i = 0; i < tempstr.length(); i++)
				if (!std::isdigit(tempstr[i]) && !(i == 0 && tempstr[0] == '-'))
					throw(tempstr);
			takednum = std::stoi(tempstr);
			if (takednum < min || takednum > max) {
				tempstr = "Введенное число не входит в требуемый интервал выбора (";
				tempstr += std::to_string(min);
				tempstr += ';';
				tempstr += std::to_string(max);
				tempstr += ')';
				WriteInformationText(tempstr);
			}
		}
		catch (std::string errorstr) {
			WriteInformationText("То, что вы ввели, не является числом!\nПопробуйте ещё раз!");
			std::cin.ignore();
		}
	}
	return takednum;
}
int GettingLivelyPointsAndCountTheir(bool(&plaingfield)[widthfield][widthfield]) {
	int x, y;
	int countlivelypoints = 0;
	std::cin.ignore();
	WriteInformationText("Введите координаты живой клетки (поле имеет размеры 30x30).");
	WriteInformationText("Введите координату по х:");
	x = TakeIntNumber(1, widthfield) - 1;
	WriteInformationText("Введите координату по y:");
	y = TakeIntNumber(1, widthfield) - 1;
	plaingfield[x][y] = true;
	countlivelypoints++;
	while (true) {
		const int countanswer = 2;
		std::string variantanswer[countanswer];
		std::string heading = "Ввести координаты ещё одной клетки?";
		variantanswer[0] = "Да";
		variantanswer[1] = "Нет";
		int answ = WriteQuestionandTakeAnswer(heading, variantanswer, 2);
		if (answ == 1) {
			WriteInformationText("Введите координату по х:");
			x = TakeIntNumber(1, widthfield) - 1;
			WriteInformationText("Введите координату по y:");
			y = TakeIntNumber(1, widthfield) - 1;
			if (!plaingfield[x][y])
				countlivelypoints++;
			plaingfield[x][y] = true;
		}
		else
			break;
	}
	WriteInformationText("Получившаяся колония:\n" + ConvertingPlaintFieldInText(plaingfield));
	return countlivelypoints;
}
int GettingCountEvolution()
{
	WriteInformationText("Введите количество ходов (не более 200):");
	return TakeIntNumber(1, 200);
}
std::string GetPathFile()
{
	std::string path;
	while (path == "") {
		WriteInformationText("Введите путь к файлу:");
		std::cin >> path;
	}
	return path;
}

std::string ConvertingPlaintFieldInText(bool (&plaingfield)[widthfield][widthfield])
{
	std::string textfield = "";
	for (size_t i = 0; i < widthfield + 2; i++)
	{
		for (size_t j = 0; j < widthfield + 2; j++)
		{
			if (i == 0 || j == 0 || i == widthfield + 1 || j == widthfield + 1)
				textfield += '#';
			else {
				if (plaingfield[i - 1][j - 1])
					textfield += '@';
				else
					textfield += ' ';
			}
			textfield += ' ';
		}
		textfield += '\n';
	}
	return textfield;
}
