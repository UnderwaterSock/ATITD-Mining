#include <vector>
#include "rock-types.h"
#include "rock-match.h"
#include "mining-solver.h"

std::vector<std::vector<int>> miningsolver::solve(void){
  rockmatch match;
  for (long unsigned int pos=0; pos<rocks_.size(); pos++) {
    match.add_rock(rocks_[pos]);
    solver(match, pos+1);
    match.remove_back();
  }
  return workloads;
}

void miningsolver::solver(rockmatch match, long unsigned int position) {
  // recursion base case
  if (rocks_.size() <= position) {
    return;
  }
  
  // Do search
  for (long unsigned int pos = position; pos < rocks_.size(); pos++) {
    if (match.add_rock(rocks_[pos])) {
      solver(match, pos+1);
      if(match.rock_count() >= 3) {
        workloads.emplace_back(match.rock_positions());
      }
      match.remove_back();
    }
  }
}
