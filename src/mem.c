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

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include <librlog.h>
#include <librmem.h>

void *
xmalloc(size_t size) {
	void *dst;

	if ((dst = malloc(size)) == NULL) {
		xerror("malloc(%lu)", (unsigned long)size);
		abort();
	}

	return dst;
}

void *
xcalloc(size_t count, size_t size) {
	void *dst;

	if ((dst = calloc(count, size)) == NULL) {
		xerror("calloc(%lu, %lu)", (unsigned long)count, (unsigned long)size);
	}

	return dst;
}

void *
zmalloc(size_t size) {
	return xcalloc(1, size);
}

void *
xrealloc(void *dst, size_t size) {
	if ((dst = realloc(dst, size)) == NULL) {
		xerror("realloc(%lu)", (unsigned long)size);
	}

	return dst;
}

char *
xstrdup(const char *orig) {
	char *dst;

	if ((dst = strdup(orig)) == NULL) {
		xerror("strdup(%lu)", (unsigned long)strlen(orig));
	}

	return dst;
}

char *
xstrndup(const char *orig, size_t n) {
	char *dst;

	if ((dst = strndup(orig, n)) == NULL) {
		xerror("strndup(%lu)", (unsigned long)strlen(orig));
	}

	return dst;
}


int
xasprintf(char **strp, const char *fmt, ...) {
	int res;
	va_list ap;

	va_start(ap, fmt);
	res = vasprintf(strp, fmt, ap);
	va_end(ap);
	if (res == -1) {
		xerror("asprintf");
	}

	return res;
}

int
xvasprintf(char **strp, const char *fmt, va_list ap) {
	int res;

	res = vasprintf(strp, fmt, ap);
	if (res == -1) {
		xerror("vasprintf");
	}

	return res;
}
