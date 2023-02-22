#ifndef SAL_GPT_H
#define SAL_GPT_H

#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gpt_instance 
{
    char *API_KEY;
} 
sal_thread;

sal_thread *sal_new_thread(FILE *f);
char *sal_get_text_response(sal_thread *thr, char *prompt); // gets the response from gpt from a string prompt
char *sal_generate_request(sal_thread *thr, char *prompt);

#endif
