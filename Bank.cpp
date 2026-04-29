#include<iostream>
#include<fstream>>
#include "Bank.h"
using namespace std;

void Bank::createAccount(){

    int choice;
    cout<<"_______________________"<<endl;
    cout<<"|Choose account type   |"<<endl;
    cout<<"| 1. Saving account    |"<<endl;
    cout<<"| 2. Current account   |"<<endl;
    cout<<"| 0. Back              |"<<endl;
    cout<<"|______________________|"<<endl;
    cin>>choice;

    
    if(choice==1){

        ofstream file("SavingAccount.txt");      // Creating file so that data is stored using file handling
        
        cout<<"Enter Name: ";                   //Taking Data of user as an input
        getline(cin,Username);
        
        cout<<"Enter Father name: ";
        getline(cin,fatherName);
        
        cout<<"Enter NIC: ";
        cin>>NIC;

        cout<<"Enter your age: ";
        cin>>age;
        cin.ignore();

        cout<<"Enter your profession: ";
        getline(cin,profession);
        
        //Showing INTEREST rate and MINIMUM TRANSATION policy.
        cout<<"Interest rate on savings account is 5% per annum (p.a.)."<<endl;
        cout<<"A minimum average balance of PKR 1,000 must be maintained in the savings account."<<endl;
        
        file<<"Name : "<<Username<<endl;            //All the input data is stored inside the file
        file<<"Father name : "<<fatherName<<endl;
        file<<"NIC : "<<NIC<<endl;
        file<<"Age : "<<age<<endl;
        file<<"Profession : "<<profession<<endl;

        file.close();                               //Closing the file so that the data is stored compeletly
        cout<<"Account Saved Successfully"<<endl;
    }

    else if(choice==2){
        ofstream file("CurrentAccount.txt");         //Creating current account file to store data

        cout<<"Enter name: ";
        getline(cin,Username);

        cout<<"Enter father name: ";
        getline(cin,fatherName);

        cout<<"Enter NIC: ";
        cin>>NIC;
        cin.ignore();

        cout<<"Enter your age: ";
        cin>>age;

        cout<<"Enter your profession: ";
        getline(cin,profession);

        cout<<"There is no interest rate on Current Account."<<endl;
        cout<<"A minimum average balance of PKR 10,000 is required to maintain the current account"<<endl;

        file<<"Name : "<<Username<<endl;
        file<<"Father name : "<<fatherName<<endl;
        file<<"NIC : "<<NIC<<endl;
        file<<"Age : "<<age<<endl;
        file<<"Profession : "<<profession<<endl;
    }

    else if(choice==0){
        cout<<"Going back........"<<endl;
        //Add a going back path
    }

    else{
        cout<<"Wrong choice!!!!!!!\nTry again........"<<endl;
        createAccount();                                                  //For going back to account creation because of wrong choice....
    }



}

void Bank::closeAccount(){

}

void Bank::searchAccount(){

}

void Bank::showAccount(){

}
