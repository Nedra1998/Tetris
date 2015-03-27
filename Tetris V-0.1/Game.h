#include "Libraries.h"
#include "Logging.h"

class Game{
private:
	/*-----Variables-----*/
	int Score, Level, Speed_Set, True_Speed, New_Score, Total_Lines, New_Lines;
	float Tic_Shift;
	string Name;
	bool Game_Good, Quit;
	GLFWwindow* window;
	int Grid[10][20];
	int Game_Type, Current_Object, Current_Type;
	/*-----Functions-----*/
	bool Classic_Game();
	bool Insane_Game();
	bool Endless_Game();
	void Save_Score();
	void Close();
	void Genorate_Shape();
	bool Fall_Shape();
	bool Shift(int direction);
	bool Rotate();
	void Set_Grid();
	void Clear_Line();
	void Remove(int Number);
	void Shift_All();
	void Pause();
	char Key(int key);
public:
	bool Games;
	Hephaestus Main;
	void Initilize_Game(int Type, Hephaestus Declaration, GLFWwindow* Win);
};