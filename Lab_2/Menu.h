#pragma once
#include <clocale>
#include "FunctionsMenu.h"
#include "GameModel.h"
#include "WorkWithFile.h"
#define widthfield 30
void Greeting();
bool InputMethod();
bool TryAgain();
void WriteResult(bool(&plaingfield)[widthfield][widthfield], int countevolution);