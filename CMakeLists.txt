cmake_minimum_required(VERSION 3.10)
project(pixelize)

find_package(OpenCV REQUIRED)
# include_directories(${OpenCV_INCLUDE_DIRS})

# helpful compiler flags for gcc/clang
# the descriptions for these flags can be found on the GNU Compiler Collection's webpage.

# add the testing library Catch2
# enable_testing()
# add_library(catch2_main lib/catch2_main.cpp)
# target_include_directories(catch2_main PUBLIC lib)
# link the library so that other programs can get it
# link_libraries(catch2_main)

add_executable(pixelize src/pixelize.cpp)
# link_libraries(pixelize, ${OpenCV_LIBS})

# add_executable(pixelize_test src/pixelize.test.cpp)
# add_test(pixelize_test pixelize_test)
# add_executable(please_run pixelize.cpp)
target_link_libraries(pixelize ${OpenCV_LIBS})