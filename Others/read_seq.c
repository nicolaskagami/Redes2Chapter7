#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/timeb.h>

#define BUFFERSIZE (256*1024)
#define MEGABYTE (1024*1024)

/* Takes two arguments.  Arg 1 is file name.
arg 2 is number of megabytes to read. */

main(int argc, char * argv[])
{
long megabytes,i;
int inputfile;
char buffer[BUFFERSIZE];
struct timeb before,after;

if (argc !=3)
    {
    printf("Arguments are filename to read and how much to read in megabytes\n");
    return -1;
    }

inputfile = open(argv[1],O_RDONLY|O_SYNC);
megabytes=atol(argv[2]);

ftime(&before);

for (i=0 ; i<((MEGABYTE/BUFFERSIZE)*megabytes) ; i++)
   read(inputfile,buffer,BUFFERSIZE);

ftime(&after);

long timetowrite=after.time-before.time;
if (timetowrite > 0)
printf("Bytes per second read = %d\n",
    (MEGABYTE*megabytes)/timetowrite);

close(inputfile);

return 0;
}

