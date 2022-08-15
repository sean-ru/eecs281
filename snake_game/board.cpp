#include <iostream>
#include <vector>
#include "cell.cpp"
using namespace std;

class Board {
private:
    int rowCount, colCount;
    vector<vector<Cell> > cells;

public:
    Board(int initRowCount, int initColCount) 
      : rowCount(initRowCount), colCount(initColCount) 
      {vector<vector<Cell> > cells(rowCount, vector<Cell>(colCount, Cell::CellType::EMPTY));
        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < colCount; ++col) {
                cells[row][col] = Cell(row, col);
            }
        }
    }

    vector<vector<Cell> > getCells() {
        return cells;
    }

    void setCells(vector<vector<Cell> > cells) {
        this->cells = cells;
    }

    void generateFood() {
        int row = rand() * rowCount;
        int col = rand() * colCount; 
        while (true) {
            if (cells[row][col].getCellType() != Cell::CellType::SNAKE_NODE) {
                break;
            }
        }
        cells[row][col].setCellType(Cell::CellType::FOOD);
    }
};