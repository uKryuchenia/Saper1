#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>
#include <iostream>

MSSFMLView::MSSFMLView(MinesweeperBoard &b): board(b){}

void MSSFMLView::draw(sf::RenderWindow& win){

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout<<"error"<<std::endl;
    }

    if((ilosc_kolmn*ilosc_wierszow)<150) sizX=60;
    if((ilosc_kolmn*ilosc_wierszow)>150 and (ilosc_kolmn*ilosc_wierszow)<550) sizX=30;
    if((ilosc_kolmn*ilosc_wierszow)>550 and (ilosc_kolmn*ilosc_wierszow)<950) sizX=20;

    double width=ilosc_kolmn*sizX; //szerokosc planszy
    double height=ilosc_wierszow*sizX;  //wysokosc planszy

    sf::VertexArray line(sf::LineStrip);
    sf::VertexArray lineY(sf::Lines);
    sf::VertexArray lineX(sf::Lines);
    //zamknieta klatka
    sf::VertexArray quad(sf::Quads, 4);
    //mina
    sf::CircleShape shape;
    //flaga
    sf::RectangleShape lineF;
    sf::VertexArray triangle(sf::Triangles, 3);

    line.append(sf::Vertex(sf::Vector2f(x0, y0), sf::Color(255, 255, 255)));
    line.append(sf::Vertex(sf::Vector2f(x0, height + y0), sf::Color(255, 255, 255)));
    line.append(sf::Vertex(sf::Vector2f(width + x0, height + y0), sf::Color(255, 255, 255)));
    line.append(sf::Vertex(sf::Vector2f(width + x0, y0), sf::Color(255, 255, 255)));
    line.append(sf::Vertex(sf::Vector2f(x0, y0), sf::Color(255, 255, 255)));

    for (double i = x0; i < width + x0; i = i + sizX) {

        lineY.append(sf::Vertex(sf::Vector2f(i, y0), sf::Color(255, 255, 255)));
        lineY.append(sf::Vertex(sf::Vector2f(i, height + y0), sf::Color(255, 255, 255)));
    }

    for (double j = y0; j < height + y0; j = j + sizX) {

        lineX.append(sf::Vertex(sf::Vector2f(x0, j), sf::Color(255, 255, 255)));
        lineX.append(sf::Vertex(sf::Vector2f(width + x0, j), sf::Color(255, 255, 255)));
    }

    win.draw(line);
    win.draw(lineY);
    win.draw(lineX);

    if(board.getGameState()==0){


    for (int i = 0; i < ilosc_kolmn; i++) {
        for (int j = 0; j < ilosc_wierszow; j++) {

            char stan;
            stan = board.getFieldInfo(i, j);

            if (stan == '_') { //zamknieta

                int kwadr = (sizX - (sizX / 4.5)); //wplywa na rozmiar kwadratu
                int x = (x0 + i * sizX) + (sizX / 10); //odstep od krawedzi
                int y = (y0 + j * sizX) + (sizX / 10);
                quad.append(sf::Vertex(sf::Vector2f(x, y), sf::Color(1, 184, 184)));
                quad.append(sf::Vertex(sf::Vector2f(x + kwadr, y), sf::Color(1, 184, 184)));
                quad.append(sf::Vertex(sf::Vector2f(x + kwadr, y + kwadr), sf::Color(1, 184, 184)));
                quad.append(sf::Vertex(sf::Vector2f(x, y + kwadr), sf::Color(1, 184, 184)));
                win.draw(quad);
            }

            if (stan == 'x') {  //otwarte pole z miną

                int okrag = sizX / 2.5; //rozmiar promienia okraga
                int x = (x0 + i * sizX) + (sizX / 10); //odstep od krawedzi
                int y = (y0 + j * sizX) + (sizX / 10);

                shape.setFillColor(sf::Color(255, 0, 0));
                shape.setRadius(okrag);
                shape.setPosition(x, y);
                win.draw(shape);
            }

            if (stan == 'F') { //flaga

                int flagaSz = sizX / 10; //szerokosc flagi
                int flagaWy = sizX - sizX / 7; //wysokosc flagi

                int x = (x0 + i * sizX) + (sizX / 3); //odstep od krawedzi
                int y = (y0 + j * sizX) + (sizX / 15);

                lineF.setSize(sf::Vector2f(flagaWy, flagaSz));
                lineF.setRotation(90);
                lineF.setPosition(x,y);

                triangle.append(sf::Vertex(sf::Vector2f(x, y), sf::Color(250, 0, 0)));
                triangle.append(sf::Vertex(sf::Vector2f((x+(sizX*0.6)), (y+(sizX*0.2))), sf::Color(250, 0, 0)));
                triangle.append(sf::Vertex(sf::Vector2f(x, y+(sizX*0.4)), sf::Color(250, 0, 0)));

                win.draw(triangle);
                win.draw(lineF);


            }

            if (stan == '1') {

                int x = (x0 + i * sizX) + (sizX / 5); //odstep od krawedzi
                int y = (y0 + j * sizX);


                text.setFont(font);
                text.setString("1");
                text.setPosition(x,y);

                text.setCharacterSize(sizX*0.8);
                text.setColor(sf::Color::Green);

                win.draw(text);
            }

            if (stan == '2') {

                int x = (x0 + i * sizX) + (sizX / 5); //odstep od krawedzi
                int y = (y0 + j * sizX);


                text.setFont(font);
                text.setString("2");
                text.setPosition(x,y);

                text.setCharacterSize(sizX*0.8);
                text.setColor(sf::Color::Green);

                win.draw(text);
            }

            if (stan == '3') {

                int x = (x0 + i * sizX) + (sizX / 5); //odstep od krawedzi
                int y = (y0 + j * sizX);


                text.setFont(font);
                text.setString("3");
                text.setPosition(x,y);

                text.setCharacterSize(sizX*0.8);
                text.setColor(sf::Color::Green);

                win.draw(text);
            }

            if (stan == '4') {

                int x = (x0 + i * sizX) + (sizX / 5); //odstep od krawedzi
                int y = (y0 + j * sizX);


                text.setFont(font);
                text.setString("4");
                text.setPosition(x,y);

                text.setCharacterSize(sizX*0.8);
                text.setColor(sf::Color::Green);

                win.draw(text);
            }

            if (stan == '5') {

                int x = (x0 + i * sizX) + (sizX / 5); //odstep od krawedzi
                int y = (y0 + j * sizX);


                text.setFont(font);
                text.setString("5");
                text.setPosition(x,y);

                text.setCharacterSize(sizX*0.8);
                text.setColor(sf::Color::Green);

                win.draw(text);
            }

            if (stan == '6') {

                int x = (x0 + i * sizX) + (sizX / 5); //odstep od krawedzi
                int y = (y0 + j * sizX);


                text.setFont(font);
                text.setString("6");
                text.setPosition(x,y);

                text.setCharacterSize(sizX*0.8);
                text.setColor(sf::Color::Green);

                win.draw(text);
            }

            if (stan == '7') {

                int x = (x0 + i * sizX) + (sizX / 5); //odstep od krawedzi
                int y = (y0 + j * sizX);


                text.setFont(font);
                text.setString("7");
                text.setPosition(x,y);

                text.setCharacterSize(sizX*0.8);
                text.setColor(sf::Color::Green);

                win.draw(text);
            }

            if (stan == '8') {

                int x = (x0 + i * sizX) + (sizX / 5); //odstep od krawedzi
                int y = (y0 + j * sizX);


                text.setFont(font);
                text.setString("8");
                text.setPosition(x,y);

                text.setCharacterSize(sizX*0.8);
                text.setColor(sf::Color::Green);

                win.draw(text);
            }

         }
    }
    }
    if(board.getGameState()==2){

        for (int i = 0; i < ilosc_kolmn; i++) {
            for (int j = 0; j < ilosc_wierszow; j++) {
            board.revealField(i, j);
            if (board.getFieldInfo(i, j) == 'x') {  //otwarte pole z miną

                int okrag = sizX / 2.5; //rozmiar promienia okraga
                int x = (x0 + i * sizX) + (sizX / 10); //odstep od krawedzi
                int y = (y0 + j * sizX) + (sizX / 10);

                shape.setFillColor(sf::Color(255, 0, 0));
                shape.setRadius(okrag);
                shape.setPosition(x, y);
                win.draw(shape);
            }
    }
}

                text.setFont(font);
                text.setString("GAME OVER");
                text.setPosition(height+100,x0);
                text.setCharacterSize(sizX);
                text.setColor(sf::Color::Red);

                win.draw(text);
}
    if(board.getGameState()==1){

                win.clear();
                text.setFont(font);
                text.setString("YOU WIN");
                text.setPosition(100,x0);
                text.setCharacterSize(sizX);
                text.setColor(sf::Color::Green);

                win.draw(text);
    }
}

double MSSFMLView::getSizX() const{

    return sizX;

}
