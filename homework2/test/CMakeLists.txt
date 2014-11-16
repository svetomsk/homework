add_executable(test_runner
               SimpleTest.cpp
               gtest/gtest-all.cc
               gtest/gtest.h
               gtest/gtest_main.cc)


target_link_libraries(test_runner)