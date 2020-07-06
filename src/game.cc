#include "../include/game.h"

// Function that prompts the user to make a move
// Returns a board representing the move user made
// ! prints to console
BoardType Game::makeUserMove(){
    
    uint32_t position = 0;              // position to play (1 - 9)
    BoardType move(0);                  // empty move
    
    do{
        move.reset();
        std::cout << "Enter a valid move: ";
        std::cin >> position;
        move.set(kSize - position);     // Set the corresponding bit
    }while((move & (noughts|crosses)) != 0);            // Check for move's validity

    return move;
}

// Function that checks if the current board is a win condition
// @param: board: board to check
bool Game::checkWin(BoardType board){
    
    // iterate through all win conditions (Defined in game class) and compare
    for(int i = 0; i < 8; ++i){
        if((board&win_array[i]) == Game::win_array[i])
            return true;
    }
    return false;
}

// Function that checks the current state of the game
// Returns a eGameState variable
eGameState Game::checkBoard(){
    
    // if noughts in winning condition
    // Menace has lost
    if(checkWin(noughts))
        return kLose;
    
    // if crosses in winning condition
    // Menace has won
    if(checkWin(crosses))
        return kWin;

    // If all positions of board not occupied
    BoardType occupied = noughts|crosses;
    BoardType full("111111111");
    if((full^occupied) != 0)
        return kCurrent;
    
    // If board full, and no winner => draw
    return kDraw;
}

// Main function
// Plays the game
// ! prints to console
eGameState Game::start(){
    this->user = false;
    this->noughts.reset();
    this->crosses.reset();
    Transform::QueryResult menace_move;
    Logger::LogEntry log_entry;

    eGameState game_state = kCurrent;
    while(game_state == kCurrent){
        if(!user){
            menace_move = this->transform->makeMove(this->noughts, this->crosses);
            
            log_entry.crosses = crosses;
            log_entry.noughts = noughts;
            log_entry.move = menace_move.move;
            log_entry.transformation = menace_move.transformation;
            this->logger->updateLog(log_entry);
            
            crosses |= menace_move.move;
            user = !user;
        }
        
        else{
            // menace_move = this->transform->makeMove(this->noughts, this->crosses);
            // log_entry.crosses = crosses;
            // log_entry.noughts = noughts;
            // log_entry.move = menace_move.move;
            // log_entry.transformation = menace_move.transformation;
            // this->logger->updateLog(log_entry);
            
            // noughts |= menace_move.move;
            // user = !user;
            noughts |= makeUserMove();
            user = !user;
        }
        
        game_state = checkBoard();
        this->display->displayBoard(noughts, crosses, user);
    }

    logger->updateDB(game_state);

    switch(game_state){
        case kDraw:
            std::cout << "Game drawn!\n";
            break;
        case kWin:
            std::cout << "Menace beat you, ha ha!\n";
            break;
        case kLose:
            std::cout << "You won!\n";
            break;
        default:
            std::cout << "Oops! Looks like something went wrong. Game is in progress...";
            break;
    }

    return game_state;
}