#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

bool CheckDirectoryExists(const char *szDirectory) 
{
    struct stat st;
    if(stat(szDirectory,&st) == 0) {
        if(st.st_mode & S_IFDIR != 0)
            return true;

    }
    return false;
}
