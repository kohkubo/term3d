#include "data.h"
#include <signal.h>
#include <sys/types.h>
#include <strings.h>

extern volatile sig_atomic_t	g_draw_flg;

void	end_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	(void)sig;
	g_draw_flg = 0;
}

void	set_sigaction(int sig, void handler(int, siginfo_t *, void *))
{
	struct sigaction	act;

	bzero(&act, sizeof(struct sigaction));
	act.sa_sigaction = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(sig, &act, NULL);
}
