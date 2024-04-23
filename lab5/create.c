#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
	int file = creat("OS.txt", S_IRUSR | S_IWUSR);
	close(file);
	return 0;
}
