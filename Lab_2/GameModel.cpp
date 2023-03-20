#include "GameModel.h"


void EvolutionPlayingField(bool (&plaingfield)[widthfield][widthfield], int countstepevolv, bool writeeverystep)
{
    bool staticorvoidfield = false;
    for (int i = 0; i < countstepevolv; i++) {
        staticorvoidfield = OneEvolutionField(plaingfield);
        if(writeeverystep)
            WriteInformationText("На " + std::to_string(i+1) + " ходу колония выглядит:\n" + ConvertingPlaintFieldInText(plaingfield));
        if (staticorvoidfield)
            return;
    }
}

bool OneEvolutionField(bool(&plaingfield)[widthfield][widthfield])
{
    bool flagstatic = true;
    bool oldfield[widthfield][widthfield];
    for (int i = 0; i < widthfield; i++) 
        for (int j = 0; j < widthfield; j++)
            oldfield[i][j] = plaingfield[i][j];
    int tempcount;
    for (int i = 0; i < widthfield; i++) {
        for (int j = 0; j < widthfield; j++) {
            tempcount = CountLivelyPointNearby(i, j, oldfield);
            if (tempcount < 2 || tempcount > 3)
                plaingfield[i][j] = false;
            else {
                if (tempcount == 3)
                    plaingfield[i][j] = true;
                else
                    plaingfield[i][j] = oldfield[i][j];
            }
            if(plaingfield[i][j] != oldfield[i][j])
                flagstatic = false;
        }
    }

    return flagstatic;
}

int CountLivelyPointNearby(int x, int y, bool(&plaingfield)[widthfield][widthfield])
{
    int countlivelypoints = 0;
    if (x >= 0 && x < widthfield && y >= 0 && y < widthfield) {
        int tempx = x - 1, tempy = y - 1;
        for (int i = 0; i < 9; i++) {
            tempx = x - 1 + i % 3;
            tempy = y - 1 + i / 3;
            if (!(tempx == x && tempy == y) && CheckPointOnOutOfTheField(tempx, tempy)) {
                if (plaingfield[tempx][tempy])
                    countlivelypoints++;
            }
        }
    }
    return countlivelypoints;
}

bool CheckPointOnOutOfTheField(int x, int y)
{
    bool pointinfield = true;
    if (x < 0 || x >= widthfield)
        pointinfield = false;
    if (y < 0 || y >= widthfield)
        pointinfield = false;
    return pointinfield;
}
