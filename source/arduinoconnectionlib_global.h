#ifndef ARDUINOCONNECTIONLIB_GLOBAL_H
#define ARDUINOCONNECTIONLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ARDUINOCONNECTIONLIB_LIBRARY)
#  define ARDUINOCONNECTIONLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ARDUINOCONNECTIONLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ARDUINOCONNECTIONLIB_GLOBAL_H
