#include <string>
#include <iostream>
#include <memory>
#include "rock-match.h"
#include "mining-solver.h"
#include "mining-solver.cc"
#include "mining-input.h"
#include "mining-input.cc"

int main(int argc, char** argv) {
  mininginput input;
  miningsolver solver;
  std::unique_ptr<std::vector<rockdata>> rocks = input.get_rock_data();
  for (rockdata rock: *rocks) {
    solver.addRock(rock);
  }
  std::vector<std::vector<int>> workloads = solver.solve();
  for (std::vector<int> workload: workloads) {
    bool first = true;
    for (int rock: workload) {
      if (first) {
        first = false;
      } else {
        std::cout<< ",";
      }
      std::cout << rock;
    }
    std::cout << std::endl;
  }
}
