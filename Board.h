#include <iostream>
#include <fstream>


using namespace std;

class Board{
  public:
    int x = 0;
    int y = 0;
    //bool grid[100][100];
    char ** grid;

    Board();
    Board(int a, int b);
    //~board();

    void setSpace(int a, int b, bool z);
    bool getSpace(int a, int b);
    int getY();
    int getX();
    void consolePrint();
    void filePrint(string name, int gen);

};
