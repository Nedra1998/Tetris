#include "Libraries.h"
#include "Layer.h"
#include "Logging.h"
using namespace std;

void Layer::Display_All(){
	Display_All_Button_Objects();
	Display_All_Colored_Objects();
	Display_All_Textured_Objects();
	Display_All_Text_Objects();
}
void Layer::Display_All_Colored_Objects(){
	for (unsigned i = 0; i < Colored_Objects.size(); i++){
		Colored_Objects[i]->Display_Object();
	}
}
void Layer::Display_All_Textured_Objects(){
	for (unsigned i = 0; i < Textured_Objects.size(); i++){
		Textured_Objects[i]->Display_Object();
	}
}
void Layer::Display_All_Text_Objects(){
	for (unsigned i = 0; i < Text_Objects.size(); i++){
		Text_Objects[i]->Display_Object();
	}
}
void Layer::Display_All_Button_Objects(){
	for (unsigned i = 0; i < Button_Objects.size(); i++){
		Button_Objects[i]->Display_Object();
	}
}
void Layer::Clear_All(){
	Clear_All_Button_Objects();
	Clear_All_Colored_Objects();
	Clear_All_Textured_Objects();
	Clear_All_Text_Objects();
}
void Layer::Clear_All_Colored_Objects(){
	Colored_Objects.clear();
}
void Layer::Clear_All_Textured_Objects(){
	Textured_Objects.clear();
}
void Layer::Clear_All_Text_Objects(){
	Text_Objects.clear();
}
void Layer::Clear_All_Button_Objects(){
	Button_Objects.clear();
}
void Layer::Check_All_Buttons(int& Button, float x, float y, float cx, float cy){
	for (unsigned i = 0; i < Button_Objects.size(); i++){
		if (Button_Objects[i]->Check_Button(x, y, cx, cy) == true){
			Button = i;
			break;
		}
	}
}
void Layer::Initilize_Object(int Catagory){
	Object* Initilizer = new Object();
	if (Catagory == 1){
		Colored_Objects.push_back(Initilizer);
	}
	if (Catagory == 2){
		Textured_Objects.push_back(Initilizer);
	}
	if (Catagory == 3){
		Text_Objects.push_back(Initilizer);
	}
	if (Catagory == 4){
		Button_Objects.push_back(Initilizer);
	}
}