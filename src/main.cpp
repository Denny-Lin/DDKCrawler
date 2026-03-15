#include <iostream>
#include <ddkcrawler/downloader.h>

using namespace ddkcrawler;

int main() {

    Downloader downloader;

    std::string html = downloader.get("https://example.com");

    std::cout << html << std::endl;

    return 0;
}