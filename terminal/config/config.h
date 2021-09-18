#ifndef CONFIG_H
#define CONFIG_H

#define KEYSTANCE_VERSION "0.4"
#define KEYSTANCE_TAB_STOP 4
#define KEYSTANCE_QUIT_TIMES 3
#define HL_HIGHLIGHT_NUMBERS (1<<0)
#define HLDB_ENTRIES (sizeof(HLDB) / sizeof(HLDB[0]))
#define HL_HIGHLIGHT_STRINGS (1<<1)

#define ML_COMMENT_COLOR 35
#define KEYWORD1_COLOR 35
#define KEYWORD2_COLOR 33
#define STRING_COLOR 34
#define NUMBER_COLOR 31
#define MATCH_COLOR 31
#define DEFAULT_COLOR 37





//USER SPECIFIC (change these to whatever you're using)
#define browser "firefox"
#define music_playlist " https://www.youtube.com/watch?v=QsNLZqfalCs&list=PL34S8OSpIqm0SvQdla1fyjJ9-ck_GF65u"





#define LINE_NUMBERS false  //Change this to true if you want line numbers to appear when you run the program.
#define CUSTOM_CMDS true    //Default is set to true


#endif //CONFIG_H
