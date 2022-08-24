cmake_minimum_required(VERSION 3.17)
project(blockchain)

set(CMAKE_CXX_STANDARD 14)

add_executable(blockchain main.cpp Block.cpp Block.h Blockchain.cpp Blockchain.h TransactionData.cpp TransactionData.h Miner.cpp Miner.h)