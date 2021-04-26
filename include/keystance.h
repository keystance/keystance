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



//DEFINES
#define CTRL_KEY(k) ((k) & 0x1f)

#define FIND 'f'
#define SAVE 's'
#define QUIT 'q'
#define HELP 'h'
#define DEL_LINE_L 'd'
#define DEL_LINE_R 'e'
#define RUN_CMD 'r'

#define KEYSTANCE_VERSION "0.0.1"
#define KEYSTANCE_TAB_STOP 8
#define KEYSTANCE_QUIT_TIMES 3
#define HL_HIGHLIGHT_NUMBERS (1<<0)
#define HLDB_ENTRIES (sizeof(HLDB) / sizeof(HLDB[0]))
#define HL_HIGHLIGHT_STRINGS (1<<1)


//COLORS
#define ML_COMMENT_COLOR 37
#define KEYWORD1_COLOR 33
#define KEYWORD2_COLOR 32
#define STRING_COLOR 34
#define NUMBER_COLOR 31
#define MATCH_COLOR 34
#define DEFAULT_COLOR 37

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


struct termios orig_termios;


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

struct editorConfig E;


//FILETYPES
char *C_HL_extensions[] = { ".c", ".h", ".cpp", ".py", NULL };

char *C_HL_keywords[] = {
  "switch", "#include", "if", "while", "for", "break", "continue", "return", "else",
  "struct", "union", "typedef", "static", "enum", "class", "case",
  "auto", "const", "extern", "goto", "register", "sizeof", "asm",
  "namespace", "std", "using", "false", "true", "private", "public",
  "protected", "try", "virtual", "mutable", "inline", "template", "this",
  "delete", "typeid", "typename", "operator", "explicit", "new",
  "static_cast", "catch", "class",
  "int|", "long|", "double|", "float|", "char|", "unsigned|", "signed|", "short|",
  "void|", NULL
};


struct editorSyntax HLDB[] = {
  {
    "c",
    C_HL_extensions,
    C_HL_keywords,
    "//", "/*", "*/",
    HL_HIGHLIGHT_NUMBERS | HL_HIGHLIGHT_STRINGS
  },
};




//PROTOTYPES


void editorSetStatusMessage(const char *fmt, ...);
void editorRefreshScreen();
char *editorPrompt(char *prompt, void (*callback)(char *, int));







#endif
