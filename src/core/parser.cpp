#include <ddkcrawler/parser.h>

#include <regex>

namespace ddkcrawler {

std::vector<std::string> Parser::extract_links(const std::string& html)
{
    std::vector<std::string> links;

    std::regex link_regex("<a\\s+[^>]*href=\"([^\"]*)\"");

    auto begin = std::sregex_iterator(html.begin(), html.end(), link_regex);
    auto end = std::sregex_iterator();

    for (auto i = begin; i != end; ++i)
    {
        links.push_back((*i)[1].str());
    }

    return links;
}

std::string Parser::extract_title(const std::string& html)
{
    std::regex title_regex("<title>(.*?)</title>");
    std::smatch match;

    if (std::regex_search(html, match, title_regex)) {
        return match[1].str();
    }

    return "";
}

std::vector<std::string> Parser::filter_links(const std::vector<std::string>& links)
{
    std::vector<std::string> filtered;

    for (const auto& link : links)
    {
        if (link.find("http") == 0)
        {
            filtered.push_back(link);
        }
    }

    return filtered;
}

}