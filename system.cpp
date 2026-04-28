
/*----------------------------------------------------------------------
                                Header Files
----------------------------------------------------------------------*/
/* ****Header guideline****
    1. iostream
        Function used:
            cin, cout, endl
        Data type:
            int, double, bool, char, char [], string, float, const

    2. cstring
        Function used:
            strcpy, strcat, strcmp, strlen, strchr, strstr, strtok, strdup
    3. iomanip
        Function used:
            setw, alignments
    4. ctime
        Function used:
            time(), localtime()
    5. string
        Function used:
            stoi()
    6.vector
        Function used:
            Initialization:
                  <vector>
                Capacity type function:
                  size()
                Access type function:
                    at(), front(), back()
                Append and delete
                  push_back(), pop_back()
                  erase()
    7. array
        Function used:
            Initialization:
                    <array>
    8. cmath
      Function used:
        round
*/


#include <iostream>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <string>
#include <vector>
#include <array>
#include <cmath>
using namespace std;

/*----------------------------------------------------------------------
                                Global Variables
----------------------------------------------------------------------*/

bool HAVE_LOAD_DATA = false;
bool CAN_MODIFY_DATA = true; // converse of HAVE_LOAD_DATA: once loaded data =
// set new object in customer and gift

int NUMBER_OF_CUSTOMERV = 0; // count number of customers
int NUMBER_OF_GIFT = 0;      // count number of gifts record

/*----------------------------------------------------------------------
                              Class Definitions

                              1. Gift
                              2. Customer
----------------------------------------------------------------------*/

class Gift {
    /*
        1. Objective:
            Store informations of gifts as objects and retrieve or manipulate them when required.

        2. Member Functions:
            2.1 void setGiftInfo(const char inGift[], const char inGiftDescription[], int p,
        int ptRequired)
            2.2 void printGiftInfo()
            2.3 void printGiftInfoWithDiscountPt(int currentCustomerBalance)
            2.4 void setdiscountPointDiff(int diffPoint)
            2.5 string getGiftInfo(int typeOfItem)

        3. Private variables
            1. char
                giftID[3 + 1], giftDescription[100 + 1]
            2. int
                price, pointRequired, discountPointDifference

    */

public:
    void setGiftInfo(const char inGift[], const char inGiftDescription[], int p,
        int ptRequired) {
        /*
            1. Objective
                Sets up information for gift object
            2. Parameters guideline
                2.1 const char inGift[]
                        C-string storing the gift ID
                2.2 const char inGiftDescription[]
                        C-string storing the gift description
                2.3 int p
                        integer storing price
                2.4 int ptRequired
                    integer storing CC points required for redemption
        */

        strcpy_s(giftID, inGift);
        strcpy_s(giftDescription, inGiftDescription);
        price = p;
        pointRequired = ptRequired;
        discountPointDifference = 0;
    } // end of setGiftInfo()


    void printGiftInfo() const {
        /*
            1. Objective
                    Print the gift info of a gift object.
                    Sets as const so that it won't modify the data
        */


        cout << setw(10) << left << giftID << setw(30) << left << giftDescription;
        cout << setw(15) << left << price << setw(15) << left << pointRequired;
        return;
    } // end of printGiftInfo()

    void printGiftInfoWithDiscountPt(int currentCustomerBalance) const {
        /*
            1. Objective
                    Prints gift info of a gift object PLUS the discounted required points for a customer.

            2. Parameters
                int currentCustomerBalance
                    Integer storing the current CC Balance of the customer
        */

        cout << setw(10) << left << giftID << setw(30) << left << giftDescription;
        cout << setw(15) << left << price << setw(20) << left << pointRequired
            << setw(20) << left << discountPointDifference
            << ((discountPointDifference < currentCustomerBalance) ? "(redeemable)" : "")
            << endl;
        return;
    } // end of printGiftInfoWithDiscountPt()


    void setdiscountPointDiff(int diffPoint) {
        /*
            1. Objective
                    Set the discounted Point Difference from the current gift item to the imported integer
            2. Parameter
                2.1 int diffPoint
                    Integer storing the point difference
        */

        discountPointDifference = diffPoint;
    } // end of setdiscountPointDiff()

    string getGiftInfo(int typeOfItem) {
        /*
        1. Objective
                Return a specific type of gift information as stored in the object.
            Returns as a string, convert to other types outside of function if requried.

        2. Parameters
            take in int 0-3, return item in string type with respect to the list below
                0: giftID
                1: giftDescription
                2: price
                3: pointRequired
                4: discountPointDifference
                default: error message
        */

        switch (typeOfItem) {
        case 0:
            return giftID;
        case 1:
            return giftDescription;
        case 2:
            return std::to_string(price);
        case 3:
            return std::to_string(pointRequired);
        case 4:
            return std::to_string(discountPointDifference);
        default:
            cout << "class Gift: Invalid type of item";
            return "-1";
            break;
        }
    } // end of getGiftInfo()

private:
    // class variables
    char giftID[3 + 1],
        giftDescription[100 + 1]; // giftID and giftDescription are a c-string. +1 for the '\0'
    int price, pointRequired, discountPointDifference; // discountPointDifference is for R4 printing purpose
}; // end of class Gift

class Customer {
    /*
        1. Objective
            Store informations of customers as objects and retrieve or manipulate them when required.

        2. Member functions:
            2.1 Customer()
            2.2 void setCustomerInfo(const char inCus[], const char inRank[], int ptBalance)
            2.3 void printCustomersInfo()
            2.4 string getCustomerSpecificInfo(int typeOfItem)
            2.5 void updatePointsBalance(int newBalance)
            2.6 void earnCCPoints(float amountSpent)
            2.7 int calculateDiscountedPoints(int pointsRequired)

            2.8 void addTransaction(char transactionType, int CCChange, string infoA = "",
        string infoB = "")
            2.9 void printTransHistory(Gift giftRecord[])
            2.10 int searchGift(Gift g[], int NUMBER_OF_GIFT, char inputGiftID[])

        3. Private Variables
            3.1 char
                customerID[50 + 1], rank[1 + 1]
            3.2 int
                CCPointBalance
            3.3 vector
                    <array<string, 6>> transRecords

    */

public:
    Customer() {
        /*
            1. Objective
                 Constructor w/o input parameter to set some default values for a Customer object
              to prevent error.
        */
        strcpy_s(customerID, "KenTsangTheBest!!");
        strcpy_s(rank, "G");
        CCPointBalance = 0;
    }

    void setCustomerInfo(const char inCus[], const char inRank[], int ptBalance) {
        /*
            1. Objective
                    Set up customer info for a customer object

            2. Parameter
                2.1 const char inCus[]
                        C-string storing the customer ID
                2.2 const char inRank[]
                        C-string storing the customer rank
                2.3 int ptBalance
                        integer storing the customer's CC balance
        */

        // copy the data into the object variable
        strcpy_s(customerID, inCus);
        strcpy_s(rank, inRank);
        CCPointBalance = ptBalance;
    } // end of setCustomerInfo()

    void printCustomersInfo() const {
        /*
            1. Objective
                Call to print out the object's data. Function const so that it won't modify the data
        */

        cout << setw(50) << left << customerID << setw(15) << left << rank;
        cout << setw(15) << left << CCPointBalance << endl;
    } // end of printCustomersInfo()

    string getCustomerSpecificInfo(int typeOfItem) {
        /*
            1. objective
                    Returns a specific type of customer info as requested in parameter.
                Returns as string, convert to other types if required.

            2. Parameter
                take in int 0-2, retrun item in string type with respect to the list below
                    0: customerID.
                    1: rank.
                    2: CCPointBalance.
                    default: error message
        */

        switch (typeOfItem) {
        case 0:
            return customerID;
        case 1:
            return rank;
        case 2:
            return std::to_string(CCPointBalance);
        default:
            cout << "class Customer: Invalid type of item";
            return "-1";
            break;
        }
    } // end of getCustomerSpecificInfo()

    void updatePointsBalance(int newBalance) {
        /*
            1. Objective
                    Updates the CC point balance of a customer w/ a new value

            2. Parameter
                2.1 int newBalance
                        integer storing the new CC Balance
        */

        CCPointBalance = newBalance;
    } // end of updatePointsBalance()

    void earnCCPoints(float amountSpent) {
        /*
            1. Objective
                    Updates the customer's CC point balance with earned CC pts calculated in function

            2. Parameter
                2.1 float amountSpent
                    Floating point number storing the amount of money spent for earning pts
        */

        const float conversionRate = 250.0; // $250 per 1 point
        int pointsEarned = static_cast<int>(amountSpent / conversionRate);
        CCPointBalance += pointsEarned;
    } // end of earnCCPoints()

    int calculateDiscountedPoints(int pointsRequired) {
        /*
            1. Objective
                    Calculates and returns the discounted points for a gift after
                after discount based on customer rank. (Rounded to nearest integer)

            2. Parameter
                2.1 int pointsRequired
                        integer storing the required points of a gift
        */

        // Returns discounted points (required for redeeming a gift) based on
        // customer's rank

        if (strcmp(rank, "G") == 0) {
            return round((pointsRequired * 0.9)); // 10% discount
        }
        else if (strcmp(rank, "S") == 0) {
            return round((pointsRequired * 0.95)); // 5% discount
        }
        else {
            return pointsRequired; // no discount
        }
    } // end of calculateDiscountedPoints()

    /*======================================================================
                          Transactions Functions
    ========================================================================*/
    void addTransaction(char transactionType, int CCChange, string infoA = "",
        string infoB = "") {
        /*
            1. Objective:
                    adds a singular transaction to the transaction history of a customer
                stored inside a vector that is inside a customer object

            2. Parameters:
                1. char transactionType
                    ‘A’ = Add CC pts
                    ‘R’ = Redeem Gifts
                    ‘M’ = Modify CC pts
                    Anything else: error msg
                2. int CCChange
                    **UNSIGNED** integer of change in CC points
                3. string infoA & infoB
                    [Add CC]    infoA = (string number) money spent for earning CC pts
                    [Redeem Gift] infoA = (string) GiftID
                                  infoB = (string number) extra money needed to pay
                                                        ^^ fill 0 if no money is needed
                    [Modify CC] infoA = type of modification (increase/decrease) (string)

        */

        if (transactionType != 'A' && transactionType != 'R' &&
            transactionType != 'M') {
            cout << "!!!!ERROR in creating transaction number " << transRecords.size()
                << "!!!!\n";
            cout << transactionType
                << " is not a valid transaction type. View valid types as below: "
                << endl;
            cout << "\'A\' : Add CC Points Transactions\n\'R\' : Redeem Gifts "
                "Transactions\n\'M\' : Modify CC Points Balance Transactions"
                << endl;
            cout << "~~~End of Error Message~~~";
            return;
        }

        string string_transactionType(1, transactionType);
        array<string, 6> dummyRecord{};

        dummyRecord[0] = string_transactionType;
        dummyRecord[1] = to_string(CCChange);
        switch (transactionType) {
        case 'A':
            dummyRecord[2] = infoA;
            break;
        case 'R':
            dummyRecord[3] = infoA;
            dummyRecord[4] = infoB;
            break;
        case 'M':
            dummyRecord[5] = infoA;
            break;
        default:
            cout << "There is error in transaction type.";
        }

        transRecords.push_back(dummyRecord);
        cout << "transaction " << transRecords.size() << " successful." << endl;

        return;
    }

    void printTransHistory(Gift giftRecord[]) {
        /*
          1. Objective:
                    prints the full transaction history of the customer since the program
             starts running

          2. Parameters:
                2.1	Gift giftRecord[]
                        The array storing all gift objects
        */

        int sumCCChange = 0, extraMoney = 0;

        // Print message if no transaction by this customer
        if (transRecords.size() == 0) {
            cout << "\nThis customer did not perform any transaction since the "
                "program starts running."
                << endl;
            return;
        }
        else {
            cout << "\nThe following is the transaction history for customer \""
                << customerID << "\" since the program starts running: " << endl;

            for (int row = 0; row < transRecords.size(); row++) {

                // For all records, prints record no + transaction type + change in CC
                cout << "\nRecord " << row + 1 << ": " << endl;
                cout << "\tTransaction Type: "
                    << ((transRecords[row][0] == "A") ? "Add CC Points"
                        : (transRecords[row][0] == "R") ? "Redeem Gift"
                        : "Modify CC Points Balance")
                    << endl;

                // Based on transaction type, prints record info
                if (transRecords[row][0] == "A") {
                    cout << "\tChange in CC: +" << transRecords[row][1] << endl;
                    cout << "\tMoney spent for earning CC points: $"
                        << transRecords[row][2] << endl;
                    sumCCChange += stoi(transRecords[row][1]);
                }
                else if (transRecords[row][0] == "R") {
                    cout << "\tChange in CC: -" << transRecords[row][1] << endl;
                    cout << "\tGift ID: " << transRecords[row][3] << endl;

                    char someGiftID[10];
                    strcpy_s(someGiftID, 10, transRecords[row][3].c_str());

                    int tempIndex = searchGift(giftRecord, NUMBER_OF_GIFT, someGiftID);

                    cout << "\tGift Description: "
                        << ((tempIndex != -1) ? giftRecord[tempIndex].getGiftInfo(1)
                            : "ERROR!! GiftID does not exist!")
                        << endl;

                    cout << "\tExtra money needed to pay: $" << transRecords[row][4]
                        << endl;
                    sumCCChange -= stoi(transRecords[row][1]);
                    extraMoney += stoi(transRecords[row][4]);
                }
                else {
                    string modType = transRecords[row][5];
                    cout << "\tChange in CC: "
                        << ((modType == "increase") ? "+"
                            : (modType == "decrease") ? "-"
                            : "error in modType")
                        << transRecords[row][1] << endl;
                    cout << "\tType of modification: " << modType << endl;
                    if (modType == "increase") {
                        sumCCChange += stoi(transRecords[row][1]);
                    }
                    else {
                        sumCCChange -= stoi(transRecords[row][1]);
                    }
                }
            } // // end of outer layer else

            // prints out summary
            cout << "\nSummary: " << endl;
            cout << "\tA total of " << transRecords.size()
                << " transactions have been performed." << endl;
            cout << "\n\tOriginal CC Points Balance: "
                << (CCPointBalance - sumCCChange) << endl;
            cout << "\tFinal CC Points Balance: " << CCPointBalance << endl;
            cout << "\tChange in CC Points Balance: "
                << ((sumCCChange > 0) ? "+" : "") << sumCCChange << " pts" << endl;
            cout << "\tExtra money needed to pay: $" << extraMoney << endl;
        }

        return;
    } // end of printTransHistory()

    int searchGift(Gift g[], int NUMBER_OF_GIFT, char inputGiftID[]) {
        /*
        1. Objective:
            Returns index of gift inside giftRecords based on giftID entered.

        2. Parameters:
            1.	Gift g[]
                The array storing all gift objects
            2. int NUMBER_OF_GIFT
                The global variable counting the number of gift objects in g[]
            3. char inputGiftID[]
                The giftID of the gift which index is to be searched for
        */

        for (int i = 0; i <= NUMBER_OF_GIFT; i++) {
            if (strcmp(g[i].getGiftInfo(0).c_str(), inputGiftID) == 0)
                return i;
        }
        return -1;
    }

private:
    // class variables
    char customerID[50 + 1],
        rank[1 + 1]; // customerID and rank are a c-string. +1 for the '\0'
    int CCPointBalance;

    vector<array<string, 6>>
        transRecords; // 2D vector storing all transaction records of a customer

}; // end of class Customer

/*----------------------------------------------------------------------
                          Function Definitions

                 1. R1 & R2: Loading, sorting and showing data
                 2. R3     : Edit Customers (creating & deleting)**1
                 3. R4     : Customer's View
                 4. R5     : Show Transaction History
                 5. R6     : Credits and Exit

----------------------------------------------------------------------*/

//======================R1 & R2: Loading, sorting and showing data===================

bool loadDataCustomerV(vector<Customer>& vC) {
    /* 1. Objectives:
           1) create Customer class as dummy object
           2) using the dummy object to create object with required information
                information: CustomerID, Rank, Point Balance
           3) push the object into the vector
           4) repeat until all date is loaded into the vector
           5) return true once done all action

        2. Parameter:
            2.1 vector<Customer>
                Input the vector storing all customer objects
     */

    Customer cCustomer;
    cCustomer.setCustomerInfo("Tommy2015", "B", 8500);
    vC.push_back(cCustomer);

    cCustomer.setCustomerInfo("DavidChan", "B", 22800);
    vC.push_back(cCustomer);

    cCustomer.setCustomerInfo("Luna123", "B", 650);
    vC.push_back(cCustomer);

    cCustomer.setCustomerInfo("TigerMan", "B", 14000);
    vC.push_back(cCustomer);

    cCustomer.setCustomerInfo("Max5678", "S", 2580);
    vC.push_back(cCustomer);

    cCustomer.setCustomerInfo("Neo2000", "S", 8000);
    vC.push_back(cCustomer);

    cCustomer.setCustomerInfo("CCTang", "S", 33554);
    vC.push_back(cCustomer);

    cCustomer.setCustomerInfo("EchoWong", "G", 8650);
    vC.push_back(cCustomer);

    cCustomer.setCustomerInfo("Rubychow", "G", 28000);
    vC.push_back(cCustomer);

    cCustomer.setCustomerInfo("Ivy2023", "G", 12340);
    vC.push_back(cCustomer);

    // update the number of customer in the vector
    // by getting the size of the vector (=number of customer record)
    NUMBER_OF_CUSTOMERV = vC.size();

    return true;
} // end of loadDataCustomerV()

bool loadDataGift(Gift gGift[]) {
    /*
        1. Objective
                Loads data for gifts, creating gift objects and stores them all in
            an array for all gift objects.
                Returns True after loading.
        2. Parameters:
            2.1 Gift gGift[]
                    array storing all gift objects
    */


    // object array name [index access by global variable].class function(default
    // required data); default required data: GiftId, GiftDescription, GiftPrice,
    // GiftPoints
    gGift[NUMBER_OF_GIFT].setGiftInfo("A01", "LG Internet TV", 3900, 19000);
    gGift[++NUMBER_OF_GIFT].setGiftInfo("A02", "Pioneer Hifi Set", 2400, 11500);
    gGift[++NUMBER_OF_GIFT].setGiftInfo("A03", "Sony DVD Player", 400, 2000);
    gGift[++NUMBER_OF_GIFT].setGiftInfo("B01", "Healthy Air Fryer", 1500, 7300);
    gGift[++NUMBER_OF_GIFT].setGiftInfo("B02", "Tefal Microwave Oven", 480, 2400);
    gGift[++NUMBER_OF_GIFT].setGiftInfo("B03", "Famous Coffee Maker", 1800, 8800);
    gGift[++NUMBER_OF_GIFT].setGiftInfo("B04", "Smart Rice Cooker", 600, 2900);
    gGift[++NUMBER_OF_GIFT].setGiftInfo("B05", "TechCook Toaster Oven", 450,
        2250);
    gGift[++NUMBER_OF_GIFT].setGiftInfo("C01", "Wellcome $50 Coupon", 50, 250);
    gGift[++NUMBER_OF_GIFT].setGiftInfo("C02", "Mannings $50", 50, 250);
    gGift[++NUMBER_OF_GIFT].setGiftInfo("C03", "Carol Restaurant $100 Coupon",
        100, 500);
    gGift[++NUMBER_OF_GIFT].setGiftInfo("C04", "Shell $200 Coupon", 200, 960);
    gGift[++NUMBER_OF_GIFT].setGiftInfo("D01", "Clever Headset", 350, 1750);
    gGift[++NUMBER_OF_GIFT].setGiftInfo("D02", "HP Optic Mouse", 250, 1250);
    gGift[++NUMBER_OF_GIFT].setGiftInfo("D03", "Stylish Bluetooth Speaker", 800,
        3900);

    return true;
} // end of loadDataGift()

bool checkLoadData() {
    /* 
        1. Objective:
            check see if the data is loaded or not, return true if loaded, false if not
            corresponded to the option 1 limitation in R1

    */

    if (HAVE_LOAD_DATA == false) {
        cout << "\nNo data loaded yet." << endl;
        cout << "Please load data first." << endl;
        cout << "To do this, press 1 in the main menu." << endl;
        return false;
    }
    else
        return true;
} // end of checkLoadData()

void sortCustomersRecordV(vector<Customer>& vC) {
    /*
        1. Objective:
            Sort Customer Record in alphabetical order by using selection sort.

        2. Parameter:
            2.1 vector<Customer>& vC
                vector storing all customer objects
    */ 

    // outer layer
    for (int i = 0; i < vC.size() - 1; i++) {
        int Index = i;
        // inner layer
        for (int j = i + 1; j < vC.size(); j++) {
            if (strcmp(vC.at(j).getCustomerSpecificInfo(0).c_str(),
                vC.at(Index).getCustomerSpecificInfo(0).c_str()) < 0) {
                Index = j;
            }
        }
        if (Index != i) {
            swap(vC.at(i), vC.at(Index));
        }
    }
} // end of sortCustomersRecord()

void showRecordsCustomerV(vector<Customer>& vC) {
    /*
        1. Objective:
                Show all customers' information and sorted in alphabetical order.

        2. Parameters:
            2.1 vector<Customer>& vC
                vector storing all customer objects
    */


    // Sort customers' ID in alphabetical order
    sortCustomersRecordV(vC);
    // Print out customer records
    cout << "\n";
    cout << setw(50) << left << "CustomerID" << setw(15) << left << "Rank";
    cout << setw(15) << left << "Point Balance" << endl;

    cout << "===================================================================="
        "==========="
        << endl;

    for (auto it = vC.begin(); it != vC.end(); it++) {
        it->printCustomersInfo();
    }
} // end of showRecordsCustomerV()

void showRecordsSpecificCustomerV(vector<Customer>& vC, int loationOfTheCustomer) {
    /*
        1. Objective
            Show the customer information of a specific customer
        2. Parameters:
            2.1 vector<Customer>& vC
                Vector storing all customer objects
            2.2 int loationOfTheCustomer
                location of the required customer inside the vector
    */

    // Sort customers' ID in alphabetical order
    sortCustomersRecordV(vC);
    // Print out customer records
    cout << "\n";
    cout << setw(20) << left << "CustomerID" << setw(15) << left << "Rank";
    cout << setw(50) << left << "Point Balance" << endl;

    cout << "===================================================================="
        "==========="
        << endl;
    vC.at(loationOfTheCustomer).printCustomersInfo();
    cout << endl;
} // end of showRecordsCustomerV()

void showRecordsGift(Gift g[]) {
    /*
        1. Objective
                Shows all gift objects' information.

        2. Parameter
            2.1 Gift g[]
                array storing all gift objects
    */

    // Function. Take in class Gift Object array. Print out the whole Gift records in format.

    cout << setw(10) << left << "Gift ID" << setw(30) << left
        << "Gift Discription" << setw(15) << left << "Price (HKD)" << setw(10)
        << left << "Points Required" << endl;

    cout << "===================================================================="
        "==="
        << endl;

    for (int i = 0; i < NUMBER_OF_GIFT;
        i++) { // @AY: added = as we have 10 total record, but index shows 9
        g[i].printGiftInfo();
        cout << "\n";
    }
} // end of showRecordsGift()

void showRecordsV(vector<Customer>& vC, Gift g[]) {
    /*
        1. Objective
                Show all records of both customer objects and gift objects

        2. Parameters
            2.1 vector<Customer>& vC
                vector storing all customer objects
            2.2 Gift g[]
                array storing all gift objects
    */


    // call the corresponding function to print the list
    cout << "\n";
    showRecordsGift(g); // function: to print all record in Gift object array
    cout << "\n";
    showRecordsCustomerV(
        vC); // function: to print all record in Customer object array
} // end of showRecords()

// ==============================END of R1 & R2==========================================

//=========================R3: Edit Customers (creating & deleting)======================

int searchCustomerIndexV(vector<Customer> vC, char input[]) {
    // Function. Take in Class Customer vector array, c-string user input. Return .

    for (int i = 0; i < vC.size(); i++) {
        if (strcmp(vC[i].getCustomerSpecificInfo(0).c_str(), input) == 0)
            return i;
    }
    return -1;
} // end of searchCustomer

bool isDateValid(int day, int month, int year) {
    // Function: check if the date is valid or not. If not, return false. If yes, return true.

    /*
    Detail note of the function:
    1. check if the month, day, year is out of range or not.
    2. check if year is leap or not
    3. four situation here
      a. if is leap year and month is 2, check day is our of range or not
      b. if is not leap year and month is 2, check day is our of range or not
      c. if month is in the upper half year, check day is our of range or not,
          with respect to the month range.
      d. if month is in the lower half year, check day is our of range or not,
          with respect to the month range.
    if the case passes without any error, return true. Else return false.
    @AY
    */

    // credit to Jason W. for modding

    bool isLeap = false, isCorrect = false;

    if (month < 1 || month > 12 || day < 1 || year < 0)
        isCorrect = false;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        isLeap = true;
    else {
        isLeap = false;
    }

    if (!isLeap && month == 2)
        (day > 28) ? isCorrect = false : isCorrect = true;
    else if (isLeap && month == 2)
        (day > 29) ? isCorrect = false : isCorrect = true;
    else if (month <= 7)
        ((month % 2 == 0 && day > 31) || (month % 2 == 1 && day > 30))
        ? isCorrect = false
        : isCorrect = true;
    else
        ((month % 2 == 0 && day > 30) || (month % 2 == 1 && day > 31))
        ? isCorrect = false
        : isCorrect = true;

    return isCorrect;
} // end of isValid

int getCurrentDateMS(char dateType) {
    // take in dateType character, then return the corresponding current date
    // element dateType abbreviation : day: d, month: m, year: y
    // @AY

    struct tm t;
    time_t now = time(0);
    localtime_s(&t, &now);

    switch (dateType) {
    case 'y':
        return 1900 + t.tm_year;
    case 'm':
        return 1 + t.tm_mon;
    case 'd':
        return t.tm_mday;
    default:
        return -1;
    }
} // end of getCurrentDateMS()

bool isFuture(int d, int m, int y) {
    // @AY new + mod for MS
    // @JW for logic

    if (y > getCurrentDateMS('y')) { // future year
        // cout << "year true" << endl;
        return true;                           // is future
    }
    else if (getCurrentDateMS('y') == y) { // is this year
        if (m > getCurrentDateMS('m')) {
            // cout << "month true" << endl;
            return true;
        }
        else if (getCurrentDateMS('m') == m) {
            if (d > getCurrentDateMS('d')) {
                // cout << "day true" << endl;
                return true;
            }
            else
                // cout << "false day" << endl;
                return false;
        }
        else
            // cout << "false month" << endl;
            return false;
    }
    else { // year before this year
        // cout << "false year" << endl;
        return false;
    }

} // end of isFuture()

bool isLeap(int yr) {
    // separate function from isDataValid to facilitate comparing dates
    bool isLeap;
    if ((yr % 4 == 0 && yr % 100 != 0) || yr % 400 == 0)
        isLeap = true;
    else {
        isLeap = false;
    }

    return isLeap;
} // end of isLeap

int assignDay(int d, int m, int y) {
    // change the date to the nth day of the year, e.g. 25-4-2024 is the 116th day of 2024.

    int day = 0, i;
    for (i = 1; i < m; i++) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            day += 31;
        if (i == 4 || i == 6 || i == 9 || i == 11)
            day += 30;
        if (i == 2 && isLeap('y') == true)
            day += 29;
        else if (i == 2 && isLeap('y') == false)
            day += 28;
    }

    if (i == m)
        day += d;

    return day;
} // end of assignDay

double calDays(int d, int m, int y) {
    // calculate the difference of days of the dates and give ranks to customers.
    double diff;
    // assign dates for both input date and current date, and then subtract the 2
    // days.
    int cad = assignDay(getCurrentDateMS('d'), getCurrentDateMS('m'),
        getCurrentDateMS('y')), // get current assigned day
        iad = assignDay(d, m, y);               // get input assigned day

    // If not enough to minus, will lend whole year to the date depends on isLeap
    // function. Originally, this is an independent function. Now combined to here
    // due to bugs.
    if (y < getCurrentDateMS('y')) {
        for (int i = y; i != getCurrentDateMS('y'); i++) {
            if (isLeap(y) == true)
                cad += 366;
            else
                cad += 365;
        }
    }

    diff = cad - iad +
        1; // inclding the date that the customer joined the membership.

    // calculate the difference is (1)within 6 months (2)within 6 months to 1 year
    // (3)more then 1 year
    return diff / 365; // default: NOT leap year
} // end of calDays

string assignRank(int d, int m, int y) {
    // assigning rank according to the difference calculated from calDays.

    // less than half a year -> Bronze
    if ((calDays(d, m, y)) < 0.5)
        return "B";

    // within half a year and 1 year -> Silver
    else if (((calDays(d, m, y)) >= 0.5) && ((calDays(d, m, y)) < 1))
        return "S";

    // more then 1 year -> Gold
    else if ((calDays(d, m, y)) >= 1)
        return "G";

    return "errorInassignRank";
} // end of assignRank

bool checkCCPointValid(int userCCPoint) {
    // @AY new: use uin addNewCustomer()
    if (userCCPoint < 0) {
        return false;
    }
    return true;
}

void addNewCustomer(vector<Customer>& vC, char newCustomerID[]) {
    int count = 3;
    string date, extractDay, extractMonth, extractYear;
    bool flagCheckDateVaild = false;

    int day;
    int month;
    int year;

    while (count > 0 && flagCheckDateVaild == false) {
        // Prompt the user to enter the date they become a mumber
        cout << "Please enter the date you became a member (DD/MM/YYYY): ";
        cin >> date;

        // First extract the data from the date string
        // substr(start, length): extract part of the string
        if (date.length() < 10) {
            cout << "Invalid date format. Please try again. ";
            count--;
            cout << "You have " << count << " more chance(s)." << endl;
            continue;
        }
        string extractDay = date.substr(0, 2);
        string extractMonth = date.substr(3, 2);
        string extractYear = date.substr(6, 4);

        // Convert the extracted string into an integer
        day = stoi(extractDay);
        month = stoi(extractMonth);
        year = stoi(extractYear);

        // check if the date is valid or not
        bool DateValid = isDateValid(day, month, year);
        // check if the date is future or not
        bool isfuture = isFuture(day, month, year);

        // 5 case:
        // 1. when the number of time user inpit
        if ((count == 0) && ((DateValid == true && isfuture == true) ||
            (DateValid != 1 && isfuture != 1) ||
            (DateValid != 1 && isfuture == 1))) {
            count--;
            cout << endl << "Invalid date." << endl;
        }
        else if (DateValid == true && isfuture == true) {
            count--;
            cout << endl << "The input date is not valid. Please try again. " << endl;
            cout << "You have " << count << " more chance(s). " << endl << endl;
        }
        else if (DateValid == false && isfuture == false) {
            count--;
            cout << endl << "The input date is not valid. Please try again. " << endl;
            cout << "You have " << count << " more chance(s). " << endl << endl;
        }
        else if (DateValid == false && isfuture == true) {
            count--;
            cout << endl << "The input date is not valid. Please try again. " << endl;
            cout << "You have " << count << " more chance(s). " << endl << endl;
        }
        else if (DateValid == true && isfuture == false) {
            cout << endl << "The input date is valid." << endl;
            cout << "Now, the program request for the CC point balance." << endl
                << endl;
            flagCheckDateVaild = true;
        }
    } // end of while loop

    if (flagCheckDateVaild == true) {
        int userCCPoint{};
        bool isCCPointValid = false;
        string rank = assignRank(day, month, year);

        while (count > 0 && isCCPointValid == false) {
            cout << "Please enter your CC points balance: ";
            cin >> userCCPoint;
            if (std::cin.fail()) {
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n'); // Discard bad input
                std::cout << "Bad entry. Please try again." << endl << endl;

                count--;
                cout << "You have " << count << " more chance(s)." << endl << endl;
                continue; // back into the loop to get user input
            }

            if (checkCCPointValid(userCCPoint) == true) {
                cout << endl << "Customer's CC point balance is valid. " << endl;
                isCCPointValid = true;
            }
            else {
                count--;
                cout << endl
                    << "Customer's CC point balance is invalid. Please try again. "
                    << endl;
                cout << "You have " << count << " more chance(s)." << endl << endl;
                continue;
            }
        }

        if (count == 0 || flagCheckDateVaild == false || isCCPointValid == false) {
            cout << "Maximum number of attempts reached. Returning to the main menu."
                << endl
                << endl;
            return;
        }

        cout << "Now we will add the new customer information to the system."
            << endl;
        cout << "Your new customer ID is: " << newCustomerID << endl;
        cout << "Your new customer rank is: " << rank << endl;
        cout << "Your new customer CC point balance is: " << userCCPoint << endl;

        // create the new customer object and push it into the vector
        Customer dummyCustomer;
        dummyCustomer.setCustomerInfo(newCustomerID, rank.c_str(), userCCPoint);
        vC.push_back(dummyCustomer);
    }
    else
        return; // back to main meun

} // end of addNewCustomer()

void deleteCustomerV(vector<Customer>& vC, char forDeleteCustomerID[]) {
    // modded: change of parameter from nothing to c-string
    int location;
    location = searchCustomerIndexV(vC, forDeleteCustomerID);

    const char* theMagicWord[10] = {
        "Please just Enter \"Yes\" or \"No\" to confirm the deletion. ",
        "Invalid input. Please try again. ",
        "Invalid input. Please just use your eyes and input again",
        "You serious right now?",
        "Try Harder please...",
        "Error on confirmation. Please try again: ",
        "You are challenging my patient." };

    // cout << "Please enter the Customer ID that you want to delete: ";
    // cin.getline(forDeleteCustomerID, 20);

    // list out all the information of that customer
    cout << "Here is your customer's information: " << endl;
    // find out the customer index by function
    showRecordsSpecificCustomerV(vC, location);

    bool myPatientIsStillHere = true;
    ;

    char userInput[10];
    int countNoOfTry = 0;
    while (myPatientIsStillHere == true) {

        cout << endl << "Are you sure you want to delete this customer? (Yes/No): ";
        // get user input
        cin.getline(userInput, 10);

        if (strcmp(userInput, "Yes") == 0 || strcmp(userInput, "yes") == 0 ||
            strcmp(userInput, "YES") == 0 || strcmp(userInput, "y") == 0 ||
            strcmp(userInput, "Y") == 0) {
            myPatientIsStillHere = false;

            // do the deletion by using vector delete
            vC.erase(begin(vC) + location);

            // after deletion, show the record again as like a confirmation to the
            // customer.
            cout << "Here is the updated customer list: " << endl;
            showRecordsCustomerV(vC);
            cout << "\n" << forDeleteCustomerID << " is deleted. ";
            break;
        }
        else if (strcmp(userInput, "No") == 0 || strcmp(userInput, "no") == 0 ||
            strcmp(userInput, "NO") == 0 || strcmp(userInput, "n") == 0 ||
            strcmp(userInput, "N") == 0) {
            myPatientIsStillHere = false;
            cout << "\nYou cancelled deleting: " << forDeleteCustomerID << ". \n";
            break;
        }
        else {
            if (countNoOfTry > 3) {

                // this is my easter egg haha @ AY
                srand(time(0));
                int randomNumber = rand() % sizeof(theMagicWord);
                cout << theMagicWord[randomNumber] << endl;
            }
            else {
                cout << "Error on confirmation. Please try again: " << endl;
                countNoOfTry++;
                continue;
            } // end of inner else
        }   // end of outer else

    } // end of while(myPatientIsStillHere == true)

    // delete[] theMagicWord;
} // end of deleteCustomerV()

void editCusV(vector<Customer>& vC) {
    // declare variables
    string date, confirmation, extractDay, extractMonth, extractYear;
    const int cusIDSize = 51;
    char CusID[cusIDSize];
    int CustomerID_listNum;

    cout << "If you enter the Customer ID that is NOT in the record, it will be "
        "treated as adding customer. "
        << endl;
    cout << "If you enter the Customer ID that is in the record, it will be "
        "treated as deleting customer. "
        << endl;

    // get user input
    cout << "\nPlease input custumer ID: ";
    cin.ignore(255, '\n');
    cin.getline(CusID, cusIDSize);

    // check see if the CustomerID exist
    CustomerID_listNum = searchCustomerIndexV(vC, CusID);

    if (CustomerID_listNum == -1) { // CustomerID not exist -> add new customer
        addNewCustomer(vC, CusID);
        return;
    }
    else {
        deleteCustomerV(vC, CusID); // CustomerID exist -> delete customer
        return;
    }
} // end of editCus()

// ==============================END of R1 & R2==========================================

//=================R4 & 5: Customer's View & Show Transaction History====================

void sortGiftRecordsByDiscountPoint(Gift g[], int noOfGift) {
    /*
       1. Objective
                Sorts the gift record (w/o changing og record)
            based on the discounted pts in an ascending order
       2. Parameters
          2.1 Gift g[]
                array storing all gift objects
          2.2 int noOfGift
                integer storing number of gift objects
    */


    // outer layer
    for (int i = 0; i < noOfGift - 1; i++) {
        int Index = i;

        // inner layer
        for (int j = i + 1; j < noOfGift; j++) {
            // if the current(j) gift object's discounted point is less than the previous, set the index to the current (j) gift object
            if (stoi(g[j].getGiftInfo(4).c_str()) <
                stoi(g[Index].getGiftInfo(4).c_str())) {
                Index = j;
            }
        }
        if (Index != i) {
            swap(g[i], g[Index]);
        }
    }

} // end of sortGiftRecordsByDiscountPoint()

void printGiftSpecificInfo(Gift g[], char typeOfGift, Customer nowCust) {
    /*
        1. Objective
                Prints the info of a specific category of gifts
        2. Parameters
            2.1 Gift g[]
                    array storing all the gift objects
            2.2 char typeOfGift
                    character storing the category initial of a gift category
                    A: Audio & Video
                    B: Kitchenware
                    C: Coupons
                    D: Computer Accessories
            2.3 Customer nowCust
                    The customer object we are performing actions on
    */


    // get the current customer's rank
    const char* tempRank =
        ((nowCust.getCustomerSpecificInfo(1) == "B")
            ? "Bronze"
            : ((nowCust.getCustomerSpecificInfo(1) == "S") ? "Silver" : "Gold"));

    cout << setw(10) << left << "Gift ID" << setw(30) << left
        << "Gift Description" << setw(15) << left << "Price (HKD)" << setw(20)
        << left << "Points Required" << setw(20) << left
        << "Discounted Points for \' " << setw(6) << left << tempRank << setw(20)
        << left << " \' Customers" << endl;

    cout << "===================================================================="
        "================================================="
        << endl;

    // record the starting and ending point to print gift record
    int printStartPoint, printEndPoint;
    switch (typeOfGift) {
    case 'A':
        printStartPoint = 0;
        printEndPoint = 2;
        break;
    case 'B':
        printStartPoint = 3;
        printEndPoint = 7;
        break;
    case 'C':
        printStartPoint = 8;
        printEndPoint = 11;
        break;
    case 'D':
        printStartPoint = 12;
        printEndPoint = 14;
        break;
    default:
        cout << "printGiftSpecificInfo: Invalid type of gift.";
        return;
    }

    const int dummyNoOfGift = 5; // just for setting the size if the object array
    int loopDiff = printEndPoint - printStartPoint + 1; // for printing
    Gift dummyGift[dummyNoOfGift]; // dummy object array for printing
    int j = 0;

    for (int i = printStartPoint; i <= printEndPoint; i++) {
        dummyGift[j].setGiftInfo(
            g[i].getGiftInfo(0).c_str(), g[i].getGiftInfo(1).c_str(),
            stoi(g[i].getGiftInfo(2).c_str()), stoi(g[i].getGiftInfo(3).c_str()));

        // first, get the current gift point
        int x = stoi(dummyGift[j].getGiftInfo(3).c_str());

        // then, find out the customer's rank, and apply the rank to become the
        // actual CC point need to pay
        int tempToCal = nowCust.calculateDiscountedPoints(x);

        // lastly, put the point differences with discount
        dummyGift[j].setdiscountPointDiff(tempToCal);

        j++;
    }

    // sort the Gift Record by the discounted CC point in ascending order
    sortGiftRecordsByDiscountPoint(dummyGift, loopDiff);

    for (int i = 0; i < loopDiff; i++) {
        dummyGift[i].printGiftInfoWithDiscountPt(stoi(nowCust.getCustomerSpecificInfo(2))); // will auto endl
    }

    return;
} // end of getGiftSpecificInfo()

void earnCC(Customer& customer) {
    /*
        1. Objective
                To allow a customer to earn CC points by spending money
            And update the customer object accordingly

        2. Parameter
         2.1 Customer& customer
                The customer object who will be receiving the CC pts
    */

    // Prompt user for the amount spent
    float amountSpent;
    int CCchange = 0;

    int beforeCCchange = stoi(customer.getCustomerSpecificInfo(2));

    cout << "Enter the amount spent to convert to CC points: ";
    cin >> amountSpent;
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(std::numeric_limits<std::streamsize>::max(),
            '\n'); // Discard bad input
        cout << "Bad entry. Please try again." << endl << endl;

        // count--;
        /*cout << "Incorrect type, please" << endl << endl;*/
        return; // back into the loop to get user input
    }

    if (amountSpent <= 0) {
        cout << "No negative value or zero. Please try again. \n";
        return;
    }

    // Add points to the customer's balance according to the calculation
    customer.earnCCPoints(amountSpent);

    int afterCCchange = stoi(customer.getCustomerSpecificInfo(2));

    CCchange = afterCCchange - beforeCCchange;

    // Confirm the transaction
    cout << "New CC Points Balance: " << customer.getCustomerSpecificInfo(2)
        << endl;

    customer.addTransaction('A', CCchange, to_string(amountSpent));

} // end of earnCCPoints()

void modifyCC(Customer& customer) {
    /*
        1. Objective
                Modifies the CC points of a customer. And updates the balance w/ a new value

        2. Parameters
         2.1 Customer& customer
                The customer object we are performing actions on
    */

    int CCchange = 0;

    // Display current balance
    cout << "Current CC Points Balance: " << customer.getCustomerSpecificInfo(2)
        << endl;

    int beforeCCchange = stoi(customer.getCustomerSpecificInfo(2));

    // Ask for new balance
    int newBalance;
    cout << "Enter new CC Points Balance value: ";
    cin >> newBalance;
    if (std::cin.fail()) {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
            '\n'); // Discard bad input
        std::cout << "Bad entry. Please try again." << endl << endl;

        // count--;
        /*cout << "Incorrect type, please" << endl << endl;*/
        return; // back into the loop to get user input
    }
    if (newBalance <= 0) {
        cout << "No negative value or zero. Please try again. \n";
        return;
    }
    // Update the customer's balance
    customer.updatePointsBalance(newBalance);

    int afterCCchange = stoi(customer.getCustomerSpecificInfo(2));

    // Confirm the update
    cout << "CC Points Balance updated to: "
        << customer.getCustomerSpecificInfo(2) << endl;

    CCchange = afterCCchange - beforeCCchange;

    if (CCchange > 0) {
        customer.addTransaction('M', CCchange, "increase");
    }
    else
        customer.addTransaction('M', CCchange, "decrease");

} // end of modifyCCPointsBalance()

//***R5: Show Transaction History
void showTransactionHistory(Customer nowCus, Gift giftRecord[]) {
    /*
        1. Objective
                Shows all transactions records of a customer before returning to main menu

        2. Parameters
            2.1 Customer nowCus
                    The customer whose transactions we want to view
            2.2 Gift giftRecord[]
                    array storing all gift records
    */

    nowCus.printTransHistory(giftRecord);
    return;
} // end of showTransactionHistory()

void redeemGifts(Customer& customer, Gift giftRecords[]) {
    /*
        1. Objective
                Lets a customer redeem gifts w/ thier CC points and updates their CC balance
            accordingly. Does not allow redeems w/ invalid inputs or insufficient balance.
                Returns to customer view menu when input errors reaches 3 times.

        2. Parameters
            2.1 Customer& customer
                    Customer object that stores the customer who is redeeming the gift
            2.2 Gift giftRecords[]
                    array storing all gift records
    */

    int usingCCpoints, actualRequiredPoints, b4Balance, count = 3;
    char typeOfGift;
    char gID[100 + 1];

    while (true) {

        if (count == 0) {
            return;
        }
        b4Balance = stoi(customer.getCustomerSpecificInfo(2));

        cout << "Gift Categories:\nA: Audio & Video\nB: Kitchenware\nC: Coupons\nD: "
            "Computer Accessories\nR: Redeem a random gift"
            << endl;
        cout << "Input: ";
        cin >> typeOfGift;
        cout << endl;

        if (typeOfGift == 'R') {
            int actualRequiredCC, randomGiftIndex;

            //loops until a random gift that customer can afford w/ CC is selected
            while (true) {
                srand(time(0));
                randomGiftIndex = rand() % NUMBER_OF_GIFT;
                actualRequiredCC = customer.calculateDiscountedPoints(stoi(giftRecords[randomGiftIndex].getGiftInfo(3)));
                if (actualRequiredCC <= b4Balance)
                    break;
            }

            cout << "Redeemed gift with ID \'" << giftRecords[randomGiftIndex].getGiftInfo(0) << "\' and name \'" << giftRecords[randomGiftIndex].getGiftInfo(1) << "\' for you! Enjoy!" << endl;
            customer.updatePointsBalance(b4Balance - actualRequiredCC);
            customer.addTransaction('R', actualRequiredCC, giftRecords[randomGiftIndex].getGiftInfo(0), "0");

            return;
        }

        printGiftSpecificInfo(giftRecords, typeOfGift, customer);


        cout << "\nYou have " << b4Balance << " CC points in your account." << endl;

        cout << "\nEnter ID for gift to be redeemed: ";
        cin >> gID;
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(),
                '\n'); // Discard bad input
            cout << "Bad entry. Please try again." << endl << endl;
            count--;
            cout << "You have " << count << " chances. \n\n";
            continue; // back into the loop to get user input
        }
        //[to do]error if gift ID DNE
        if (customer.searchGift(giftRecords, NUMBER_OF_GIFT, gID) == -1) {
            cout << "Gift not found, please try again. \n";
            count--;
            cout << "You have " << count << " chances. \n\n";
            continue;
        }
        else if (typeOfGift != gID[0]) {
            cout << "Gift not found, please try again. \n\n";
            count--;
            cout << "You have " << count << " chances. \n\n";
            continue;
        }

        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(),
                '\n'); // Discard bad input
            cout << "Bad entry. Please try again." << endl << endl;
            count--;
            cout << "You have " << count << " chances. \n\n";
            continue; // back into the loop to get user input
        }
        cout << "How many CC points would you want to use? : ";
        cin >> usingCCpoints;
        //[to do]error if usingCCpoints > current CC balance
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
            cout << "Bad entry. Please try again." << endl << endl;

            count--;
            cout << "You have " << count << " chances. \n\n";
            continue; // back into the loop to get user input
        }

        if (usingCCpoints > b4Balance)
        {
            cout << "Not enough CC points. Please try again. \n";
            count--;
            cout << "You have " << count << " chances. \n\n";
            continue;
        }


        // calc selected gift's actual requried pts based on customer rank
        int gIndex = customer.searchGift(giftRecords, NUMBER_OF_GIFT, gID);
        actualRequiredPoints = customer.calculateDiscountedPoints(
            stoi(giftRecords[gIndex].getGiftInfo(3)));

        //[to do]IF less-than-required, print how many extra to pay after all user
        //inputs.
        //       Ask for user confirmation b4 subtracting CC pts from Balance
        if (usingCCpoints > actualRequiredPoints) {
            cout << "You do not need that much CC points to redeem this gift! Please try again\n";
            count--;
            cout << "You have " << count << " chances. \n\n";
            continue;
        }
        else if (usingCCpoints <= actualRequiredPoints) {
            string confirm;

            int extraMoneyRequired = stof(giftRecords[gIndex].getGiftInfo(2)) - (usingCCpoints) * 0.2;
            if (usingCCpoints == actualRequiredPoints) {
                extraMoneyRequired = 0;
            }

            //int extraMoneyRequired = stof(giftRecords[gIndex].getGiftInfo(2)) - (usingCCpoints) * 0.2;
            cout << "\nYou will need to pay $" << extraMoneyRequired << " AND " << usingCCpoints << " CC points." << endl;

            cout << "Enter \"Yes\" to proceed. \"No\" to cancel." << endl;
            cout << "Input: ";
            cin >> confirm;

            if (confirm == "YES" || confirm == "Yes" || confirm == "yes" || confirm == "Y" || confirm == "y") {
                customer.updatePointsBalance(b4Balance - usingCCpoints);
                cout << "Thank you for your purchase!" << endl;
                cout << "Your current CC points Balance is: " << stoi(customer.getCustomerSpecificInfo(2)) << endl;

                customer.addTransaction('R', usingCCpoints, giftRecords[gIndex].getGiftInfo(0), to_string(extraMoneyRequired));
                return;
            }
            else if (confirm == "NO" || confirm == "No" || confirm == "no" || confirm == "N" || confirm == "n") {
                cout << "You have cancelled the transaction." << endl;
                return;
            }
            else {
                cout << "That is not a valid input. Please try again. \n";
                count--;
                cout << "You have " << count << " chances. \n\n";
                return;
            }
        }

        //
    }
}

// ===============================END of R4 & R5==========================================

//==============================R6: Credits & Exit=======================================
int loadCredit() {
    /*
        1. Objective
                Shows a confirmation message for user to confirm to quit the program.
            Allows retries if user inputs a wrong input.

            On successful inputs:
              a) When user confirms,
                 Prints credits and quits program.
              b) When user says no,
                 Returns to main menu.
    */

    char subOption[100];
    bool flag_exit = false;

    cout << "Are you sure you want to leave?" << endl;
    cin.ignore(1024, '\n');

    while (flag_exit == false) {
        cout << "Type \'y\' \/ \'Y\' to leave. Or \'n\' \/ \'N\' to return to menu.\nInput: ";


        cin.getline(subOption, 100, '\n');
        //cout << "\nthe option was [" << subOption << "] and string length: " << strlen(subOption)<< endl;

        if (strlen(subOption) != 1) {
            cout << "Bad entry! Try again!" << endl;
            continue;
        }

        //cout << "suboption[0] is " << subOption[0] << endl;
        if (subOption[0] == 'y' || strcmp(subOption, "Y") == 0) {
            cout << "\nCREDITS: " << endl;
            cout << "Group 4 of B05D SEHH2042 (s2 23/24)\n\n";
            cout << setw(15) << left << "Student Name" << setw(10) << left << "StudentID" << setw(15) << "Tutorial Group" << endl;
            cout << setw(15) << left << "============" << setw(10) << left << "=========" << setw(15) << "==============" << endl;
            cout << setw(15) << left << "Wing" << setw(10) << left << "XXXXXXXXA" << setw(8) << right << "B05D" << "\t*Group Leader" << endl;
            cout << setw(15) << left << "LI" << setw(10) << left << "XXXXXXXXA" << setw(8) << right << "B05A" << endl;
            cout << setw(15) << left << "KOMINE" << setw(10) << left << "XXXXXXXXA" << setw(8) << right << "B05A" << endl;
            cout << setw(15) << left << "WONG" << setw(10) << "XXXXXXXXA" << setw(8) << right << "B05D" << endl;
            cout << setw(15) << left << "YWH" << setw(10) << "XXXX3827A" << setw(8) << right << "B05D" << endl;
            //cout << "TSUI\t XXXXXXXXA" << endl;

            return 1;
        }
        else if (subOption[0] == 'n' || subOption[0] == 'N') {
            return 0;
        }
        else {
            cout << "Please type command as instructed! Try again!" << endl;
            continue;
        }
    }
} // end of loadCredit()

// ===================================END of R6==========================================

//****R4: Enter Customer View **moved this to bottom because some functions have to be defined before it @Wing 25/4/2024 19:26
void cusView(vector<Customer>& vCustomer, Gift giftRecords[]) {

    /*
      Objective:
        Upon running, prompts customerID input to perform CC pt manipulation with
      the relevant customer. If customerID does not exist, ends program.

        When customerID exists, loops menu until option 4 is chosen, which will
      end the program.

      Parameters guideline:
        1.	vector<Customer> &vCustomer
            The vector array storing all customer objects
        2.	 Gift giftRecords
            The array storing all gift objects
    */

    char currentCustomerID[49 + 1];

    cout << "Enter a customer ID to continue: ";
    cin.ignore();
    cin.getline(currentCustomerID, 50, '\n');

    // exit customer view if customerID does not exist
    if (searchCustomerIndexV(vCustomer, currentCustomerID) == -1) {
        cout << "Customer ID does not exist. Returning to main menu." << endl;
        return;
    }

    Customer* nowCustomer = &(vCustomer[searchCustomerIndexV(
        vCustomer,
        currentCustomerID)]); // stores current customer as Customer object

    // Menu loops until option 4 is chosen
    while (true) {
        int option;

        cout << "\nAction for Customer ID: " << currentCustomerID << endl;
        cout << "***** Customer View Menu *****\n";
        cout << "[1] Earn CC Points\n";
        cout << "[2] Redeem Gifts\n";
        cout << "[3] Modify CC Points Balance\n";
        cout << "[4] Return to Main Menu\n";
        cout << "**********************************\n";

        cout << "Option (1 - 4): ";
        cin >> option;

        switch (option) {
        case 1:
            earnCC(*nowCustomer);
            break;
        case 2:
            redeemGifts(*nowCustomer, giftRecords);
            break;
        case 3:
            modifyCC(*nowCustomer);
            break;
        case 4:
            return;
        default:
            cout << "No such option. Please try again." << endl;
            break;
        }
    }
} // end of enterCustomerView()

int main() {

    // declare local variables

    // class Gift record size
    const int giftRecordSIZE = 20;
    // declare class Gift object array
    Gift giftRecord[giftRecordSIZE];

    // vector version of Customer
    vector<Customer> vCustomer;

    // user input character
    char option[10];
    // @AY: will we have bugs here? like user enter a lot of letter
    // @AY: I suggest we use getline() + c-string to get the whole line
    // @AY: everytime get user input we ignore the previous input (so not to have
    // infinity input bug)

    bool flag_exit = false;
    cout << "Welcome to the HKCC Mall's Gift Redemption System!" << endl;
    cout << "This is a modified version for Hong Kong Non-Jupas application demonstration. All right reserved to creator.\n";
    cout << "Contact to owner: trytofollowup4.01@gmail.com\n\n";

    do {
        cout << "\n*** Main Menu ***" << endl;
        cout << "[1] Load Starting Data" << endl;
        cout << "[2] Show Records" << endl;
        cout << "[3] Edit Customers" << endl;
        cout << "[4] Enter Customer View" << endl;
        cout << "[5] Show Transaction History" << endl;
        cout << "[6] Credits and Exit" << endl;
        cout << "*****************" << endl;
        cout << "Options (1 - 6) : ";
        cin.clear();
        // cin.ignore();
        cin >> option;

        if (strlen(option) > 1) {
            cout << "No such option :" << option << endl;
            continue;
        }

        switch (option[0]) {
        case '1':
            // load Data(customerRecord, giftRecord, HAVE_LOAD_DATA);
            if (loadDataCustomerV(vCustomer) && loadDataGift(giftRecord)) {
                cout << "\nData loaded." << endl;
                HAVE_LOAD_DATA = true;
            }
            else {
                continue;
            }
            break;
        case '2':
            if (checkLoadData() == true) {
                showRecordsV(vCustomer, giftRecord);
            }
            else {
                continue;
            }
            break;
        case '3':
            if (checkLoadData() == true) {
                editCusV(vCustomer);
            }
            else {
                continue;
            }

            break;
        case '4':
            if (checkLoadData() == true) {
                cusView(vCustomer, giftRecord);
            }
            else {
                continue;
            }

            break;
        case '5':
            if (checkLoadData() == true) {
                char currentCustomerID[49 + 1];

                cout << "Please input customer ID to check their transaction record: ";
                cin.ignore();
                cin.getline(currentCustomerID, 50, '\n');

                // exit customer view if customerID does not exist
                if (searchCustomerIndexV(vCustomer, currentCustomerID) == -1) {
                    cout << "Customer ID does not exist. Returning to main menu." << endl;
                    break;
                }

                Customer nowCustomer = vCustomer[searchCustomerIndexV(
                    vCustomer,
                    currentCustomerID)]; // stores current customer as Customer object
                cout << "The customer retrieved is: "
                    << vCustomer[searchCustomerIndexV(vCustomer, currentCustomerID)]
                    .getCustomerSpecificInfo(0)
                    << endl;

                nowCustomer.printTransHistory(giftRecord);
            }
            else {
                continue;
            }
            break;
        case '6':
            flag_exit = loadCredit();
            // debug: exit reaction code
            if (flag_exit == 1) {
                cout << "\nBye bye!" << endl;
                break;
            }
            else {
                cout << "Returning to main menu..." << endl;
                continue;
            }
        default:
            cout << "No such option :" << option << endl;
        }
    } while (flag_exit == false);
    // has context menu


    return 0;
} // end of main()
