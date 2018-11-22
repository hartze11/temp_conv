#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

void c2f(double temp){
  printf("%2.2f F\n", (temp * 9/5) + 32);
}

int main(int argc, char * argv[]){

  if (argc == 2) c2f(strtol(argv[1], NULL, 10));

  else {
    printf("got %d args\n", argc);
    printf("Enter a Celcius floating point value to convert to F. Exiting.\n");
    return(0);
  }

  return 0;
}
