#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int mx_read_line(char **lineptr, int buf_size, int delim, const int fd) {
    char buf;
    int i = 0;
    

    while(read(fd, &buf, 1)) {
    	if (!buf)
    		return -1;
       
    	if (buf == delim) 
            return i;

    	*lineptr[i] = buf;
        i++;
        
    	if (i  == buf_size - 1) 
            return i;
    }

    return 0;
}
/*
 int main () {
    int fd = open("test", O_RDONLY);
    int buf_size = 6;
 	char **str = (char**)malloc(sizeof(char*) * 100);
    printf("%d\n", mx_read_line(str, buf_size, 32, fd));
    close(fd);
    printf("%s\n", str[0]);
    printf("%s\n", str[1]);
    printf("%s\n", str[2]);
    printf("%s\n", str[3]);  
    printf("%s\n", str[4]);    
 }*/
