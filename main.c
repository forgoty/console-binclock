#include <stdio.h>
#include <time.h>
#include <unistd.h>


void getbinary(int num, char *str){
    *(str+6) = '\0';
    int mask = 0x20 << 1;
    while(mask >>= 1)
        *str++ = !!(mask & num) + '0';
}


int main(int argc, char** argv[]){
    char buff[6];

    while (1) {
        time_t t = time(NULL);
        struct tm* aTm = localtime(&t);

        getbinary(aTm->tm_hour, buff);
        printf("%s", buff);
        getbinary(aTm->tm_min, buff);
        printf(":%s", buff);
        getbinary(aTm->tm_sec, buff);
        printf(":%s \n", buff);

        sleep (1);//from <unistd.h>
        printf("\033c"); //clear screen
    }
    
        return 0;
}
