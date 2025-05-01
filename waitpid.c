#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char *argv[]){
        int status;
        pid_t pid=fork();

        if(pid==0)
        {
                sleep(15);
                return 24;
        }
        else
        {
                while(!waitpid(-1,&status,WNOHANG)) //-1을 인자로 받는것은 임의의 자식 프로세스가 종료되기를 기다리는것,WNOHANG=블로킹 상태X
                {
                        sleep(3);
                        puts("sleep 3sec.");
                }
                if(WIFEXITED(status))
                        printf("Child send %d\n",WEXITSTATUS(status));
        }
        return 0;
}
