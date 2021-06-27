#include <vector>
#include "rock-match.h"
#include <iostream>
using namespace std;

void rockmatch::remove_back() {
    positions_.pop_back();
    if (!crystals_match_) crystals_value_.pop_back();
    if (!stone_shapes_match_) stone_shapes_value_.pop_back();
    if (!base_shapes_match_) base_shapes_value_.pop_back();
    if (!patterns_match_) patterns_value_.pop_back();

    if (positions_.size() == 0) {
      if (crystals_value_.size() > 0) crystals_value_.pop_back();
      if (stone_shapes_value_.size() > 0) stone_shapes_value_.pop_back();
      if (base_shapes_value_.size() > 0) base_shapes_value_.pop_back();
      if (patterns_value_.size() > 0) patterns_value_.pop_back();
    }
}

bool rockmatch::add_first_rock(rockdata new_rock) {
  positions_.emplace_back(new_rock.get_position());
  crystals_value_.emplace_back(new_rock.get_crystal());
  stone_shapes_value_.emplace_back(new_rock.get_stone_shape());
  base_shapes_value_.emplace_back(new_rock.get_base_shape());
  patterns_value_.emplace_back(new_rock.get_pattern());
  return true;
}

bool rockmatch::add_second_rock(rockdata new_rock) {
  if (crystals_value_[0] == new_rock.get_crystal()) {
    crystals_match_ = true;
  } else {
    crystals_match_ = false;
    crystals_value_.emplace_back(new_rock.get_crystal());
  }

  if (stone_shapes_value_[0] == new_rock.get_stone_shape()) {
    stone_shapes_match_ = true;
  } else {
    stone_shapes_match_ = false;
    stone_shapes_value_.emplace_back(new_rock.get_stone_shape());
  }

  if (base_shapes_value_[0] == new_rock.get_base_shape()) {
    base_shapes_match_ = true;
  } else {
    base_shapes_match_ = false;
    base_shapes_value_.emplace_back(new_rock.get_base_shape());
  }

  if (patterns_value_[0] == new_rock.get_pattern()) {
    patterns_match_ = true;
  } else {
    patterns_match_ = false;
    patterns_value_.emplace_back(new_rock.get_pattern());
  }

  positions_.emplace_back(new_rock.get_position());
  return true;
}

bool rockmatch::rock_matches(rockdata new_rock) {
  if (crystals_match(new_rock.get_crystal()) &&
      stone_shapes_match(new_rock.get_stone_shape()) &&
      base_shapes_match(new_rock.get_base_shape()) &&
      patterns_match(new_rock.get_pattern())) {
    return true;
  }

  return false;
}

bool rockmatch::crystals_match(crystals crystal) {
  if (crystals_match_) {
    if (crystal==crystals_value_[0]) {
      return true;
    }
    return false; 
  }

  for (crystals crystal_value: crystals_value_) {
    if(crystal_value == crystal) return false;
  }
  return true;
}

bool rockmatch::stone_shapes_match(stone_shapes stone_shape) {
  if (stone_shapes_match_) {
    if (stone_shape==stone_shapes_value_[0]) {
      return true;
    }
    return false; 
  }

  for (stone_shapes stone_shape_value: stone_shapes_value_) {
    if(stone_shape_value == stone_shape) return false;
  }
  return true;
}

bool rockmatch::base_shapes_match(base_shapes base_shape) {
  if (base_shapes_match_) {
    if (base_shape==base_shapes_value_[0]) {
      return true;
    }
    return false; 
  }

  for (base_shapes base_shape_value: base_shapes_value_) {
    if(base_shape_value == base_shape) return false;
  }
  return true;
}

bool rockmatch::patterns_match(patterns pattern) {
  if (patterns_match_) {
    if (pattern==patterns_value_[0]) {
      return true;
    }
    return false; 
  }

  for (patterns pattern_value: patterns_value_) {
    if(pattern_value == pattern) return false;
  }
  return true;
}


bool rockmatch::add_rock(rockdata new_rock) {
  if (positions_.size() == 0) {
    return add_first_rock(new_rock);
  }

  if (positions_.size() == 1) {
    return add_second_rock(new_rock);
  }

  if (rock_matches(new_rock)) {
    if (!crystals_match_) crystals_value_.emplace_back(new_rock.get_crystal());
    if (!stone_shapes_match_)
      stone_shapes_value_.emplace_back(new_rock.get_stone_shape());
    if (!base_shapes_match_) 
      base_shapes_value_.emplace_back(new_rock.get_base_shape());
    if (!patterns_match_) patterns_value_.emplace_back(new_rock.get_pattern());
    positions_.emplace_back(new_rock.get_position());
    return true;
  }

  return false;
}
