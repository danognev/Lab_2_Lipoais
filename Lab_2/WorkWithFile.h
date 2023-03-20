#pragma once
#include <fstream>
#include <string>
#include <filesystem>
#include "FunctionsMenu.h"
#define widthfield 30
void ReadFromFile(bool (&playingfield)[widthfield][widthfield]);
void WriteInFile(std::string text);
bool CheckPathOncon(std::string path);