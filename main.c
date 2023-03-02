#include <curl/curl.h>
#include "sal_gpt.h"

#define whereami printf("%s: %d\n", __FUNCTION__, __LINE__)

int main(int argc, char **argv)
{
    curl_global_init(CURL_GLOBAL_DEFAULT);
    sal_thread *thr = sal_new_thread(0);
    if (sal_get_text_response(thr, argv[1]))
    {
        printf("%d\n", thr->res);
    }
    printf("Size: %lu\nData: %s\n", (unsigned long)thr->data.len, thr->data.mem);
    printf("\n");
    curl_easy_cleanup(thr->curl);
    free(thr->data.mem);
}