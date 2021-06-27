#include <string>
#include <iostream>
#include <vector>
#include "ore-types.h"

std::unique_ptr<std::vector<rockdata>> mininginput::get_rock_data() {
  ore_markers ore = ore_type();
  int count = rock_count();
  int i = 0;
  auto rocks = std::make_unique<std::vector<rockdata>>();
  for (i = 0; i < count; i++) {
    rockdata rock = input_rock(i, ore);
    rocks->emplace_back(rock);
  }
  return rocks;
}

int mininginput::rock_count() {
  int rock_count;
  std::cout << "How many rocks? ";
  std::cin >> rock_count;
  return rock_count;
}

ore_markers mininginput::ore_type() {
  int ore_type;
  std::cout << "What kind of rocks?" << std::endl;
  std::cout << "0:Copper" << std::endl;
  std::cout << "1:Iron" << std::endl;
  std::cin >> ore_type;
  switch(ore_type) {
    case 0:
        return copper;
    case 1:
        return iron;
  }
  return null_ore;
}

rockdata mininginput::input_rock(const int &position, ore_markers ore) {
  std::cout << "Rock:" << position+1 << std::endl;
  int crystal = 0, stone = 0, base = 0, pattern = 0;
  if (ore.crystal)
    crystal = input_crystal_shape();
  if (ore.stone)
    stone = input_stone_shape();
  if (ore.base)
    base = input_base_shape();
  if (ore.pattern)
    pattern = input_pattern();
  return rockdata(position+1,
                  static_cast<crystals>(crystal),
                  static_cast<stone_shapes>(stone),
                  static_cast<base_shapes>(base),
                  static_cast<patterns>(pattern)); 
}

int mininginput::input_base_shape() {
  int base;
  std::cout << "Base shape:" << std::endl;
  std::cout << "     1:boxes" << std::endl;
  std::cout << "     2:fractured" << std::endl;
  std::cout << "     3:rounded edged" << std::endl;
  std::cout << "     4:round stone" << std::endl;
  std::cout << "     5:flat" << std::endl;
  std::cout << "     6:mounds" << std::endl;
  std::cout << "     7:flat oval" << std::endl;
  std::cin >> base;
  return base;
}

int mininginput::input_stone_shape() {
  int stone;
  std::cout << "Stone shape:" << std::endl; 
  std::cout << "     1:udder" << std::endl;
  std::cout << "     2:bowl" << std::endl;
  std::cout << "     3:oval" << std::endl;
  std::cout << "     4:stacked" << std::endl;
  std::cout << "     5:round" << std::endl;
  std::cout << "     6:angled" << std::endl;
  std::cout << "     7:squashed" << std::endl;
  std::cin >> stone;
  return stone;
}

int mininginput::input_crystal_shape() {
  int crystal;
  std::cout << "Crystal shape:" << std::endl; 
  std::cout << "     1:mixed" << std::endl;
  std::cout << "     2:long_shard" << std::endl;
  std::cout << "     3:long_branched" << std::endl;
  std::cout << "     4:long_smooth" << std::endl;
  std::cout << "     5:raw_crystal" << std::endl;
  std::cout << "     6:shards" << std::endl;
  std::cout << "     7:faceted" << std::endl;
  std::cin >> crystal;
  return crystal;
}

int mininginput::input_pattern() {
  int pattern;
  std::cout << "Pattern:" << std::endl; 
  std::cout << "     1:honeycomb" << std::endl;
  std::cout << "     2:wiggly" << std::endl;
  std::cout << "     3:lined" << std::endl;
  std::cout << "     4:volcanic" << std::endl;
  std::cout << "     5:splattered" << std::endl;
  std::cout << "     6:speckled" << std::endl;
  std::cin >> pattern;
  return pattern;
}
