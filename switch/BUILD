cc_binary(
    name = "test",
    srcs = ["test.cpp"],
    deps = ["process_interface"],
)

cc_library(
    name = "process_interface",
    srcs = ["process_interface.cpp"],
    hdrs = ["process_interface.h"],
    deps = ["mock_pigpio"],
    linkopts = ["-lpigpio",  # Link pigpio
        "-lrt",      # Link the real-time library (required by pigpio)
    ],
)

cc_library(
    name = "mock_pigpio",
    hdrs = ["mock_pigpio.h"],
    deps = [],
)