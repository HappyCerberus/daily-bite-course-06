cc_library(
    name = "validate",
    srcs = ["validate.h"],
)

cc_test(
    name = "validate_test",
    srcs = ["validate_test.cc"],
    deps = [
        ":validate",
        "@catch2//:catch2_main",
    ],
)
