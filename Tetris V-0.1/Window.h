#include "Libraries.h"
using namespace std;
class Window{
private:
	string Name;
	float speed = 1.0f;
	float timmer;
	float last_position = 0.0f;
	int X, Y, I, F;
	void glfw();
	void glew();
	void version();
	void update_fps_counter(GLFWwindow* windo);
	GLFWwindow* New_Window(string tital, bool full);
	void Get_Resolution(int i);
public:
	GLFWwindow* Setup_Window();
	void Frame(GLFWwindow* Win);
	void Start_Timmer();
	void Stop_Timmer();
	int Get_Window_Size(int a);
	void Set_Window(int i, int f);
	void Window_Res(int& x, int& y);
};