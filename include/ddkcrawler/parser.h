#ifndef DDKCRAWLER_PARSER_H
#define DDKCRAWLER_PARSER_H

#include <string>
#include <vector>

namespace ddkcrawler {

class Parser {
public:
    std::vector<std::string> extract_links(const std::string& html);

    std::string extract_title(const std::string& html);

    std::vector<std::string> filter_links(const std::vector<std::string>& links);};

}

#endif