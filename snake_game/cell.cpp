class Cell {
public:
    enum CellType {
        EMPTY, FOOD, SNAKE_NODE
    };

private:
    int row, col;
    CellType cellType;

public:    
    Cell(int rowIn, int colIn)
      : row(rowIn), col(colIn) {} 

    CellType getCellType() {
        return cellType;
    }

    void setCellType(CellType cellType) {
        this->cellType = cellType;
    }

    int getRow() {
        return row;
    }

    int getCol() {
        return col;
    }
};