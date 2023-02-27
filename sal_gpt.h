#ifndef SAL_GPT_H
#define SAL_GPT_H

#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 256
#define REQUEST_LENGTH 1024
#define REPLY_LENGTH 2048
#define MAX_TOKENS 512

typedef struct gpt_instance 
{
    char *API_KEY;
}
sal_thread;
struct sal_list
{
    char *mem;
    size_t len;
};

sal_thread *sal_new_thread(FILE *f);
char *sal_get_text_response(sal_thread *thr, char *prompt); // gets the response from gpt from a string prompt
char *sal_generate_request(sal_thread *thr, char *prompt);
size_t sal_write_function(void *contents, size_t size, size_t nmemb, void *userp);

#endif
