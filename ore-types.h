#ifndef ORETYPES_H
#define ORETYPES_H

struct ore_markers{
  bool crystal;
  bool stone;
  bool base;
  bool pattern;
};

ore_markers null_ore{false, false, false, false};
ore_markers copper{true, true, false, false};
ore_markers lead{true, true, true, false};
ore_markers iron{true, true, true, false};


#endif
