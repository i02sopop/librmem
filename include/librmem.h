/*********************************************************************************
 * Copyright (c) 2019 librmem project (see AUTHORS)                              *
 *                                                                               *
 * This file is part of librmem.                                                 *
 *                                                                               *
 * librmem is free software: you can redistribute it and/or modify it under the  *
 * terms of the GNU General Public License as published by the Free Software     *
 * Foundation, either version 3 of the License, or (at your option) any later    *
 * version.                                                                      *
 *                                                                               *
 * librmem is distributed in the hope that it will be useful, but WITHOUT ANY    *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR *
 * A PARTICULAR PURPOSE.  See the GNU General Public License for more details.   *
 *                                                                               *
 * You should have received a copy of the GNU General Public License along with  *
 * librmem. If not, see <http://www.gnu.org/licenses/>.                          *
 ********************************************************************************/

#ifndef __LIBRMEM_H__
#define __LIBRMEM_H__

#include <stdlib.h>

void *xmalloc(size_t size);
void *xcalloc(size_t count, size_t size);
void *zmalloc(size_t size);
void *xrealloc(void *dst, size_t size);
char *xstrdup(const char *orig);
char *xstrndup(const char *orig, size_t n);
int xasprintf(char **strp, const char *fmt, ...);
int xvasprintf(char **strp, const char *fmt, va_list ap);

#endif // __LIBRMEM_H__
