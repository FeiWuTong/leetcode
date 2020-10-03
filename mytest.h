#ifndef __MYTEST_H__
#define __MYTEST_H__

#include<stdio.h>

volatile static int dummy = 1;

void output() {
    printf("%p\n", &dummy);
}

#endif