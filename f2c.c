#include <stdio.h>
#include <stdlib.h>

int f2c(double temp){
  printf("%2.2f C\n", (temp - 32) * 5/9);
  return 0;
}

int main(int argc, char * argv[]){

  if (argc == 2) f2c(strtol(argv[1], NULL, 10));
  else {
    printf("got %d args\n", argc);
    printf("Enter a F floating point value to convert to C. Exiting.\n");
    return(0);
  }

  return 0;
}
