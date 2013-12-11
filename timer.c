#include "config.h"
#include "timer.h"

#include <stdio.h>
#include <time.h>

void
timer_start (struct timespec *const start_time)
{
  clock_gettime(CLOCK_MONOTONIC_RAW, start_time);
}

void
timer_stop (struct timespec *const end_time)
{
  clock_gettime(CLOCK_MONOTONIC_RAW, end_time);
}

double
timer_get (const struct timespec *const start_time,
    const struct timespec *const end_time)
{
  return (end_time->tv_sec+end_time->tv_nsec*1.0e-9)
    -(start_time->tv_sec+start_time->tv_nsec*1.0e-9);
}

void
timer_print(const char *const name,
    const struct timespec *const start_time,
    const struct timespec *const end_time)
{
  double elapsed_time = timer_get(start_time, end_time);

  printf("%s took %e seconds, %e seconds / allocation of %d bytes\n",
      name, elapsed_time, elapsed_time/(double) REPETITIONS,
      BUFFER_SIZE);
}
