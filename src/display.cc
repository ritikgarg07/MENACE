#include "../include/display.h"

// Function that displays the board
// @param: noughts: noughts board
// @param: crosses: crosses board
// @param: user: whether its user turn
void Display::displayBoard(BoardType noughts, BoardType crosses, bool user){
    
    std::cout << "\n\n";
    for (u_int32_t i = 0; i < kSize; ++i){
        if (i%3 == 0 && i !=0 ){
            std::cout << "\n";
            std::cout << "____________";
            std::cout << "\n";
        }

        if (noughts[kSize - 1 - i])
            std::cout << " O |";
        else if (crosses[kSize - 1 - i])
            std::cout << " X |";
        else
            std::cout << " " << i + 1 << " |";
    

    }
    if(user)
        std::cout << "\n\nPress corresponding number for making move\n";
    else
        std::cout << "\n\n\n";
}