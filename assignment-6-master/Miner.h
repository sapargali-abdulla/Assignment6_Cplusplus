#ifndef BLOCKCHAIN_MINER_H
#define BLOCKCHAIN_MINER_H

#include <iostream>
#include <thread>
#include <ctime>
#include <cmath>
#include <mutex>

#include "Blockchain.h"
#include "Block.h"
#include "TransactionData.h"

using namespace std;

class Miner {
public:
    bool miner(Blockchain blockchain, TransactionData data);
    bool miner2(Blockchain blockchain, TransactionData data);
};


#endif //BLOCKCHAIN_MINER_H
