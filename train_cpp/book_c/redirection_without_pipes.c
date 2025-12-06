#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	printf("Hello, world (pid: %d)\n", (int)getpid());
	int rc = fork();
	if (rc < 0)
	{
		perror("fork");
		exit(1);
	}
	else if (rc == 0)
	{
		printf("Hello, I'm child (pid: %d)\n", (int)getpid());
		close(STDOUT_FILENO);// open всегда возвращает самый маленький дескриптор, и так как 1 у нас свободен, open вернет именно его!
		open("./redirection_without_pipes.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

		char *myargs[3];
		myargs[0] = strdup("wc");
		myargs[1] = strdup("redirection_without_pipes.c");
		myargs[2] = NULL;
		execvp(myargs[0], myargs);
		exit(1);
	}
	else
	{
		int rc_wait = wait(NULL);
		printf("Hello, I'm parent of %d (rc_wait: %d) (pid: %d)\n", rc, rc_wait, (int)getpid());
	}
	return 0;
}