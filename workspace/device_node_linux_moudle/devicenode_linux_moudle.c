#include <linux/init.h>
#include <linux/module.h>

/*driver register head file inlcude driver struct and function of register and deregister*/
#include <linux/platform_device.h>
/*register misc device head file*/
#include <linux/miscdevice.h>
/*包含文件结构体的头文件*/
#include <include/linux/fs.h>



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
