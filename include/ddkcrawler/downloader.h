#ifndef DDKCRAWLER_DOWNLOADER_H
#define DDKCRAWLER_DOWNLOADER_H

#include <string>

namespace ddkcrawler {

class Downloader {
public:
    std::string get(const std::string& url);
};

}

#endif