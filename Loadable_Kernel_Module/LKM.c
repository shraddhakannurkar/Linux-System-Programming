//used for all kernel modules
#include<linux/kernel.h>

//used for the module functionality
#include<linux/module.h>

//Gets called when module gets loaded
int init_module(void)
{	
	printk(KERN_INFO "Shraddha : Kernel module loaded\n");
	return 0;
}

//Gets called when module gets unloaded
void cleanup_module(void)
{
	printk(KERN_INFO "Shraddha : Kernel module unloaded\n");
}

