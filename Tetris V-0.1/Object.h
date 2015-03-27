#include "Libraries.h"
using namespace std;
class Object{
private:
	/*>>>>>-----DATA-----<<<<<*/
	int Object_Type;
	/*-----Object Data-----*/
	glm::mat4 Model_Matrix, View_Matrix;
	float Object_Data[16];
	/*-----Colored Object Data-----*/
	unsigned Uniform_Mvp_Color, Points_Vbo, Color_Vbo, Vao, Uniform_Color;
	float Colors[120], Points[90];
	/*-----Textured Object Data-----*/
	GLuint texture_id, texture_vao, program_id, uniform_mytexture;
	unsigned vbo_texcoords, Uniform_Mvp_Texture;
	unsigned char * data;
	unsigned int width, height;
	string Texture;
	/*-----Text Object Data-----*/
	float Text_Data[10];
	string Charictars[400];
	vector<Object*> Letters;
	string Directory;
	/*-----Button Data-----*/
	Object* Text;
	Object* Background;
	string Font;
	int Mouse_Over = 0;
	/*>>>>>-----PRIVATE FUNCTIONS-----<<<<<*/
	/*-----Objects Functions-----*/
	void Genorate_Points();
	string GFAS(string file);
	void Genorate_Colored_Object();
	void Read_TGA(string file);
	void Genorate_Textured_Object();
	
	/*-----Text Object Functions-----*/
	void Read_Line(string line);
	void Update_Text_Object();
public:
	/*>>>>>-----PUBLIC FUNCTIONS-----<<<<<*/
	/*-----Objects Functions-----*/
	void Edit_Object(int Type, float Value);
	void Set_View_Matrix_Object(glm::vec3 view);
	void Translate_Object(float x, float y, float z);
	float Return_Float_Value(int val);
	string Return_String_Value(int val);
	void Display_Object();
	void New_Colored_Object(int points, float xsize, float ysize, float r, float g, float b, float a, int colision, int physics);
	void New_Textured_Object(string texture, int points, float xsize, float ysize, int colision, int physics);
	
	/*-----Text Object Functions-----*/
	void Set_Text_Data(int Type, float Value);
	void Reset_Text_Data(float X_Size, float Y_Size, float Font, float Color, float Collision, float Physics);
	void New_Text_Object(string Line, string font);
	void Edit_Text_Object(string Line);
	void Display_Text_Object();
	void Set_View_Matrix_Text_Object(glm::vec3 view);
	void Translate_Text_Object(float x, float y, float z);

	/*-----Button Objects Functions-----*/
	void New_Button(string text, string texture, string font, float x, float y);
	void Edit_Button(string text);
	bool Check_Button(float x, float y, float cx, float cy);
	void Translate_Button(float x, float y, float z);
};