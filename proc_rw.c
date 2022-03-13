#include<linux/fs.h>		//struct file_operations
#include<linux/proc_fs.h>
#include<linux/uaccess.h>
#include<linux/init.h>
#include<linux/sched.h>
#include<linux/seq_file.h>
#include<linux/module.h>	//all modules need this
#include<linux/slab.h>		//memory allocation, kzalloc

/*-----------------------------------------------------------------------*/
//metadata
/*-----------------------------------------------------------------------*/
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pham Doan HIeu");
MODULE_DESCRIPTION("Creates /proc entry with read/write functionality.");

static char *message = NULL;


static ssize_t write_msg(struct file *file, const char __user *buff, size_t cnt, loff_t *f_pos){
	char *temp = kzalloc((cnt+1),GFP_KERNEL); //allocate memory, (size and flag) - flag: type of memory

	if(!temp){
		return -ENOMEM;
	}

	if(copy_from_user(temp,buff,cnt)){
		kfree(temp);	//free memory
		return EFAULT;
	}

	kfree(message);	//free memory
	message=temp;
	return cnt;
}

/*-----------------------------------------------------------------------*/
//open, read, print message
/*-----------------------------------------------------------------------*/
static int show_the_proc(struct seq_file *a, void *v){
	seq_printf(a,"%s\n",message);
	return 0;
}

static int open_the_proc(struct inode *inode, struct file *file){
	return single_open(file,show_the_proc,NULL);
}

/*-----------------------------------------------------------------------*/
//kernel uses file_operations to access functions
//file associated with functions via the new_fops pointer
/*-----------------------------------------------------------------------*/

static struct proc_ops new_fops={
    .proc_open = open_the_proc,
    .proc_release = single_release,
    .proc_read = seq_read,
    .proc_lseek = seq_lseek,
    .proc_write = write_msg
};

/*-----------------------------------------------------------------------*/
//start
/*-----------------------------------------------------------------------*/
static int __init devstate_init(void){

	struct proc_dir_entry *new;

	new = proc_create("proc_rw", 0777, NULL, &new_fops); //create proc entry

	if(!new) {
		return -1;
	}
	else {
		printk(KERN_INFO "Loading module.....!\n");
	}
	return 0;
}

/*-----------------------------------------------------------------------*/
//end
/*-----------------------------------------------------------------------*/
static void __exit devstate_exit(void){
	remove_proc_entry("proc_rw", NULL);
	printk(KERN_INFO "Removing module.....!\n");
}

module_init(devstate_init);
module_exit(devstate_exit);