#include <iostream>
#include <iomanip>
using namespace std;

/*
 buck is the name given to the variable given to the group of 4 numbers
 formed after breaking down the credit card number into four parts
*/
class sno
{
protected:
    int buck1;
    int buck2;
    int buck3;
    int buck4;

public:
    int getBuck1() { return buck1; }
    int getBuck2() { return buck2; }
    int getBuck3() { return buck3; }
    int getBuck4() { return buck4; }
    void setBuck1(int b1) { buck1 = b1; }
    void setBuck2(int b2) { buck2 = b2; }
    void setBuck3(int b3) { buck3 = b3; }
    void setBuck4(int b4) { buck4 = b4; }
    sno() {}
    sno(int b1, int b2, int b3, int b4) : buck1(b1), buck2(b2), buck3(b3), buck4(b4) {}
};

// Class for credit card
class CreditCard
{
private:
    sno serialno;
    string name;
    float balance;
    int securityCode;

public:
    sno getSno() { return serialno; }
    void setSno(sno temp) { serialno = temp; }
    string getName() { return name; }
    void setName(string nm) { name = nm; }
    void setBalance(float bal) { balance = bal; }
    void setSecurityCode(int code) { securityCode = code; }
    float getBalance() { return balance; }
    int getSecurityCode() { return securityCode; }

    CreditCard() {}
    // CreditCard(sno s) : serialno(s) {}
    CreditCard(sno s, string nm, float bal, int code) : serialno(s), name(nm), balance(bal), securityCode(code) {}
};

// Class for currency
class Currency
{
private:
    int value1;
    int value2;

public:
    Currency() {}
    Currency(int a, int b) : value1(a), value2(b) {}
    int getValue1() { return value1; }
    int getValue2() { return value2; }
    void setValue1(int a) { value1 = a; }
    void setValue2(int b) { value2 = b; }
};

// ---------------------------------FUNCTIONS-----------------------------------------

// Function to validate card
bool validateCard(CreditCard c1)
{
    if (c1.getSno().getBuck1() < 1000 || c1.getSno().getBuck2() < 1000 || c1.getSno().getBuck3() < 1000 || c1.getSno().getBuck4() < 1000)
    {
        return false;
    }
    else
    {
        int doubled1, doubled2, doubled3, doubled4, doubled5, doubled6, doubled7, doubled8;

        // variables to store the temporarily store the alternatively doubled values
        doubled1 = (c1.getSno().getBuck1() / 1000) * 2;
        doubled2 = (((c1.getSno().getBuck1() % 1000) % 100) / 10) * 2;
        doubled3 = (c1.getSno().getBuck2() / 1000) * 2;
        doubled4 = (((c1.getSno().getBuck2() % 1000) % 100) / 10) * 2;
        doubled5 = (c1.getSno().getBuck3() / 1000) * 2;
        doubled6 = (((c1.getSno().getBuck3() % 1000) % 100) / 10) * 2;
        doubled7 = (c1.getSno().getBuck4() / 1000) * 2;
        doubled8 = (((c1.getSno().getBuck4() % 1000) % 100) / 10) * 2;

        // Putting these values in an array
        int doubled_array[8] = {doubled1, doubled2, doubled3, doubled4, doubled5, doubled6, doubled7, doubled8};
        int sum = 0;
        int recurred_sum = 0;
        // creating the first part of validation algorithm
        for (int i = 0; i < 8; i++)
        {
            if (doubled_array[i] >= 10)
            {

                recurred_sum += (doubled_array[i] / 10) + (doubled_array[i] % 10);
            }
            else
            {
                sum += doubled_array[i];
            }
        }
        sum = sum + recurred_sum;

        // creating variables to store second part of validation
        int undoubled1, undoubled2, undoubled3, undoubled4, undoubled5, undoubled6, undoubled7, undoubled8;
        undoubled1 = (c1.getSno().getBuck1() % 1000) / 100;
        undoubled2 = (((c1.getSno().getBuck1() % 1000) % 100) % 10);
        undoubled3 = (c1.getSno().getBuck2() % 1000) / 100;
        undoubled4 = (((c1.getSno().getBuck2() % 1000) % 100) % 10);
        undoubled5 = (c1.getSno().getBuck3() % 1000) / 100;
        undoubled6 = (((c1.getSno().getBuck3() % 1000) % 100) % 10);
        undoubled7 = (c1.getSno().getBuck4() % 1000) / 100;
        undoubled8 = (((c1.getSno().getBuck4() % 1000) % 100) % 10);

        // putting these variables in another array
        int undoubled_array[8] = {undoubled1, undoubled2, undoubled3, undoubled4, undoubled5, undoubled6, undoubled7, undoubled8};
        int undoubled_sum = 0;
        for (int i = 0; i < 8; i++)
        {
            undoubled_sum += undoubled_array[i];
        }

        // final step of validation
        if ((sum + undoubled_sum) % 10 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

// Function for Converting into US Dollars
Currency convertToUsDollars(float balance)
{
    Currency converted;

    float val1 = balance * 0.0086;
    int dollar = int(val1);
    int cents = int((val1 - int(dollar)) * 100);
    converted.setValue1(dollar);
    converted.setValue2(cents);
    return converted;
}

// Function for Converting to Indian Rupees
Currency convertToIndianRupee(float balance)
{
    Currency converted;

    float val1 = balance * 0.63;
    int inrrupee = int(val1);
    int inrpaisa = int((val1 - int(inrrupee)) * 100);
    converted.setValue1(inrrupee);
    converted.setValue2(inrpaisa);
    return converted;
}

// Function for Converting to Japanese Yen
Currency convertToJapaneseYen(float balance)
{
    Currency converted;

    float val1 = balance * 1.05;
    int yen = int(val1);
    int rin = int((val1 - int(yen)) * 100);
    converted.setValue1(yen);
    converted.setValue2(rin);
    return converted;
}

// Function for Converting to Canadian Dollar
Currency convertToCanadianDollar(float balance)
{
    Currency converted;

    float val1 = balance * 0.01;
    int caddollar = int(val1);
    int cadcents = int((val1 - int(caddollar)) * 100);
    converted.setValue1(caddollar);
    converted.setValue2(cadcents);
    return converted;
}

// Function for Converting to Euro
Currency convertToEuro(float balance)
{
    Currency converted;

    float val1 = balance * 0.0076;
    int euro = int(val1);
    int eurocents = int((val1 - int(euro)) * 100);
    converted.setValue1(euro);
    converted.setValue2(eurocents);
    return converted;
}

// Function for Converting to Pound
Currency convertToPound(float balance)
{
    Currency converted;

    float val1 = balance * 0.0064;
    int pound = int(val1);
    int pence = int((val1 - int(pound)) * 100);
    converted.setValue1(pound);
    converted.setValue2(pence);
    return converted;
}