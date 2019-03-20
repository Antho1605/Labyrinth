#include <iostream>
#include <bitset>
#include "MazeCardShape.h"

using namespace labyrinth;

int main(){

    MazeCardShape shape{MazeCardShape::UP | MazeCardShape::DOWN};
    std::bitset <4> bitset {MazeCardShape::UP | MazeCardShape::DOWN};
    std::cout << bitset << std::endl;
    shape.rotate();
    std::cout << bitset << std::endl;
}
