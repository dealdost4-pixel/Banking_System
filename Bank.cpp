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
    ifstream file;
    ofstream tempfile("TempAccount.txt");

    string filename,line;

    int choise;
    cout<<"_____________________________"<<endl;
    cout<<"|Which account do you have:  |"<<endl;
    cout<<"| 1. Saving Account          |"<<endl;
    cout<<"| 2. Current Account         |"<<endl;
    cout<<"|____________________________|"<<endl;
    cout<<"Choose: ";
    cin>>choise;
    if(choise==1){
        filename="SavingAccont.txt";
        //filestore=filename;
        file.open(filename);

        while(getline(file,line)){
            tempfile<<line<<endl;
        }
    }
    if(choise==2){
        filename="CurrentAccount.txt";
        //filestore=filename;
        file.open(filename); 
        
        while(getline(file,line)){
            tempfile<<line<<endl;
        }
    } 

   
   
    char choice;
    cout<<"Do you want to close account (y=yes/n=no):";
    cin>>choice;
    int searchNIC;
    if(choice=='y'){
        cout<<"Enter NIC: ";
        cin>>searchNIC;

        bool found=false;

        while(file>>Username>>fatherName>>NIC>>age>>profession){
            if(searchNIC==NIC){
                cout<<"Account Found"<<endl;
                cout<<"Name: "<<Username<<endl;
                cout<<"Father name: "<<fatherName<<endl;
                cout<<"NIC: "<<NIC<<endl;
                cout<<"Profession: "<<profession<<endl;

                found=true;

                break;
            }
        }

        if(!found){
            cout<<"File does not found......"<<endl;
        }

        
    }

    file.close();

    
}

void Bank::searchAccount(){
    ifstream file;

    int choise;
    cout<<"Which account do you have: "<<endl;
    cout<<"1. Saving Account  "<<endl;
    cout<<"2. Current Account "<<endl;
    cout<<"Choose: ";
    cin>>choise;
    if(choise==1){
        file.open("SavingAccount.txt");
    }
    if(choise==2){
        file.open("CurrentAccount.txt");     
    }
   
    char choice;
    cout<<"Do you want to close account (y=yes/n=no):";
    cin>>choice;
    int searchNIC;
    if(choice=='y'){
        cout<<"Enter NIC: ";
        cin>>searchNIC;

        bool found=false;

        while(file>>Username>>fatherName>>NIC>>age>>profession){
            if(searchNIC==NIC){
                cout<<"Account Found"<<endl;
                cout<<"Name: "<<Username<<endl;
                cout<<"Father name: "<<fatherName<<endl;
                cout<<"NIC: "<<NIC<<endl;
                cout<<"Profession: "<<profession<<endl;

                found=true;

                break;
            }
        }

        if(!found){
            cout<<"File does not found......"<<endl;
        }

        
    }

    file.close();

}

void Bank::showAccount(){

}
