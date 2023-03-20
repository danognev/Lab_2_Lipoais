#pragma once
#include "FunctionsMenu.h"
#define widthfield 30

void EvolutionPlayingField(bool(&plaingfield)[widthfield][widthfield], int countstepevolv, bool writeeverystep);
bool OneEvolutionField(bool(&plaingfield)[widthfield][widthfield]);
int CountLivelyPointNearby(int x, int y, bool(&plaingfield)[widthfield][widthfield]);
bool CheckPointOnOutOfTheField(int x, int y);