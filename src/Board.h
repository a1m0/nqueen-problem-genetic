#ifndef _BOARD_H_
#define _BOARD_H_

#include <cstdlib>
#include <string>

class Board {
  friend int cmp (const void *, const void*);

  private:
    int *queen;
    int fitness = -1;

  public:
    Board() {}
    Board(int n);

    int _size;
    
    void cross(Board B1, Board B2, int n);

    void setFitness();

    int getFitness();

    void printArr();

    int* getQueen();

    int getSize();
};

#endif