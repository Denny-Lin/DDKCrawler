#include <ddkcrawler/downloader.h>
#include <curl/curl.h>

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

    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    return response;
}

}