#include "Libraries.h"
#include "Window.h"
#include "Layer.h"
using namespace std;
class Hephaestus{
private:
	GLFWwindow* Current_Window;
	int Mouse_Click_XPos, Mouse_Click_YPos, Current_Mouse_X, Current_Mouse_Y, Mouse_Button, Key;
	bool Custom_Cursor, First;
	Layer Top;
public:
	/*----->>>>>Declarations<<<<<-----*/
	vector<Layer*> Layers;
	Window Win;
	/*----->>>>>FUNCTIONS<<<<<-----*/
	/*-----Window-----*/
	GLFWwindow* Full_Setup();
	GLFWwindow* New_Window();
	void Frame();
	void Set_Window(GLFWwindow* WIN);
	void Set_Custom_Cursor(string Image, float x, float y);
	/*-----Logging-----*/
	void Initilize_Log();
	void Terminate_Log();
	/*-----User Input-----*/
	void Key_Call_Back(GLFWwindow* Win, int key, int scancode, int action, int mods);
	void Mouse_Call_Back(GLFWwindow* Win, int button, int action, int mods);
	int Check_Key();
	void Clear_Mouse();
	void Clear_Key();
	/*-----Layers-----*/
	/*>>Layer Actions<<*/
	void Display_All_Layers();
	void Clear_All_Layer_Content();
	void Clear_All_Layer_Colored();
	void Clear_All_Layer_Textured();
	void Clear_All_Layer_Text();
	void Clear_All_Layer_Button();
	void Check_All_Buttons(int& Layer, int&Button, int& Action);
	/*>>Creation/Deletion<<*/
	void Create_New_Layer();
	void Clear_All_Layers();
	void Delete_Layer(int Layer_Num);
	/*>>Movement<<*/
	void Move_Layer_Forward(int Layer_Num);
	void Move_Layer_Back(int Layer_Num);
	void Move_Layer_To_Front(int Layer_Num);
	void Move_Layer_To_Back(int Layer_Num);
	void Swap_Layer_Positions(int Layer_One, int Layer_Two);
};