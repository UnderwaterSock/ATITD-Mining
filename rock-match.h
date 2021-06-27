#ifndef ROCKMATCH_H
#define ROCKMATCH_H
#include <vector>
#include "rock-types.h"

class rockmatch {
 public:
    bool add_rock(rockdata new_rock);
    long unsigned int rock_count() {return positions_.size();}
    std::vector<int> rock_positions() {return positions_;}
    void remove_back();

 private:
    bool add_first_rock(rockdata new_rock);
    bool add_second_rock(rockdata new_rock);
    bool rock_matches(rockdata new_rock);
    bool crystals_match(crystals crystal);
    bool stone_shapes_match(stone_shapes stone_shape);
    bool base_shapes_match(base_shapes base_shape);
    bool patterns_match(patterns pattern);

    std::vector<int> positions_;
    bool crystals_match_;
    bool stone_shapes_match_;
    bool base_shapes_match_;
    bool patterns_match_;
    std::vector<crystals> crystals_value_;
    std::vector<stone_shapes> stone_shapes_value_;
    std::vector<base_shapes> base_shapes_value_;
    std::vector<patterns> patterns_value_;
};

#endif
