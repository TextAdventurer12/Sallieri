#include "sal_gpt.h"
#include <stdio.h>

sal_thread *sal_new_thread_input()
{
    printf("Enter API Key:\n");
    char buf[256];
    scanf("%s", buf);
    printf("what");
    sal_thread *thread = malloc(sizeof(sal_thread));
    strcpy(thread->API_KEY, buf);
    return thread;
}

sal_thread *sal_new_thread(FILE *f)
{
    if (!f)
        return sal_new_thread_input();
    char buf[256];
    fscanf(f, "%s", buf);
    sal_thread *thread = malloc(sizeof(sal_thread));
    strcpy(thread->API_KEY, buf);
    return thread;
}

char *sal_get_text_response(sal_thread *thr, char *prompt)
{
    
}
