/* 
   OpenMP "sections" clause example

   Jim Teresco, CS 338, Williams College, CS 341, Mount Holyoke College
   Mon Feb 24 22:30:57 EST 2003

   Updated for CSIS-335, Siena College, Fall 2021
*/

#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]) {

  int thread_num;

#pragma omp parallel sections private(thread_num)
  {
#pragma omp section
    {
    thread_num = omp_get_thread_num();
    printf("In this section, thread_num=%d\n", thread_num);
    }
#pragma omp section
    {
    thread_num = omp_get_thread_num();
    printf("But in this section, thread_num=%d\n", thread_num);
    }
#pragma omp section
    {
    thread_num = omp_get_thread_num();
    printf("And in this section, thread_num=%d\n", thread_num);
    }
#pragma omp section
    {
    thread_num = omp_get_thread_num();
    printf("Over here in this section, thread_num=%d\n", thread_num);
    }
#pragma omp section
    {
    thread_num = omp_get_thread_num();
    printf("Yet another section, with thread_num=%d\n", thread_num);
    }
#pragma omp section
    {
    thread_num = omp_get_thread_num();
    printf("Our last section, thread_num=%d\n", thread_num);
    }
  }
  return 0;
}
