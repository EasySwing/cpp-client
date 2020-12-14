#include <iostream>
#include <string>
#include <curl/curl.h>


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(void)
{
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    std::string base_url = "https://easy-swing-staging.herokuapp.com/api/v1";
    std::string tag_uuid = "2b2f48c2-74e6-4d6b-98c1-111630bfa7ae";

    struct curl_slist *headers=NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "Authorization: Bearer Tq8poocim6ePqeRsWac2mHbqGIEUnhLE7efAXWbtqmUSdyUBfRVdof8JIFjC91xC");

    curl = curl_easy_init();
    if(curl) {
        std::string url = base_url + "/sign_in/" + tag_uuid;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        std::cout << readBuffer << std::endl;
    }
    return 0;
}
