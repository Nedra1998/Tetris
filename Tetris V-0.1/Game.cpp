#include "Libraries.h"
#include "Logging.h"
#include "Hephaestus.h"
#include "Game.h"

using namespace std;
void Game::Initilize_Game(int Type, Hephaestus Declaration, GLFWwindow* Win, string Texture){
	Games = true;
	Current_Object = 0;
	Main = Declaration;
	Game_Type = Type;
	Game_Good = true;
	Quit = false;
	window = Win;
	Score = 0;
	New_Score = 0;
	Level = 0;
	Total_Lines = 0;
	New_Lines = 0;
	Set_Grid();
	Texture_Pack = Texture;
	if (Game_Type == 1 || Game_Type == 2){
		Classic_Game();
	}
	if (Game_Type == 3){
		Endless_Game();
	}
}

void Game::Save_Score(){
	string Saved[2][6], Tempstr;
	int High_Scores[6], Tempint;
	ifstream Scores("HighScores.Scores");
	if (Scores.is_open()){
		Scores >> Saved[0][0] >> Saved[1][0];
		Scores >> Saved[0][1] >> Saved[1][1];
		Scores >> Saved[0][2] >> Saved[1][2];
		Scores >> Saved[0][3] >> Saved[1][3];
		Scores >> Saved[0][4] >> Saved[1][4];
		Scores.close();
	}
	stringstream Stream;
	for (int a = 0; a < 5; a++){
		Stream << Saved[1][a];
		Stream >> High_Scores[a];
		Stream.str("");
		Stream.clear();
	}
	High_Scores[5] = Score;
	Saved[0][5] = Name;
	for (int a = 6; a > 0; a--){
		if (High_Scores[a] > High_Scores[a - 1]){
			Tempint = High_Scores[a - 1];
			High_Scores[a - 1] = High_Scores[a];
			High_Scores[a] = Tempint;
			Tempstr = Saved[0][a - 1];
			Saved[0][a - 1] = Saved[0][a];
			Saved[0][a] = Tempstr;
		}
	}
	ofstream Saving("HighScores.Scores");
	if (Saving.is_open()){
		for (int a = 0; a < 5; a++){
			Saving << Saved[0][a] << " " << High_Scores[a] << "\n";
		}
		Saving.close();
	}
}

void Game::Close(){
	if (glfwWindowShouldClose(window)){
		Game_Good = false;
		Quit = true;
	}
}

void Game::Genorate_Shape(){
	int Object = 0, X, Y;
	string Texture = "Textures/" + Texture_Pack + "/Block ";
	if (Game_Type == 1 || Game_Type == 3){
		Main.Layers[2]->Initilize_Object(2);
		Main.Layers[2]->Initilize_Object(2);
		Main.Layers[2]->Initilize_Object(2);
		Main.Layers[2]->Initilize_Object(2);
		Object = Next_Object;
		Next_Object = ((rand() % 7) + 1);
		Main.Layers[3]->Clear_All();
		Main.Layers[3]->Initilize_Object(2);
		Main.Layers[3]->Initilize_Object(2);
		Main.Layers[3]->Initilize_Object(2);
		Main.Layers[3]->Initilize_Object(2);
		if (Object != 7){
			Texture = Texture + to_string(Object);
		}
		else{
			Texture = Texture + to_string(4);
		}
		Main.Layers[2]->Textured_Objects[Current_Object]->New_Textured_Object(Texture, 4, 0.05, 0.05, 0, 0);
		Main.Layers[2]->Textured_Objects[Current_Object + 1]->New_Textured_Object(Texture, 4, 0.05, 0.05, 0, 0);
		Main.Layers[2]->Textured_Objects[Current_Object + 2]->New_Textured_Object(Texture, 4, 0.05, 0.05, 0, 0);
		Main.Layers[2]->Textured_Objects[Current_Object + 3]->New_Textured_Object(Texture, 4, 0.05, 0.05, 0, 0);
		Current_Type = Object;
		ifstream Points(to_string(Object) + ".Points");
		if (Points.is_open()){
			for (int a = Current_Object; a < Current_Object + 4; a++){
				Points >> X >> Y;
				if (Grid[X][Y] != -1){
					Game_Good = false;
				}
				Grid[X][Y] = a;
				if (X == 3){
					Main.Layers[2]->Textured_Objects[a]->Translate_Object(-0.45, 0.0, 0.0);
				}
				else if (X == 4){
					Main.Layers[2]->Textured_Objects[a]->Translate_Object(-0.35, 0.0, 0.0);
				}
				else if (X == 5){
					Main.Layers[2]->Textured_Objects[a]->Translate_Object(-0.25, 0.0, 0.0);
				}
				else if (X == 6){
					Main.Layers[2]->Textured_Objects[a]->Translate_Object(-0.15, 0.0, 0.0);
				}
				else if (X == 7){
					Main.Layers[2]->Textured_Objects[a]->Translate_Object(-0.05, 0.0, 0.0);
				}
				if (Y == 19){
					Main.Layers[2]->Textured_Objects[a]->Translate_Object(0.0, 1.05, 0.0);
				}
				if (Y == 18){
					Main.Layers[2]->Textured_Objects[a]->Translate_Object(0.0, 0.95, 0.0);
				}
				if (Y == 17){
					Main.Layers[2]->Textured_Objects[a]->Translate_Object(0.0, 0.85, 0.0);
				}
			}
			Points.close();
		}
		Texture = "Textures/" + Texture_Pack + "/Block ";
		if (Next_Object != 7){
			Texture = Texture + to_string(Next_Object);
		}
		else{
			Texture = Texture + to_string(4);
		}
		Main.Layers[3]->Textured_Objects[0]->New_Textured_Object(Texture, 4, 0.03, 0.03, 0, 0);
		Main.Layers[3]->Textured_Objects[1]->New_Textured_Object(Texture, 4, 0.03, 0.03, 0, 0);
		Main.Layers[3]->Textured_Objects[2]->New_Textured_Object(Texture, 4, 0.03, 0.03, 0, 0);
		Main.Layers[3]->Textured_Objects[3]->New_Textured_Object(Texture, 4, 0.03, 0.03, 0, 0);
		ifstream PointsN(to_string(Next_Object) + ".Points");
		if (PointsN.is_open()){
			for (int a = 0; a < 4; a++){
				PointsN >> X >> Y;
				if (X == 3){
					Main.Layers[3]->Textured_Objects[a]->Translate_Object(0.48, 0.0, 0.0);
				}
				else if (X == 4){
					Main.Layers[3]->Textured_Objects[a]->Translate_Object(0.54, 0.0, 0.0);
				}
				else if (X == 5){
					Main.Layers[3]->Textured_Objects[a]->Translate_Object(0.6, 0.0, 0.0);
				}
				else if (X == 6){
					Main.Layers[3]->Textured_Objects[a]->Translate_Object(0.66, 0.0, 0.0);
				}
				else if (X == 7){
					Main.Layers[3]->Textured_Objects[a]->Translate_Object(0.72, 0.0, 0.0);
				}
				if (Y == 19){
					Main.Layers[3]->Textured_Objects[a]->Translate_Object(0.0, -0.64, 0.0);
				}
				if (Y == 18){
					Main.Layers[3]->Textured_Objects[a]->Translate_Object(0.0, -0.7, 0.0);
				}
				if (Y == 17){
					Main.Layers[3]->Textured_Objects[a]->Translate_Object(0.0, -0.76, 0.0);
				}
			}
			PointsN.close();
		}
	}
	if (Game_Type == 2){

	}
}


bool Game::Fall_Shape(){
	for (int a = 0; a < 20; a++){
		for (int b = 0; b < 10; b++){
			if (Grid[b][a] == Current_Object || Grid[b][a] == Current_Object + 1 || Grid[b][a] == Current_Object + 2 || Grid[b][a] == Current_Object + 3){
				if (a == 0){
					return(false);
				}
				if (Grid[b][a - 1] != -1){
					return(false);
				}
				Grid[b][a - 1] = Grid[b][a];
				Grid[b][a] = -1;
			}
		}
	}
	return(true);
}

void Game::Set_Grid(){
	for (int a = 0; a < 20; a++){
		for (int b = 0; b < 10; b++){
			Grid[b][a] = -1;
		}
	}
}

bool Game::Shift(int direction){
	int c, d, e, f;
	c = Current_Object;
	d = Current_Object + 1;
	e = Current_Object + 2;
	f = Current_Object + 3;
	for (int a = 0; a < 20; a++){
		for (int b = 0; b < 10; b++){
			if (Grid[b][a] == c || Grid[b][a] == d || Grid[b][a] == e || Grid[b][a] == f){
				if (direction > 0){
					if (b + 1 == 10){
						return(false);
					}
					if (Grid[b + 1][a] != c && Grid[b + 1][a] != d && Grid[b + 1][a] != e && Grid[b + 1][a] != f && Grid[b + 1][a] != -1){
						return(false);
					}
				}
				else if (direction < 0){
					if (b - 1 == -1){
						return(false);
					}
					if (Grid[b - 1][a] != c && Grid[b - 1][a] != d && Grid[b - 1][a] != e && Grid[b - 1][a] != f && Grid[b - 1][a] != -1){
						return(false);
					}
				}
			}
		}
	}
	for (int a = 0; a < 20; a++){
		if (direction > 0){
			for (int b = 9; b > -1; b--){
				if (Grid[b][a] == Current_Object || Grid[b][a] == Current_Object + 1 || Grid[b][a] == Current_Object + 2 || Grid[b][a] == Current_Object + 3){
					if (b == 10){
						return(false);
					}
					if (Grid[b + 1][a] != -1){
						return(false);
					}
					Grid[b + 1][a] = Grid[b][a];
					Main.Layers[2]->Textured_Objects[Grid[b][a]]->Translate_Object(0.1, 0.0, 0.0);
					Grid[b][a] = -1;
				}
			}
		}
		else if (direction < 0){
			for (int b = 0; b < 10; b++){
				if (Grid[b][a] == Current_Object || Grid[b][a] == Current_Object + 1 || Grid[b][a] == Current_Object + 2 || Grid[b][a] == Current_Object + 3){
					if (b == -1){
						return(false);
					}
					if (Grid[b - 1][a] != -1){
						return(false);
					}
					Grid[b - 1][a] = Grid[b][a];
					Main.Layers[2]->Textured_Objects[Grid[b][a]]->Translate_Object(-0.1, 0.0, 0.0);
					Grid[b][a] = -1;
				}
			}
		}
	}
	return(true);
}

bool Game::Check_Avalible(int x, int y){
	bool Avalible = false;

	for (unsigned i = Current_Object; i < Main.Layers[2]->Textured_Objects.size(); i++){
		if (Temp_Grid_1[x][y] == i){
			Avalible = true;
		}
	}
	if (Temp_Grid_1[x][y] == -1){
		Avalible = true;
	}

	return(Avalible);
}

bool Game::Rotate(){
	bool Rotate_Good = true;
	if (Current_Type != 1){
		int Temp_Grid_2[3][3];
		int Center_X, Center_Y, x, y;
		for (int a = 0; a < 20; a++){
			for (int b = 0; b < 10; b++){
				if (Grid[b][a] == Current_Object){
					Center_X = b;
					Center_Y = a;
				}
			}
		}
		x = 0;
		y = 0;
		for (int a = 0; a < 3; a++){
			for (int b = 0; b < 3; b++){
				Temp_Grid_1[a][b] = -1;
				Temp_Grid_2[a][b] = -1;
			}
		}
		for (int a = (Center_Y + 1); a > (Center_Y - 2); a--){
			x = 0;
			for (int b = Center_X - 1; b < Center_X + 2; b++){
				Temp_Grid_1[x][y] = Grid[b][a];
				x++;
			}
			y++;
		}
		for (int a = 0; a < 3; a++){
			for (int b = 0; b < 3; b++){
				if (Temp_Grid_1[a][b] != -1){
					if (a == 1 && b == 1){
						Temp_Grid_2[1][1] = Temp_Grid_1[1][1];
					}
					else if (a == 0 && b == 0){
						if (Check_Avalible(2, 0) == true){
							Temp_Grid_2[2][0] = Temp_Grid_1[0][0];
						}
						else{
							Rotate_Good = false;
						}
					}
					else if (a == 2 && b == 0){
						if (Check_Avalible(2, 2) == true){
							Temp_Grid_2[2][2] = Temp_Grid_1[2][0];
						}
						else{
							Rotate_Good = false;
						}
					}
					else if (a == 2 && b == 2){
						if (Check_Avalible(0, 2) == true){
							Temp_Grid_2[0][2] = Temp_Grid_1[2][2];
						}
						else{
							Rotate_Good = false;
						}
					}
					else if (a == 0 && b == 2){
						if (Check_Avalible(0, 0) == true){
							Temp_Grid_2[0][0] = Temp_Grid_1[0][2];
						}
						else{
							Rotate_Good = false;
						}
					}

					else if (a == 1 && b == 0){
						if (Check_Avalible(2, 1) == true){
							Temp_Grid_2[2][1] = Temp_Grid_1[1][0];
						}
						else{
							Rotate_Good = false;
						}
					}
					else if (a == 2 && b == 1){
						if (Check_Avalible(1, 2) == true){
							Temp_Grid_2[1][2] = Temp_Grid_1[2][1];
						}
						else{
							Rotate_Good = false;
						}
					}
					else if (a == 1 && b == 2){
						if (Check_Avalible(0, 1) == true){
							Temp_Grid_2[0][1] = Temp_Grid_1[1][2];
						}
						else{
							Rotate_Good = false;
						}
					}
					else if (a == 0 && b == 1){
						if (Check_Avalible(1, 0) == true){
							Temp_Grid_2[1][0] = Temp_Grid_1[0][1];
						}
						else{
							Rotate_Good = false;
						}
					}
				}
			}
		}

		if (Rotate_Good == true){
			float Middle_X, Middle_Y, Check_X, Check_Y;
			Middle_X = Main.Layers[2]->Textured_Objects[Current_Object]->Return_Float_Value(2);
			Middle_Y = Main.Layers[2]->Textured_Objects[Current_Object]->Return_Float_Value(3);
			for (int i = Current_Object + 1; i < Current_Object + 4; i++){
				Check_X = Main.Layers[2]->Textured_Objects[i]->Return_Float_Value(2);
				Check_Y = Main.Layers[2]->Textured_Objects[i]->Return_Float_Value(3);
				if (Check_X == Middle_X){
				}
				else if (Check_X >= (Middle_X + 0.09)){
					Main.Layers[2]->Textured_Objects[i]->Translate_Object(-0.1, 0.0, 0.0);
				}
				else if (Check_X <= (Middle_X - 0.09)){
					Main.Layers[2]->Textured_Objects[i]->Translate_Object(0.1, 0.0, 0.0);
				}
				if (Check_Y < (Middle_Y + 0.01) && Check_Y >(Middle_Y - 0.01)){
				}
				else if (Check_Y >= (Middle_Y - 0.09)){
					Main.Layers[2]->Textured_Objects[i]->Translate_Object(0.0, -0.1, 0.0);
				}
				else if (Check_Y <= (Middle_Y - 0.09)){
					Main.Layers[2]->Textured_Objects[i]->Translate_Object(0.0, 0.1, 0.0);
				}
			}
			y = 0;

			for (int c = 0; c < 3; c++){
				for (int d = 0; d < 3; d++){
					Temp_Grid_1[c][d] = Temp_Grid_2[c][d];
				}
			}
			for (int a = (Center_Y + 1); a > (Center_Y - 2); a--){
				x = 0;
				for (int b = Center_X - 1; b < Center_X + 2; b++){
					Grid[b][a] = Temp_Grid_2[x][y];
					if (Check_Avalible(x,y) == true && Temp_Grid_2[x][y] != -1){
						if (x == 0){
							Main.Layers[2]->Textured_Objects[Temp_Grid_2[x][y]]->Translate_Object(-0.1, 0.0, 0.0);
						}
						else if (x == 2){
							Main.Layers[2]->Textured_Objects[Temp_Grid_2[x][y]]->Translate_Object(0.1, 0.0, 0.0);
						}
						if (y == 0){
							Main.Layers[2]->Textured_Objects[Temp_Grid_2[x][y]]->Translate_Object(0.0, 0.1, 0.0);
						}
						else if (y == 2){
							Main.Layers[2]->Textured_Objects[Temp_Grid_2[x][y]]->Translate_Object(0.0, -0.1, 0.0);
						}
					}
					x++;
				}
				y++;
			}
		}
		return(Rotate_Good);
	}
	else if (Current_Type == 1){
		int X, Y, Dir;
		bool Rotate_Good = true;
		for (int a = 0; a < 20; a++){
			for (int b = 0; b < 10; b++){
				if (Grid[b][a] == Current_Object){
					X = b;
					Y = a;
				}
			}
		}
		if (Grid[X - 1][Y] == Current_Object + 1){
			Dir = 1;
		}
		else if (Grid[X][Y - 1] == Current_Object + 1){
			Dir = 2;
		}
		if (Dir == 1){
			if (Y - 1 == -1 || Y + 2 > 19){
				Rotate_Good = false;
			}
			else if (Grid[X][Y - 1] != -1){
				Rotate_Good = false;
			}
			else if (Grid[X][Y + 1] != -1){
				Rotate_Good = false;
			}
			else if (Grid[X][Y + 2] != -1){
				Rotate_Good = false;
			}
			if (Rotate_Good == true){
				Grid[X][Y - 1] = Current_Object + 1;
				Grid[X - 1][Y] = -1;
				Grid[X][Y + 1] = Current_Object + 2;
				Grid[X + 1][Y] = -1;
				Grid[X][Y + 2] = Current_Object + 3;
				Grid[X + 2][Y] = -1;
				Main.Layers[2]->Textured_Objects[Current_Object + 1]->Translate_Object(0.1, -0.1, 0.0);
				Main.Layers[2]->Textured_Objects[Current_Object + 2]->Translate_Object(-0.1, 0.1, 0.0);
				Main.Layers[2]->Textured_Objects[Current_Object + 3]->Translate_Object(-0.2, 0.2, 0.0);
			}
		}
		if (Dir == 2){
			if (X - 1 == -1 || X + 2 > 9){
				Rotate_Good = false;

			}
			else if (Grid[X - 1][Y] != -1){
				Rotate_Good = false;
			}
			else if (Grid[X + 1][Y] != -1){
				Rotate_Good = false;
			}
			else if (Grid[X + 2][Y] != -1){
				Rotate_Good = false;
			}
			if (Rotate_Good == true){
				Grid[X - 1][Y] = Current_Object + 1;
				Grid[X][Y - 1] = -1;
				Grid[X + 1][Y] = Current_Object + 2;
				Grid[X][Y + 1] = -1;
				Grid[X + 2][Y] = Current_Object + 3;
				Grid[X][Y + 2] = -1;
				Main.Layers[2]->Textured_Objects[Current_Object + 1]->Translate_Object(-0.1, 0.1, 0.0);
				Main.Layers[2]->Textured_Objects[Current_Object + 2]->Translate_Object(0.1, -0.1, 0.0);
				Main.Layers[2]->Textured_Objects[Current_Object + 3]->Translate_Object(0.2, -0.2, 0.0);
			}
		}
	}
}

void Game::Clear_Line(){
	int Cleared = 0;
	vector <int> Lines;
	bool Line = false;
	for (int i = 0; i < 20; i++){
		Line = true;
		for (int x = 0; x < 10; x++){
			if (Grid[x][i] == -1){
				Line = false;
			}
		}
		if (Line == true){
			Lines.push_back(i);
			Cleared++;
		}
		
	}
	for (unsigned l = 0; l < Lines.size(); l++){
		for (int x = 0; x < 10; x++){
			Main.Layers[2]->Textured_Objects.erase(Main.Layers[2]->Textured_Objects.begin() + Grid[x][Lines[l]]);
			Remove(Grid[x][Lines[l]]);
			Grid[x][Lines[l]] = -1;
		}
		Current_Object = Main.Layers[2]->Textured_Objects.size();
		New_Lines = New_Lines + 1;
	}
	if (Lines.size() >= 1){
		for (unsigned l = 0; l < Lines.size(); l++){
			Shift_All();
		}
	}
	if (Lines.size() == 1){
		New_Score = Score + (40 * (Level + 1));
	}
	if (Lines.size() == 2){
		New_Score = Score + (100 * (Level + 1));
	}
	if (Lines.size() == 3){
		New_Score = Score + (300 * (Level + 1));
	}
	if (Lines.size() == 4){
		New_Score = Score + (1200 * (Level + 1));
	}
}

void Game::Remove(int Number){
	for (int y = 0; y < 20; y++){
		for (int x = 0; x < 10; x++){
			if (Grid[x][y] >= Number){
				Grid[x][y] = Grid[x][y] - 1;
			}
		}
	}
}

void Game::Shift_All(){
	for (int y = 1; y < 20; y++){
		for (int x = 0; x < 10; x++){
			if (Grid[x][y] != -1 && Grid[x][y-1] == -1){
				Grid[x][y - 1] = Grid[x][y];
				Main.Layers[2]->Textured_Objects[Grid[x][y]]->Translate_Object(0.0, -0.1, 0.0);
				Grid[x][y] = -1;
			}
		}
	}
}

void Game::Pause(){
	bool Pause_Good = true;
	int Layer = -1, Button = -1, Action = -1, Update = 15;
	Main.Layers[3]->Initilize_Object(2);
	Main.Layers[3]->Textured_Objects[0]->New_Textured_Object("Textures/" + Texture_Pack + "/In Game Menu", 4, 0.5, 0.8, 0, 0);
	Main.Layers[4]->Initilize_Object(4);
	Main.Layers[4]->Button_Objects[0]->New_Button("PAUSE", "Textures/" + Texture_Pack + "/Transparent", "Basic/Black", 0.35, 0.15);
	Main.Layers[4]->Button_Objects[0]->Translate_Button(0.0, 0.55, 0.0);
	Main.Layers[4]->Initilize_Object(4);
	Main.Layers[4]->Button_Objects[1]->New_Button("Resume", "Textures/" + Texture_Pack + "/Button", "Basic/Black", 0.35, 0.15);
	Main.Layers[4]->Button_Objects[1]->Translate_Button(0.0, 0.2, 0.0);
	Main.Layers[4]->Initilize_Object(4);
	Main.Layers[4]->Button_Objects[2]->New_Button("Quit", "Textures/" + Texture_Pack + "/Button", "Basic/Black", 0.35, 0.15);
	Main.Layers[4]->Button_Objects[2]->Translate_Button(0.0, -0.2, 0.0);
	while (Pause_Good == true && Game_Good == true){
		if (Update > 0){
			Update--;
		}
		if (Update == 0){
			Main.Check_All_Buttons(Layer, Button, Action);
		}
		if (Layer == 4 && Button == 1){
			Pause_Good = false;
		}
		else if (Layer == 4 && Button == 2){
			Quit = true;
			Pause_Good = false;
			Game_Good = false;
		}
		if (Update == 0){
			if (glfwGetKey(window, GLFW_KEY_ESCAPE)){
				Pause_Good = false;
			}
		}
		Main.Display_All_Layers();
		Main.Frame();
		Close();
	}
	Main.Layers[3]->Clear_All();
	Main.Layers[4]->Clear_All();
}

char Game::Key(int key){
	return(char(key));
}

bool Game::Classic_Game(){
	Score = 0;
	Level = 0;
	bool Falling = false, Soft_Drop = false;
	First = true;
	int Speed = 0, Update = 10;
	Speed_Set = 60;
	True_Speed = 60;
	Total_Lines = 2;
	New_Lines = 0;
	Next_Object = 1 + (rand() % 7);
	Main.Create_New_Layer();
	Main.Create_New_Layer();
	Main.Create_New_Layer();
	Main.Create_New_Layer();
	Main.Layers[0]->Initilize_Object(2);
	Main.Layers[0]->Textured_Objects[0]->New_Textured_Object("Textures/" + Texture_Pack + "/Background Menu", 4, 1, 1, 0, 0);
	Main.Layers[0]->Textured_Objects[0]->Translate_Object(0.0, 0.0, 0.0);
	Main.Layers[0]->Initilize_Object(2);
	Main.Layers[0]->Textured_Objects[1]->New_Textured_Object("Textures/" + Texture_Pack + "/Background Game", 4, 0.5, 1, 0, 0);
	Main.Layers[0]->Textured_Objects[1]->Translate_Object(-0.3, 0.0, 0.0);
	Main.Layers[1]->Initilize_Object(4);
	Main.Layers[1]->Button_Objects[0]->New_Button("TETRIS", "Textures/" + Texture_Pack + "/ButtonB", "Special", 0.35, 0.15);
	Main.Layers[1]->Button_Objects[0]->Translate_Button(0.6, 0.8, 0.0);
	Main.Layers[1]->Initilize_Object(4);
	Main.Layers[1]->Button_Objects[1]->New_Button("Score", "Textures/" + Texture_Pack + "/ButtonB", "Basic/Black", 0.3, 0.1);
	Main.Layers[1]->Button_Objects[1]->Translate_Button(0.6, 0.5, 0.0);
	Main.Layers[1]->Initilize_Object(4);
	Main.Layers[1]->Button_Objects[2]->New_Button("Level", "Textures/" + Texture_Pack + "/ButtonB", "Basic/Black", 0.3, 0.1);
	Main.Layers[1]->Button_Objects[2]->Translate_Button(0.6, -0.1, 0.0);
	Main.Layers[1]->Initilize_Object(4);
	Main.Layers[1]->Button_Objects[3]->New_Button("", "Textures/" + Texture_Pack + "/ButtonB", "Basic/Black", 0.2, 0.2);
	Main.Layers[1]->Button_Objects[3]->Translate_Button(0.6, -0.7, 0.0);
	Main.Layers[1]->Initilize_Object(4);
	Main.Layers[1]->Button_Objects[4]->New_Button(to_string(Score), "Textures/" + Texture_Pack + "/ButtonB", "Basic/Black", 0.3, 0.1);
	Main.Layers[1]->Button_Objects[4]->Translate_Button(0.6, 0.28, 0.0);
	Main.Layers[1]->Initilize_Object(4);
	Main.Layers[1]->Button_Objects[5]->New_Button(to_string(Level), "Textures/" + Texture_Pack + "/ButtonB", "Basic/Black", 0.3, 0.1);
	Main.Layers[1]->Button_Objects[5]->Translate_Button(0.6, -0.32, 0.0);
	
	while (Game_Good == true){
		if (Falling == false){
			Genorate_Shape();
			Falling = true;
		}
		if (Speed == 0 || Soft_Drop == true){
			Speed = Speed_Set;
			Main.Layers[2]->Textured_Objects[Current_Object]->Translate_Object(0.0, -0.1, 0.0);
			Main.Layers[2]->Textured_Objects[Current_Object + 1]->Translate_Object(0.0, -0.1, 0.0);
			Main.Layers[2]->Textured_Objects[Current_Object + 2]->Translate_Object(0.0, -0.1, 0.0);
			Main.Layers[2]->Textured_Objects[Current_Object + 3]->Translate_Object(0.0, -0.1, 0.0);
			if (Fall_Shape() == false){
				Falling = false;
				Current_Object = Current_Object + 4;
			}
			if (Soft_Drop == true){
				New_Score = Score + 1;
				Soft_Drop = false;
			}
		}
		if (Speed > 0){
			Speed--;
		}
		if (Update > 0){
			Update--;
		}
		Speed_Set = True_Speed;
		if (Update == 0){
			if (glfwGetKey(window, GLFW_KEY_RIGHT)){
				Shift(1);
			}
			else if (glfwGetKey(window, GLFW_KEY_LEFT)){
				Shift(-1);
			}
			else if (glfwGetKey(window, GLFW_KEY_UP)){
				Rotate();
			}
			else if (glfwGetKey(window, GLFW_KEY_ESCAPE)){
				Pause();
			}
			Update = 5;
		}
		else if (glfwGetKey(window, GLFW_KEY_DOWN)){
			Soft_Drop = true;
		}
		if (Falling == false){
			Clear_Line();
		}
		if (New_Score != Score){
			Score = New_Score;
			Main.Layers[1]->Button_Objects[4]->Edit_Button(to_string(Score));
		}
		if (New_Lines >= Total_Lines){
			Level++;
			if (True_Speed > 1){
				True_Speed--;
			}
			Total_Lines = New_Lines;
			Total_Lines = Total_Lines + ((Level + 1));
			Main.Layers[1]->Button_Objects[5]->Edit_Button(to_string(Level));
		}
		Main.Display_All_Layers();
		Main.Frame();
		Close();
	}
	Main.Clear_All_Layers();
	if (Quit == false){
		Update = 10;
		Name = "";
		Main.Create_New_Layer();
		Main.Layers[0]->Initilize_Object(2);
		Main.Layers[0]->Textured_Objects[0]->New_Textured_Object("Textures/" + Texture_Pack + "/Background Menu", 4, 1, 1, 0, 0);
		Main.Layers[1]->Initilize_Object(4);
		Main.Layers[1]->Button_Objects[0]->New_Button("Save Score", "Textures/" + Texture_Pack + "/ButtonB", "Basic/Black", 0.5, 0.2);
		Main.Layers[1]->Button_Objects[0]->Translate_Button(0.0, 0.7, 0.0);
		Main.Layers[1]->Initilize_Object(4);
		Main.Layers[1]->Button_Objects[1]->New_Button("Name", "Textures/" + Texture_Pack + "/ButtonB", "Basic/Black", 0.3, 0.15);
		Main.Layers[1]->Button_Objects[1]->Translate_Button(-0.6, 0.3, 0.0);
		Main.Layers[1]->Initilize_Object(4);
		Main.Layers[1]->Button_Objects[2]->New_Button("", "Textures/" + Texture_Pack + "/ButtonB", "Basic/Black", 0.55, 0.15);
		Main.Layers[1]->Button_Objects[2]->Translate_Button(0.4, 0.3, 0.0);
		Main.Layers[1]->Initilize_Object(4);
		Main.Layers[1]->Button_Objects[3]->New_Button("Score", "Textures/" + Texture_Pack + "/ButtonB", "Basic/Black", 0.3, 0.15);
		Main.Layers[1]->Button_Objects[3]->Translate_Button(-0.6, -0.1, 0.0);
		Main.Layers[1]->Initilize_Object(4);
		Main.Layers[1]->Button_Objects[4]->New_Button(to_string(Score), "Textures/" + Texture_Pack + "/ButtonB", "Basic/Black", 0.55, 0.15);
		Main.Layers[1]->Button_Objects[4]->Translate_Button(0.4, -0.1, 0.0);
		Main.Layers[1]->Initilize_Object(4);
		Main.Layers[1]->Button_Objects[5]->New_Button("Main Menu", "Textures/" + Texture_Pack + "/Button", "Basic/Black", 0.5, 0.15);
		Main.Layers[1]->Button_Objects[5]->Translate_Button(0.0, -0.5, 0.0);
	}
	while (Quit == false){
		int Layer, Button, Action;
		if (Update > 0){
			Update--;
			Main.Clear_Key();
		}
		if (Main.Check_Key() < 97 && Main.Check_Key() > 31 && Update == 0){
			Name = Name + Key(Main.Check_Key());
			Update = 10;
		}
		if (glfwGetKey(window, GLFW_KEY_BACKSPACE) && Update == 0){
			string New = "";
			for (int i = 0; i < Name.size() - 1 && Name.size() > 0; i++){
				New = New + Name[i];
			}
			Name = New;
			Update = 10;
		}
		if (glfwGetKey(window, GLFW_KEY_ENTER) || glfwGetKey(window, GLFW_KEY_ESCAPE)){
			if (Name == "" || Name == " "){
				Name = "DEFAULT";
			}
			Save_Score();
			Quit = true;
		}
		Main.Layers[1]->Button_Objects[2]->Edit_Button(Name);
		Main.Check_All_Buttons(Layer, Button, Action);
		if (Button == 5){
			if (Name == "" || Name == " "){
				Name = "DEFAULT";
			}
			Save_Score();
			Quit = true;
		}
		Main.Display_All_Layers();
		Main.Frame();
		Close();
	}
	Main.Clear_All_Layers();
	return(true);
}

bool Game::Endless_Game(){
	return(true);
}