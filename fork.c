#include <stdio.h>
#include <unistd.h>

int gval=10;
int main(int argc,char *argv[]){
        pid_t pid;
        int lval=20;
        gval++,lval+=5;

        pid=fork();
        if(pid==0)
                gval+=2,lval+=2;
        else
                gval-=2,lval-=2;

        if(pid==0){
                printf("Child pid: [%d]\n",pid);
                printf("Child proc: [%d,%d] \n",gval,lval);
                sleep(60);
        }       else{
                printf("Parent pid: [%d]\n",pid);
                printf("Parent proc: [%d,%d] \n",gval,lval);
                sleep(60);

        }
        return 0;
}
