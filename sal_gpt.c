#include "sal_gpt.h"
#include <stdio.h>

sal_thread *sal_new_thread_input()
{
    printf("Enter API Key:\n");
    char buf[KEY_LENGTH];
    char format[16];
    sprintf(format, "%%%ds", KEY_LENGTH-1);
    scanf(format, buf);
    sal_thread *thread = malloc(sizeof(sal_thread));
    thread->API_KEY = malloc(KEY_LENGTH);
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

char *sal_generate_request(sal_thread *thr, char *prompt)
{
    char *request = malloc(REQUEST_LENGTH);
    sprintf(request, "curl https://api.openai.com/v1/completions -H \"Content-Type: application/json\" -H \"Authorization: Bearer %s\" -d '{\"model\": \"text-davinci-003\", \"prompt\": \"%s\", \"temperature\": 0, \"max_tokens\": %d}'", thr->API_KEY, prompt, MAX_TOKENS);
    return request;
}
