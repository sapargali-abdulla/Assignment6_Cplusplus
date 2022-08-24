//
// Created by undefined on 02.11.2021.
//

#include "Block.h"
#include "TransactionData.h"

int Block::getIndex() const {
    return index;
}
void Block::setIndex(int index) {
    Block::index = index;
}
const TransactionData &Block::getTransactionData() const {
    return transactionData;
}
void Block::setTransactionData(const TransactionData &transactionData) {
    Block::transactionData = transactionData;
}
size_t Block::getBlockHash() const {
    return block_hash;
}
void Block::setBlockHash(size_t blockHash) {
    block_hash = blockHash;
}
size_t Block::getPrevHash() const {
    return prev_hash;
}
void Block::setPrevHash(size_t prevHash) {
    prev_hash = prevHash;
}
size_t Block::generateHash() const{
    string toHashS = to_string(transactionData.amount) + transactionData.receiverKey + transactionData.senderKey + to_string(transactionData.timestamp);
// 2 hashes to combine
    hash<string> tDataHash; // hashes transaction data string
    hash<string> prevHash; // re-hashes previous hash (for combination)
// combine hashes and get size_t for block hash
    return tDataHash(toHashS) ^ (prevHash(to_string(prev_hash)) << 1);

}
Block::Block(int index, const TransactionData &transactionData, size_t prevHash) : index(index),
                                                                                   transactionData(transactionData),
                                                                                   prev_hash(prevHash) {
    this->block_hash = generateHash();
}
