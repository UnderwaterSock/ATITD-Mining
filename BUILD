cc_library(
    name = "rockmatch",
    hdrs = ["rock-types.h",
            "rock-match.h",
            "rock-match-interface.h"],
    srcs = ["rock-match.cc"],
)

cc_library(
    name = "miningsolver",
    hdrs = ["mining-solver.cc"],
    srcs = ["mining-solver.h"],
    deps = [":rockmatch"],
)

cc_library(
    name = "mininginput",
    hdrs = ["mining-input.cc"],
    srcs = ["mining-input.h",
            "ore-types.h"],
    deps = [":rockmatch"],
)

cc_binary(
    name = "mining",
    srcs = ["mining.cc"],
    deps = [
           ":miningsolver",
           ":mininginput",
           ],
)

cc_test(
    name = "rockmatch-test",
    size = "small",
    srcs = ["rockmatch-test.cc"],
    deps = [
        ":rockmatch",
        "@gtest//:gtest_main",
    ],
)

cc_test(
    name = "miningsolver-test",
    size = "small",
    srcs = ["miningsolver-test.cc"],
    deps = [
        ":miningsolver",
        "@gtest//:gtest_main",
    ],
)
