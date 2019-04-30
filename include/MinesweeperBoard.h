#ifndef MINESWEEPERBOARD_H
#define MINESWEEPERBOARD_H


enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };


struct Field
{
	bool hasMine;
	bool hasFlag;
	bool isRevealed;
};

class MinesweeperBoard
{
    Field board[100][100];
    int width;
    int height;
    int step=0;

private:

    void fillMenes(int w, int h, GameMode mode);
    bool isRevealedWithMine() const;
    bool isClosedWithMine() const;
    bool flagWithMine() const;

public:


    GameState state=RUNNING;
    MinesweeperBoard(int w, int h, GameMode mode );
    void debug_display() const;


    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    bool isRevealed(int x, int y) const;

    int countAllMines() const;
    int countMines(int x, int y) const;
    bool hasFlag(int x, int y) const;
    void toggleFlag(int x, int y);
    void deleteFlag(int x, int y);

    void revealField(int x, int y);
    GameState getGameState() const;

    char getFieldInfo(int x, int y) const;

};


#endif // MINESWEEPERBOARD_H
