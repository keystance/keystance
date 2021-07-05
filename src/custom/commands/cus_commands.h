//HEADER GUARD

#ifndef CUS_COMMANDS_H
#define CUS_COMMANDS_H



//INCLUDES

#include "../../include/keystance.h"






//DEFINES

#define SYS_CUSTOM_CMD_START '$'


#define CUSTOM_CMD_TIME "$time"
#define CUSTOM_CMD_WEATHER "$weather"
#define CUSTOM_CMD_GOOGLE "$google"
#define CUSTOM_CMD_WIKI "$wiki"
#define CUSTOM_CMD_SO "$so" //stack overflow





//FUNCTIONS

void cus_cmd_time();
void cus_cmd_weather();
void cus_cmd_google();
void cus_cmd_wiki();
void cus_cmd_so();




#endif //CUS_COMMANDS_H