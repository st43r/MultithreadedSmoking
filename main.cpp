#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include <vector>

std::mutex mtx;
std::condition_variable cv;
bool table[3] = {false, false, false};
bool smoking = false;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distrib(0, 2);

void bartender() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::unique_lock<std::mutex> lock(mtx);

        while (smoking) {
            cv.wait(lock);
        }

        table[0] = table[1] = table[2] = false;

        int first = distrib(gen);
        int second;
        do {
            second = distrib(gen);
        } while (second == first);

        table[first] = true;
        table[second] = true;

        std::cout << "BARTENDER placed components on the table: "
                  << (first == 0 ? "Tobacco" : first == 1 ? "Paper" : "Matches")
                  << " and "
                  << (second == 0 ? "Tobacco" : second == 1 ? "Paper" : "Matches") << std::endl;

        cv.notify_all();
    }
}

void smoker(int id, int required1, int required2) {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);

        while (!(table[required1] && table[required2]) || smoking) {
            cv.wait(lock);
        }

        smoking = true;

        table[required1] = table[required2] = false;

        std::cout << "SMOKER " << id << " is smoking a cigarette." << std::endl;

        lock.unlock();

        std::this_thread::sleep_for(std::chrono::seconds(2));

        lock.lock();
        smoking = false;
        cv.notify_all();
    }
}

int main() {
    std::thread b(bartender);
    std::vector<std::thread> smokers;

    smokers.emplace_back(smoker, 1, 1, 2);
    smokers.emplace_back(smoker, 2, 0, 2);
    smokers.emplace_back(smoker, 3, 0, 1);

    b.join();
    for (auto &s: smokers) {
        s.join();
    }

    return 0;
}

