#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/usb.h>

#define PDEBUG(fmt, ...) printk("USB-SERIAL [%s]: " fmt, __func__, ##__VA_ARGS__)

static struct usb_device_id us_table[] = 
{
    {USB_DEVICE(0x1a86, 0x7523)},
    {}
};
MODULE_DEVICE_TABLE(usb, us_table);


static int us_probe(struct usb_interface *interface, const struct usb_device_id *device_id)
{
    PDEBUG("us_probe");
    return 0;
}

static void us_disconnect(struct usb_interface *interface)
{
    PDEBUG("us_disconnect");
}


static struct usb_driver us_driver = 
{
    .name = "usb_serial_driver",
    .id_table = us_table,
    .probe = us_probe,
    .disconnect = us_disconnect
};

static int __init us_init(void)
{
    PDEBUG("init");
    return usb_register(&us_driver);
}
module_init(us_init);

static void __exit us_exit(void)
{
    usb_deregister(&us_driver);
}
module_exit(us_exit);

MODULE_LICENSE("GPL");