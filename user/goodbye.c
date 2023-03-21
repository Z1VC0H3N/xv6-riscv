#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

// exit(x)-> exit(x,"")
// wait(x)->wait(0,0)
// sh.c

int main(int argc, char *argv[])
{
    exit(0, "Goodbye World XV6\n");
}
