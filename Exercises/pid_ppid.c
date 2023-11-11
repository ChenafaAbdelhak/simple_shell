#include <stdio.h>
#include <unistd.h>
/**
 * main - PID
 *
 * Return: Always 0.
 */

int main(void)
{
	pid_t pid, ppid;

	/**
	 * getpid()- returns the process ID (PID)
	 * of the calling process.
	 */
	pid = getpid();
	/**
	 * getppid() returns the process ID
	 * of the parent of the calling  process.
	 */
	ppid = getppid();
	printf("pid = %d\nparent pid = %d\n", pid, ppid);
	return (0);
}
