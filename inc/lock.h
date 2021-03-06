/*
  Copyright (c) 2008 by Jeff Weisberg
  Author: Jeff Weisberg <jaw @ tcp4me.com>
  Created: 2008-Dec-27 19:15 (EST)
  Function:
*/

#ifndef __fbdb_lock_h_
#define __fbdb_lock_h_

#include "defs.h"
#include "pthread.h"
#include "hrtime.h"

// try = 0 => got the lock

class Mutex {
private:
    pthread_mutex_t _mutex;

public:
    Mutex();
    ~Mutex();
    void lock(void);
    void unlock(void);
    int trylock(void);

private:
    DISALLOW_COPY(Mutex);
};

// ################################################################

class SpinLock {
private:
    pthread_spinlock_t _spin;

public:
    SpinLock();
    ~SpinLock();
    void lock(void);
    void unlock(void);
    int trylock(void);

private:
    DISALLOW_COPY(SpinLock);
};

// ################################################################

class RWLock {
private:
    pthread_rwlock_t _rwlock;

public:
    RWLock();
    ~RWLock();
    // do, or do not, there is no try
    void r_lock(void);
    void r_unlock(void);
    void w_lock(void);
    void w_unlock(void);
    int r_trylock(void);
    int w_trylock(void);

private:
    DISALLOW_COPY(RWLock);
};


#endif //__fbdb_lock_h_
