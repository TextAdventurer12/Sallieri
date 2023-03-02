#include "sal_gpt.h"
#include <stdio.h>

sal_thread *sal_get_thread_input()
{
    printf("Enter API Key:\n");
    char buf[KEY_LENGTH];
    char format[24];
    sprintf(format, "%%%ds", KEY_LENGTH-1);
    scanf(format, buf);
    sal_thread *thread = malloc(sizeof(sal_thread));
    thread->API_KEY = malloc(KEY_LENGTH);
    strcpy(thread->API_KEY, buf);
    return sa
}

sal_thread *sal_get_thread_file ()
{
    char buf[256];
    fscanf(f, "%s", buf);
    sal_thread *thread = malloc(sizeof(sal_thread));
    strcpy(thread->API_KEY, buf);
    return sal_thread;
}

sal_thread *sal_new_thread(FILE *f)
{
    sal_thread *thread = f ? sal_get_thread_file(f) : sal_get_thread_input();
    if (!f)
        return sal_new_thread_input();
    thread->curl = curl_easy_init();
    thread->data = sal_init_list();
    if (!thread->curl)
        return NULL;
    curl_easy_setopt(thread->curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(thread->curl, CURLOPT_WRITEFUNCTION, sal_write_function);
    curl_easy_setopt(thread->curl, CURLOPT_WRITEDATA, (void *)&thread->data);
    curl_easy_setopt(thread->curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    return thread;
}

int sal_get_text_response(sal_thread *thr, char *prompt)
{
    curl_easy_setopt(thr->curl, CURLOPT_URL, sal_generate_request(thr, prompt));
    thr->res = curl_easy_perform(thr->curl);
    if (thr->res != CURLE_OK)
        return 1;
    return 0;
}

//   -H \"Content-Type: application/json\" -H \"Authorization: Bearer %s\" -d '{\"model\": \"text-davinci-003\", \"prompt\": \"%s\", \"temperature\": 0, \"max_tokens\": %d}'", thr->API_KEY, prompt, MAX_TOKENS
char *sal_generate_request(sal_thread *thr, char *prompt)
{
    char *request = malloc(REQUEST_LENGTH);
    sprintf(request, "https://api.openai.com/v1/completions");
    return request;
}

size_t sal_write_function (void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t real_size = size * nmemb;
    struct sal_list *mem = (struct sal_list *)userp;
    {
        char *ptr = realloc(mem->mem, mem->len + real_size + 1);
        if (!ptr)
            return 0;
        mem->mem = ptr;
    }
    memcpy(&(mem->mem[mem->len]), contents, real_size);
    mem->len += real_size;
    mem->mem[mem->len] = 0;

    return real_size;
}

struct sal_list sal_init_list()
{
    return (struct sal_list) {malloc(0), 0};
}