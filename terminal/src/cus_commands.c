#include "../custom/commands/cus_commands.h"



//prints out what the current time is
void cus_cmd_time(){
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    editorSetStatusMessage("Local time and date: %s", asctime(timeinfo));
}


//opens your default browser and searches for the weather
void cus_cmd_weather(){
    char *cmd = (char*)malloc(sizeof(char) * 50);

    if(!cmd){
        editorSetStatusMessage("%sERROR!%s 'cmd' variable ran out of memory", red(), white());

        
    }


    strcpy(cmd, browser);
    strcat(cmd, " https://google.com/search?q=");
    strcat(cmd, "weather");

    system(cmd);


    free(cmd);


}

//Takes input as what you want to google and searches it
void cus_cmd_google(){
    char *cmd = (char*)malloc(sizeof(char) * 100);
    char *search = editorPrompt("search: %s", NULL);

    if(!search){
        editorSetStatusMessage("%sERROR!%s 'search' variable ran out of memory", red(), white());

        
    }


    if(!cmd){
        editorSetStatusMessage("%sERROR!%s 'cmd' variable ran out of memory", red(), white());
    
        
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
    

    free(cmd);
    free(search);
}


//Opens wikipedia
void cus_cmd_wiki(){
    char *cmd = (char*)malloc(sizeof(char) * 100);
    char *search = editorPrompt("search: %s", NULL);

    if(!search){
        editorSetStatusMessage("%sERROR!%s 'search' variable ran out of memory", red(), white());

        
    }


    if(!cmd){
        editorSetStatusMessage("%sERROR!%s 'cmd' variable ran out of memory", red(), white());
    
      
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


    free(cmd);
    free(search);
}


//Opens stackoverflow
void cus_cmd_so(){

    char *cmd = (char*)malloc(sizeof(char) * 100);
    char *search = editorPrompt("search: %s", NULL);

    if(!search){
        editorSetStatusMessage("%sERROR!%s 'search' variable ran out of memory", red(), white());


    }


    if(!cmd){
        editorSetStatusMessage("%sERROR!%s 'cmd' variable ran out of memory", red(), white());
    

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


    free(cmd);
    free(search);
}


//opens your music playlist on default browser
void cus_cmd_music(){
    char *cmd = (char*)malloc(sizeof(char) * 50);

    if(!cmd){
        editorSetStatusMessage("%sERROR!%s variable 'cmd' ran out of memory", red(), white());
        

    }


    strcpy(cmd, browser);
    strcat(cmd, music_playlist);

    system(cmd);


    free(cmd);
}



void cus_cmd_open_cur_dir(){
    char *current_dir = (char*)malloc(sizeof(char) * 50);

    if(!current_dir){
        current_dir = (char*)realloc(current_dir, 100);

        open_nautilus_cur_dir(current_dir);
    }

    else{
        open_nautilus_cur_dir(current_dir);
    }

}









/* * FUNCTIONS TO BE USED IN OTHER FUNCTIONS*/


void open_nautilus_cur_dir(char* current_dir){
    if(getcwd(current_dir, sizeof(current_dir)) != NULL){


        char *cmd = (char*)malloc(sizeof(char) * 20);


        if(!cmd){
            editorSetStatusMessage("%sERROR!%s 'cmd' variable ran out of memory", red(), white());
        }

        strcpy(cmd, "nautilus ");
        strcat(cmd, current_dir);


        system(cmd);


        free(cmd);
        free(current_dir);
    }

    else{
        editorSetStatusMessage("%sERROR!%S Couldn't open current directory", red(), white());
    }
}
