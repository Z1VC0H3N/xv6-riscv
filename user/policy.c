#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        exit(0, "missing one argument\n");
    }
    int out = set_policy(atoi(argv[1]));
    if (out == 0)
    {
        printf("success , policy changed to %s", argv[1]);
        exit(0, "\n");
    }
    exit(0, "bad argument\n");
}