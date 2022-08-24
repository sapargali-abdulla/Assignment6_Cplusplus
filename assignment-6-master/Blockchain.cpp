#include "Blockchain.h"
#include "Block.h"
#include "TransactionData.h"

Block Blockchain::createFirstBlock() {
    time_t current;
    TransactionData dataFirstBlock(0, "FirstBlock", "FirstBlock", time(&current));
    Block firstBlock(0, dataFirstBlock, 0);
    return firstBlock;
}

void Blockchain::addBlock(TransactionData data) {
    int index = (int)chain.size();
    size_t previousHash = getLatestBlock()->getBlockHash();
    Block newBlock(index, data, previousHash);
    chain.push_back(newBlock);
}

Block *Blockchain::getLatestBlock() {
    return &chain.back();
}

Blockchain::Blockchain() {
    Block firstBlock = createFirstBlock();
    chain.push_back(firstBlock);
}

void Blockchain::printBlockchain() {
    for(auto const &it : chain){
        cout <<"ID: "<< it.getIndex() << ": " << it.getTransactionData().timestamp << " " << it.getTransactionData().senderKey << " - " << it.getTransactionData().receiverKey << ", amount: " << it.getTransactionData().amount << "\n";
    }
}

bool Blockchain::isBlockchainValid() {
    for(auto const &it : chain){
        if(it.getBlockHash() != it.generateHash()) {
            return false;
        }
    }
    return true;
}
