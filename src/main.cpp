#include <iostream>
#include <unordered_set>

#include <ddkcrawler/downloader.h>
#include <ddkcrawler/parser.h>
#include <ddkcrawler/scheduler.h>

#include <curl/curl.h>

using namespace ddkcrawler;

int main() {

    curl_global_init(CURL_GLOBAL_ALL);

    Downloader downloader;
    Parser parser;
    Scheduler scheduler;

    std::unordered_set<std::string> visited;

    scheduler.push("https://example.com");

    int max_pages = 5;
    int count = 0;

    while (!scheduler.empty() && count < max_pages) {

        std::string url = scheduler.pop();

        // skip visited URLs
        if (visited.count(url)) {
            continue;
        }

        visited.insert(url);

        std::cout << "\nCrawling: " << url << std::endl;

        std::string html = downloader.get(url);

        if (html.empty()) {
            std::cerr << "Download failed." << std::endl;
            continue;
        }

        std::string title = parser.extract_title(html);
        std::cout << "Title: " << title << std::endl;

        auto links = parser.extract_links(html);
        auto filtered_links = parser.filter_links(links);

        for (const auto& link : filtered_links) {

            if (!visited.count(link)) {
                scheduler.push(link);
            }

        }

        count++;
    }

    curl_global_cleanup();

    return 0;
}