#ifndef PARAM_H
#define PARAM_H

#include <bitset>
#include <random>
#include <vector>

const uint32_t kSize = 9;               // Size of game board
const uint32_t kWinConditions = 8;
const uint32_t kStartBeads = 5;


typedef std::bitset<kSize> BoardType;   // Datatype representing board
typedef uint32_t BoardKeyType;          // Datatype representing board key

// Enum encapsulating the result of the game
// With respect to MENACE 
enum eGameState{
    kLose = 0,
    kDraw = 1,
    kWin = 2,
    kCurrent = 3,
    kStatesTotal = 4
};

const int32_t bead_change[kStatesTotal - 1] = {-1, 1, 3};

#endif