#pragma once

#include <stdlib.h>
#include <raylib.h>

struct Grid {
    int grid[20][10];
    int numRows;
    int numCols;
    int cellSize;
    Color *colors;
};

typedef struct Grid Grid;

void GridInit(Grid *grid);

void Print(Grid grid);

void Draw(Grid grid);

Color *GetCellColors();

