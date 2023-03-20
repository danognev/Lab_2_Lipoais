#pragma once
#define widthfield 30
#include <clocale>
#include <iostream>
#include <string>
void WriteInformationText(std::string text);
int WriteQuestionandTakeAnswer(std::string textquestion, std::string* variantsanswer, int countanswer);
int TakeIntNumber(int min, int max);
int GettingLivelyPointsAndCountTheir(bool (&plaingfield)[widthfield][widthfield]);
int GettingCountEvolution();
std::string GetPathFile();
std::string ConvertingPlaintFieldInText(bool(&plaingfield)[widthfield][widthfield]);