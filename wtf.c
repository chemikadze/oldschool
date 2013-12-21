#include <stdlib.h>
#include <stdio.h>
int main(void) {/*
 int i;
 char **q;
 q = (char **) malloc(10000000 * sizeof(char *));
 while(1) {
 printf("12\n");
 for (i=0; i<10000000; i++) {
 free(q[i]);
 }
 }*/
 
 char **c;
 c = (char**)malloc(sizeof(char*));
 *c = (char*)malloc(sizeof(char));
 free(*c);
 printf("lol1\n");
 free(c);
 printf("lol2\n");
 return 0;
}