#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/time.h>
#define SIZE 8*1024*1024

int main(int argc, char ** argv)
{
    srand(time(NULL));
    struct timeval tv0, tv1;
    struct timezone tz0, tz1;
    char * buffer = malloc(SIZE);
    FILE* pFile;
    unsigned long file_size;
    int j;

    pFile = fopen(argv[1], "rb");
    //setvbuf(pFile, NULL, _IONBF, 0);
    fseek(pFile, 0, SEEK_END);
    file_size = ftell(pFile);
    rewind(pFile);
    unsigned loop_size = (unsigned) ((file_size)/((SIZE)-1));
    int ret = gettimeofday(&tv0, &tz0);

    printf("%d\n",loop_size);
    for (j = 0; j < loop_size; j++)
    {
        //rewind(pFile);
        //int i = rand() % (loop_size);
        //int i = loop_size - j;
        //printf("%d,",i);
        //fseek(pFile, (SIZE)*(i), SEEK_SET);
        fread(buffer,1,(SIZE), pFile);
    }

    fclose(pFile);
    ret = gettimeofday(&tv1, &tz1);
    
    double time = ((tv1.tv_sec - tv0.tv_sec) * 1000000 + tv1.tv_usec - tv0.tv_usec) * 1.0 / 1000000;
    float speed = (float) file_size/time;

    //printf("Size: %u\n",file_size);
    //printf("Time: %f\n",time);
    //printf("%f MB/s\n",speed/(1024*1024));
    printf("%f\n",speed/(1024*1024));
    return 0;
}
