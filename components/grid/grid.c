#include <stdio.h>
#include "grid.h"

Color *GetCellColors() {
    Color darkGrey = {26, 31, 40, 255};
    Color green = {47, 230, 23, 255};
    Color red = {232, 18, 18, 255};
    Color orange = {226, 116, 17, 255};
    Color yellow = {237, 234, 4, 255};
    Color purple = {166, 0, 247, 255};
    Color cyan = {21, 204, 209, 255};
    Color blue = {13, 64, 216, 255};

    Color *result = (Color *) malloc(8 * sizeof(Color));
    result[0] = darkGrey;
    result[1] = green;
    result[2] = red;
    result[3] = orange;
    result[4] = yellow;
    result[5] = purple;
    result[6] = cyan;
    result[7] = blue;

    return result;
}

void GridInit(Grid *grid) {
    grid->numRows = 20;
    grid->numCols = 10;
    grid->cellSize = 30;
    for (int row = 0; row < grid->numRows; ++row) {
        for (int col = 0; col < grid->numCols; ++col) {
            grid->grid[row][col] = 0;
        }
    }
    grid->colors = GetCellColors();
}

void Print(Grid grid) {
    for (int row = 0; row < grid.numRows; ++row) {
        for (int col = 0; col < grid.numCols; ++col) {
            printf("%d ", grid.grid[row][col]);
        }
    }
    printf("%c", '\n');
}

void Draw(Grid grid) {
    for (int row = 0; row < grid.numRows; ++row) {
        for (int col = 0; col < grid.numCols; ++col) {
            int cellValue = grid.grid[row][col];
            DrawRectangle(col * grid.cellSize, row * grid.cellSize, grid.cellSize, grid.cellSize, grid.colors[cellValue]);
        }
    }
}

