#include "Libraries.h"
#include "Audio.h"
#include "Logging.h"
using namespace std;

void Audio::Play_Wav(string file){
	file = file + ".wav";
	if (!PlaySound(TEXT(file.c_str()), NULL, SND_ASYNC | SND_FILENAME)){
		Logging::log_error("Failed to play sound", "Audio");
	}
	else{
		Logging::log_success("Played sound", "Audio");
	}
}
void Audio::Stop_Wav(){
	PlaySound(TEXT("None.wav"), NULL, SND_ASYNC | SND_FILENAME);
	Logging::log_error("Stoped Sound", "Audio");
}
