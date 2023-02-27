#include <curl/curl.h>
#include "sal_gpt.h"

#define whereami printf("%s: %d\n", __FUNCTION__, __LINE__)

int main(int argc, char **argv)
{
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (!curl)
        return 1;
    sal_thread *thr = sal_new_thread(NULL);
    struct sal_list data = (struct sal_list){malloc(1), 1};
    curl_easy_setopt(curl, CURLOPT_URL, sal_generate_request(thr, argv[1]));
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, sal_write_function);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&data);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    res = curl_easy_perform(curl);
    whereami;
    printf("res: %d\n", (int)res);
    if (res != CURLE_OK)
        return 0;
    whereami;
    printf("Size: %lu\nData: %s\n", (unsigned long)data.len, data.mem);
    curl_easy_cleanup(curl);
    free(data.mem);
}