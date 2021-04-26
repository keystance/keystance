#include "../include/keystancer.h"


int main(int argc, char *argv[]) {
    enableRawMode();

    initEditor();

    if (argc >= 2) {
        editorOpen(argv[1]);
    }

    editorSetStatusMessage(
        "HELP: Ctrl-S = save | Ctrl-Q = quit | Ctrl-F = find");

    while (true) {
        editorRefreshScreen();
        editorProcessKeypress();
    }


    return 0;
}
