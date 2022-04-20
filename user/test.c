// test

#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int test1();
int test2();

int main(int argc, char** argv){
    // test1();

    test2();
    return 0;
}

int test1(){
    fprintf(2, "hello world test 1 !, yanay gay \n");
    int pid = fork();
    if (pid == 0){
        while (1){
            fprintf(2, "yanay super gay \n");
            sleep(1);
        }
    }
    sleep(4);
    pause_system(5);
    // exit(0);
    return 0;
}

int test2(){
    // fprintf(2, "hello world test 2 ! , yanay gay \n");
    // int pid1 = fork();
    // if (pid1 == 0){
    //     while (1){
    //         fprintf(2, "I am yanay super gay and that is proc child 1 \n");
    //         sleep(2);
    //     }
    // }
    // int pid2 = fork();
    // if (pid2 == 0){
    //     while(1){
    //         fprintf(2, "I am yanay super gay and that is proc child 2 \n");
    //         sleep(2);
    //     }
    // }
    // sleep(7);
    // kill_system();
    // return 0;

    int pid;
    if((pid = fork()) < 0)
        exit(1);
    if(pid == 0){
        for (int i = 0; i < 30; i++)
        {
            fprintf(0, "**child: %d\n", i);
        }
        kill_system();
        for (int i = 0; i < 30; i++)
        {
            fprintf(0, "**child: %d\n", i);
        }
    }
    
    else
    {
        for (int i = 0; i < 20; i++)
        {
            fprintf(0, "~~parent: %d\n", i);
        }
        // fprintf(0, "parent pausing:\n");
        // pause_system(10);
        wait(0);
    }
    exit(0);
}
