#include <vector>
#include <gtest/gtest.h>
#include "rock-types.h"
#include "rock-match.h"
#include "mining-solver.h"
#include "mining-solver.cc"

TEST(MiningSolver, NoRocks) {
  miningsolver solver;

  std::vector<std::vector<int>> results = solver.solve();
  EXPECT_EQ(results.size(),0);
}

TEST(MiningSolver, OneRock) {
  miningsolver solver;

  rockdata rock(0,
                crystals::mixed,
                stone_shapes::udder,
                base_shapes::boxes,
                patterns::honeycomb);
  solver.addRock(rock);
  std::vector<std::vector<int>> results = solver.solve();
  EXPECT_EQ(results.size(),0);
} 

TEST(MiningSolver, TwoRocks) {
  miningsolver solver;

  rockdata rock(0,
                crystals::mixed,
                stone_shapes::udder,
                base_shapes::boxes,
                patterns::honeycomb);
  solver.addRock(rock);
  solver.addRock(rock);
  std::vector<std::vector<int>> results = solver.solve();
  EXPECT_EQ(results.size(),0);
} 

TEST(MiningSolver, ThreeSameRock) {
  miningsolver solver;

  rockdata rock1(0,
                crystals::mixed,
                stone_shapes::udder,
                base_shapes::boxes,
                patterns::honeycomb);
  rockdata rock2(1,
                crystals::mixed,
                stone_shapes::udder,
                base_shapes::boxes,
                patterns::honeycomb);
  rockdata rock3(2,
                crystals::mixed,
                stone_shapes::udder,
                base_shapes::boxes,
                patterns::honeycomb);
  solver.addRock(rock1);
  solver.addRock(rock2);
  solver.addRock(rock3);
  std::vector<std::vector<int>> results = solver.solve();
  EXPECT_EQ(results.size(),1);
} 

TEST(MiningSolver, ThreeDifferentRock) {
  miningsolver solver;

  rockdata rock1(0,
                crystals::mixed,
                stone_shapes::udder,
                base_shapes::boxes,
                patterns::honeycomb);
  rockdata rock2(1,
                crystals::long_shard,
                stone_shapes::bowl,
                base_shapes::fractured,
                patterns::wiggly);
  rockdata rock3(2,
                crystals::long_branched,
                stone_shapes::oval,
                base_shapes::flat,
                patterns::lined);
  solver.addRock(rock1);
  solver.addRock(rock2);
  solver.addRock(rock3);
  std::vector<std::vector<int>> results = solver.solve();
  EXPECT_EQ(results.size(),1);
} 

TEST(MiningSolver, ThreeRockNoMatch) {
  miningsolver solver;

  rockdata rock1(0,
                crystals::mixed,
                stone_shapes::udder,
                base_shapes::boxes,
                patterns::honeycomb);
  rockdata rock2(1,
                crystals::mixed,
                stone_shapes::udder,
                base_shapes::boxes,
                patterns::honeycomb);
  rockdata rock3(2,
                crystals::mixed,
                stone_shapes::udder,
                base_shapes::fractured,
                patterns::honeycomb);
  solver.addRock(rock1);
  solver.addRock(rock2);
  solver.addRock(rock3);
  std::vector<std::vector<int>> results = solver.solve();
  EXPECT_EQ(results.size(),0);
}

TEST(MiningSolver, FourSameRock) {
  miningsolver solver;

  rockdata rock1(0,
                crystals::mixed,
                stone_shapes::udder,
                base_shapes::boxes,
                patterns::honeycomb);
  rockdata rock2(1,
                crystals::mixed,
                stone_shapes::udder,
                base_shapes::boxes,
                patterns::honeycomb);
  rockdata rock3(2,
                crystals::mixed,
                stone_shapes::udder,
                base_shapes::boxes,
                patterns::honeycomb);
  rockdata rock4(3,
                crystals::mixed,
                stone_shapes::udder,
                base_shapes::boxes,
                patterns::honeycomb);
  solver.addRock(rock1);
  solver.addRock(rock2);
  solver.addRock(rock3);
  solver.addRock(rock4);
  std::vector<std::vector<int>> results = solver.solve();
  EXPECT_EQ(results.size(),5);
} 

TEST(MiningSolver, FiveRockSameAndDifferentMatch) {
  miningsolver solver;

  rockdata rock1(0,
                crystals::mixed,
                stone_shapes::udder,
                base_shapes::boxes,
                patterns::honeycomb);
  rockdata rock2(1,
                crystals::long_shard,
                stone_shapes::bowl,
                base_shapes::fractured,
                patterns::wiggly);
  rockdata rock3(2,
                crystals::long_branched,
                stone_shapes::oval,
                base_shapes::flat,
                patterns::lined);
  solver.addRock(rock1);
  solver.addRock(rock2);
  solver.addRock(rock3);
  solver.addRock(rock3);
  solver.addRock(rock3);
  std::vector<std::vector<int>> results = solver.solve();
  EXPECT_EQ(results.size(),4);
} 

TEST(MiningSolver, FiveRockSameAndDifferentMatchOutOfOrder) {
  miningsolver solver;

  rockdata rock1(0,
                crystals::long_branched,
                stone_shapes::oval,
                base_shapes::flat,
                patterns::lined);
  rockdata rock2(1,
                crystals::mixed,
                stone_shapes::udder,
                base_shapes::boxes,
                patterns::honeycomb);
  rockdata rock3(2,
                crystals::long_shard,
                stone_shapes::bowl,
                base_shapes::fractured,
                patterns::wiggly);
  rockdata rock4(3,
                crystals::long_branched,
                stone_shapes::oval,
                base_shapes::flat,
                patterns::lined);
  rockdata rock5(4,
                crystals::long_branched,
                stone_shapes::oval,
                base_shapes::flat,
                patterns::lined);
  solver.addRock(rock1);
  solver.addRock(rock2);
  solver.addRock(rock3);
  solver.addRock(rock4);
  solver.addRock(rock5);
  std::vector<std::vector<int>> results = solver.solve();
  EXPECT_EQ(results.size(),4);
} 

TEST(MiningSolver, RealWorld) {
  miningsolver solver;

  rockdata rock1(0,
                crystals::raw_crystal,
                stone_shapes::udder,
                base_shapes::rounded_edged,
                patterns::pattern_none);
  rockdata rock2(1,
                crystals::long_shard,
                stone_shapes::stacked,
                base_shapes::rounded_edged,
                patterns::pattern_none);
  rockdata rock3(2,
                crystals::raw_crystal,
                stone_shapes::udder,
                base_shapes::flat_oval,
                patterns::pattern_none);
  rockdata rock4(3,
                crystals::shards,
                stone_shapes::squashed,
                base_shapes::flat_oval,
                patterns::pattern_none);
  rockdata rock5(4,
                crystals::raw_crystal,
                stone_shapes::stacked,
                base_shapes::boxes,
                patterns::pattern_none);
  rockdata rock6(5,
                crystals::shards,
                stone_shapes::squashed,
                base_shapes::mounds,
                patterns::pattern_none);
  rockdata rock7(6,
                crystals::raw_crystal,
                stone_shapes::squashed,
                base_shapes::mounds,
                patterns::pattern_none);
  rockdata rock8(7,
                crystals::raw_crystal,
                stone_shapes::squashed,
                base_shapes::rounded_edged,
                patterns::pattern_none);
  rockdata rock9(8,
                crystals::long_shard,
                stone_shapes::udder,
                base_shapes::mounds,
                patterns::pattern_none);
  solver.addRock(rock1);
  solver.addRock(rock2);
  solver.addRock(rock3);
  solver.addRock(rock4);
  solver.addRock(rock5);
  solver.addRock(rock6);
  solver.addRock(rock7);
  solver.addRock(rock8);
  solver.addRock(rock9);
  std::vector<std::vector<int>> results = solver.solve();
  EXPECT_EQ(results.size(),5);
} 
