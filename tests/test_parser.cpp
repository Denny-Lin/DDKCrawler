#include <iostream>
#include <ddkcrawler/parser.h>

using namespace ddkcrawler;

int main() {

    Parser parser;

    std::string html =
        "<html>"
        "<head><title>Test Page</title></head>"
        "<body>"
        "<a href=\"https://example.com\">Example</a>"
        "<a href=\"https://google.com\">Google</a>"
        "</body>"
        "</html>";

    auto links = parser.extract_links(html);

    std::cout << "Links found:\n";

    for (auto& link : links) {
        std::cout << link << std::endl;
    }

    return 0;
}