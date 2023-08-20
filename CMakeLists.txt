cmake_minimum_required(VERSION 3.12)
project(QuantDaz VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add compile flags
# set(CMAKE_CXX_FLAGS "{CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

# Set optimisation
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# Create shared library
add_library(QuantDaz SHARED
  src/MCEuropeanCall.cpp
  src/BoxMullerSampling.cpp
  include/MCEuropeanCall.h
  include/BoxMullerSampling.h
)

# Include header files directories
target_include_directories(QuantDaz PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)

# Install the library and headers
install(TARGETS QuantDaz
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

install(DIRECTORY include/ DESTINATION include)

#add_executable(ExampleApp
#  src/main.cpp
#)

#target_link_libraries(ExampleApp PRIVATE QuantFinanceCpp)
