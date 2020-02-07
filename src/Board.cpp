#include <cstdlib>
#include <string>
#include <iostream>

#include "Board.h"

Board::Board(int n) {
  this->queen = new int[n];
  _size = n;
  for (int i = 0; i < n; i++) {
  this->queen[i] = (rand() % n) + 1;
  }
  setFitness();
}

void Board::cross(Board B1, Board B2, int n) {
  int r = (int)rand() % n;
  std::copy(B1.queen, B1.queen+r, this->queen);
  std::copy(B2.queen+r, B2.queen+n, this->queen+r);
  r = (int)(rand() % 10000);
  if (r < 20) {
    r = (int)(rand() % n);
    this->queen[r] = ((int)(rand() % n) + 1);
  }
  setFitness();
}

void Board::setFitness() {
  int temp = 0;
  for (int i = 0; i < this->_size; i++) {
    for (int j = 0; j < i; j++) {
      if (this->queen[i] == this->queen[j]) temp++;
      else if (this->queen[i]+i == this->queen[j]+j) temp++;
      else if (this->queen[i]-i == this->queen[j]-j) temp++;
    }
  }
  this->fitness = temp;
}

int Board::getFitness() {
  if(this->fitness!=-1) return this->fitness;
  this->setFitness();
  return this->fitness;
}

void Board::printArr() {
  std::cout << "{";
  for (int i = 0; i < _size; i++) {
    std::cout << this->queen[i];
    if (i != _size-1) std::cout << ", ";
  }
  std::cout << "}";
}

int* Board::getQueen() {
  return this->queen;
}

int Board::getSize() {
  return _size;
}
