#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int child_info(int child, int sleep_for){
  printf("I am child %d. My PID is %d.\n", child, getpid());
  sleep(sleep_for);
  printf("I, child %d, has just woken up! I took a %d second nap.\n", child, sleep_for);
  return sleep_for;
}

int main() {
  srand(time(NULL));
  int status;
  printf("Hi! I am a single parent. My PID is %d.\n",getpid()); //prints out initial message before fork
  int f1=fork(); //my firstborn
  int sleep_for=rand()%16+5; //chooses random # for child 1 to sleep for
//  printf("1 random time is %d\n", sleep_for );
  int sleep_for2=rand()%16+5; //chooses random # for child 2 to sleep for
//  printf("2 random time is %d\n", sleep_for2 );
  if (!f1) { //first child process (f1 would return 0)
    int slept_for = child_info(1, sleep_for);
    return slept_for;
  }
  else {
    int f2=fork(); //put in here bc no one wants grandkids... creates my secondborn
    if (!f2) { //child 2 process
      int slept_for = child_info(2,sleep_for2);
      return slept_for;
    }
    // after my children
    else {
      printf("-------------\n");
      printf("My child, %d has woken up after sleeping for %d seconds. What a pidty. I'm done. \n",wait(&status),WEXITSTATUS(status));
      return 0;
    }
  }
  return 0;
}
