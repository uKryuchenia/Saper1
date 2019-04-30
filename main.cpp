#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <MSBoardTextView.h>
#include <MinesweeperBoard.h>
#include <MSSFMLView.h>
#include <MinesweeperController.h>
#include <IntroView.h>

using namespace std;


int main()
{

    srand (time(NULL));
    /*
        GameMode mode;

        int modeZ=0;
        cout << "Tryb gry\nEASY   - 1\nNormal - 2\nHARD   - 3\nDebug  - 4 "<< endl;
        cin >> modeZ;

        switch(modeZ){
        case 1: {mode=EASY;break;}
        case 2: {mode=NORMAL;break;}
        case 3: {mode=HARD;break;}
        case 4: {mode=DEBUG;break;}

        }

        int fieldBoard=0,x=0,y=0;
        cout << "Rozmiar pola\n10x10 - 1\n20x20 - 2\n30x30 - 3"<< endl;
        cin >> fieldBoard;

        switch(fieldBoard){
        case 1: {x=10;y=10;break;}
        case 2: {x=20;y=20;break;}
        case 3: {x=30;y=30;break;}
        }
    */
    MinesweeperBoard board(3,3,DEBUG);

    // Create the main window
    sf::RenderWindow window(sf::VideoMode( 1280, 720), "SAPER");

    MSSFMLView view (board);
    /*
        IntroView intro;
        intro.draw(window);
    */
    board.debug_display();

    cout << "Wsego min = " << board.countAllMines();

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();


            if (event.type == sf::Event::MouseButtonPressed)
            {
                int wiersz=0, kolumna=0;
                int sizY = view.getSizX();

                int kolumnaP =(event.mouseButton.x - 50);
                int wierszP =(event.mouseButton.y - 50);

                for(wiersz ; wierszP>sizY ; wiersz++)
                {
                    wierszP-=sizY;
                }
                for(kolumna; kolumnaP>sizY ; kolumna++)
                {
                    kolumnaP-=sizY;
                }

                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    board.revealField(kolumna, wiersz);
                    if(board.countMines(kolumna, wiersz)==0)
                    {
                        for(int j=wiersz-1; j<=wiersz+1; j++)
                        {
                            for(int i=kolumna-1; i<=kolumna+1; i++)
                            {
                                board.revealField(i, j);
                            }
                        }
                    }
                }
                else if (event.mouseButton.button == sf::Mouse::Right)
                {

                    if(board.hasFlag(kolumna, wiersz))
                        board.deleteFlag(kolumna, wiersz);
                    else
                        board.toggleFlag(kolumna, wiersz);

                    cout << "x ";
                }
            }
        }// GAME sterownik od   // Process events

        // Clear screen
        window.clear();

        view.draw(window);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;

}


