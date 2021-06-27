#ifndef MININGSOLVER_H
#define MININGSOLVER_H

#include <vector>
#include "rock-types.h"

class miningsolver{
 public:
  std::vector<std::vector<int>> solve(void);
  void addRock(rockdata rock) {rocks_.emplace_back(rock);}

 private:
  void solver(rockmatch match, long unsigned int position);

  std::vector<std::vector<int>> workloads;
  std::vector<rockdata> rocks_;
};
#endif
