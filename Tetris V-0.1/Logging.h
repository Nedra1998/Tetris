#include "Libraries.h"
namespace Logging{
	void Initilize_Log();
	void log_error(std::string Error, std::string Location);
	void log_success(std::string Success, std::string Location);
	void log_data(std::string Data, std::string Location);
	void log_information(std::string Information, std::string Location);
	void Terminate_Log();
}