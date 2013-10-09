#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
	char *retBuffer;

	retBuffer = _fullpath(NULL, ".", 0);
	if (NULL == retBuffer) {
		printf("An error has occurred, errno is set to %d.\n", errno);

	} else
		printf("Full path name of current directory is %s.\n", retBuffer);
}
