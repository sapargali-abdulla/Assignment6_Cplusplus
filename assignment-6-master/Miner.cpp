#include "Miner.h"
mutex mu;
bool Miner::miner(Blockchain blockchain, TransactionData data) {
    lock_guard<mutex> guard(mu);

    //mu.lock();
    srand(time(0));
    int captcha;
    cout<<"Please complete these simple tasks in order to continue:"<<endl;
    bool isCorrect = false;
    int amount = 0;
    while(!isCorrect) {
        this_thread::sleep_for(chrono::milliseconds(1200));
        int a = (rand() % 10);
        int b = (rand() % 10);
        cout << a << " * " << b << " =";
        cin >> captcha;
        if (captcha == a*b){
            isCorrect = true;
            cout<<"Accepted, move on"<<endl;
        }else {
            cout<<"Wrong, try again"<<endl;
            cout<<"Attempts left: "<<2-amount<<endl;
            amount++;
        }
        if(amount==3) return false;
    }
    amount = 0;
    while(isCorrect) {
        this_thread::sleep_for(chrono::milliseconds(1200));
        int a = (rand() % 10);
        int b = (rand() % 10);
        cout << a << " + " << b << " =";
        cin >> captcha;
        if (captcha == a+b){
            isCorrect = false;
        }else {
            cout<<"Wrong, try again"<<endl;
            cout<<"Attempts left: "<<2-amount<<endl;
            amount++;
        }
        if(amount==3) return false;
    }
    cout<<"Captcha was solved"<<endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    //mu.unlock();
    return true;

}

bool Miner::miner2(Blockchain blockchain, TransactionData data) {
  //  mu.lock();
    srand(time(NULL));
    char letters[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char randLetters[] = {letters[rand() % 25], letters[rand() % 25], letters[rand() % 25]};

    char captcha[3];
    captcha[0] = randLetters[rand() % 3];
    captcha[1] = randLetters[rand() % 3];
    captcha[2] = randLetters[rand() % 3];

    char letter;
    int length = 0;
    cout<<"Please write these letters:"<<endl;
    for(int i=0;i<3;i++)
        cout << captcha[i];
    cout<<endl;
    string answer = "";

    int amount = 3;
    while(length != 3){
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << answer;
        for(int i = 1; i <= 3 - length; i++){
            cout << "*";
        }cout<<endl;
        cin >> letter;
        if(captcha[length] == letter){
            answer += letter;
            length++;
            cout << "Correct: ";
        }else {
            cout << "Wrong: ";
            amount--;
        }
        if(amount == 0) return false;
    } cout << answer << endl;

    cout<<"Captcha was solved"<<endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
 //   mu.unlock();
    return true;
}
