#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string>

using namespace std;

void list_dir(string dir_path)
{
	DIR *dir;
	struct dirent *ent;
	struct stat buf;
	if ((dir = opendir(dir_path.c_str())) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir(dir)) != NULL) {
			if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
				continue;
			char absPath[100];
			realpath(ent->d_name, absPath);
			printf("%s\n", absPath);
			printf("%s\n", ent->d_name);
			stat(absPath, &buf);
			if (S_ISDIR(buf.st_mode))
				list_dir(absPath);
		}
		closedir(dir);
	} else {
		cout << "can not open dir!" << endl;
	}

}

int main(int argc, char **argv)
{
	string dir;
	cin >> dir;
	list_dir(dir);
	return 0;
}
