#ifndef DATA_H
#define DATA_H


#include <unordered_map>
#include <fstream>
#include <math.h>
#include <random>
#include <iostream>
#include <string>
#include "param.h"

typedef std::vector<uint32_t> MatchBoxType;
typedef std::unordered_map<BoardKeyType, MatchBoxType> DatabaseType;

class Data{
    public:

        Data(std::mt19937 *gen, std::string file_db){
            this->gen = gen;
            this->file_db = file_db;
        }

        BoardType getMove(BoardKeyType key);
        void updateEntry(BoardKeyType key, BoardType move, eWinCondition result);         // TODO: Implement
        void saveDatabase();
        void readDatabase();

    private:

        std::mt19937 *gen;
        DatabaseType database;
        std::string file_db;
        BoardType choosePlace(DatabaseType::iterator);
        DatabaseType::iterator createEntry(BoardKeyType key);
        
};


#endif