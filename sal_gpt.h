#ifndef SAL_GPT_H
#define SAL_GPT_H

#include <stdio.h>

typedef struct gpt_instance 
{
    char *API_KEY;
} 
sal_thread;

sal_thread *sal_new_thread();   // starts a new instance of gpt
sal_thread *sal_new_thread_file(FILE *f);
char *sal_get_text_response(sal_thread *thr, char *prompt); // gets the response from gpt from a string prompt

#endif