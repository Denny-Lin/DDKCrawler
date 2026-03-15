#include <iostream>

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

    scheduler.push("https://example.com");

    int max_pages = 5;
    int count = 0;

    while (!scheduler.empty() && count < max_pages) {

        std::string url = scheduler.pop();

        std::cout << "\nCrawling: " << url << std::endl;

        std::string html = downloader.get(url);

        if (html.empty()) {
            std::cerr << "Download failed." << std::endl;
            continue;
        }

        // title
        std::string title = parser.extract_title(html);
        std::cout << "Title: " << title << std::endl;

        // extract links
        auto links = parser.extract_links(html);

        // filter links
        auto filtered_links = parser.filter_links(links);

        for (const auto& link : filtered_links) {

            std::cout << "Found link: " << link << std::endl;

            scheduler.push(link);
        }

        count++;
    }

    curl_global_cleanup();

    return 0;
}