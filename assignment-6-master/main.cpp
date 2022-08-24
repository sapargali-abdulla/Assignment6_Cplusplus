#include "Blockchain.h"
#include "Block.h"
#include "TransactionData.h"
#include "Miner.h"
#include <thread>
#include <mutex>
#include <future>
using namespace std;
//mutex mu;
double getTotalVolume(Blockchain chain){
    double amount = 0;
    for(auto const &it : chain.chain){
        amount += it.getTransactionData().amount;
    }
    return amount;
}
void new_thread1(Blockchain *blockchain, TransactionData data, Miner miner){
    bool ans = miner.miner(*blockchain, data);
    //bool ans = miner.miner2(*blockchain, data);
    if(ans) blockchain->addBlock(data);
    else cout<<"No data has been added"<<endl;
}
void new_thread2(Blockchain *blockchain, TransactionData data, Miner miner){
    bool ans = miner.miner(*blockchain, data);
    //bool ans = miner.miner2(*blockchain, data);
    if(ans) blockchain->addBlock(data);
    else cout<<"No data has been added"<<endl;
}
int main(){
    Blockchain *blockchain = new Blockchain();

    blockchain->addBlock(*new TransactionData(10, "Manat", "Yerassyl", time(0)));
    blockchain->addBlock(*new TransactionData(20, "Abdu", "Andrey", time(0)));

    blockchain->printBlockchain();

    TransactionData data = *new TransactionData(30, "Eren", "Mikasa", time(0));
    TransactionData data1 = *new TransactionData(40, "Zoro", "Batman", time(0));

    Miner miner;

    thread th1(new_thread1, blockchain, data, miner);
    thread th2(new_thread2, blockchain, data1, miner);
    th1.join();
    th2.join();

    blockchain->printBlockchain();

    future<double> res = async(launch::async, getTotalVolume, *blockchain);
    double  dataRes = res.get();
    cout<<"Total volume is: "<<dataRes<<endl;

    cout << (blockchain->isBlockchainValid() ? "Valid" : "Invalid");
}
