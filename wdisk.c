#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<sys/time.h>
#define SIZE 8*1024*1024

int main(int argc, char ** argv)
{
    struct timeval tv0, tv1;
    struct timezone tz0, tz1;
    unsigned long long * buffer = malloc(SIZE*sizeof(long long));
    int rounds = 15;
    FILE* pFile;
    int j;

    pFile = fopen(argv[1], "wb");
    //setvbuf(pFile, NULL, _IONBF, 0);
    int ret = gettimeofday(&tv0, &tz0);

    for (j = 0; j < rounds; j++)
        fwrite(buffer, sizeof(long long),SIZE, pFile);

    fclose(pFile);
    ret = gettimeofday(&tv1, &tz1);
    
    double time = ((tv1.tv_sec - tv0.tv_sec) * 1000000 + tv1.tv_usec - tv0.tv_usec) * 1.0 / 1000000;
    float total_size = (float) SIZE*rounds*sizeof(long long);
    float speed = (float) total_size/time;

    //printf("Size: %f\n",total_size);
    //printf("Time: %f\n",time);
    //printf("%f MB/s\n",speed/(1024*1024));
    printf("%f\n",speed/(1024*1024));
    return 0;
}
