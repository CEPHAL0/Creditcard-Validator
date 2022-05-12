/*

Program:            Project for CPP
Objective:          To validate credit card and perform transactions and transformation
Authors:            Sharad Sharma, Serena Dangi, Anish Regmi
Date:               2022/04/25
Syntax Errors:      None
Logical Errors:     Problem while storing balance without registering the card along with balance first

*/

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "classes.h"
using namespace std;

int main()
{
    int option;
    sno serialno(4624, 7482, 3324, 9780);
    sno serialno2(8910, 8192, 0421, 9018);
    sno serialno3(4235, 5900, 4143, 4840);
    CreditCard visaCard;
    CreditCard registerCreditCard;

    // Insert Graphics here
    cout << "--------------------------------";
    cout << "\n\nWELCOME TO THE MAZE BANK SERVICES\n\n";
    cout << "--------------------------------" << endl;
    cout << "WHAT SERVICE WOULD YOU LIKE TO CHOOSE:" << endl;

Transaction:
    cout << "\n1. Register Credit Card\n2. Perform Transactions\n3. Check the exchange rates\n4. Convert your currency\n5. Exit" << endl;
    cout << endl;
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

            // Insert Graphics Here
            cout << "\n\nSerial Number verified successfully\n\n"
                 << endl;

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

                // Insert Graphics here
                cout << "\nCard Successfully Registered" << endl;

                goto Transaction;
            }
            else
            {

                // Insert Graphics Here
                cout << "\nInvalid Security code! " << endl;

                cout << "Want to enter the code again(Y/N): ";
                char choice;
                cin >> choice;
                if (choice == 'Y')
                {
                    goto ReEnter;
                }
                else if (choice != 'Y' && choice != 'N')
                {
                    cout << "Invalid Option\n";
                    goto ReEnter;
                }
            }
        }
        else
        {
            cout << "Error while verifying the card";
        }
    }
    else if (option == 2)
    {
        cout << "\n------------------------\n\n";
        cout << "PERFORM TRANSACTIONS\n\n";
        cout << "-------------------------\n";
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
                cout << "\nAuthentication successfull\n"
                     << endl;
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
                    cout << "\nInsufficient Balance!!\n";
                    goto TransactionOptions;
                }
            }
            else
            {
                cout << "\nWrong Security Code!! Enter again\n";
                goto TransactionOptions;
            }
        }
        else if (transactionOption == 2)
        {
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
            cout << "Invalid Option";
            goto TransactionOptions;
        }
    }
    else if (option == 3)
    {
        cout << "\n\n------------------------------------\n\n";
        cout << "THE EXCHANGE RATES FOR TODAY ARE:";
        cout << "\n\n------------------------------------\n";
        CreditCard unitBalanceCard;
        unitBalanceCard.setBalance(100.00);

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
            cout << "\nInvalid option\n";
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
        cout << "\nInvalid Option\n"
             << endl;
        goto Transaction;
    }
End:
    return 0;
}
