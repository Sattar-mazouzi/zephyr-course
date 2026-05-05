#include <zephyr/kernel.h>
#include <zephyr/init.h>

void board_early_init_hook(void)
{
    	printk("Board Initialized\n");
}
