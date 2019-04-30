#ifndef MSSFMLVIEW_H
#define MSSFMLVIEW_H

#include <SFML/Graphics.hpp>
#include<MinesweeperBoard.h>

class MSSFMLView{

    MinesweeperBoard &board;

    sf::Clock clk;
    sf::Font font;
    sf::Text text;

    int x0=50; //odstep od (0,0)
    int y0=50; //odstep od (0,0)

    int ilosc_kolmn=board.getBoardWidth();
    int ilosc_wierszow=board.getBoardHeight();
    double sizX=0; //rozmiar klatki



public:
    MSSFMLView(MinesweeperBoard &b);
    void draw(sf::RenderWindow &win);
    double getSizX() const;
};

#endif // MSSFMLVIEW_H
