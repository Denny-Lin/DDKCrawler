#include <iostream>
#include <ddkcrawler/downloader.h>
#include <curl/curl.h>

using namespace ddkcrawler;

int main() {
    // Initialize libcurl global state
    curl_global_init(CURL_GLOBAL_ALL);

    Downloader downloader;
    std::string html = downloader.get("https://example.com");

    if (!html.empty()) {
        std::cout << html << std::endl;
    } else {
        std::cerr << "Failed to fetch content or received empty response." << std::endl;
    }

    // Cleanup libcurl global state
    curl_global_cleanup();

    return 0;
}