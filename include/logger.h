#ifndef LOGGER_H
#define LOGGER_H

#include "param.h"
#include "transform.h"
#include <vector>

class Logger{
    
    public:
    
        Logger(Transform* transform){
            this->transform = transform;
        }
    
        struct LogEntry{
            BoardType move;
            Transform::eTransformation transformation;
            BoardType noughts;
            BoardType crosses;
        };

        void updateLog(LogEntry);
        void updateDB(eGameState);

    private:
        std::vector<LogEntry> log;    
        Transform* transform;
};


#endif