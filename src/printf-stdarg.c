/*
	Copyright 2001, 2002 Georges Menie (www.menie.org)
	stdarg version contributed by Christian Ettinger

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/*
	putchar is the only external dependency for this file,
	if you have a working putchar, leave it commented out.
	If not, uncomment the define below and
	replace outbyte(c) by your own function call.

*/

#include <stdarg.h>

#include "console.h"

/* Support files for GNU libc.  Files in the system namespace go here.
   Files in the C namespace (ie those that do not start with an
   underscore) go in .c.  */
#include <sys/types.h>


int __io_putchar(char  ch)
{
        if(ch == '\n')
                console_putchar('\r');

        console_putchar(ch);

        return ch;
}

char __io_getchar()
{
        char ch = console_getchar();
        return ch;
}

int _write(int file, char *ptr, int len)
{
        console_write(ptr, len);
        return len;
}

int _read(int file, char *ptr, int len)
{
        console_read((uint8_t *)ptr, len);

        return len;
}