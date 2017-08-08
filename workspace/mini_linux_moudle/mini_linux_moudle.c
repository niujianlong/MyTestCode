#include <linux/init.h>
#include <linux/module.h>


MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("NJL");


static int hello_init(void)
{
	printk(KERN_EMERG "HELLO WORLD ENTER!\n");
	return 0;
}
static void hello_exit(void)
{
	printk(KERN_EMERG "HELLO WORLD EXIT!\n");
}

module_init(hello_init);
module_exit(hello_exit);
