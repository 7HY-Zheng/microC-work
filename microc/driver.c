// C driver for x86 code generated by Assembly/X86Comp.fs and NASM.
// Defines the initial entrypoint (main) which calls the assembly
// entrypoint (asm_main), and utility functions (printc, printf,
// checkargc) called from the assembly code.

// Originally by Niels Kokholm, March 2002
// sestoft@itu.dk * 2017-11-18

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void asm_main(int,int*);

int printc(int c) { printf("%c", c); return c; }

int printi(int i) { printf("%d ", i); return i; }

void checkargc(int a, int b) { 
  if (a!=b) {
    printf("Wrong argument count: expected %d but got %d\n",a,b); 
    exit(1);
  }
}

int main(int argc, char **argv) {
  int i, args[63];
  for (i=1; i<argc; i++) 
    args[i-1] = atoi(argv[i]);
  asm_main(argc-1,args);
  printf("\nRan %.3f s\n",(clock())*1.0/CLOCKS_PER_SEC);
  exit(0);
}
