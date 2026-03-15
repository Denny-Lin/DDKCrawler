#include <ddkcrawler/storage.h>
#include <iostream>

namespace ddkcrawler {

void Storage::save_page(const std::string& url, const std::string& html) {
    std::cout << "Saving page: " << url << std::endl;
}

}