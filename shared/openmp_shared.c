/* 
   OpenMP "shared" clause example

   Jim Teresco, CS 338, Williams College, CS 341, Mount Holyoke College
   Mon Feb 24 22:30:57 EST 2003

   Updated for CSIS-335, Siena College, Fall 2021
*/

#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]) {

  int thread_num = 997;

  /* by putting thread_num into the shared clause, we are 
     making it available to all threads */
#pragma omp parallel shared(thread_num)
  {
    /* this sure is unsafe, but it demonstrates our point */
    thread_num = omp_get_thread_num();
    printf("In parallel directive, thread_num=%d\n", thread_num);
    
  }

  /* and when we're done, it's got the value assigned to it by the
     last thread to assign to it */
  printf("Back from parallel directive, thread_num=%d\n", thread_num);

  return 0;
}
