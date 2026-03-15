#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "DDKCrawler starting..." << std::endl;

    // 1. initialize modules
    std::cout << "[Init] Spider" << std::endl;
    std::cout << "[Init] Scheduler" << std::endl;
    std::cout << "[Init] Downloader" << std::endl;
    std::cout << "[Init] Parser" << std::endl;
    std::cout << "[Init] Pipeline" << std::endl;
    std::cout << "[Init] Storage" << std::endl;

    std::cout << std::endl;
    std::cout << "Crawler engine running..." << std::endl;

    // crawler main loop (placeholder)
    for (int i = 0; i < 3; i++)
    {
        std::cout << "[Engine] crawling task " << i << std::endl;
    }

    std::cout << "Crawler finished." << std::endl;

    return 0;
}
