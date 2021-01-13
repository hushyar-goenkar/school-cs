/*Simple(but not so simple) ATM system made by Samarth Nasnodkar.*/
#include<bits/stdc++.h>
#include<fstream>
#include<string>
#include<time.h>
#include<sys/stat.h>
using namespace std;

class Account{
    public:
        bool logged = false; //To signify if the user is logged in or not.
        string universalId = "";
        string generateId(string userName , bool raw = false){
            //Generates the ID of the user based of factors like user"s name and the number of accounts already present.
            int lines = getDataLength();
            string alphabet = "abcdefghijklmnopqrstuvwxyz";
            string idInString = "";
            if(raw == false){
                idInString = to_string(lines);
            }
            int nameLength = userName.length();
            if(nameLength < 7){
                userName += "aaaaaaaa";
            }
            for(int i=0;i<7;i++){
                for(int j=0;j<26;j++){
                    if(tolower(userName[i]) == alphabet[j]){
                        int temp = j+1;
                        idInString += "." + to_string(temp);
                    }
                }
            }
            return idInString;//returning the ID in form of a string.

        }
        int getDataLength(){//Returns the number of accounts present.
            ifstream dataFile("ATMsystem/accounts.txt");
            string temp;
            int lines = 0;
            while(getline(dataFile , temp)){
                lines += 1;
            }
            return lines;
        }
        void updateBalance(string userId , float amount){
            //Updates the balance of the specified User.
            ifstream dataFile("ATMsystem/accounts.txt");
            string temp;
            string userIdInString = userId;
            string outputBalance;
            float outputNumericalbalance;
            bool found = false;
            while (getline(dataFile , temp))
            {
                if(temp.find(userIdInString) == 0){
                    outputBalance = temp.substr(temp.find(":") + 1);
                    outputNumericalbalance = stoi(outputBalance);
                    outputNumericalbalance += amount;
                    found = true;
                } 
            }
            if(found == true){
                string secondTemp;
                string content;
                ifstream dataFile("ATMsystem/accounts.txt");
                while(getline(dataFile , secondTemp)){
                    if(secondTemp.find(userIdInString) != 0){
                        content += secondTemp;
                        content += "\n";
                    }
                    else{
                        string edited;
                        edited = userIdInString + " : " + to_string(outputNumericalbalance) + "\n";
                        content += edited;
                    }
                }
                ofstream outputFile("ATMsystem/accounts.txt");
                outputFile<<content;
                outputFile.close();
            }
            
        }
        float getBalance(string userId){//Returns the balance of the User. -1 if account not present.
            ifstream dataFile("ATMsystem/accounts.txt");
            string temp;
            while(getline(dataFile , temp)){
                if(temp.find(userId) == 0){
                    string balance = temp.substr(temp.find(":") + 1);
                    float output = stof(balance);
                    return output;
                }
            }

            return -1;
        }
        bool createAccount(string userId , string name,float amount){//creates the Account. Returns true on success and false on some failure.
            ifstream dataFile("ATMsystem/accounts.txt");
            string temp;
            string content = "";
            while(getline(dataFile , temp)){
                if(temp.find(userId) == 0){
                    return false;
                }
            }

            ifstream newFile("ATMsystem/accounts.txt");
            while(getline(newFile , temp)){
                content += temp;
                content += "\n";
            }
            content += userId + " : " + to_string(amount) + "\n";
            ofstream outputFile("ATMsystem/accounts.txt");
            outputFile<<content;
            content = "";
            ifstream nameFile("ATMsystem/data.txt");
            while(getline(nameFile , temp)){
                content += temp;
                content += "\n";
            }
            content += userId + " :" + name + "\n";
            ofstream dFile("ATMsystem/data.txt");
            dFile<<content;
            return true;
        }
        string getName(string userId){
            //Returns the name of the User.
            ifstream dataFile("ATMsystem/data.txt");
            string temp;
            string empty = "";
            while(getline(dataFile , temp)){
                if(temp.find(userId) == 0){
                    string name = temp.substr(temp.find(":") + 1);
                    return name;
                }
            }
            return empty;
        }
        void lostId(string userName){//Comes into play when you lose your ID.
            string tempId = generateId(userName , true);
            ifstream dataFile("ATMsystem/accounts.txt");
            string temp;
            string availableIds = "";
            bool found = false;
            int i=0;
            while(getline(dataFile , temp)){
                string tempCounter = to_string(i);
                string tempstarter = tempCounter + tempId;
                if(temp.find(tempstarter) == 0){
                    found = true;
                    availableIds += tempstarter + "\n";
                }
                i+=1;
            }
            cout<<"Here are the ids which match your credentials:\n"<<availableIds;
        }
        void display(string userId){
            //Displays the balane of the user.
            float balance = getBalance(userId); 
            cout<<"Your balance : "<<balance<<endl;
        }
        void setup(){
            string s = "./ATMsystem";
            struct stat buffer;
            //Creates all the necessary files.
            if(stat (s.c_str(), &buffer) != 0)
                waitingLoop("Creating directories ...");
                system("mkdir ATMsystem");
            ifstream dataFile("ATMsystem/accounts.txt");
            if(dataFile.good() == false){
                waitingLoop("creating data files ...");
                ofstream createFIle("ATMsystem/accounts.txt");
                createFIle.close();
            }
            ifstream namesFile("ATMsystem/data.txt");
            if(namesFile.good() == false){
                ofstream fileCreate("ATMsystem/data.txt");
                fileCreate.close();
            }
            ifstream logsFile("ATMsystem/logs.txt");
            if(namesFile.good() == false){
                ofstream logCreate("ATMsystem/logs.txt");
                logCreate.close();
            }
            waitingLoop("Getting things ready ...");
        }
        void logEvent(string event){
            ifstream logs("ATMsystem/logs.txt");
            string temp;
            string content = "";
            time_t my_time = time(NULL);
            while(getline(logs,temp)){
                content += temp + "\n";
            }
            string log_Time = "";
            for(int i=0;i<strlen(ctime(&my_time)) - 1;i++){
                log_Time += ctime(&my_time)[i];
            }
            content += "[" + log_Time +"] " + event + "\n";
            ofstream Output("ATMsystem/logs.txt");
            Output<<content;
        }
        void login(){
            //Logs you in.
            string userId;
            cout<<"Enter your ID\n";
            cin>>userId;
            waitingLoop("Attempting Log In ...\n");
            float balance = getBalance(userId);
            if(balance == -1){
                char Red[] = "\033[1;31m";
                cout<<Red<<"There was no bank account matching your credentials. Please try again.\n";
                logEvent("Failed to log in " + userId);
                logged = false;
            }
            else{
                logged = true;
                char Green[] = "\033[0;32m";
                cout<<Green<<"Welcome back "<<getName(userId)<<endl;
                logEvent(userId + " logged in with their account");
                universalId = userId;
            }
        }
        int msleep(long msec)
        {
            //To make the script sleep.
            struct timespec ts;
            int res;

            if (msec < 0)
            {
                errno = EINVAL;
                return -1;
            }

            ts.tv_sec = msec / 1000;
            ts.tv_nsec = (msec % 1000) * 1000000;

            do {
                res = nanosleep(&ts, &ts);
            } while (res && errno == EINTR);

            return res;
        }
        void waitingLoop(string text = "Loading ..."){
            //The cool loading animation
            float progress = 0.0;
            char NC[] = "\033[0m";
            char Green[] = "\033[0;32m";
            char ORANGE_NO_FLASH[] = "\033[1;33m";
            cout<<ORANGE_NO_FLASH<<text<<endl;
            while (progress < 1.0) {

                int barWidth = 10;
                int pos = barWidth * progress;

                msleep(10);

                std::cout << "[";
                for (int i = 0; i < barWidth; i++) {
                    if (i < pos) std::cout << Green<<"=";
                    else if (i == pos) std::cout << Green<<"=";
                    else std::cout << " ";
                }
                std::cout << NC<<"]" << int(progress * 100.0) << " %\r";
                std::cout.flush();

                progress += 0.01;
            }
            std::cout << std::endl;
            system("clear");
        }

};

int main(){
    Account a;
    int choice = 0;
    string someTemp; 
    string theirId;
    float initialBalance;
    string yourname;
    int logChoice = 0;
    bool exit = false;
    char NC[] = "\033[0m";
    char ORANGE_NO_FLASH[] = "\033[1;33m";
    a.setup();
    while(!a.logged && !exit){
        cout<<NC<<"xxxxxxxxx Home Screen xxxxxxxxx\n\n1 ➜ Create an Account\n2 ➜ Manage your existing account\n3 ➜ Exit\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        cin>>logChoice;
        switch (logChoice)
        {
        case 1:
            float amount;
            bool done;
            cout<<"Enter the name\n";
            cin>>someTemp;
            cout<<"Enter the amount to be added\n";
            cin>>amount;
            theirId = a.generateId(someTemp);
            done = a.createAccount(theirId , someTemp,amount);
            if(done == true){
                cout<<"Your account has successfully been created.\nID:"<<theirId<<"\n";
                a.logEvent(someTemp + " created an account. ID : " + theirId);
            }
            else{
                cout<<"your account already exists.\n";
                a.logEvent("Creation of account of " + someTemp + " failed");
            }
            break;
        case 2:
            a.login();
            if(a.logged == true){
                do
                {
                    cout<<NC<<"-------------------------Main Menu-------------------------\n\n1 ➜ Display your balance\n2 ➜ Withdraw money\n3 ➜ Deposit money\n4 ➜ How it works\n5 ➜ Log Out\n\n-----------------------------------------------------------\n";
                    cin>>choice;
                    switch(choice)
                    {                    
                    case 1:
                        a.display(a.universalId);
                        a.logEvent(a.universalId + " checked their balance");
                        break;
                    case 2:
                        float withdrawnAmount; 
                        cout<<"Enter the amount to be withdrawn\n";
                        cin>>withdrawnAmount;
                        initialBalance = a.getBalance(a.universalId);
                        if (withdrawnAmount > initialBalance){
                            cout<<"You do no have enough money in your account.\n";
                            a.logEvent("failure of withdrawal of money. ID : " + a.universalId);
                        }
                        else{
                            a.updateBalance(a.universalId , -1*withdrawnAmount);
                            cout<<"Successfully withdrew Rs."<<withdrawnAmount<<" from your account\nYour current balance : "<<a.getBalance(a.universalId)<<endl;
                            a.logEvent("Successful withdrawal of money. ID : " + a.universalId + " Amount : " + to_string(withdrawnAmount));
                        }
                        break;
                    case 3:
                        float depositedAmount; 
                        cout<<"Enter the amount to be deposited.\n";
                        cin>>depositedAmount;
                        a.updateBalance(a.universalId , depositedAmount);
                        cout<<"Successfully deposited Rs."<<depositedAmount<<" from your account\nYour current balance : "<<a.getBalance(a.universalId)<<endl;
                        a.logEvent("Successful deposition of money. ID : " + a.universalId + " Amount : " + to_string(depositedAmount));
                        break;
                    case 4:
                        cout<<ORANGE_NO_FLASH<<"ATM system made by Samarth Nasnodkar©.\nThis ATM script works on an ID system.When a new account is created , an ID is generated by an algorithm which is unique to all accounts. This method is really useful when there are multiple accounts with same Names.\nAll the data is stored in 'accounts.txt' and 'data.txt' files which are created(if not already present) during the running of this script. The data is stored in a format of 'ID : balance' and 'ID : name'.\nAll Functions and their uses:\nvoid setup() ☛ Creates all the necessary files(accounts.txt and data.txt) during the startup of this application\nvoid display() ☛ Displays the balance of the user on the console\nstring getName() ☛ Returns the name of the User\nvoid waitingLoop() ☛ The loading animaiton generator\nvoid lostId() ☛ Finds all IDs matching the credentials of the user\nbool createAccount() ☛ Creates a new account for the user(returns true on success, false on failure)\nfloat getBalance() ☛ Returns the balance of the user(0 if the account is not present)\nvoid updateBalance() ☛ Updates the balance of the user\nint getDataLangth() ☛ Returns the number of currently active accounts\nstring generateid() ☛ Generates and returns the ID of the user with the provided credentials.\n---------The End---------\n\n";
                        break;
                    case 5:
                        a.waitingLoop("Logging out....");
                        a.logged = false;
                        a.logEvent("Successful log out of ID : " + a.universalId);
                        a.universalId = "";
                        break;
                    }

                } while (choice<6 && a.logged == true);
            }
            break;
        case 3:
            exit = true;
            break;
        }
        
    }

    return 0;
    
}