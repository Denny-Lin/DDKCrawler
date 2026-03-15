#include <ddkcrawler/scheduler.h>

namespace ddkcrawler {

void Scheduler::push(const std::string& url) {
    url_queue.push(url);
}

std::string Scheduler::pop() {
    std::string url = url_queue.front();
    url_queue.pop();
    return url;
}

bool Scheduler::empty() {
    return url_queue.empty();
}

}