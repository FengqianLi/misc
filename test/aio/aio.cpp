#include <sys/types.h>
#include <aio.h>
#include <fcntl.h>
#include <errno.h>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int SIZE_TO_READ = 100;

int main()
{
	// open the file
    FILE* file;
	file = fopen("blah.txt", "r");

	if (file == NULL) {
		cout << "Unable to open file!" << endl;
		return 1;
	}
	// create the buffer
	char *buffer = new char[SIZE_TO_READ];

	// create the control block structure
	aiocb *cb = new aiocb;

	memset(cb, 0, sizeof(aiocb));
	cb->aio_nbytes = SIZE_TO_READ;
	cb->aio_fildes = fileno(file);
	cb->aio_offset = 3;
	cb->aio_buf = buffer;

	// read!
	if (aio_read(cb) == -1) {
		cout << "Unable to create request!" << endl;
		fclose(file);
	}

	cout << "Request enqueued!" << endl;

	// wait until the request has finished
	while (aio_error(cb) == EINPROGRESS) {
		cout << "Working..." << endl;
	}

	// success?
	int numBytes = aio_return(cb);

	if (numBytes != -1) {
		cout << "Success!" << endl;
        cout << "the content is:" << buffer << endl;
    }
	else
		cout << "Error!" << endl;

	// now clean up
	delete[]buffer;
	fclose(file);

	return 0;
}
