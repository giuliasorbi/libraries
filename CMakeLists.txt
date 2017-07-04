cmake_minimum_required(VERSION 2.8.11)
project ( Libraries )

if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

add_executable( libraries main.cpp category.cpp book.cpp library.cpp )
#add_executable( libraries main.cpp book.cpp category.cpp library.cpp )