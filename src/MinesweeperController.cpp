#include "MinesweeperController.h"
#include <iostream>

MinesweeperController::MinesweeperController(MSSFMLView &v) :view(v)
{}

void MinesweeperController::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            finished = true;
            std::cout << " PROBEL "<< std::endl;
        }
    }
   // if(finished) std::cout << " PROBEL "<< std::endl;
}
