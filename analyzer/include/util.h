#ifndef UTIL_H
#define UTIL_H

#include "../../include/keystance.h"

char *read_file(const char *path){
  FILE *fptr;
  fptr = fopen(path, "r");

  if(!fptr){
      printf("Couldn't open file %s", path);
  }

  fseek(fptr, 0, SEEK_END);
  int size = ftell(fptr);
  fseek(fptr, 0, SEEK_SET);

  char *buffer = (char*)malloc(sizeof(char) * (size + 1));

  if(!buffer){
      printf("Couldn't allocate memory %d", __LINE__);
      return NULL;
  }

  fread(buffer, 1, size, fptr);
  buffer[size] = '\0';

  fclose(fptr);

  return buffer;
}

#endif //UTIL_H
