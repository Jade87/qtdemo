#ifndef CHEKOS_H
#define CHEKOS_H
#if defined(Q_OS_LINUX)
//Линукс
#elif defined(Q_OS_WIN)
#include "win32sys.h"
#endif
#endif // CHEKOS_H
