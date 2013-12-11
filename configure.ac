AC_INIT(malloc-timer, 1)
AM_INIT_AUTOMAKE([dist-bzip2 no-dist-gzip silent-rules])
AM_SILENT_RULES([yes])

AC_PROG_CC_STDC

AC_SEARCH_LIBS([clock_gettime], [rt],
               [],
               [AC_MSG_FAILURE([can not find clock_gettime()])])

repetitions=1000000
buffer_size=4096

if [[ $((${repetitions}*${buffer_size})) -gt $((5*1024*1024*1024)) ]]; then
  AC_MSG_FAILURE([The requested allocation is too large])
fi
AC_MSG_NOTICE([requested allocation of $((${repetitions}*${buffer_size})) bytes])

AC_DEFINE_UNQUOTED([REPETITIONS], [${repetitions}], [The number of repetitions per test])
AC_DEFINE_UNQUOTED([BUFFER_SIZE], [${buffer_size}], [The size of the allocated buffer])

AC_CONFIG_HEADERS(config.h)
AC_OUTPUT(Makefile)
