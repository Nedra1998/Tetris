#include "Libraries.h"
#include "Window.h"
#include "Logging.h"
using namespace std;
void Window::glfw(){
	if (glfwInit()){
		Logging::log_success("Loaded GLFW", "Window");
	}
	else{
		Logging::log_error("Unable To Load GLFW", "Window");
	}
}
void Window::glew(){
	glewExperimental = GL_TRUE;
	if (!glewInit()){
		Logging::log_success("Loaded GLEW", "Window");
	}
	else{
		Logging::log_error("Unable To Load GLEW", "Window");
	}
}
void Window::version(){
	const GLubyte* renderer = glGetString(GL_RENDERER);
	Logging::log_success("Loaded Renderer", "Window");
	const GLubyte* version = glGetString(GL_VERSION);
	Logging::log_success("Loaded Version", "Window");
}
void Window::update_fps_counter(GLFWwindow* windo)
{
	static double previous_seconds = glfwGetTime();
	static int frame_count;
	double current_seconds = glfwGetTime();
	double elapsed_seconds = current_seconds - previous_seconds;
	if (elapsed_seconds > 1){
		previous_seconds = current_seconds;
		double fps = (double)frame_count / elapsed_seconds;
		frame_count = 0;
	}
	frame_count++;
}
GLFWwindow* Window::New_Window(string tital, bool full){
	GLFWwindow* window;
	if (full == true){
		window = glfwCreateWindow(X, Y, tital.c_str(), glfwGetPrimaryMonitor(), NULL);
	}
	else{
		window = glfwCreateWindow(X, Y, tital.c_str(), NULL, NULL);
	}
	if (!window) {
		cout << "ERROR: could not open window: [" << tital << "] with GLFW3\n";
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	return window;
}
void Window::Get_Resolution(int i){
	ifstream res("Resolutions.txt");
	if (res.is_open()){
		while (i > 0){
			res >> X;
			res >> Y;
			i--;
		}
		Logging::log_success("Loaded Resolution", "Window");
		res.close();
	}
	else{
		Logging::log_error("Failed To Load Resolutions", "Window");
	}
}
GLFWwindow* Window::Setup_Window(){
	GLFWwindow* win;
	int temp;
	bool full = false;
	ifstream def("Window Settings.txt");
	if (def.is_open()){
		getline(def, Name);
		def >> I;
		def >> temp;
		Logging::log_success("Loaded Window Data", "Window");
		def.close();
	}
	else{
		Logging::log_error("Failed To Load Window Data", "Window");
	}
	if (temp == 1){
		full = true;
		Logging::log_information("Fullscreen Enabled", "Window");
	}
	else{
		Logging::log_information("Windowed Mode Enabled", "Window");
	}
	F = temp;
	Get_Resolution(I);
	string z = "Resoulution Of Window Is:[" + to_string(X) + ":" + to_string(Y) + "]";
	Logging::log_information(z, "Window");
	glfw();
	win = New_Window(Name, full);
	glew();
	version();
	srand(time(NULL));
	return win;
}
void Window::Frame(GLFWwindow* Win){
	static double previous_seconds = glfwGetTime();
	double current_seconds = glfwGetTime();
	double elapsed_seconds = current_seconds - previous_seconds;
	previous_seconds = current_seconds;
	if (fabs(last_position) > 1.0f) {
		speed = -speed;
	}
	glfwPollEvents();
	glfwSwapBuffers(Win);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	update_fps_counter(Win);
}
void Window::Start_Timmer(){
	timmer = glfwGetTime();
}
void Window::Stop_Timmer(){
	float ts = glfwGetTime();
	ts = ts - timmer;
	cout << ts << "::Nano Seconeds-";
}
int Window::Get_Window_Size(int a){
	if (a == 1){
		return(I);
	}
	if (a == 2){
		return(F);
	}
	if (a == 3){
		return(X);
	}
	if (a == 4){
		return(Y);
	}
	return(0);
}
void Window::Set_Window(int i, int f){
	ofstream def("Window Settings.txt");
	if (def.is_open()){
		def << Name << "\n" << i << "\n" << f;
		def.close();
	}
	I = i;
	F = f;
}
void Window::Window_Res(int& x, int& y){
	x = X;
	y = Y;
}