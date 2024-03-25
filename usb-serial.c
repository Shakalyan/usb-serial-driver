#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

MODULE_LICENSE("GPL");

static int __init us_init(void)
{
    printk(KERN_DEBUG "usb-serial init");
    return 0;
}
module_init(us_init);

static void __exit us_exit(void)
{
    printk(KERN_DEBUG "usb-serial exit");
}
module_exit(us_exit);