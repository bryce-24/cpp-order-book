cmake_minimum_required(VERSION 3.20)

project(OrderBook)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OrderBook
    src/main.cpp
    src/Order.cpp
    src/OrderBook.cpp
    src/PriceLevel.cpp
)

target_include_directories(OrderBook PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)