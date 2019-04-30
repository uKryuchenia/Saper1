#ifndef MINESWEEPERCONTROLLER_H
#define MINESWEEPERCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"
#include<MinesweeperBoard.h>

class MinesweeperController {
    bool finished = false;

    MSSFMLView & view;
    // ... & model;
public:
    explicit MinesweeperController(MSSFMLView & v);
public:
    void handleEvent(sf::Event &event);

    // no need to change this
    void draw (sf::RenderWindow & win) { view.draw(win); }
    bool isFinished() const { return finished;}
};



#endif // MINESWEEPERCONTROLLER_H
