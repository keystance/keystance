#ifndef CUS_COMMANDS_H
#define CUS_COMMANDS_H




#include "../../include/keystance.h"






//DEFINES

#define SYS_CUSTOM_CMD_START '$'


#define CUSTOM_CMD_TIME "$time"
#define CUSTOM_CMD_WEATHER "$weather"
#define CUSTOM_CMD_GOOGLE "$google"
#define CUSTOM_CMD_WIKI "$wiki"




void cus_cmd_time();
void cus_cmd_weather();
void cus_cmd_google();
void cus_cmd_wiki();




#endif //CUS_COMMANDS_H