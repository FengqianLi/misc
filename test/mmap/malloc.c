#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv)
{
	char *brk_mm, *mmap_mm;

	printf("-----------------------\n");
	brk_mm = (char *)malloc(100);
	memset(brk_mm, '\0', 100);
	mmap_mm = (char *)malloc(500 * 1024);
	memset(mmap_mm, '\0', 500 * 1024);
	free(brk_mm);
	free(mmap_mm);
	printf("-----------------------\n");

	return 1;
}
