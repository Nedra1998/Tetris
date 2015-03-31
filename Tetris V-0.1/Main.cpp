#include "Libraries.h"
#include "Hephaestus.h"
#include "Logging.h"
#include "Game.h"
using namespace std;
Hephaestus H;
GLFWwindow* Win;
Game G;
struct Shape{
	int a, b, c, d;
};
vector <Shape> Falling;
int Current = 0;
string Texture_Pack;
void Create_Block();
bool Texture_Check(string Texture);
void Key_Call(GLFWwindow* Win, int key, int scancode, int action, int mods){
	H.Key_Call_Back(Win, key, scancode, action, mods);
	if (G.Games == true){
		G.Main.Key_Call_Back(Win, key, scancode, action, mods);
	}
}
void Mouse_Call(GLFWwindow* Win, int button, int action, int mods){
	H.Mouse_Call_Back(Win, button, action, mods);
	if (G.Games == true){
		G.Main.Mouse_Call_Back(Win, button, action, mods);
	}
}
void Window_Call(GLFWwindow* Win, int width, int hight){
	glfwSetWindowSize(Win, width, hight);
}
int main(){
	GLFWwindow* Win;
	Win = H.Full_Setup();
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwSetKeyCallback(Win, Key_Call);
	glfwSetMouseButtonCallback(Win, Mouse_Call);
	glfwSetWindowSizeCallback(Win, Window_Call);
	srand(time(NULL));
	/*>>>>>Place Before Start Code Here<<<<<*/
	int Stage = 0, Temp = 0;
	bool First = true;
	int Layer = -1, Button = -1, Action = -1, I = 0, F = 0, Update = 0;
	string Highscores[5], Line, Resolutions[7];
	bool Enter = false;
	ifstream Settings("Game Settings.txt");
	if (Settings.is_open()){
		getline(Settings, Texture_Pack);
		Settings.close();
	}
	H.Set_Custom_Cursor("Textures/" + Texture_Pack + "/Arrow", 0.05, 0.05);
	while (!glfwWindowShouldClose(Win)){
		/*>>>>>Place While Running Code Here<<<<<*/
		if (First == true){
			H.Clear_All_Layers();
			First = false;
			Current = 0;
			Falling.clear();
			Layer = -1;
			Button = -1;
			Action = -1;
			Update = 10;
			if (Stage == 0){
				H.Create_New_Layer();
				H.Create_New_Layer();
				H.Layers[0]->Initilize_Object(2);
				H.Layers[0]->Textured_Objects[0]->New_Textured_Object("Textures/" + Texture_Pack + "/Background Game", 4, 1, 1, 0, 0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[0]->New_Button("Play", "Textures/" + Texture_Pack + "/Button", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[0]->Translate_Button(0.0, 0.2, 0.0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[1]->New_Button("High Scores", "Textures/" + Texture_Pack + "/Button", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[1]->Translate_Button(0.0, -0.1, 0.0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[2]->New_Button("Settings", "Textures/" + Texture_Pack + "/Button", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[2]->Translate_Button(0.0, -0.4, 0.0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[3]->New_Button("Quit", "Textures/" + Texture_Pack + "/Button", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[3]->Translate_Button(0.0, -0.7, 0.0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[4]->New_Button("TETRIS", "Textures/" + Texture_Pack + "/ButtonB", "Special", 0.5, 0.2);
				H.Layers[2]->Button_Objects[4]->Translate_Button(0.0, 0.7, 0.0);
			}
			if (Stage == 1){
				H.Create_New_Layer();
				H.Create_New_Layer();
				H.Layers[0]->Initilize_Object(2);
				H.Layers[0]->Textured_Objects[0]->New_Textured_Object("Textures/" + Texture_Pack + "/Background Game", 4, 1, 1, 0, 0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[5]->New_Button("Back", "Textures/" + Texture_Pack + "/Button", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[5]->Translate_Button(0.0, -0.8, 0.0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[6]->New_Button("TETRIS", "Textures/" + Texture_Pack + "/ButtonB", "Special", 0.5, 0.2);
				H.Layers[2]->Button_Objects[6]->Translate_Button(0.0, 0.7, 0.0);
				ifstream Scores("HighScores.Scores");
				if (Scores.is_open()){
					while(getline(Scores, Line)){
						Highscores[Temp] = Line;
						Temp++;
					}
					Scores.close();
				}
				Temp = 0;
				H.Layers[2]->Button_Objects[0]->New_Button(Highscores[0], "Textures/" + Texture_Pack + "/ButtonB", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[1]->New_Button(Highscores[1], "Textures/" + Texture_Pack + "/ButtonB", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[2]->New_Button(Highscores[2], "Textures/" + Texture_Pack + "/ButtonB", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[3]->New_Button(Highscores[3], "Textures/" + Texture_Pack + "/ButtonB", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[4]->New_Button(Highscores[4], "Textures/" + Texture_Pack + "/ButtonB", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[0]->Translate_Button(0.0, 0.3, 0.0);
				H.Layers[2]->Button_Objects[1]->Translate_Button(0.0, 0.1, 0.0);
				H.Layers[2]->Button_Objects[2]->Translate_Button(0.0, -0.1, 0.0);
				H.Layers[2]->Button_Objects[3]->Translate_Button(0.0, -0.3, 0.0);
				H.Layers[2]->Button_Objects[4]->Translate_Button(0.0, -0.5, 0.0);
			}
			if (Stage == 2){
				ifstream Res("Resolutions.txt");
				if (Res.is_open()){
					while (getline(Res, Line)){
						Resolutions[Temp] = Line;
						Temp++;
					}
				}
				Temp = 0;
				I = H.Win.Get_Window_Size(1);
				F = H.Win.Get_Window_Size(2);
				I = I - 1;
				H.Create_New_Layer();
				H.Create_New_Layer();
				H.Layers[0]->Initilize_Object(2);
				H.Layers[0]->Textured_Objects[0]->New_Textured_Object("Textures/" + Texture_Pack + "/Background Game", 4, 1, 1, 0, 0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[0]->New_Button("TETRIS", "Textures/" + Texture_Pack + "/ButtonB", "Special", 0.5, 0.2);
				H.Layers[2]->Button_Objects[0]->Translate_Button(0.0, 0.7, 0.0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[1]->New_Button("Resolution", "Textures/" + Texture_Pack + "/Transparent", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[1]->Translate_Button(0.0, 0.4, 0.0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[2]->New_Button(Resolutions[I], "Textures/" + Texture_Pack + "/Button", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[2]->Translate_Button(0.0, 0.23, 0.0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[3]->New_Button("Full Screen", "Textures/" + Texture_Pack + "/Transparent", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[3]->Translate_Button(0.0, 0.0, 0.0);
				H.Layers[2]->Initilize_Object(4);
				if (F == 0){
					Line = " ";
				}
				else if (F == 1){
					Line = "X";
				}
				H.Layers[2]->Button_Objects[4]->New_Button(Line, "Textures/" + Texture_Pack + "/Button", "Basic/Black", 0.1, 0.1);
				H.Layers[2]->Button_Objects[4]->Translate_Button(0.0, -0.16, 0.0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[5]->New_Button("Texture Pack", "Textures/" + Texture_Pack + "/Transparent", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[5]->Translate_Button(0.0, -0.35, 0.0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[6]->New_Button(Texture_Pack, "Textures/" + Texture_Pack + "/Button", "Basic/Black", 0.7, 0.1);
				H.Layers[2]->Button_Objects[6]->Translate_Button(0.0, -0.51, 0.0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[7]->New_Button("Back", "Textures/" + Texture_Pack + "/Button", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[7]->Translate_Button(0.0, -0.8, 0.0);
			}
			if (Stage == 3){
				H.Create_New_Layer();
				H.Create_New_Layer();
				H.Layers[0]->Initilize_Object(2);
				H.Layers[0]->Textured_Objects[0]->New_Textured_Object("Textures/" + Texture_Pack + "/Background Game", 4, 1, 1, 0, 0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[0]->New_Button("Classic", "Textures/" + Texture_Pack + "/Button", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[0]->Translate_Button(0.0, 0.2, 0.0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[1]->New_Button("Insane", "Textures/" + Texture_Pack + "/Button", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[1]->Translate_Button(0.0, -0.1, 0.0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[2]->New_Button("Endless", "Textures/" + Texture_Pack + "/Button", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[2]->Translate_Button(0.0, -0.4, 0.0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[3]->New_Button("Back", "Textures/" + Texture_Pack + "/Button", "Basic/Black", 0.5, 0.1);
				H.Layers[2]->Button_Objects[3]->Translate_Button(0.0, -0.7, 0.0);
				H.Layers[2]->Initilize_Object(4);
				H.Layers[2]->Button_Objects[4]->New_Button("TETRIS", "Textures/" + Texture_Pack + "/ButtonB", "Special", 0.5, 0.2);
				H.Layers[2]->Button_Objects[4]->Translate_Button(0.0, 0.7, 0.0);
			}
		}
		if ((rand() % 45) == 1){
			Create_Block();
		}
		for (unsigned i = 0; i < Falling.size(); i++){
			H.Layers[1]->Textured_Objects[Falling[i].a]->Translate_Object(0.0, -0.02, 0.0);
			H.Layers[1]->Textured_Objects[Falling[i].b]->Translate_Object(0.0, -0.02, 0.0);
			H.Layers[1]->Textured_Objects[Falling[i].c]->Translate_Object(0.0, -0.02, 0.0);
			H.Layers[1]->Textured_Objects[Falling[i].d]->Translate_Object(0.0, -0.02, 0.0);
		}
		if (Update > 0){
			Update--;
			H.Clear_Mouse();
		}
		if (Update == 0){
			H.Check_All_Buttons(Layer, Button, Action);
		}
		if (Stage == 0){
			if (Layer == 2 && Button == 0 && Action == 0){
				Stage = 3;
				First = true;
			}
			if (Layer == 2 && Button == 1 && Action == 0){
				Stage = 1;
				First = true;
			}
			if (Layer == 2 && Button == 2 && Action == 0){
				Stage = 2;
				First = true;
			}
			if (Layer == 2 && Button == 3 && Action == 0){
				glfwSetWindowShouldClose(Win, 1);
			}
		}
		else if (Stage == 1){
			if (Layer == 2 && Button == 5 && Action == 0){
				Stage = 0;
				First = true;
			}
		}
		else if (Stage == 2){
			if (Layer == 2 && Button == 7 && Action == 0){
				Stage = 0;
				First = true;
			}
			if (Layer == 2 && Button == 2 && Action == 0){
				I++;
				if (I == 7){
					I = 0;
				}
				H.Win.Set_Window(I + 1, F);
				First = true;
			}
			if (Layer == 2 && Button == 2 && Action == 1){
				I--;
				if (I == -1){
					I = 6;
				}
				H.Win.Set_Window(I + 1, F);
				First = true;
			}
			if (Layer == 2 && Button == 4 && Action == 0){
				if (F == 0){
					F = 1;
				}
				else if (F == 1){
					F = 0;
				}
				H.Win.Set_Window(I + 1, F);
				First = true;
			}
			if (Layer == 2 && Button == 6 && Action == 0){
				string New = "";
				Enter = true;
				H.Layers[2]->Button_Objects[6]->Edit_Button(New);
				while (Enter == true){
					if (Update > 0){
						Update--;
						H.Clear_Key();
					}
					if (H.Check_Key() < 97 && H.Check_Key() > 31 && Update == 0){
						New = New + char(H.Check_Key());
						Update = 10;
						H.Layers[2]->Button_Objects[6]->Edit_Button(New);
					}
					if (glfwGetKey(Win, GLFW_KEY_BACKSPACE) && Update == 0){
						string Temp = "";
						for (int i = 0; i < New.size() - 1 && New.size() > 0; i++){
							Temp = Temp + New[i];
						}
						New = Temp;
						Update = 5;
						H.Layers[2]->Button_Objects[6]->Edit_Button(New);
					}
					if (glfwGetKey(Win, GLFW_KEY_ENTER)){
						if (New == "" || New == " "){
							New = Texture_Pack;
						}
						if (Texture_Check(New) == true){
							Texture_Pack = New;
							ofstream Out("Game Settings.txt");
							if (Out.is_open()){
								Out << Texture_Pack;
								Out.close();
							}
							else{
								cout << "Nope?\n";
							}
						}
						else{
							Logging::log_information("Entered Invalid Texture Pack Location", "Texture Pack Selection");
						}
						Enter = false;
						H.Layers[2]->Button_Objects[6]->Edit_Button(New);
					}
					if (glfwGetKey(Win, GLFW_KEY_ESCAPE)){
						Enter = false;
						H.Layers[2]->Button_Objects[6]->Edit_Button(New);
					}
					H.Display_All_Layers();
					H.Frame();
				}
			}
		}
		else if (Stage == 3){
			if (Layer == 2 && Button == 0 && Action == 0){
				H.Clear_All_Layers();
				G.Initilize_Game(1, H, Win, Texture_Pack);
				First = true;
				H = G.Main;
			}
			if (Layer == 2 && Button == 1 && Action == 0){
				H.Clear_All_Layers();
				G.Initilize_Game(2, H, Win, Texture_Pack);
				First = true;
			}
			if (Layer == 2 && Button == 2 && Action == 0){
				H.Clear_All_Layers();
				G.Initilize_Game(3, H, Win, Texture_Pack);
				First = true;
			}
			if (Layer == 2 && Button == 3 && Action == 0){
				Stage = 0;
				First = true;
			}
		}
		H.Display_All_Layers();
		H.Frame();
	}
	H.Terminate_Log();
	return(0);
}
void Create_Block(){
	float x;
	Shape Temp;
	int Block;
	float x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
	string Texture = "Textures/" + Texture_Pack + "/Block ", Point;
	Block = (rand() % 7);
	Block = Block + 1;
	if (Block == 1){
		Texture = Texture + "1";
	}
	else if (Block == 2 || Block == 3){
		Texture = Texture + "2";
	}
	else if (Block == 4){
		Texture = Texture + "3";
	}
	else if (Block == 5){
		Texture = Texture + "4";
	}
	else if (Block == 6){
		Texture = Texture + "5";
	}
	else if (Block == 7){
		Texture = Texture + "6";
	}
	Point = to_string(Block) + ".Shape";
	ifstream Points(Point);
	if (Points.is_open()){
		Points >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		Points.close();
	}
	H.Layers[1]->Initilize_Object(2);
	H.Layers[1]->Initilize_Object(2);
	H.Layers[1]->Initilize_Object(2);
	H.Layers[1]->Initilize_Object(2);
	H.Layers[1]->Textured_Objects[Current]->New_Textured_Object(Texture, 4, 0.05, 0.05, 0, 0);
	H.Layers[1]->Textured_Objects[Current + 1]->New_Textured_Object(Texture, 4, 0.05, 0.05, 0, 0);
	H.Layers[1]->Textured_Objects[Current + 2]->New_Textured_Object(Texture, 4, 0.05, 0.05, 0, 0);
	H.Layers[1]->Textured_Objects[Current + 3]->New_Textured_Object(Texture, 4, 0.05, 0.05, 0, 0);
	H.Layers[1]->Textured_Objects[Current]->Translate_Object(x1, y1, 0.0);
	H.Layers[1]->Textured_Objects[Current + 1]->Translate_Object(x2, y2, 0.0);
	H.Layers[1]->Textured_Objects[Current + 2]->Translate_Object(x3, y3, 0.0);
	H.Layers[1]->Textured_Objects[Current + 3]->Translate_Object(x4, y4, 0.0);
	Temp.a = Current;
	Temp.b = Current + 1;
	Temp.c = Current + 2;
	Temp.d = Current + 3;
	Falling.push_back(Temp);
	x = rand() % 200;
	x = x - 100;
	x = x / 100;
	for (int a = Current; a < Current + 4; a++){
		H.Layers[1]->Textured_Objects[a]->Translate_Object(x, 1.3, 0.0);
	}
	Current = Current + 4;
}
bool Texture_Check(string Texture) {
	Texture = "Textures/" + Texture + "/Arrow.tga";
	cout << Texture << endl;
	ifstream f(Texture.c_str());
	if (f.good()) {
		f.close();
		return true;
	}
	else {
		f.close();
		return false;
	}
}