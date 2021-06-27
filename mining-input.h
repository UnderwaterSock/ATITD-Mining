#ifndef MININGINPUT_H
#define MININGINPUT_H
#include "ore-types.h"

class mininginput {
 public:
  std::unique_ptr<std::vector<rockdata>> get_rock_data();
 private:
  int rock_count();
  void input_rocks();
  ore_markers ore_type();
  rockdata input_rock(const int &position, ore_markers ore);
  int input_base_shape();
  int input_stone_shape();
  int input_crystal_shape();
  int input_pattern();
};

#endif
