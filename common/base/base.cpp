#include "base.h"

namespace summit
{

TThreadID CurrentThreadID()
{
#ifdef __WINDOWS__
	return GetCurrentThreadId();
#else
	return pthread_self();
#endif
}

}

