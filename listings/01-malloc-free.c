#include <stdlib.h>
#include <stdio.h>

int main(){
  int *ip;
  //*ip = 5; // write: segfault
  //printf("%i", *ip); // read: segfault
  ip = malloc(sizeof(int)); // allocate memory
  if(ip == NULL) return 1; // success check

  *ip = 5; // work with memory

  free(ip); // free memory
  //free(ip); // crash: double free or corruption
  *ip = 5; // undefined but no crash
  printf("%i", *ip); // undefined but prints 5
  ip = NULL; // make sure the pointer is not used anymore
  //*ip = 5; // segfault
}
