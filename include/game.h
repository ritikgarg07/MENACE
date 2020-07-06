#ifndef GAME_H
#define GAME_H

#include "./param.h"
#include "./display.h"
#include "./transform.h"
#include "./data.h"
#include "./logger.h"

class Game{
    public:

        Game(Data* data, Display* display, Transform* transform, Logger* logger){
            this->data = data;
            this->display = display;
            this->transform = transform;
            this->logger = logger;
            
            this->noughts.reset();
            this->crosses.reset();
            
            this->user = false;
        }

        eGameState start();

    private:
        
        Data* data;
        Display* display;
        Transform* transform;
        Logger* logger;
        
        BoardType noughts;
        BoardType crosses;
        
        inline static BoardType const win_array[kWinConditions] = {448,  // "111000000" 
                                                    56,     // "000111000"
                                                    7,      // "000000111"
                                                    292,    // "100100100"
                                                    146,    // "010010010"
                                                    73,     // "001001001"
                                                    273,    // "100010001"
                                                    84};    // "001010100"
        
        bool user;
        
        BoardType makeUserMove();
        eGameState checkBoard();
        bool checkWin(BoardType);

};

#endif