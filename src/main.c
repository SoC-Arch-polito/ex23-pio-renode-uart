
#include <zephyr/kernel.h>
#include <string.h>
#include <zephyr/sys/printk.h>
#include <zephyr/console/console.h>

void main(void)
{
    printk("Hello! I'm running on the %s, a %s board.\n\n ",
           CONFIG_BOARD, CONFIG_ARCH);

	console_getline_init();
	printk("Enter a line finishing with Enter:\n");

	while (1)
    {
        printk("> ");
		char *s = console_getline();
		printk("Typed line: %s\n", s);
		printk("Last char was: 0x%x\n", s[strlen(s) - 1]);
	}
}
