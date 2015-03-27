#include "Libraries.h"
#include "Logging.h"

std::string Date_and_Time;
std::ofstream Log_File;
time_t Current_Time;

namespace Logging{
	void Initilize_Log(){
		std::cout << "Initilizing Log\n";
		Current_Time = time(0);
		Date_and_Time = ctime(&Current_Time);
		Log_File.open("Log_File.Log");
		if (Log_File.is_open()){
			Log_File << Date_and_Time;
			std::cout << "Began new log file at current date and time:\n";
			std::cout << Date_and_Time << std::endl;
			log_success("Opened Log File", "Logging");
		}
	}
	void log_error(std::string Error, std::string Location){
		std::string line = "";
		line = "[ERROR]>>" + Error + "<<[" + Location + "]\n";
		if (Log_File.is_open()){
			Log_File << line;
		}
		std::cout << line;
	}
	void log_success(std::string Success, std::string Location){
		std::string line = "";
		line = "[SUCCESS]>>" + Success + "<<[" + Location + "]\n";
		if (Log_File.is_open()){
			Log_File << line;
		}
	}
	void log_data(std::string Data, std::string Location){
		std::string line = "";
		line = "[DATA]>>" + Data + "<<[" + Location + "]\n";
		if (Log_File.is_open()){
			Log_File << line;
		}
	}
	void log_information(std::string Information, std::string Location){
		std::string line = "";
		line = "[INFORMATION]>>" + Information + "<<[" + Location + "]\n";
		if (Log_File.is_open()){
			Log_File << line;
		}
		std::cout << line;
	}
	void Terminate_Log(){
		Current_Time = time(0);
		Date_and_Time = ctime(&Current_Time);
		if (Log_File.is_open()){
			log_success("Closed Log File", "Logging");
			Log_File << Date_and_Time;
			Log_File.close();
		}
		std::cout << "Terminated Log\n";
	}
}
