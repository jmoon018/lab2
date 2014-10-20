#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
using namespace std;

int main()
{
	// FORK FOR LETTER 'A'
	pid_t success = fork();
	int status = 0;
	if(success == -1)
	{
		perror("Fork failed...");
	}
	else if(success == 0) // child process
	{
		for(int i = 0; i < 10000; i++)
		{
			cout << "A";
		}
		cout << endl;
	}
	else // parent process.. must print PID
	{
		pid_t waitId= waitpid(success, &status, 0);
		cout << "PID: " << success << endl; // print pid
	}
	return 0;
}
