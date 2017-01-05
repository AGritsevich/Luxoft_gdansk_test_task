// Task 4
//  Implement a solution to the dining philosophers problem. The solution should be non-blocking and dead-lock free.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

const short kNumPhilosophers = 5;
short counters[kNumPhilosophers] = {0};

struct Fork {
  Fork(){};
  std::mutex mtx;
};

void Process(Fork* left_fork, Fork* right_fork, short phil_num)
{
  // ensures there are no deadlocks
  std::lock(left_fork->mtx, right_fork->mtx);

  std::lock_guard<std::mutex>
    left_fork_lock(left_fork->mtx, std::adopt_lock);
  std::lock_guard<std::mutex>
    right_fork_lock(right_fork->mtx, std::adopt_lock);

  std::cout << "Philosopher " << phil_num << " eats.\n";

  std::chrono::milliseconds timeout(500);
  std::this_thread::sleep_for(timeout);
};

void main()
{
  std::vector< std::unique_ptr<Fork> > forks(kNumPhilosophers);

  for (auto i = 0; i < kNumPhilosophers; ++i) {
    forks[i] = move(std::unique_ptr<Fork>(new Fork()));
  }

  std::vector<std::thread> tasks(kNumPhilosophers);

  tasks[0] = std::thread(Process,
    forks[0].get(),
    forks[kNumPhilosophers - 1].get(),
    0 + 1
    );

  for (auto i = 1; i < kNumPhilosophers; ++i) {
    tasks[i] = (std::thread(Process,
      forks[i - 1].get(),
      forks[i].get(),
      i + 1
      )
      );
  }
