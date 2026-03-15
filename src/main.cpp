#include <iostream>
#include <ddkcrawler/scheduler.h>

int main() {

    ddkcrawler::Scheduler scheduler;

    scheduler.push("https://example.com");
    scheduler.push("https://github.com");

    while (!scheduler.empty()) {
        std::cout << scheduler.pop() << std::endl;
    }

}