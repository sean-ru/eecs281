#include <iostream>
#include <list>
#include "cell.cpp"
using namespace std;

class Snake {
private:
    list<Cell> snakeBody;
    Cell head;

public:
    Snake(Cell initPos)
      : head(initPos) {snakeBody.push_back(head); head.setCellType(Cell::CellType::SNAKE_NODE);}

    void grow() {
        snakeBody.push_back(head);
    }   

    void move(Cell nextCell) {
        Cell tail = snakeBody.back();
        tail.setCellType(Cell::CellType::EMPTY);
        head = nextCell;
        head.setCellType(Cell::CellType::SNAKE_NODE);
        snakeBody.push_front(head);
    } 

    bool checkCrash(Cell nextCell) {
        for (auto& cell : snakeBody) {
            if (cell == nextCell) {
                return true;
            }
        }
        return false;
    }

    list<Cell> getSnakeBody() {
        return snakeBody;
    }

    void setSnakeBody(list<Cell> snakeBody) {
        this->snakeBody = snakeBody;
    }

    Cell getHead() {
        return head;
    }

    void setHead(Cell head) {
        this->head = head;
    }
};