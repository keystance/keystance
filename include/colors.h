#ifndef COLORS_H
#define COLORS_H

#include "./keystancer.h"

#define ML_COMMENT_COLOR 37
#define KEYWORD1_COLOR 33
#define KEYWORD2_COLOR 32
#define STRING_COLOR 34
#define NUMBER_COLOR 31
#define MATCH_COLOR 34
#define DEFAULT_COLOR 37

int editorSyntaxToColor(int hl);
void editorSelectSyntaxHighlight();

#endif //COLORS_H
