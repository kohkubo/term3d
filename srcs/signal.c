#include "data.h"
#include <signal.h>
#include <sys/types.h>
#include <strings.h>

void	end_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	(void)sig;
	printf(ENABLE_CURSOR);
	exit(0);
}

void	receiver(void handler(int, siginfo_t *, void *))
{
	struct sigaction	act;

	bzero(&act, sizeof(struct sigaction));
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &act, NULL);
}
