#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H

#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include "Block.h"
#include <future>
class Blockchain {
public:

    Block createFirstBlock();
    Block *getLatestBlock();

    vector<Block>chain;

    void printBlockchain();
    bool isBlockchainValid();
    Blockchain();

    void addBlock(TransactionData data);
};


#endif //BLOCKCHAIN_BLOCKCHAIN_H
