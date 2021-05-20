
#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <stdint.h>

void console_initialize();

void console_putchar(const char sym);

uint8_t console_getchar(void);

void console_puts(const char *buf);

void console_write(const char *buf, int size);

void console_callback(void);

void console_task(void const *argument);

void console_read(uint8_t *p, uint16_t len);


#endif /* CONSOLE_H_ */
