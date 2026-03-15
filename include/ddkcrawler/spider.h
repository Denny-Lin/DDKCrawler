#ifndef DDKCRAWLER_SPIDER_H
#define DDKCRAWLER_SPIDER_H

#include <string>
#include <vector>

namespace ddkcrawler {

class Spider {
public:
    Spider(const std::string& start_url);

    std::string start_url() const;

private:
    std::string start_url_;
};

}

#endif