#ifndef __TIMER_H
#define __TIMER_H

#include <time.h>

void
timer_start (struct timespec *const start_time);

void
timer_stop ();

double
timer_get ();

void
timer_print(const char *const name,
    const struct timespec *const start_time,
    const struct timespec *const end_time);

#endif
