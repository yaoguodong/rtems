/*
 *  COPYRIGHT (c) 1989-2011.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 *
 *  $Id$
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <errno.h>
#include <timesys.h>
#include <rtems/timerdrv.h>
#include <pthread.h>
#include "test_support.h"

pthread_rwlock_t     rwlock;

void benchmark_pthread_rwlock_init(void)
{
  long end_time;
  int  status;
  pthread_rwlockattr_t attr;

  pthread_rwlockattr_init( &attr );
  benchmark_timer_initialize();
    status = pthread_rwlock_init( &rwlock, &attr );
  end_time = benchmark_timer_read();
  rtems_test_assert( status == 0 );

  put_time(
    "pthread_rwlock_init",
    end_time,
    1,        /* Only executed once */
    0,
    0
  );
}

void benchmark_pthread_rwlock_rdlock(void)
{
  long end_time;
  int  status;

  benchmark_timer_initialize();
    status = pthread_rwlock_rdlock(&rwlock);
  end_time = benchmark_timer_read();
  rtems_test_assert( status == 0 );

  put_time(
    "pthread_rwlock_rdlock - available",
    end_time,
    1,        /* Only executed once */
    0,
    0
  );
}

void benchmark_pthread_rwlock_unlock(bool do_print)
{
  long end_time;
  int  status;

  benchmark_timer_initialize();
    status = pthread_rwlock_unlock(&rwlock);
  end_time = benchmark_timer_read();
  if ( status == EPERM )
    puts( "The current thread does not own the read-write lock");
  else
    rtems_test_assert( status == 0 );

  if ( do_print ) {
    put_time(
      "pthread_rwlock_unlock - available",
      end_time,
      1,        /* Only executed once */
      0,
      0
    );
  }
}

void benchmark_pthread_rwlock_tryrdlock(void)
{
  long end_time;
  int  status;

  benchmark_timer_initialize();
    status = pthread_rwlock_tryrdlock(&rwlock);
  end_time = benchmark_timer_read();
  rtems_test_assert( status == 0 );

  put_time(
    "pthread_rwlock_tryrdlock - available",
    end_time,
    1,        /* Only executed once */
    0,
    0
  );
}

void benchmark_pthread_rwlock_timedrdlock(void)
{
  long end_time;
  int  status;

  benchmark_timer_initialize();
    status = pthread_rwlock_timedrdlock(&rwlock, 0);
  end_time = benchmark_timer_read();
  rtems_test_assert( status == 0 );

  put_time(
    "pthread_rwlock_timedrdlock - available",
    end_time,
    1,        /* Only executed once */
    0,
    0
  );
}

void benchmark_pthread_rwlock_wrlock(void)
{
  long end_time;
  int  status;

  benchmark_timer_initialize();
    status = pthread_rwlock_wrlock(&rwlock);
  end_time = benchmark_timer_read();
  rtems_test_assert( status == 0 );

  put_time(
    "pthread_rwlock_wrlock - available",
    end_time,
    1,        /* Only executed once */
    0,
    0
  );
}

void benchmark_pthread_rwlock_trywrlock(void)
{
  long end_time;
  int  status;

  benchmark_timer_initialize();
    status = pthread_rwlock_trywrlock(&rwlock);
  end_time = benchmark_timer_read();
  rtems_test_assert( status == 0 );

  put_time(
    "pthread_rwlock_trywrlock - available",
    end_time,
    1,        /* Only executed once */
    0,
    0
  );
}

void benchmark_pthread_rwlock_timedwrlock(void)
{
  long end_time;
  int  status;

  benchmark_timer_initialize();
    status = pthread_rwlock_timedwrlock(&rwlock,0);
  end_time = benchmark_timer_read();
  rtems_test_assert( status == 0 );

  put_time(
    "pthread_rwlock_timedwrlock - available",
    end_time,
    1,        /* Only executed once */
    0,
    0
  );
}

void benchmark_pthread_rwlock_destroy(void)
{
  long end_time;
  int  status;

  benchmark_timer_initialize();
    status = pthread_rwlock_destroy(&rwlock);
  end_time = benchmark_timer_read();
  rtems_test_assert( status == 0 );

  put_time(
    "pthread_rwlock_destroy",
    end_time,
    1,        /* Only executed once */
    0,
    0
  );
}

void *POSIX_Init(
  void *argument
)
{

  puts( "\n\n*** POSIX TIME PSXTMRWLOCK 01  ***" );

  /* initializing rwlock */
  benchmark_pthread_rwlock_init();
  /* applying a read lock */
  benchmark_pthread_rwlock_rdlock();
  /* unlocking rwlock */
  benchmark_pthread_rwlock_unlock( true );
  /* trying to apply a read lock when it is available */
  benchmark_pthread_rwlock_tryrdlock();
  /* unlocking rwlock */
  benchmark_pthread_rwlock_unlock( false );
  /* applying a timed read lock */
  benchmark_pthread_rwlock_timedrdlock();
  /* unlocking rwlock */
  benchmark_pthread_rwlock_unlock( false );
  /* applying a write lock */
  benchmark_pthread_rwlock_wrlock();
  /* unlocking rwlock */
  benchmark_pthread_rwlock_unlock( false );
  /* trying to apply a write lock, when it is available */
  benchmark_pthread_rwlock_trywrlock();
  /* unlocking rwlock */
  benchmark_pthread_rwlock_unlock( false );
  /* applying a timed write lock */
  benchmark_pthread_rwlock_timedwrlock();
  /* unlocking rwlock */
  benchmark_pthread_rwlock_unlock( false );
  /* destroying rwlock */
  benchmark_pthread_rwlock_destroy();

  puts( "*** END OF POSIX TIME PSXTMRWLOCK 01 ***" );
  rtems_test_exit(0);
}

/* configuration information */

#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_TIMER_DRIVER

#define CONFIGURE_MAXIMUM_POSIX_THREADS     1
#define CONFIGURE_MAXIMUM_POSIX_RWLOCKS     1
#define CONFIGURE_POSIX_INIT_THREAD_TABLE

#define CONFIGURE_INIT

#include <rtems/confdefs.h>
/* end of file */