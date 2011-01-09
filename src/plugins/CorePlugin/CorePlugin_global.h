#ifndef COREPLUGIN_GLOBAL_H
#define COREPLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(COREPLUGIN_LIBRARY)
#  define COREPLUGINSHARED_EXPORT Q_DECL_EXPORT
#else
#  define COREPLUGINSHARED_EXPORT Q_DECL_IMPORT
#endif
#endif                                            // COREPLUGIN_GLOBAL_H
