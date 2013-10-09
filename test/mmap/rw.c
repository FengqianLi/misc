#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd, len;
	char *buf;
	char *fname = "/tmp/file_mmap";
	ssize_t ret;
	struct stat sb;

	fd = open(fname, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if (fd == -1) {
		perror("open");
		return 1;
	}
	if (fstat(fd, &sb) == -1) {
		perror("stat");
		return 1;
	}

	buf = malloc(sb.st_size);
	if (buf == NULL) {
		perror("malloc");
		return 1;
	}
	ret = read(fd, buf, sb.st_size);
	for (len = 0; len < sb.st_size; ++len) {
		buf[len] = toupper(buf[len]);
		/*putchar(buf[len]); */
	}

	lseek(fd, 0, SEEK_SET);
	ret = write(fd, buf, sb.st_size);
	if (ret == -1) {
		perror("error");
		return 1;
	}

	if (close(fd) == -1) {
		perror("close");
		return 1;
	}
	free(buf);
	return 0;
}
