/*

Program:            Project for CPP
Objective:          To validate credit card and perform transactions and transformation
Authors:            Sharad Sharma, Serena Dangi, Anish Regmi
Date:               2022/04/25
Syntax Errors:      None
Logical Errors:     Problem while storing balance without registering the card along with balance first

*/

// PLEASE USE ACTUAL CREDIT CARD CODES TO PROCEED FURTHER
// DEMO CREDIT NUMBER : 4820 7953 3349 6565

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <windows.h>
#include "classes.h"
using namespace std;

int main()
{
    // code is for colour
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    // ends here

    int option;
    sno serialno(4624, 7482, 3324, 9780);
    sno serialno2(8910, 8192, 0421, 9018);
    sno serialno3(4235, 5900, 4143, 4840);
    CreditCard visaCard;
    CreditCard registerCreditCard;

    // Graphics here
    SetConsoleTextAttribute(h, 5);
    cout << "\n";
    cout << " .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. " << endl;
    cout << "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |" << endl;
    cout << "| | _____  _____ | || |  _________   | || |   _____      | || |     ______   | || |     ____     | || | ____    ____ | || |  _________   | |" << endl;
    cout << "| ||_   _||_   _|| || | |_   ___  |  | || |  |_   _|     | || |   .' ___  |  | || |   .'    `.   | || ||_   \\  /   _|| || | |_   ___  |  | |" << endl;
    cout << "| |  | | /\\ | |  | || |   | |_  \\_|  | || |    | |       | || |  / .'   \\_|  | || |  /  .--.  \\  | || |  |   \\/   |  | || |   | |_  \\_|  | |" << endl;
    cout << "| |  | |/  \\| |  | || |   |  _|  _   | || |    | |   _   | || |  | |         | || |  | |    | |  | || |  | |\\  /| |  | || |   |  _|  _   | |" << endl;
    cout << "| |  |   /\\   |  | || |  _| |___/ |  | || |   _| |__/ |  | || |  \\ `.___.'\\  | || |  \\  `--'  /  | || | _| |_\\/_| |_ | || |  _| |___/ |  | |" << endl;
    cout << "| |  |__/  \\__|  | || | |_________|  | || |  |________|  | || |   `._____.'  | || |   `.____.'   | || ||_____||_____|| || | |_________|  | |" << endl;
    cout << "| |              | || |              | || |              | || |              | || |              | || |              | || |              | |" << endl;
    cout << "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |" << endl;
    cout << "'----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " << endl;
    cout << "\n";
    cout << "\n";
    cout << "\n";

    cout << " ____  _  _  ____    _  _   __   ____  ____    ____   __   __ _  __ _    ____  ____  ____  _  _  __  ___  ____  ____ " << endl;
    cout << "(_  _)/ )( \\(  __)  ( \\/ ) / _\\ (__  )(  __)  (  _ \\ / _\\ (  ( \\(  / )  / ___)(  __)(  _ \\/ )( \\(  )/ __)(  __)/ ___)" << endl;
    cout << "  )(  ) __ ( ) _)   / \\/ \\/    \\ / _/  ) _)    ) _ (/    \\/    / )  (   \\___ \\ ) _)  )   /\\ \\/ / )(( (__  ) _) \\___ \\" << endl;
    cout << " (__) \\_)(_/(____)  \\_)(_/\\_/\\_/(____)(____)  (____/\\_/\\_/\\_)__)(__\\_)  (____/(____)(__\\_) \\__/ (__)\\___)(____)(____/" << endl;
    cout << "\n";
    cout << "\n";

    SetConsoleTextAttribute(h, 6);
    // set colour to yellow

    cout << "--------------------------------" << endl;
    cout << "WHAT SERVICE WOULD YOU LIKE TO CHOOSE:" << endl;
    cout << "\n";
    SetConsoleTextAttribute(h, 7);

    // set colour to white

Transaction:

    SetConsoleTextAttribute(h, 9); // sets color light blue
    cout << "\n1. Register Credit Card\n2. Perform Transactions\n3. Check the exchange rates\n4. Convert your currency\n5. Exit" << endl;
    cout << endl;
    SetConsoleTextAttribute(h, 3); // sets color skyblue
    cout << "Enter your option(1/2/3/4/5): ";
    cin >> option;
    if (option == 1)
    {
        sno registerSno;
        char dump1, dump2, dump3;
        int buck1, buck2, buck3, buck4;
        cout << "Enter your credit card serial number: ";
        cin >> buck1 >> buck2 >> buck3 >> buck4;
        registerSno.setBuck1(buck1);
        registerSno.setBuck2(buck2);
        registerSno.setBuck3(buck3);
        registerSno.setBuck4(buck4);
        registerCreditCard.setSno(registerSno);
        if (validateCard(registerCreditCard) == true)
        {
            string name;
            float balance;
            int securityCode;

            // Graphics Here 01

            SetConsoleTextAttribute(h, 2); // sets color green
            cout << "\n";

            cout << " ____  ____  ____  __   __   __      __ _  _  _  _  _  ____  ____  ____    _  _  ____  ____  __  ____  __  ____  ____     " << endl;
            cout << "/ ___)(  __)(  _ \\(  ) / _\\ (  )    (  ( \\/ )( \\( \\/ )(  _ \\(  __)(  _ \\  / )( \\(  __)(  _ \\(  )(  __)(  )(  __)(    \\  " << endl;
            cout << "\\___ \\ ) _)  )   / )( /    \\/ (_/\\  /    /) \\/ (/ \\/ \\ ) _ ( ) _)  )   /  \\ \\/ / ) _)  )   / )(  ) _)  )(  ) _)  ) D (  " << endl;
            cout << "(____/(____)(__\\_)(__)\\_/\\_/\\____/  \\_)__)\\____/\\_)(_/(____/(____)(__\\_)   \\__/ (____)(__\\_)(__)(__)  (__)(____)(____/  " << endl;
            cout << "\n";
            // Graphics Here

            SetConsoleTextAttribute(h, 3); // sets color skyblue
            cout << "Enter the name of card holder: ";
            fflush(stdin);
            cin >> name;
            cout << "Enter the balance of your card: ";
            fflush(stdin);
            cin >> balance;
        ReEnter:
            cout << "Enter the Security Code of your card: ";
            cin >> securityCode;
            if (securityCode <= 999)
            {
                registerCreditCard.setName(name);
                registerCreditCard.setBalance(balance);
                registerCreditCard.setSecurityCode(securityCode);

                // Graphics here 02

                SetConsoleTextAttribute(h, 2); // sets color green
                cout << "\n";
                cout << "  ___   __   ____  ____    ____  _  _   ___  ___  ____  ____  ____  ____  _  _  __    __    _  _    ____  ____  ___  __  ____  ____  ____  ____  ____  ____ " << endl;
                cout << " / __) / _\\ (  _ \\(    \\  / ___)/ )( \\ / __)/ __)(  __)/ ___)/ ___)(  __)/ )( \\(  )  (  )  ( \\/ )  (  _ \\(  __)/ __)(  )/ ___)(_  _)(  __)(  _ \\(  __)(    \\" << endl;
                cout << "( (__ /    \\ )   / ) D (  \\___ \\) \\/ (( (__( (__  ) _) \\___ \\\\___ \\ ) _) ) \\/ (/ (_/\\/ (_/\\ )  /    )   / ) _)( (_ \\ )( \\___ \\  )(   ) _)  )   / ) _)  ) D (" << endl;
                cout << " \\___)\\_/\\_/(__\\_)(____/  (____/\\____/ \\___)\\___)(____)(____/(____/(__)  \\____/\\____/\\____/(__/    (__\\_)(____)\\___/(__)(____/ (__) (____)(__\\_)(____)(____/" << endl;
                // Graphics here
                goto Transaction;
            }
            else
            {

                // Graphics Here 03

                SetConsoleTextAttribute(h, 4); // sets color red
                cout << "\n";
                cout << "  __  __ _  _  _   __   __    __  ____    ____  ____  ___  _  _  ____  __  ____  _  _     ___  __  ____  ____  _   " << endl;
                cout << " (  )(  ( \\/ )( \\ / _\\ (  )  (  )(    \\  / ___)(  __)/ __)/ )( \\(  _ \\(  )(_  _)( \\/ )   / __)/  \\(    \\(  __)/ \\  " << endl;
                cout << "  )( /    /\\ \\/ //    \\/ (_/\\ )(  ) D (  \\___ \\ ) _)( (__ ) \\/ ( )   / )(   )(   )  /   ( (__(  O )) D ( ) _) \\_/  " << endl;
                cout << " (__)\\_)__) \\__/ \\_/\\_/\\____/(__)(____/  (____/(____)\\___)\\____/(__\\_)(__) (__) (__/     \\___)\\__/(____/(____)(_)" << endl;

                // Graphics Here 04

                SetConsoleTextAttribute(h, 3); // sets color skyblue
                cout << "Want to enter the code again(Y/N): ";
                char choice;
                cin >> choice;
                if (choice == 'Y')
                {
                    goto ReEnter;
                }
                else if (choice != 'Y' && choice != 'N')
                {
                    // Graphics Here 05

                    SetConsoleTextAttribute(h, 4); // sets color red
                    cout << "\n";
                    cout << " __  __ _  _  _   __   __    __  ____     __  ____  ____  __  __   __ _ " << endl;
                    cout << "(  )(  ( \\/ )( \\ / _\\ (  )  (  )(    \\   /  \\(  _ \\(_  _)(  )/  \\ (  ( \\" << endl;
                    cout << " )( /    /\\ \\/ //    \\/ (_/\\ )(  ) D (  (  O )) __/  )(   )((  O )/    /" << endl;
                    cout << "(__)\\_)__) \\__/ \\_/\\_/\\____/(__)(____/   \\__/(__)   (__) (__)\\__/ \\_)__)" << endl;

                    goto ReEnter;
                }
            }
        }
        else
        {
            // Graphics Here 05

            SetConsoleTextAttribute(h, 4); // sets color red
            cout << "\n";
            cout << " ____  ____  ____   __  ____    _  _  _  _  __  __    ____    _  _  ____  ____  __  ____  _  _  __  __ _   ___    ____  _  _  ____     ___   __   ____  ____" << endl;
            cout << "(  __)(  _ \\(  _ \\ /  \\(  _ \\  / )( \\/ )( \\(  )(  )  (  __)  / )( \\(  __)(  _ \\(  )(  __)( \\/ )(  )(  ( \\ / __)  (_  _)/ )( \\(  __)   / __) / _\\ (  _ \\(    \\" << endl;
            cout << " ) _)  )   / )   /(  O ))   /  \\ /\\ /) __ ( )( / (_/\\ ) _)   \\ \\/ / ) _)  )   / )(  ) _)  )  /  )( /    /( (_ \\    )(  ) __ ( ) _)   ( (__ /    \\ )   / ) D (" << endl;
            cout << "(____)(__\\_)(__\\_) \\__/(__\\_)  (_/\\_)\\_)(_/(__)\\____/(____)   \\__/ (____)(__\\_)(__)(__)  (__/  (__)\\_)__) \\___/   (__) \\_)(_/(____)   \\___)\\_/\\_/(__\\_)(____/" << endl;
        }
    }
    else if (option == 2)
    {

        SetConsoleTextAttribute(h, 5); // sets color violet
        cout << "\n------------------------\n\n";
        // Graphics Here 06
        cout << "\n";
        cout << " ____  ____  ____  ____  __  ____  _  _    ____  ____   __   __ _  ____   __    ___  ____  __  __   __ _  ____ " << endl;
        cout << "(  _ \\(  __)(  _ \\(  __)/  \\(  _ \\( \\/ )  (_  _)(  _ \\ / _\\ (  ( \\/ ___) / _\\  / __)(_  _)(  )/  \\ (  ( \\/ ___)" << endl;
        cout << " ) __/ ) _)  )   / ) _)(  O ))   // \\/ \\    )(   )   //    \\/    /\\___ \\/    \\( (__   )(   )((  O )/    /\\___ \\" << endl;
        cout << "(__)  (____)(__\\_)(__)  \\__/(__\\_)\\_)(_/   (__) (__\\_)\\_/\\_/\\_)__)(____/\\_/\\_/ \\___) (__) (__)\\__/ \\_)__)(____/" << endl;
        cout << "-------------------------\n";

        SetConsoleTextAttribute(h, 3); // sets color skyblue
    TransactionOptions:
        cout << "\n1.Withdraw Money\n2.Deposit Money\n3.Return Back" << endl;
        cout << "\nChoose an option: ";
        int transactionOption;
        cin >> transactionOption;
        visaCard = registerCreditCard;
        if (transactionOption == 1)
        {
            int verification;
            cout << "Enter your security code: ";
            cin >> verification;
            if (verification == visaCard.getSecurityCode())
            {
                float oldBalance, newBalance;
                cout << "\nAuthentication successfull\n";
                // graphics here 07

                SetConsoleTextAttribute(h, 4); // sets color red
                cout << "\n";
                cout << "  __   _  _  ____  _  _  ____  __ _  ____  __  ___   __  ____  __  __   __ _    ____  _  _   ___  ___  ____  ____  ____  ____  _  _  __    __   " << endl;
                cout << " / _\\ / )( \\(_  _)/ )( \\(  __)(  ( \\(_  _)(  )/ __) / _\\(_  _)(  )/  \\ (  ( \\  / ___)/ )( \\ / __)/ __)(  __)/ ___)/ ___)(  __)/ )( \\(  )  (  )  " << endl;
                cout << "/    \\) \\/ (  )(  ) __ ( ) _) /    /  )(   )(( (__ /    \\ )(   )((  O )/    /  \\___ \\) \\/ (( (__( (__  ) _) \\___ \\\\___ \\ ) _) ) \\/ (/ (_/\\/ (_/\\" << endl;
                cout << "\\_/\\_/\\____/ (__) \\_)(_/(____)\\_)__) (__) (__)\\___)\\_/\\_/(__) (__)\\__/ \\_)__)  (____/\\____/ \\___)\\___)(____)(____/(____/(__)  \\____/\\____/\\____/" << endl;
                // graphics here

                SetConsoleTextAttribute(h, 3); // sets color skyblue

                cout << "How much money do you want to withdraw: ";
                cin >> newBalance;
                if (newBalance < visaCard.getBalance())
                {
                    visaCard.setBalance(visaCard.getBalance() - newBalance);
                    cout << "\n";
                    cout << newBalance << " successfully withdrawed from your account.\nNew Balance: Rs." << visaCard.getBalance() << endl;
                    cout << "\n";
                    goto TransactionOptions;
                }
                else
                {
                    // Graphics Here 08

                    SetConsoleTextAttribute(h, 4); // sets color red
                    cout << "\n";
                    cout << " __  __ _  ____  _  _  ____  ____  __  ___  __  ____  __ _  ____    ____   __   __     __   __ _   ___  ____  _  _   " << endl;
                    cout << "(  )(  ( \\/ ___)/ )( \\(  __)(  __)(  )/ __)(  )(  __)(  ( \\(_  _)  (  _ \\ / _\\ (  )   / _\\ (  ( \\ / __)(  __)/ \\/ \\  " << endl;
                    cout << " )( /    /\\___ \\) \\/ ( ) _)  ) _)  )(( (__  )(  ) _) /    /  )(     ) _ (/    \\/ (_/\\/    \\/    /( (__  ) _) \\_/\\_/  " << endl;
                    cout << "(__)\\_)__)(____/\\____/(__)  (__)  (__)\\___)(__)(____)\\_)__) (__)   (____/\\_/\\_/\\____/\\_/\\_/\\_)__) \\___)(____)(_)(_)  " << endl;
                    // Graphics Here
                    goto TransactionOptions;
                }
            }
            else
            {
                // Graphics Here 09
                cout << "\n";
                cout << " _  _  ____   __   __ _   ___    ____  ____  ___  _  _  ____  __  ____  _  _     ___  __  ____  ____  _  _   " << endl;
                cout << "/ )( \\(  _ \\ /  \\ (  ( \\ / __)  / ___)(  __)/ __)/ )( \\(  _ \\(  )(_  _)( \\/ )   / __)/  \\(    \\(  __)/ \\/ \\  " << endl;
                cout << "\\ /\\ / )   /(  O )/    /( (_ \\  \\___ \\ ) _)( (__ ) \\/ ( )   / )(   )(   )  /   ( (__(  O )) D ( ) _) \\_/\\_/ " << endl;
                cout << "(_/\\_)(__\\_) \\__/ \\_)__) \\___/  (____/(____)\\___)\\____/(__\\_)(__) (__) (__/     \\___)\\__/(____/(____)(_)(_) " << endl;

                // Graphics Here 10

                SetConsoleTextAttribute(h, 5); // sets color voilet
                cout << "\n";

                cout << " ____  __ _  ____  ____  ____     __    ___   __   __  __ _ " << endl;
                cout << "(  __)(  ( \\(_  _)(  __)(  _ \\   / _\\  / __) / _\\ (  )(  ( \\" << endl;
                cout << " ) _) /    /  )(   ) _)  )   /  /    \\( (_ \\/    \\ )( /    /" << endl;
                cout << "(____)\\_)__) (__) (____)(__\\_)  \\_/\\_/ \\___/\\_/\\_/(__)\\_)__)" << endl;
                // Graphics Here
                goto TransactionOptions;
            }
        }
        else if (transactionOption == 2)

        {

            SetConsoleTextAttribute(h, 3); // sets color skyblue
            cout << "How much do you want to deposit: ";
            float additionalBalance;
            cin >> additionalBalance;
            visaCard.setBalance(visaCard.getBalance() + additionalBalance);
            cout << "\n";
            cout << additionalBalance << " successfully deposited to your account\nYour new balance is: Rs." << visaCard.getBalance() << endl;
            goto TransactionOptions;
        }
        else if (transactionOption == 3)
        {
            goto Transaction;
        }

        else
        {
            // Graphics Here 11

            SetConsoleTextAttribute(h, 4); // sets color red
            cout << "\n";
            cout << " __  __ _  _  _   __   __    __  ____     __  ____  ____  __  __   __ _ " << endl;
            cout << "(  )(  ( \\/ )( \\ / _\\ (  )  (  )(    \\   /  \\(  _ \\(_  _)(  )/  \\ (  ( \\" << endl;
            cout << " )( /    /\\ \\/ //    \\/ (_/\\ )(  ) D (  (  O )) __/  )(   )((  O )/    /" << endl;
            cout << "(__)\\_)__) \\__/ \\_/\\_/\\____/(__)(____/   \\__/(__)   (__) (__)\\__/ \\_)__)" << endl;
            // Graphics Here
            goto TransactionOptions;
        }
    }
    else if (option == 3)
    {
        cout << "\n\n------------------------------------\n\n";
        // Graphics Here 12

        SetConsoleTextAttribute(h, 5); // sets color violet
        cout << "\n";
        cout << " ____  _  _  ___  _  _   __   __ _   ___  ____    ____   __  ____  ____  ____    ____  __  ____    ____  __  ____   __   _  _     __   ____  ____  _   " << endl;
        cout << "(  __)( \\/ )/ __)/ )( \\ / _\\ (  ( \\ / __)(  __)  (  _ \\ / _\\(_  _)(  __)/ ___)  (  __)/  \\(  _ \\  (_  _)/  \\(    \\ / _\\ ( \\/ )   / _\\ (  _ \\(  __)(_)  " << endl;
        cout << " ) _)  )  (( (__ ) __ (/    \\/    /( (_ \\ ) _)    )   //    \\ )(   ) _) \\___ \\   ) _)(  O ))   /    )( (  O )) D (/    \\ )  /   /    \\ )   / ) _)  _   " << endl;
        cout << "(____)(_/\\_)\\___)\\_)(_/\\_/\\_/\\_)__) \\___/(____)  (__\\_)\\_/\\_/(__) (____)(____/  (__)  \\__/(__\\_)   (__) \\__/(____/\\_/\\_/(__/    \\_/\\_/(__\\_)(____)(_)  " << endl;
        // Graphics Here
        cout << "\n\n------------------------------------\n";
        CreditCard unitBalanceCard;
        unitBalanceCard.setBalance(100.00);

        SetConsoleTextAttribute(h, 9); // sets color light blue

        Currency usdollars;
        usdollars = convertToUsDollars(unitBalanceCard.getBalance());
        cout << "US Dollars rate for today (per Rs.100)" << endl;
        cout << "Rs. " << unitBalanceCard.getBalance() << " : " << usdollars.getValue1() << "$ " << usdollars.getValue2() << " Cents" << endl;
        cout << "\n";

        Currency canadiandollars;
        canadiandollars = convertToCanadianDollar(unitBalanceCard.getBalance());
        cout << "Canadian Dollars rate for today (per Rs.100)" << endl;
        cout << "Rs. " << unitBalanceCard.getBalance() << " : " << canadiandollars.getValue1() << "$ " << canadiandollars.getValue2() << " Cents" << endl;
        cout << "\n";

        Currency indianrupees;
        indianrupees = convertToIndianRupee(unitBalanceCard.getBalance());
        cout << "Indian Rupees rate for today (per Rs.100)" << endl;
        cout << "Rs. " << unitBalanceCard.getBalance() << " : "
             << "Rs." << indianrupees.getValue1() << " " << indianrupees.getValue2() << " Paisa" << endl;
        cout << "\n";

        Currency japaneseseyen;
        indianrupees = convertToJapaneseYen(unitBalanceCard.getBalance());
        cout << "Japanese Yen rate for today (per Rs.100)" << endl;
        cout << "Rs. " << unitBalanceCard.getBalance() << " : " << japaneseseyen.getValue1() << " Yen " << japaneseseyen.getValue2() << " Rin" << endl;
        cout << "\n";

        Currency euro;
        euro = convertToEuro(unitBalanceCard.getBalance());
        cout << "Euros rate for today (per Rs.100)" << endl;
        cout << "Rs. " << unitBalanceCard.getBalance() << " : " << euro.getValue1() << " Euro " << euro.getValue2() << " Cents" << endl;
        cout << "\n";

        Currency pound;
        pound = convertToPound(unitBalanceCard.getBalance());
        cout << "Pounds Rupees rate for today (per Rs.100)" << endl;
        cout << "Rs. " << unitBalanceCard.getBalance() << " : " << pound.getValue1() << " Pound " << pound.getValue2() << " Pence" << endl;
        cout << "\n";

        goto Transaction;
    }
    else if (option == 4)
    {

        SetConsoleTextAttribute(h, 3); // sets color skyblue
        int convertOption;
        cout << "Options: " << endl;
        cout << "1. US Dollars" << endl;
        cout << "2. Indian Rupee" << endl;
        cout << "3. Canadian Dollars" << endl;
        cout << "4. Japanese Yen" << endl;
        cout << "5. Euro" << endl;
        cout << "6. British Pound" << endl;
        cout << endl;
        cout << "Choose an option: ";
        cin >> convertOption;
        Currency remitted;

        if (convertOption == 1)
        {
            remitted = convertToUsDollars(visaCard.getBalance());
            cout << "The converted balance is: " << remitted.getValue1() << "$ " << remitted.getValue2() << " Cents" << endl;
        }
        else if (convertOption == 2)
        {
            remitted = convertToIndianRupee(visaCard.getBalance());
            cout << "The converted balance is: "
                 << "Rs. " << remitted.getValue1() << " " << remitted.getValue2() << " Paisa" << endl;
        }
        else if (convertOption == 3)
        {
            remitted = convertToCanadianDollar(visaCard.getBalance());
            cout << "The converted balance is: " << remitted.getValue1() << "$ " << remitted.getValue2() << " Cents" << endl;
        }
        else if (convertOption == 4)
        {
            remitted = convertToJapaneseYen(visaCard.getBalance());
            cout << "The converted balance is: " << remitted.getValue1() << " Yen " << remitted.getValue2() << " Rin" << endl;
        }
        else if (convertOption == 5)
        {
            remitted = convertToEuro(visaCard.getBalance());
            cout << "The converted balance is: " << remitted.getValue1() << " Euro " << remitted.getValue2() << " Cents" << endl;
        }
        else if (convertOption == 6)
        {
            remitted = convertToPound(visaCard.getBalance());
            cout << "The converted balance is: " << remitted.getValue1() << " Pound " << remitted.getValue2() << " Pence" << endl;
        }
        else
        {
            // Graphics Here 13
            cout << "\n";

            SetConsoleTextAttribute(h, 4); // sets color red
            cout << " __  __ _  _  _   __   __    __  ____     __  ____  ____  __  __   __ _ " << endl;
            cout << "(  )(  ( \\/ )( \\ / _\\ (  )  (  )(    \\   /  \\(  _ \\(_  _)(  )/  \\ (  ( \\" << endl;
            cout << " )( /    /\\ \\/ //    \\/ (_/\\ )(  ) D (  (  O )) __/  )(   )((  O )/    /" << endl;
            cout << "(__)\\_)__) \\__/ \\_/\\_/\\____/(__)(____/   \\__/(__)   (__) (__)\\__/ \\_)__)" << endl;
            // Graphics Here
            goto Transaction;
        }
        goto Transaction;
    }
    else if (option == 5)
    {
        goto End;
    }
    else
    {
        // Graphics Here 14
        cout << "\n";
        cout << " __  __ _  _  _   __   __    __  ____     __  ____  ____  __  __   __ _ " << endl;
        cout << "(  )(  ( \\/ )( \\ / _\\ (  )  (  )(    \\   /  \\(  _ \\(_  _)(  )/  \\ (  ( \\" << endl;
        cout << " )( /    /\\ \\/ //    \\/ (_/\\ )(  ) D (  (  O )) __/  )(   )((  O )/    /" << endl;
        cout << "(__)\\_)__) \\__/ \\_/\\_/\\____/(__)(____/   \\__/(__)   (__) (__)\\__/ \\_)__)" << endl;
        // Graphics Here 15
        cout << "\n";
        cout << " __  __ _  _  _   __   __    __  ____     __  ____  ____  __  __   __ _ " << endl;
        cout << "(  )(  ( \\/ )( \\ / _\\ (  )  (  )(    \\   /  \\(  _ \\(_  _)(  )/  \\ (  ( \\" << endl;
        cout << " )( /    /\\ \\/ //    \\/ (_/\\ )(  ) D (  (  O )) __/  )(   )((  O )/    /" << endl;
        cout << "(__)\\_)__) \\__/ \\_/\\_/\\____/(__)(____/   \\__/(__)   (__) (__)\\__/ \\_)__)" << endl;
        // Graphics Here

        goto Transaction;
    }
End:
    return 0;
}