#include <iostream>
#include "board.cpp"
#include "snake.cpp"
//#include "cell.cpp"
using namespace std;

class Game {
private:
    Snake snake;
    Board board;
    int dir;
    bool gameOver;

    Cell getNextCell(Cell curPos) {
        int row = curPos.getRow(), col = curPos.getCol();
        if (dir == DIR_RIGHT) {
            ++col;
        }
        if (dir == DIR_LEFT) {
            --col;
        }
        if (dir == DIR_UP) {
            --row;
        }
        if (dir == DIR_DOWN) {
            ++row;
        }
        Cell nextCell = board.getCells()[row][col];
        return nextCell;
    }

public:
    static const int DIR_NONE = 0, DIR_RIGHT = 1, DIR_LEFT = -1,
    DIR_UP = 2, DIR_DOWN = -2;

    Game(Snake initSnake, Board initBoard)
      : snake(initSnake), board(initBoard) {}

    Snake getSnake() {
        return snake;
    }

    void setSnake(Snake snake) {
        this->snake = snake;
    }

    Board getBoard() {
        return board;
    }

    void setBoard(Board board) {
        this->board = board;
    }

    int getDirection() {
        return dir;
    }

    void setDirection(int dir) {
        this->dir = dir;
    }

    void update() {
        if (!gameOver) {
            if (dir != DIR_NONE) {
                Cell nextCell = getNextCell(snake.getHead());
                if (snake.checkCrash(nextCell)) {
                    setDirection(DIR_NONE);
                    gameOver = true;
                }
                else {
                    snake.move(nextCell);
                    if (nextCell.getCellType() == Cell::CellType::FOOD) {
                        snake.grow();
                        board.generateFood();
                    }
                }
            }
        }
    }
};