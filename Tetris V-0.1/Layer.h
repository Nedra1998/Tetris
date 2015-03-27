#include "Libraries.h"
#include "Object.h"
using namespace std;
class Layer{
private:
public:
	vector<Object*> Colored_Objects;
	vector<Object*> Textured_Objects;
	vector<Object*> Text_Objects;
	vector<Object*> Button_Objects;
	void Display_All();
	void Display_All_Colored_Objects();
	void Display_All_Textured_Objects();
	void Display_All_Text_Objects();
	void Display_All_Button_Objects();
	void Clear_All();
	void Clear_All_Colored_Objects();
	void Clear_All_Textured_Objects();
	void Clear_All_Text_Objects();
	void Clear_All_Button_Objects();
	void Check_All_Buttons(int& Button, float x, float y, float cx, float cy);
	void Initilize_Object(int Catagory);
};