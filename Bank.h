#include<string>

class Bank{
private:

    std::string bankName,fatherName,Username,profession;
    int branchCode,NIC,age;
    float interest,transation,minimumBalance;

public:

    void createAccount();
    void closeAccount();
    void searchAccount();
    void showAccount();

};