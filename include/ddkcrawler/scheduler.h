#ifndef DDKCRAWLER_SCHEDULER_H
#define DDKCRAWLER_SCHEDULER_H

#include <queue>
#include <string>

namespace ddkcrawler {

class Scheduler {
public:
    void push(const std::string& url);
    std::string pop();
    bool empty();

private:
    std::queue<std::string> url_queue;
};

}

#endif