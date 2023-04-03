#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main()
{
    int pid1 = fork();

    if (pid1 != 0)
    {
        set_cfs_priority(0);
        sleep(100);
    }
    else
    {
        set_cfs_priority(1);
        int pid2 = fork();
        if (pid2 == 0)
        {
            set_cfs_priority(2);
            sleep(50);
        }

        for (int i = 0; i < 1000000; i++)
        {
            if (i % 100000 == 0)
                sleep(1);
        }
    }
    int mypid = getpid();
    int rtime, cfs_priority, retime, stime;
    printf("my pid: %d\n", mypid);
    get_cfs_stats(getpid(), &cfs_priority, &rtime, &retime, &stime);
    printf("cfs priority is: %d\n", cfs_priority);
    printf("cfs rtime is: %d\n", rtime);
    printf("cfs retime is: %d\n", retime);
    printf("cfs stime is: %d\n", stime);

    return 0;
}
// another try that didnt success
//  #include "kernel/types.h"
//  #include "kernel/stat.h"
//  #include "user/user.h"
//  int main(int argc, char *argv[])
//  {
//      int pid0;
//      int pid1;
//      int pid2;
//      if (fork() == 0)
//      {
//          sleep(100);
//          set_cfs_priority(0);
//          for (int i = 1; i < 1000000; i++)
//          {
//              if (i % 100000 == 0)
//              {
//                  sleep(10);
//              }
//          }
//          pid0 = getpid();
//          int cfs;
//          int rtime;
//          int stime;
//          int retime;
//          get_cfs_stats(pid0, &cfs, &rtime, &stime, &retime);
//          printf("first child pid: %d\n", pid0);
//          printf("first child cfs priority: %d\n", cfs);
//          printf("first child rtime: %d\n ", rtime);
//          printf("first child stime: %d\n", stime);
//          printf("first child retime: %d\n", retime);
//          exit(0, "child 1 exited\n");
//      }
//      if (fork() == 0)
//      {
//          sleep(100);
//          set_cfs_priority(1);
//          for (int i = 1; i < 1000000; i++)
//          {
//              if (i % 100000 == 0)
//              {
//                  sleep(10);
//              }
//          }
//          pid1 = getpid();
//          int cfs;
//          int rtime;
//          int stime;
//          int retime;
//          get_cfs_stats(pid1, &cfs, &rtime, &stime, &retime);
//          // wait(&pid, 0);
//          printf("second child pid: %d\n", pid1);
//          printf("second child cfs priority: %d\n", cfs);
//          printf("second child rtime: %d\n ", rtime);
//          printf("second child stime: %d\n", stime);
//          printf("second child retime: %d\n", retime);
//          exit(0, "child 2 exited\n");
//      }
//      if (fork() == 0)
//      {
//          sleep(100);
//          set_cfs_priority(2);
//          for (int i = 1; i < 1000000; i++)
//          {
//              if (i % 100000 == 0)
//              {
//                  sleep(10);
//              }
//          }
//          pid2 = getpid();
//          int cfs;
//          int rtime;
//          int stime;
//          int retime;
//          get_cfs_stats(pid2, &cfs, &rtime, &stime, &retime);
//          // wait(&pid, 0);
//          printf("third child pid: %d\n", pid2);
//          printf("third child cfs priority: %d\n", cfs);
//          printf("third child rtime: %d\n ", rtime);
//          printf("third child stime: %d\n", stime);
//          printf("third child retime: %d\n", retime);
//          exit(0, "child 3 exited\n");
//      }
//      wait(&pid0, 0);
//      wait(&pid1, 0);
//      wait(&pid2, 0);
