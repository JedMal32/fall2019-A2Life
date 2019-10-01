#include <iostream>
class Board;

using namespace std;


class Generationer{
  public:
    char mode;
    int sameAsLast;

    Generationer();
    Generationer(char c);

    char getMode();
    void setMode(char c);
    int getSame();
    void incrementSame();

    Board evaluator(Board b);

    Board evaluatorClassic(Board b);
    Board evaluatorDonut(Board b);
    Board evaluatorMirror(Board b);


};
