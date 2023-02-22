#include <curl/curl.h>
#include "sal_gpt.h"

int main(int argc, char **argv)
{
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if (!curl)
        return 1;
    curl_easy_setopt(curl, CURLOPT_URL, )
    sal_thread *thr = sal_new_thread(NULL);
    char *request;
    curlk_easy_setopt(curl, CURLOPT_URL, request = sal_generate_request(thr, argv[1])
}
