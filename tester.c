#include "config.h"
#include "tester.h"
#include "timer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void
malloc_test (void)
{
  struct timespec start_time;
  struct timespec end_time;

  void **buffer = (void*) calloc(REPETITIONS, sizeof(void*));

  timer_start(&start_time);
  for(size_t i = 0; i < REPETITIONS; i++)
  {
    buffer[i] = malloc(BUFFER_SIZE);
  }
  timer_stop(&end_time);

  timer_print("malloc", &start_time, &end_time);

  for(size_t i = 0; i < REPETITIONS; i++)
  {
    free(buffer[i]);
  }
  free(buffer);
}

void
calloc_test (void)
{
  struct timespec start_time;
  struct timespec end_time;

  void **buffer = (void*) calloc(REPETITIONS, sizeof(void*));

  timer_start(&start_time);
  for(size_t i = 0; i < REPETITIONS; i++)
  {
    buffer[i] = calloc(BUFFER_SIZE, 1);
  }
  timer_stop(&end_time);

  timer_print("calloc", &start_time, &end_time);

  for(size_t i = 0; i < REPETITIONS; i++)
  {
    free(buffer[i]);
  }
  free(buffer);
}

void
malloc_plus_memset_test (void)
{
  struct timespec start_time;
  struct timespec end_time;

  void **buffer = (void*) calloc(REPETITIONS, sizeof(void*));

  timer_start(&start_time);
  for(size_t i = 0; i < REPETITIONS; i++)
  {
    buffer[i] = malloc(BUFFER_SIZE);
    memset(buffer[i], 0, BUFFER_SIZE);
  }
  timer_stop(&end_time);

  timer_print("malloc", &start_time, &end_time);

  for(size_t i = 0; i < REPETITIONS; i++)
  {
    free(buffer[i]);
  }
  free(buffer);
}
