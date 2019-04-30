#ifndef INTROVIEW_H
#define INTROVIEW_H

#include <SFML/Graphics.hpp>

class IntroView {
    sf::RectangleShape rect;
    sf::Font font;
    sf::Text txt;
public:

    IntroView();
    void draw(sf::RenderWindow &win);
};


#endif // INTROVIEW_H
