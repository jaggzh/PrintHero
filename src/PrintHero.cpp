#define _IN_PRINTHERO_C
#include <Arduino.h>
#include <stdarg.h>
#include "PrintHero.h"

/* Serial print from a list of type,data pairs:
 *  Example: spt(T_CHAR, 'H', T_CHARP, "ello world", T_END);
 */
void spt(int type, ...) {
	va_list ap;
	va_start(ap, type);
	do {
		/* Note: ... promotes char to int
		 * float is promoted to double */
		if (type == T_CH || type == T_INT) sp(va_arg(ap, int));
		else if (type == T_UCH || type == T_UINT) sp(va_arg(ap, unsigned int));
		else if (type == T_CHP) sp(va_arg(ap, char *));
		else if (type == T_LON) sp(va_arg(ap, long));
		else if (type == T_ULON) sp(va_arg(ap, unsigned long));
		else if (type == T_FLO) sp(va_arg(ap, double));
		else if (type == T_DOUB) sp(va_arg(ap, double));
		else if (type == T_STR) sp(va_arg(ap, const String));
		type = va_arg(ap, int); // next type
	} while (type != T_END); // should be 0
	va_end(ap);
}

