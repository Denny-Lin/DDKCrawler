#include <ddkcrawler/downloader.h>
#include <curl/curl.h>

#include <string>
#include <cstdio>

namespace ddkcrawler {

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* buffer) {
    size_t total = size * nmemb;
    buffer->append((char*)contents, total);
    return total;
}

std::string Downloader::get(const std::string& url) {
    CURL* curl = curl_easy_init();
    std::string response;

    if (!curl) return response;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); 
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "DDKCrawler/0.1"); 
    
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L); 
    curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, ""); 

    CURLcode res = curl_easy_perform(curl);
    
    if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }

    curl_easy_cleanup(curl);
    return response;
}
}