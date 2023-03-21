#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int before = memsize();
    printf("before allocating , size = %d \n", before);
    void *addr = malloc(sizeof(20000));
    int after = memsize();
    printf("after allocating , size = %d \n", after);
    free(addr);
    int afterFree = memsize();
    printf("after free  , size = %d \n", afterFree);
    exit(0, "");
}