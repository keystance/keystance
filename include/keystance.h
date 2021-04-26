#ifndef KEYSTANCE_H
#define KEYSTANCE_H

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __WIN32
  #include <windows.h>
#else
  #include <unistd.h>
#endif

#define true 1
#define false 0

void activate(GtkApplication *app, gpointer user_data);

#endif //KEYSTANCE_H
