#include "../custom/commands/cus_commands.h"


void cus_cmd_time(){
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    editorSetStatusMessage("Local time and date: %s", asctime(timeinfo));
}


void cus_cmd_weather(){

}


void cus_cmd_google(){

}


void cus_cmd_wiki(){

}