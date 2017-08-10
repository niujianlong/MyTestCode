#include <linux/init.h>
#include <linux/module.h>

/*driver register head file inlcude driver struct and function of register and deregister*/
#include <linux/platform_device.h>
/*register misc device head file*/
#include <linux/miscdevice.h>
/*包含文件结构体的头文件*/
#include <linux/fs.h>

//#include <include/linux/module.h>

#define DRIVER_NAME "hello_ctl"
#define DEVICE_NAME "hello_ctl123"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("NJL");

static int hello_open (struct inode *inode, struct file *file){
	printk(KERN_EMERG"\thello_open\n");
	return 0;
}
static int hello_release (struct inode *inode, struct file *file){
	printk(KERN_EMERG"\thello_release\n");
	return 0;
}
#if 0
static int hello_ioctl1(struct inode *, struct file *, unsigned int, unsigned long){

}
#endif
static long hello_ioctl (struct file *file, unsigned int cmd, unsigned long argv){
	printk(KERN_EMERG"cmd = %d\n argv = %d\n",cmd,argv);
	return 0;
}
static struct file_operations hello_ops = 
{
	.owner = THIS_MODULE,
	.open = hello_open,
    .release = hello_release,
    .unlocked_ioctl = hello_ioctl, 

};

static struct miscdevice hello_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = DEVICE_NAME,
	.fops = &hello_ops,
};


static int hello_probe(struct platform_device *pdv){
	printk(KERN_EMERG "\tinitialized\n");
	misc_register(&hello_dev);
	return 0;
}	

static int hello_remove(struct platform_device *pdv){
	printk(KERN_EMERG "\thello_remove\n");
	misc_deregister(&hello_dev);
	return 0;
}	
static int hello_suspend(struct platform_device *pdv, pm_message_t state){
	printk(KERN_EMERG "\thello_suspend\n");
	return 0;
}	

static void hello_shutdown(struct platform_device *pdv){
	printk(KERN_EMERG "\thello_shutdown\n");
	return;
}	
static int hello_resume(struct platform_device *pdv){
	
	return 0;
}

struct platform_driver hello_driver = {
	.probe = hello_probe,
	.remove = hello_remove,
	.shutdown = hello_shutdown,
	.suspend = hello_suspend,
	.resume = hello_resume,
	.driver = {
		.name = DRIVER_NAME,
		.owner = THIS_MODULE,
	}
};

static int hello_init(void)
{
	int DriverState = 100;
	
	printk(KERN_EMERG "HELLO WORLD enter!\n");
	DriverState = platform_driver_register(&hello_driver);
	
	printk(KERN_EMERG "\tDriverState is %d\n",DriverState);
	return 0;
}
static void hello_exit(void)
{
	printk(KERN_EMERG "HELLO WORLD EXIT!\n");
	platform_driver_unregister(&hello_driver);	
}

module_init(hello_init);
module_exit(hello_exit);
