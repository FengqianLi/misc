#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstring>
#include <stdio.h>
#include <ctype.h>
#include <sys/mman.h>		/*mmap munmap */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

bool GetFileSize(const char * szFile, uint64_t & size)
{
    if (!szFile || !*szFile)
        return false;

    ifstream is(szFile, ifstream::binary);
    if (!is)
    {
        return false;

    }

    is.seekg(0, ios::end);
    size = is.tellg();
    is.close();
    return true;
}

int main(int argc, char *argv[])
{
    int fd;
    uint64_t size;
    char *buf;
    off_t len;
    char *fname = "/home/damon/mmap_test";

    fd = open(fname, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    GetFileSize(fname, size);

    buf = (char*)mmap(0, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (buf == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    for (len = 0; len < size; ++len) {
        buf[len] = toupper(buf[len]);
        /*putchar(buf[len]); */
    }

    if (munmap(buf, size) == -1) {
        perror("munmap");
        return 1;
    }
    return 0;
}
