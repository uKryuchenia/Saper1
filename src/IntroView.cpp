#include "IntroView.h"
#include <cstdlib> // abort()


IntroView::IntroView() {}

void IntroView::draw(sf::RenderWindow &window) {

	sf::Texture menuTexture1, menuTexture2, menuTexture3, menuTexture4, menuTexture5, menuTexture6, menuTexture7,menuTexture8, menuTexture9;

    menuTexture1.loadFromFile("images/easy.png");
	menuTexture2.loadFromFile("images/normal.png");
	menuTexture3.loadFromFile("images/hard.png");
    menuTexture4.loadFromFile("images/debug.png");
	menuTexture5.loadFromFile("images/10.png");
	menuTexture6.loadFromFile("images/20.png");
	menuTexture7.loadFromFile("images/30.png");
	menuTexture8.loadFromFile("images/play.png");
	menuTexture9.loadFromFile("images/exit.png");

	sf::Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menu4(menuTexture4), menu5(menuTexture5), menu6(menuTexture6),menu7(menuTexture7),menu8(menuTexture8), menu9(menuTexture9);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 150);
	menu2.setPosition(300, 150);
	menu3.setPosition(500, 150);
	menu4.setPosition(700, 150);
	menu5.setPosition(100, 300);
	menu6.setPosition(300, 300);
	menu7.setPosition(500, 300);
	menu8.setPosition(100, 450);
	menu9.setPosition(300, 450);


	//////////////////////////////menu///////////////////
	while (isMenu)
	{
		menu1.setColor(sf::Color::White);
		menu2.setColor(sf::Color::White);
		menu3.setColor(sf::Color::White);
		menu4.setColor(sf::Color::White);
		menu5.setColor(sf::Color::White);
		menu6.setColor(sf::Color::White);
		menu7.setColor(sf::Color::White);
		menu8.setColor(sf::Color::White);
		menu9.setColor(sf::Color::White);
		menuNum = 0;
		window.clear(sf::Color(129, 181, 221));

		if (sf::IntRect(150, 150, 100, 70).contains(sf::Mouse::getPosition(window))) { menu1.setColor(sf::Color::Blue); menuNum = 1; }
		if (sf::IntRect(350, 150, 100, 70).contains(sf::Mouse::getPosition(window))) { menu2.setColor(sf::Color::Blue); menuNum = 2; }
		if (sf::IntRect(550, 150, 100, 70).contains(sf::Mouse::getPosition(window))) { menu3.setColor(sf::Color::Blue); menuNum = 3; }
        if (sf::IntRect(750, 150, 100, 70).contains(sf::Mouse::getPosition(window))) { menu4.setColor(sf::Color::Blue); menuNum = 4; }
		if (sf::IntRect(150, 300, 100, 70).contains(sf::Mouse::getPosition(window))) { menu5.setColor(sf::Color::Blue); menuNum = 5; }
		if (sf::IntRect(350, 300, 100, 70).contains(sf::Mouse::getPosition(window))) { menu6.setColor(sf::Color::Blue); menuNum = 6; }
        if (sf::IntRect(550, 300, 100, 70).contains(sf::Mouse::getPosition(window))) { menu7.setColor(sf::Color::Blue); menuNum = 7; }
		if (sf::IntRect(150, 450, 100, 70).contains(sf::Mouse::getPosition(window))) { menu8.setColor(sf::Color::Blue); menuNum = 8; }
		if (sf::IntRect(350, 450, 100, 70).contains(sf::Mouse::getPosition(window))) { menu9.setColor(sf::Color::Blue); menuNum = 9; }

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1) {  }
			if (menuNum == 2) { }
			if (menuNum == 9)  { window.close(); isMenu = false; } //если нажали первую кнопку, то выходим из меню

		}

	}

		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(menu4);
		window.draw(menu5);
		window.draw(menu6);
		window.draw(menu7);
		window.draw(menu8);
		window.draw(menu9);

		window.display();
}
