#include "../custom/commands/cus_commands.h"


void cus_cmd_time(){
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    editorSetStatusMessage("Local time and date: %s", asctime(timeinfo));
}


void cus_cmd_weather(){
    char *cmd = (char*)malloc(sizeof(char) * 50);

    if(!cmd){
        editorSetStatusMessage("%sERROR!%s 'cmd' variable ran out of memory", red(), white());

        exit(1);
    }


    strcpy(cmd, browser);
    strcat(cmd, " https://google.com/search?q=");
    strcat(cmd, "weather");

    system(cmd);


}


void cus_cmd_google(){
    char *cmd = (char*)malloc(sizeof(char) * 100);
    char *search = editorPrompt("search: %s", NULL);

    if(!search){
        editorSetStatusMessage("%sERROR!%s 'search' variable ran out of memory", red(), white());

        exit(1);
    }


    if(!cmd){
        editorSetStatusMessage("%sERROR!%s 'cmd' variable ran out of memory", red(), white());
    
        exit(1);
    }


    for(int i = 0; i < strlen(search); i++){
        if(search[i] == ' '){
            search[i] = '+';
        }
    }



    strcpy(cmd, browser);
    strcat(cmd, " https://google.com/search?q=");
    strcat(cmd, search);


    system(cmd);
}


void cus_cmd_wiki(){
    char *cmd = (char*)malloc(sizeof(char) * 100);
    char *search = editorPrompt("search: %s", NULL);

    if(!search){
        editorSetStatusMessage("%sERROR!%s 'search' variable ran out of memory", red(), white());

        exit(1);
    }


    if(!cmd){
        editorSetStatusMessage("%sERROR!%s 'cmd' variable ran out of memory", red(), white());
    
        exit(1);
    }


    for(int i = 0; i < strlen(search); i++){
        if(search[i] == ' '){
            search[i] = '_';
        }
    }



    strcpy(cmd, browser);
    strcat(cmd, " https://en.wikipedia.org/wiki/");
    strcat(cmd, search);


    system(cmd);
}



void cus_cmd_so(){

    char *cmd = (char*)malloc(sizeof(char) * 100);
    char *search = editorPrompt("search: %s", NULL);

    if(!search){
        editorSetStatusMessage("%sERROR!%s 'search' variable ran out of memory", red(), white());

        exit(1);
    }


    if(!cmd){
        editorSetStatusMessage("%sERROR!%s 'cmd' variable ran out of memory", red(), white());
    
        exit(1);
    }


    for(int i = 0; i < strlen(search); i++){
        if(search[i] == ' '){
            search[i] = '+';
        }
    }



    strcpy(cmd, browser);
    strcat(cmd, " http://stackoverflow.com/search?q=");
    strcat(cmd, search);


    system(cmd);
}



void cus_cmd_music(){
    char *cmd = (char*)malloc(sizeof(char) * 50);

    if(!cmd){
        editorSetStatusMessage("%sERROR!%s variable 'cmd' ran out of memory", red(), white());
        
        exit(1);
    }


    strcpy(cmd, browser);
    strcat(cmd, music_playlist);

    system(cmd);
}