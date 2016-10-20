/* signal test */
/* sigaction */
#include <signal.h>
#include <stdio.h>
#include <string.h>

void signal_handler(int signo);

int main()
{
	struct sigaction old_sa;
	struct sigaction new_sa;
	memset(&new_sa, 0, sizeof(new_sa));
	new_sa.sa_handler = &signal_handler;
	sigaction(SIGALRM, &new_sa, &old_sa);

	while (1);
	return 0;
}

void signal_handler(int signo)
{
	printf("signaled! %d \n", signo);
}

