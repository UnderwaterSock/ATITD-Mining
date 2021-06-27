#include "rock-types.h"
#include "rock-match.h"
#include <gtest/gtest.h>

TEST(RockTypes, ConstructorAssignment) {
    rockdata rock(0,
                  crystals::mixed,
                  stone_shapes::udder,
                  base_shapes::boxes,
                  patterns::honeycomb);

    EXPECT_EQ(rock.get_position(), 0);
    EXPECT_EQ(rock.get_crystal(), crystals::mixed);
    EXPECT_EQ(rock.get_stone_shape(), stone_shapes::udder);
    EXPECT_EQ(rock.get_base_shape(), base_shapes::boxes);
    EXPECT_EQ(rock.get_pattern(), patterns::honeycomb);
}

TEST(RockMatch, EmptyCheck) {
    rockmatch match;
    EXPECT_EQ(match.rock_count(), 0);
}

TEST(RockMatch, AddOne) {
    rockmatch match;

    rockdata rock(0,
                  crystals::mixed,
                  stone_shapes::udder,
                  base_shapes::boxes,
                  patterns::honeycomb);
    ASSERT_TRUE(match.add_rock(rock));
    EXPECT_EQ(match.rock_count(), 1);
}

TEST(RockMatch, AddTwo) {
    rockmatch match;

    rockdata rock(0,
                  crystals::mixed,
                  stone_shapes::udder,
                  base_shapes::boxes,
                  patterns::honeycomb);
    ASSERT_TRUE(match.add_rock(rock));
    ASSERT_TRUE(match.add_rock(rock));
    EXPECT_EQ(match.rock_count(), 2);
}

TEST(RockMatch, AddThree) {
    rockmatch match;

    rockdata rock(0,
                  crystals::mixed,
                  stone_shapes::udder,
                  base_shapes::boxes,
                  patterns::honeycomb);
    ASSERT_TRUE(match.add_rock(rock));
    ASSERT_TRUE(match.add_rock(rock));
    ASSERT_TRUE(match.add_rock(rock));
    EXPECT_EQ(match.rock_count(), 3);
}

TEST(RockMatch, FailedAddMismatchCrystal) {
    rockmatch match;

    rockdata rock(0,
                  crystals::mixed,
                  stone_shapes::udder,
                  base_shapes::boxes,
                  patterns::honeycomb);
    rockdata badrock(1,
                     crystals::raw_crystal,
                     stone_shapes::udder,
                     base_shapes::boxes,
                     patterns::honeycomb);
    ASSERT_TRUE(match.add_rock(rock));
    ASSERT_TRUE(match.add_rock(rock));
    ASSERT_FALSE(match.add_rock(badrock));
    EXPECT_EQ(match.rock_count(), 2);
}

TEST(RockMatch, FailedAddMismatchStone) {
    rockmatch match;

    rockdata rock(0,
                  crystals::mixed,
                  stone_shapes::udder,
                  base_shapes::boxes,
                  patterns::honeycomb);
    rockdata badrock(1,
                     crystals::mixed,
                     stone_shapes::bowl,
                     base_shapes::boxes,
                     patterns::honeycomb);
    ASSERT_TRUE(match.add_rock(rock));
    ASSERT_TRUE(match.add_rock(rock));
    ASSERT_FALSE(match.add_rock(badrock));
    EXPECT_EQ(match.rock_count(), 2);
}

TEST(RockMatch, FailedAddMismatchBase) {
    rockmatch match;

    rockdata rock(0,
                  crystals::mixed,
                  stone_shapes::udder,
                  base_shapes::boxes,
                  patterns::honeycomb);
    rockdata badrock(1,
                     crystals::mixed,
                     stone_shapes::udder,
                     base_shapes::fractured,
                     patterns::honeycomb);
    ASSERT_TRUE(match.add_rock(rock));
    ASSERT_TRUE(match.add_rock(rock));
    ASSERT_FALSE(match.add_rock(badrock));
    EXPECT_EQ(match.rock_count(), 2);
}

TEST(RockMatch, FailedAddMismatchPattern) {
    rockmatch match;

    rockdata rock(0,
                  crystals::mixed,
                  stone_shapes::udder,
                  base_shapes::boxes,
                  patterns::honeycomb);
    rockdata badrock(1,
                     crystals::mixed,
                     stone_shapes::udder,
                     base_shapes::boxes,
                     patterns::wiggly);
    ASSERT_TRUE(match.add_rock(rock));
    ASSERT_TRUE(match.add_rock(rock));
    ASSERT_FALSE(match.add_rock(badrock));
    EXPECT_EQ(match.rock_count(), 2);
}

TEST(RockMatch, FailedAddMatchedCrystal) {
    rockmatch match;

    rockdata rockone(0,
                  crystals::mixed,
                  stone_shapes::udder,
                  base_shapes::boxes,
                  patterns::honeycomb);
    rockdata rocktwo(0,
                  crystals::long_shard,
                  stone_shapes::udder,
                  base_shapes::boxes,
                  patterns::honeycomb);
    rockdata badrock(1,
                     crystals::mixed,
                     stone_shapes::udder,
                     base_shapes::boxes,
                     patterns::honeycomb);
    ASSERT_TRUE(match.add_rock(rockone));
    ASSERT_TRUE(match.add_rock(rocktwo));
    ASSERT_FALSE(match.add_rock(badrock));
    EXPECT_EQ(match.rock_count(), 2);
}

TEST(RockMatch, FailedAddMatchedShape) {
    rockmatch match;

    rockdata rockone(0,
                  crystals::mixed,
                  stone_shapes::udder,
                  base_shapes::boxes,
                  patterns::honeycomb);
    rockdata rocktwo(0,
                  crystals::mixed,
                  stone_shapes::bowl,
                  base_shapes::boxes,
                  patterns::honeycomb);
    rockdata badrock(1,
                     crystals::mixed,
                     stone_shapes::bowl,
                     base_shapes::boxes,
                     patterns::honeycomb);
    ASSERT_TRUE(match.add_rock(rockone));
    ASSERT_TRUE(match.add_rock(rocktwo));
    ASSERT_FALSE(match.add_rock(badrock));
    EXPECT_EQ(match.rock_count(), 2);
}

TEST(RockMatch, FailedAddMatchedBase) {
    rockmatch match;

    rockdata rockone(0,
                  crystals::mixed,
                  stone_shapes::udder,
                  base_shapes::boxes,
                  patterns::honeycomb);
    rockdata rocktwo(0,
                  crystals::mixed,
                  stone_shapes::udder,
                  base_shapes::fractured,
                  patterns::honeycomb);
    rockdata badrock(1,
                     crystals::mixed,
                     stone_shapes::bowl,
                     base_shapes::boxes,
                     patterns::honeycomb);
    ASSERT_TRUE(match.add_rock(rockone));
    ASSERT_TRUE(match.add_rock(rocktwo));
    ASSERT_FALSE(match.add_rock(badrock));
    EXPECT_EQ(match.rock_count(), 2);
}

TEST(RockMatch, FailedAddMatchedPattern) {
    rockmatch match;

    rockdata rockone(0,
                  crystals::mixed,
                  stone_shapes::udder,
                  base_shapes::boxes,
                  patterns::honeycomb);
    rockdata rocktwo(0,
                  crystals::mixed,
                  stone_shapes::udder,
                  base_shapes::boxes,
                  patterns::wiggly);
    rockdata badrock(1,
                     crystals::mixed,
                     stone_shapes::bowl,
                     base_shapes::boxes,
                     patterns::honeycomb);
    ASSERT_TRUE(match.add_rock(rockone));
    ASSERT_TRUE(match.add_rock(rocktwo));
    ASSERT_FALSE(match.add_rock(badrock));
    EXPECT_EQ(match.rock_count(), 2);
}
