#ifndef DDKCRAWLER_STORAGE_H
#define DDKCRAWLER_STORAGE_H

#include <string>

namespace ddkcrawler {

class Storage {
public:
    void save_page(const std::string& url, const std::string& html);
};

}

#endif