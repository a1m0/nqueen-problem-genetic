#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <sstream>
#include <chrono> 
using namespace std::chrono; 

template <typename T>
  std::string NumberToString ( T Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }

#include "Board.h"

int cmp (const void *ptr1 , const void *ptr2)
{
    Board *m1 = *(Board**)ptr1;
    Board *m2 = *(Board**)ptr2;

    return m1->getFitness() - m2->getFitness();
}

int main() {
  srand(time(NULL));
  int n;
  std::cout << "Enter number of Queens: ";
  std::cin >> n;
  std::cout << std::endl;

  auto start = high_resolution_clock::now(); 

  int m = n * 1000 + (n / 3) *100;
  int p = n * 1000;
  int w = m / 10;

  Board* board[m];

  for (int i = 0; i < m; i++) {
    board[i] = new Board(n);
  }

  double last = -1.0;

  for (int i = 0; i < p; i++) {
    if (last != i * 100 / p) {
        last = i*100/(double)p;
        std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b" << "Loading " << NumberToString(last) << "%  " << std::flush;
        Sleep(1);
        if(last == 99) {
          std::cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b" << "Loading " << NumberToString(100) << "%  " << std::flush;
          std::cout << std::endl << "Answer: ";
        }
    }
    qsort (board,m,sizeof(Board *), (int (*)(const void *, const void *)) cmp);
    for (int j = w; j < m; j++){
        Board p1 = *board[(int)(rand() % w)];
        Board p2 = *board[(int)(rand() % w)];
        (*board[j]).cross(p1, p2, n);
    }
  }
  qsort (board,m,sizeof(Board *), (int (*)(const void *, const void *)) cmp);
  auto stop = high_resolution_clock::now(); 
  auto duration = duration_cast<microseconds>(stop - start); 
  board[0]->printArr();
  std::cout << std::endl << duration.count() / (double)1000000<< " s" << std::endl;

}