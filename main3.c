// Author: Maize Booker
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void  ChildProcess(void)
{
     int   i;
     int numOfIterations;
     int sleepTime;

     numOfIterations = rand() % 3 + 1; // random number between 1-30
     sleepTime = rand() % 10 + 1; // random number between 1-10

     for (i = 1; i <= numOfIterations; i++){
        printf("Child Pid: %d is going to sleep!\n", getpid());
        sleep(sleepTime);
        printf("Child Pid: %d is awake!\nWhere is my Parent: %d\n",getpid(), getppid());
     }
     printf("Done with iterations\n");
     exit(0);
}



void  ParentProcess(void)
{
     int   i;
     int exitstatus;
     int childID;

     for (i = 1; i <= 2; i++){
       childID = wait(&exitstatus);
       printf("Child Pid: %d has completed\n", childID);
     }
      
}

void  main(void)
{
     pid_t  pid;
     int    i;

     for (i = 1; i <= 2; i++) {
       pid = fork();
       if (pid == 0){
        printf("Forking\n");
        ChildProcess();
       } else if (pid < 0){
        printf("Error: Child processes could not be forked.\n");
        exit(0);
       }
     } 
     printf("ParentProcess\n");
     ParentProcess();
     
}
