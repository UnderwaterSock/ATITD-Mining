#ifndef ROCKTYPES_H
#define ROCKTYPES_H

enum crystals{
crystal_none,
mixed,
long_shard,
long_branched,
long_smooth,
raw_crystal,
shards,
faceted
};

enum stone_shapes{
stone_shape_none,
udder,
bowl,
oval,
stacked,
round,
angled,
squashed
};

enum base_shapes{
base_shape_none,
boxes,
fractured,
rounded_edged,
round_stone,
flat,
mounds,
flat_oval
};

enum patterns{
pattern_none,
honeycomb,
wiggly,
lined,
volcanic,
splattered,
speckled
};

class rockdata {
 public:
    rockdata(const int &position,
             crystals crystal,
             stone_shapes stone_shape,
             base_shapes base_shape,
             patterns pattern): position_(position),
                                crystal_(crystal),
                                stone_shape_(stone_shape),
                                base_shape_(base_shape),
                                pattern_(pattern) {}

    crystals get_crystal() {return crystal_;}
    stone_shapes get_stone_shape() {return stone_shape_;}
    base_shapes get_base_shape() {return base_shape_;}
    patterns get_pattern() {return pattern_;}
    int get_position() {return position_;}

 private:
  const int position_;
  const crystals crystal_;
  const stone_shapes stone_shape_;
  const base_shapes base_shape_;
  const patterns pattern_;

};

#endif
