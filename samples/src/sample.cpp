#include "timeit/timeit.hpp"
#include "timeit/timers/chronotimer.hpp"
#include <iostream>
#include <ratio>

template <class... Ts>
double sum(Ts... args) {
  return (... + args);
}

int main() {
  TimeIt ti(sum<int, int, float, double, short>, ChronoTimer{}, 3, 1);
  ti.run(1, 2, 3, 4, 5);
  ti.run(5, 4, 3, 2, 1);

  for (auto t : ti.measurements()) {
    std::cout << t * std::milli::den << "ms\n";
  }

  std::cout << std::endl << ti.last() * std::milli::den << "ms\n";

  return 0;
}