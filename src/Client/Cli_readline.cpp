#include <readline/readline.h>
#include <readline/history.h>

#include "common.h"
#include "DefScript/DefScript.h"
#include "PseuWoW.h"
#include "Cli.h"

CliRunnable::CliRunnable(PseuInstance *p)
{
    _stop = false;
    _instance = p;
}

void CliRunnable::run(void)
{
    char *in;

    while(!_stop)
    {
		in = readline("> ");

		if(*in)
		{
			add_history(in);
			_instance->AddCliCommand(in);
		}
		
		free(in);
    }
}

void CliRunnable::stop(void)
{
	_stop=true;
	rl_free_line_state();
	rl_cleanup_after_signal();
	log("Shutting down CLI...");
}
