#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(){

	mkfifo("p1", 0644);
	mkfifo("p2", 0644);

	int w = open("p1", O_WRONLY, 0644);
	int r = open("p2", O_RDONLY, 0644);

	while (1){
    char buff[1000];
		printf("Send me something: ");
		fgets(buff, 1000, stdin);
		write(w, buff, strlen(buff));
		read(r, buff,1000);
		printf("Child done: %s\n", buff);
	}
  close(r);
  close(w);
	return 0;
}
