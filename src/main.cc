#include "../include/data.h"
#include "../include/game.h"
#include "../include/param.h"
#include "../include/logger.h"

int main(){   

    std::random_device rd;
    std::mt19937 gen(rd());
    Data data = Data(&gen, "./data/database.txt");
    std::cout << "Loading database...\n";
    data.readDatabase();
    std::cout << "Database loaded successfully!\n ";
    Display display = Display();
    Transform transform = Transform(&data);
    Logger logger = Logger(&transform);

    char answer;
    // while(true){
    int stats[kStatesTotal - 1] = {0, 0, 0};
    Game game(&data, &display, &transform, &logger);
    for(int i = 0; i < 500; ++i){
        std::cout << "Start game? (y/n)" << std::endl;
        std::cin >> answer;
        if(answer != 'y')
            break;

        std::cout << "Game number: " << i + 1 << std::endl;
        stats[game.start()]++;
        data.saveDatabase();
    }

    std::cout << "Saving database...\n";
    std::cout << "Database saved. Exiting..\n";
    return 0;
}
