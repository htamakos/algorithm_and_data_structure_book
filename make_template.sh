#!/bin/bash

BASEDIR="$1"
SOURCEDIR=$BASEDIR/src/
TESTDIR=$BASEDIR/test/
BUILDDIR=$BASEDIR/build/

mkdir $BASEDIR
mkdir -p $SOURCEDIR
mkdir -p $BUILDDIR
mkdir -p $TESTDIR

cat <<'EOS' > $BASEDIR/.gitignore
build
<<EOS

cat <<'EOS' > $BASEDIR/CMakeLists.txt

project(MY_PROGRAM)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#
# find pthread for googletest
#
find_package(Threads REQUIRED)

#
# enable external project
#
include(ExternalProject)
# set directory of external project
SET_DIRECTORY_PROPERTIES(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/../../../libs)

#
# import googletest as an external project
#
externalproject_add(
  googletest
  URL https://github.com/google/googletest/archive/release-1.8.1.zip
  UPDATE_COMMAND "" # skip update command
  INSTALL_COMMAND "" # skip install step
  )

externalproject_get_property(googletest source_dir)
set(GTEST_INCLUDE_PATH ${source_dir}/googletest/include)
set(GMOCK_INCLUDE_PATH ${source_dir}/googlemock/include)

externalproject_get_property(googletest binary_dir)
set(GTEST_LIBRARY_PATH ${binary_dir}/googlemock/gtest/${CMAKE_FIND_LIBRARY_PREFIXES}gtest.a) # in Unix, libgtest.a
set(GTEST_LIBRARY GTest::GTest)
add_library(${GTEST_LIBRARY} UNKNOWN IMPORTED)
set_target_properties(${GTEST_LIBRARY} PROPERTIES
  IMPORTED_LOCATION ${GTEST_LIBRARY_PATH}
  INTERFACE_LINK_LIBRARIES Threads::Threads)
add_dependencies(${GTEST_LIBRARY} googletest)

set(GMOCK_LIBRARY_PATH ${binary_dir}/googlemock/${CMAKE_FIND_LIBRARY_PREFIXES}gmock.a) # in Unix, libgmock.a
set(GMOCK_LIBRARY GTest::GMock)
add_library(${GMOCK_LIBRARY} UNKNOWN IMPORTED)
set_target_properties(${GMOCK_LIBRARY} PROPERTIES
  IMPORTED_LOCATION ${GMOCK_LIBRARY_PATH}
  INTERFACE_LINK_LIBRARIES Threads::Threads)
add_dependencies(${GMOCK_LIBRARY} googletest)

#
# create common variable
#
file(GLOB MY_SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)
set(MY_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/src)

#
# sub directories
#
add_subdirectory(src)
add_subdirectory(test)
EOS

cat <<'EOS' > $SOURCEDIR/CMakeLists.txt
add_executable(${PROJECT_NAME}
  ${MY_SRCS}
  )
target_include_directories(${PROJECT_NAME} PUBLIC
  ${MY_INCLUDE_PATH}
  )
EOS

cat <<'EOS' >$TESTDIR/CMakeLists.txt
set(MY_SRCS_MINUS_MAIN ${MY_SRCS})
list(REMOVE_ITEM MY_SRCS_MINUS_MAIN ${PROJECT_SOURCE_DIR}/src/main.cpp)

file(GLOB MY_TEST_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
set(MY_TEST_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(MY_BINARY_NAME "UnitTestExecutor")

add_executable(${MY_BINARY_NAME}
  ${MY_TEST_SRCS}
  ${MY_SRCS_MINUS_MAIN}
  )

target_include_directories(${MY_BINARY_NAME} PUBLIC
  ${GTEST_INCLUDE_PATH}
  ${GMOCK_INCLUDE_PATH}
  ${MY_INCLUDE_PATH}
  ${MY_TEST_INCLUDE_PATH}
  )

target_link_libraries(${MY_BINARY_NAME}
  GTest::GTest
  GTest::GMock
  )

add_dependencies(${MY_BINARY_NAME}
  googletest
  )
EOS

cat <<'EOS' > $SOURCEDIR/main.cpp
int main(){
  return 0;
}
EOS

cat <<'EOS' >$SOURCEDIR/SampleClass.hpp
class SampleClass
{
public:
  SampleClass() = default;
  ~SampleClass() = default;
  int calc();
};
EOS

#cat <<'EOS' > $SOURCEDIR/SampleClass.cpp
##include "SampleClass.hpp"
#
#EOS

cat <<'EOS' >$TESTDIR/main.cpp
#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char **argv)
{
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
EOS

cat <<'EOS' > $TESTDIR/SampleClassTest.cpp
#include "SampleClass.hpp"
#include <gtest/gtest.h>

TEST(calc, normal)
{
  ASSERT_EQ(0, 0);
}

EOS

cat <<'EOS' > $BASEDIR/build.sh
#!/bin/sh
rm -r build
mkdir build
cd build
cmake ..
make
EOS

cat <<'EOS' > $BASEDIR/exec.sh
sh build.sh
./build/src/MY_PROGRAM
EOS

cat <<'EOS' > $BASEDIR/test.sh
sh build.sh
./build/test/UnitTestExecutor
EOS
