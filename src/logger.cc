#include "../include/logger.h"

void Logger::updateLog(LogEntry log_entry){
    log.push_back(log_entry);
}

void Logger::updateDB(eGameState game_state){
    for(uint32_t i = 0; i < log.size(); ++i){
        this->transform->updateEntry(log[i].move, log[i].transformation, log[i].noughts, log[i].crosses, game_state);
    }
    log.clear();
}