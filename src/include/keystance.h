#ifndef KEYSTANCER_H
#define KEYSTANCER_H


#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE



#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>
#include "./config.h"
#include "../custom/commands/cus_commands.h"
#include "./colors.h"

//DEFINES
// The CTRL KEY for keyboard shortcuts
#define CTRL_KEY(k) ((k) & 0x1f)


/*All keyboard shortcuts*/
#define FIND 'f'
#define SAVE 's'
#define QUIT 'q'
#define DEL_LINE_L 'd'
#define DEL_LINE_R 'e'
#define RUN_CMD 'r'
#define INSERT_END 'a'
//#define PAGE_UP 'p'
#define SPLIT 'n'
#define SHOW_L_NUMBER 'b'
#define LINE_UP 'k'
#define LINE_DOWN 'j'
#define CHAR_RIGHT 'l'
#define CHAR_LEFT 'h'
#define MOVE_WORD_FOR 'z'
#define MOVE_WORD_BACK 'x'
#define MOVE_START 't'
#define MOVE_END 'c'
#define PASTE 'p'
#define COPY_R 'o'
#define MOVE_CENTER 'g'



/*EDITOR BUILTIN COMMANDS*/

#define SYS_CMD_START '!'

#define CMD_EXIT ":q"
#define CMD_FORCE_EXIT ":q!"
#define CMD_SAVE ":w"
#define CMD_SAVE_EXIT ":wq"
#define CMD_FIND ":f"
#define CMD_HELP ":h"
#define CMD_TERMINAL ":term"
#define CMD_OPEN_NEW_FILE ":onf"
#define CMD_RUN_C_FILE ":rcf"


#define clear() system("clear");


//true and false
#define true 1
#define false 0




enum editorKey {
  BACKSPACE = 127,
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN,
  DEL_KEY,
  HOME_KEY,
  END_KEY,
  PAGE_UP,
  PAGE_DOWN
};

enum editorHighlight {
    HL_NORMAL = 0,
    HL_COMMENT,
    HL_MLCOMMENT,
    HL_KEYWORD1,
    HL_KEYWORD2,
    HL_STRING,
    HL_NUMBER,
    HL_MATCH
};


//DATA





struct editorSyntax {
  char *filetype;
  char **filematch;
  char **keywords;
  char *singleline_comment_start;
  char *multiline_comment_start;
  char *multiline_comment_end;
  int flags;
};


typedef struct erow {
  int idx;
  int size;
  int rsize;
  char *chars;
  char *render;
  unsigned char *hl;
  int hl_open_comment;
} erow;


struct editorConfig {
    int cx, cy;
    int rx;
    int rowoff;
    int coloff;
    int screenrows;
    int screencols;
    int numrows;
    erow *row;
    int dirty;
    char *filename;
    char statusmsg[80];
    time_t statusmsg_time;
    struct editorSyntax *syntax;
    struct termios orig_termios;
};






//PROTOTYPES


void editorSetStatusMessage(const char *fmt, ...);
void editorRefreshScreen();
char *editorPrompt(char *prompt, void (*callback)(char *, int));







#endif
