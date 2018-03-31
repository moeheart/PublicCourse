package(default_visibility = ["//visibility:public"])

cc_library(
    name = "pointcloud",
    srcs = ["pointcloud.cc"],
    hdrs = ["pointcloud.h"],
    deps = [
        "@eigen//:eigen",
        "@glog//:glog",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":pointcloud",
    ],
)

cc_output(
    name = "output",
    srcs = ["output.cc"],
    deps = [
        ":pointcloud",
    ],
)

