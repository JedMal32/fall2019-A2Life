#include <iostream>
class Board;

using namespace std;

class Generator
{
  public:
    Generator();

    Board text(string file);
    Board random(int y, int x, float d);
};
