#include <unistd.h>
#include <stdlib.h>

int main() {
    char* cmd = "ls";
    char* ar[4] = { "ls" , "-l", "/tmp", NULL};

    execvp(cmd, ar);
    exit(1); // nunca executado
}