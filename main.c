/*
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	Charles Golonek, Mohit Nakrani
	CS 332: OS Project [C Kernel]
	Oct. 19, 2015
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*/

#include <linux/module.h>
#include <linux/sched.h>
#include <linux/kernel.h> // Needed for KERN_INFO

int init_module(void) {
  struct task_struct *task;
  char *dlm = " ";
  //int i = 0;

  //printk(KERN_INFO "  #\t  PID\t PPID\tSTATE\t UID\tCMD\tPOLICY\n");
  printk(KERN_INFO "#PID%sPPID%sSTATE%sUID%sPOLICY%sCMD\n", dlm, dlm, dlm, dlm, dlm);
  //printk(KERN_INFO "#===================================\n");

  for_each_process(task) {
	//++i;
	//printk(KERN_INFO "%3d\t%5d\t%5d\t%2lu\t%4d\t%u\t%s\n", i, task->pid, task->parent->pid, task->state, task->cred->uid.val, task->policy, task->comm);
	printk(KERN_INFO "%d%s%d%s%lu%s%d%s%u%s%s\n", task->pid, dlm, task->parent->pid, dlm, task->state, dlm, task->cred->uid.val, dlm, task->policy, dlm, task->comm);
  }
  return 0;
}

void cleanup_module(void) {
  //printk(KERN_INFO "\n");
}
