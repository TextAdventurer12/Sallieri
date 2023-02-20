#include "sal_gpt.h"
#include <stdio.h>

sal_thread *sal_new_thread()
{
    char buf[256];
    while(scanf("%s", buf) == 1)
        printf("READ ERROR, TRY AGAIN");
    sal_thread *thread = malloc(sizeof(sal_thread));
    strcpy(thread->API_KEY, buf);
    return thread;
}

sal_thread *sal_new_thread_file(FILE *f)
{
    char buf[256];
    while (fscanf(f, "%s", buf) == 1);
    sal_thread *thread = malloc(sizeof(sal_thread));
    strcpy(thread->API_KEY, buf);
    return thread;
}