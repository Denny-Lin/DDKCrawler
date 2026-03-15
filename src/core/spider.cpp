#include <ddkcrawler/spider.h>

namespace ddkcrawler {

Spider::Spider(const std::string& start_url)
    : start_url_(start_url) {}

std::string Spider::start_url() const {
    return start_url_;
}

bool Spider::allowed(const std::string& url) const {
    return url.find(start_url_) != std::string::npos;

}

}