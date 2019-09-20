cmake_minimum_required(VERSION 3.14)



SET(CMAKE_C_COMPILER /usr/bin/gcc)
SET(CMAKE_CXX_COMPILER /usr/bin/g++)

# Build Types

    
if(NOT CMAKE_BUILD_TYPE)

  set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE}
  CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel tsan asan lsan msan ubsan"
  FORCE)

endif()

project(run)
set(EXECUTABLE_NAME "run")

file(GLOB src ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB include ${PROJECT_SOURCE_DIR}/include/*.h)
file(GLOB audio ${PROJECT_SOURCE_DIR}/audio/*)

add_compile_options(-pedantic -Wall -g -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align  -Woverloaded-virtual -Wpedantic -Wconversion -Wunused -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast)
add_executable(${EXECUTABLE_NAME} ${main} ${include} ${src} ${audio} )

include_directories(${PROJECT_SOURCE_DIR}/include ${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "-pedantic -Wall -g -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast -fsanitize=leak -fsanitize=address  -fsanitize=undefined  -fsanitize=pointer-compare  -fsanitize=pointer-subtract")

set(SFML_DIR "./library/frameworks/SFML-2.5.1/lib/cmake/SFML")


find_package(GTest REQUIRED)
target_link_libraries(run sfml-graphics sfml-audio sfml-window sfml-system)

# testing

enable_testing() 
file(GLOB test_src_files ${PROJECT_SOURCE_DIR}/tests/*.cpp)

# add_executable(runAllTests ${test_src_files})
# add_test(Tests runAllTests)
# target_link_libraries(runAllTests sfml-graphics sfml-audio sfml-window sfml-system ${GTEST_LIBRARIES} pthread)