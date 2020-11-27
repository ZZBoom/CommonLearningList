#include "plthook.h"
#include "hello.h"

#include <stdio.h>

static void my_hello()
{
  printf("hello ylw!\n");
}
    
int install_hook_function() {
    plthook_t *plthook;
    
    if (plthook_open(&plthook, "libhello.so") != 0) {
        printf("plthook_open error: %s\n", plthook_error());
        return -1;
    }
    if (plthook_replace(plthook, "say", (void*)my_hello, NULL) != 0) {
        printf("plthook_replace error: %s\n", plthook_error());
        plthook_close(plthook);
        return -1;
    }
    plthook_close(plthook);
    return 0;
}

int main() {
  //install_hook_function();
  say_hello();
  return 0;
}
