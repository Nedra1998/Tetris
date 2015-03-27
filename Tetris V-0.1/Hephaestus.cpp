#include "Libraries.h"
#include "Logging.h"
#include "Audio.h"
#include "Hephaestus.h"
using namespace std;

GLFWwindow* Hephaestus::Full_Setup(){
	Initilize_Log();
	GLFWwindow* Win = New_Window();
	Create_New_Layer();
	Mouse_Button = -1;
	First = true;
	return(Win);
}
/*>>>>>-----Window-----<<<<<*/
GLFWwindow* Hephaestus::New_Window(){
	GLFWwindow* win = Win.Setup_Window();
	Set_Window(win);
	return(win);
}
void Hephaestus::Frame(){
	double Current_x, Current_y;
	int resx, resy;
	float Change_x, Change_y, Change_x1, Change_y1;
	Win.Frame(Current_Window);
	if (Custom_Cursor == true){
		Win.Window_Res(resx, resy);
		glfwGetCursorPos(Current_Window, &Current_x, &Current_y);
		Current_x = Current_x * 2;
		Current_y = Current_y * 2;
		Change_x = Current_x / resx;
		Change_y = Current_y / resy;
		Change_x = Change_x - 1;
		Change_y = Change_y - 1;
		Change_y = Change_y * -1;
		Current_x = Current_Mouse_X;
		Current_y = Current_Mouse_Y;
		Current_x = Current_x * 2;
		Current_y = Current_y * 2;
		Change_x1 = Current_x / resx;
		Change_y1 = Current_y / resy;
		Change_x1 = Change_x1 - 1;
		Change_y1 = Change_y1 - 1;
		Change_y1 = Change_y1 * -1;
		Change_x = Change_x - Change_x1;
		Change_y = Change_y - Change_y1;
		if (Current_Mouse_X != 0 && Current_Mouse_Y != 0){
			Top.Textured_Objects[0]->Translate_Object(Change_x, Change_y, 0.0);
		}
		glfwGetCursorPos(Current_Window, &Current_x, &Current_y);
		Current_Mouse_X = Current_x;
		Current_Mouse_Y = Current_y;
	}
}
void Hephaestus::Set_Window(GLFWwindow* WIN){
	Current_Window = WIN;
}
void Hephaestus::Set_Custom_Cursor(string Image, float x, float y){
	int resx, resy, posx, posy;
	double Current_x, Current_y;
	Custom_Cursor = true;
	ShowCursor(false);
	Top.Initilize_Object(2);
	Top.Textured_Objects[0]->New_Textured_Object(Image, 4, x, y, 0, 0);
	Win.Window_Res(resx, resy);
	resx = resx / 2;
	resy = resy / 2;
	glfwGetWindowPos(Current_Window, &posx, &posy);
	resx = resx + posx;
	resy = resy + posy;
	SetCursorPos(resx, resy);
	Top.Textured_Objects[0]->Translate_Object(x, -y, 0);
}
/*>>>>>-----Logging-----<<<<<*/
void Hephaestus::Initilize_Log(){
	Logging::Initilize_Log();
}
void Hephaestus::Terminate_Log(){
	Logging::Terminate_Log();
}
/*>>>>>-----User Interface-----<<<<<*/
void Hephaestus::Key_Call_Back(GLFWwindow* Win, int key, int scancode, int action, int mods){
	Key = key;
}
void Hephaestus::Mouse_Call_Back(GLFWwindow* Win, int button, int action, int mods){
	double xpos, ypos;
	glfwGetCursorPos(Win, &xpos, &ypos);
	Mouse_Click_XPos = xpos;
	Mouse_Click_YPos = ypos;
	Mouse_Button = button;
}
int Hephaestus::Check_Key(){
	return(Key);
}
void Hephaestus::Clear_Mouse(){
	Mouse_Click_XPos = 0;
	Mouse_Click_YPos = 0;
}
void Hephaestus::Clear_Key(){
	Key = 0;
}
/*>>>>>-----Layers-----<<<<<*/
/*-----Layer Actions-----*/
void Hephaestus::Display_All_Layers(){
	for (unsigned i = 0; i < Layers.size(); i++){
		Layers[i]->Display_All();
	}
	Top.Display_All();
}
void Hephaestus::Clear_All_Layer_Content(){
	for (unsigned i = 0; i < Layers.size(); i++){
		Layers[i]->Clear_All();
	}
}
void Hephaestus::Clear_All_Layer_Colored(){
	for (unsigned i = 0; i < Layers.size(); i++){
		Layers[i]->Clear_All_Colored_Objects();
	}
}
void Hephaestus::Clear_All_Layer_Textured(){
	for (unsigned i = 0; i < Layers.size(); i++){
		Layers[i]->Clear_All_Textured_Objects();
	}
}
void Hephaestus::Clear_All_Layer_Text(){
	for (unsigned i = 0; i < Layers.size(); i++){
		Layers[i]->Clear_All_Text_Objects();
	}
}
void Hephaestus::Clear_All_Layer_Button(){
	for (unsigned i = 0; i < Layers.size(); i++){
		Layers[i]->Clear_All_Button_Objects();
	}
}
void Hephaestus::Check_All_Buttons(int& Layer, int&Button, int& Action){
	double xpos, ypos;
	int resx, resy;
	float x, y, cx, cy;
	glfwGetCursorPos(Current_Window, &xpos, &ypos);
	Win.Window_Res(resx, resy);
	Current_Mouse_X = xpos;
	Current_Mouse_Y = ypos;
	Action = Mouse_Button;
	Button = -1;
	Layer = -1;
	xpos = xpos * 2;
	ypos = ypos * 2;
	x = xpos / resx;
	y = ypos / resy;
	cx = (Mouse_Click_XPos * 2);
	cy = (Mouse_Click_YPos * 2);
	cx = cx / resx;
	cy = cy / resy;
	x = x - 1;
	y = y - 1;
	y = y * -1;
	cx = cx - 1;
	cy = cy - 1;
	cy = cy * -1;
	for (unsigned i = 0; i < Layers.size(); i++){
		Layers[i]->Check_All_Buttons(Button, x, y, cx, cy);
		if (Button != -1){
			Mouse_Click_XPos = 0;
			Mouse_Click_YPos = 0;
			cx = 0;
			cy = 0;
			Layer = i;
			Mouse_Button = -1;
			break;
		}
	}
}
/*-----Creation/Deletion-----*/
void Hephaestus::Create_New_Layer(){
	Layer* Initilizer = new Layer();
	Layers.push_back(Initilizer);
}
void Hephaestus::Clear_All_Layers(){
	Layers.clear();
	Layer* Temp = new Layer();
	Layers.push_back(Temp);
}
void Hephaestus::Delete_Layer(int Layer_Num){
	Layers.erase(Layers.begin() + Layer_Num);
}
/*-----Movement-----*/
void Hephaestus::Move_Layer_Forward(int Layer_Num){
	Layer* Holder;
	if (Layer_Num > 0){
		Holder = Layers[Layer_Num - 1];
		Layers[Layer_Num - 1] = Layers[Layer_Num];
		Layers[Layer_Num] = Holder;
	}
}
void Hephaestus::Move_Layer_Back(int Layer_Num){
	Layer* Holder;
	if (Layer_Num < Layers.size()){
		Holder = Layers[Layer_Num + 1];
		Layers[Layer_Num + 1] = Layers[Layer_Num];
		Layers[Layer_Num] = Holder;
	}
}
void Hephaestus::Move_Layer_To_Front(int Layer_Num){
	Layer* Holder;
	Holder = Layers[0];
	Layers[0] = Layers[Layer_Num];
	Layers[Layer_Num] = Holder;
}
void Hephaestus::Move_Layer_To_Back(int Layer_Num){
	Layer* Holder;
	Holder = Layers[Layers.size()];
	Layers[Layers.size()] = Layers[Layer_Num];
	Layers[Layer_Num] = Holder;
}
void Hephaestus::Swap_Layer_Positions(int Layer_One, int Layer_Two){
	Layer* Holder;
	Holder = Layers[Layer_One];
	Layers[Layer_One] = Layers[Layer_Two];
	Layers[Layer_Two] = Holder;
}