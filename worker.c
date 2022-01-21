#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main (){
  int r = open("p1", O_RDONLY);

  int w = open("p2",O_WRONLY);

  while(1) {

    char * mess = calloc(1000, 1);
    read(r, mess, 1000);
    printf("Received: %s\n", mess);
    char * temp = calloc(1000, 1);

    int i;
    for (i = strlen(mess) - 1; i >= 0; i--){
      if (*(mess + i) != 20){
        strncat(temp, mess + i, 1);
        strcat(temp, "!");
      }
    }

    write(w, temp, 1000);
    printf("Sending back now!\n");
    free(mess);
    free(temp);

  }
  return 0;
}
