#include "../include/colors.h"


int editorSyntaxToColor(int hl) {
    switch (hl) {
        case HL_COMMENT:
        case HL_MLCOMMENT: return ML_COMMENT_COLOR;
        case HL_KEYWORD1: return KEYWORD1_COLOR;
        case HL_KEYWORD2: return KEYWORD2_COLOR;
        case HL_STRING: return STRING_COLOR;
        case HL_NUMBER: return NUMBER_COLOR;
        case HL_MATCH: return MATCH_COLOR;
        default: return DEFAULT_COLOR;
    }
}


void editorSelectSyntaxHighlight() {
    E.syntax = NULL;
    if (E.filename == NULL) return;

    char *ext = strrchr(E.filename, '.');

    for (unsigned int j = 0; j < HLDB_ENTRIES; j++) {

        struct editorSyntax *s = &HLDB[j];
        unsigned int i = 0;
        while (s->filematch[i]) {
            int is_ext = (s->filematch[i][0] == '.');

            if ((is_ext && ext && !strcmp(ext, s->filematch[i])) ||
                (!is_ext && strstr(E.filename, s->filematch[i]))) {
                    E.syntax = s;
                    int filerow;
                    for (filerow = 0; filerow < E.numrows; filerow++) {
                    editorUpdateSyntax(&E.row[filerow]);
                }
                return;
            }
            i++;
        }
    }
}
