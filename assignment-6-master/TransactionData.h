#ifndef BLOCKCHAIN_TRANSACTIONDATA_H
#define BLOCKCHAIN_TRANSACTIONDATA_H

#include <iostream>
#include <string>
#include <ctime>
#include <mutex>
#include <thread>
using namespace std;

class TransactionData {

public:
    TransactionData(double amount, const string &senderKey, const string &receiverKey, time_t stamp);

    double amount;
    string senderKey;
    string receiverKey;
    time_t timestamp;
};


#endif //BLOCKCHAIN_TRANSACTIONDATA_H
