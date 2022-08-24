#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include <iostream>
#include "TransactionData.h"
#include <mutex>
#include <thread>

class Block {
private:
    int index;
    TransactionData transactionData;
    size_t block_hash;
    size_t prev_hash;
public:
    int getIndex() const;
    void setIndex(int index);
    const TransactionData &getTransactionData() const;
    void setTransactionData(const TransactionData &transactionData);
    size_t getBlockHash() const;
    void setBlockHash(size_t blockHash);
    size_t getPrevHash() const;
    void setPrevHash(size_t prevHash);
    Block(int index, const TransactionData &transactionData, size_t prevHash);
    size_t generateHash() const;
};


#endif //BLOCKCHAIN_BLOCK_H
