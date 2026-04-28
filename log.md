update log
---
**Patch Notes @ V1_20-4_2352**
Note:
    Initial backup from 20/04/2024 with basic Gift and Customer class skeletons.

---
**Patch Notes @ V1.1_**
Note:
    Early development checkpoint with Gift/Customer structure and UI/transaction stubs.

---
**Patch Notes @ V2.0_**
Note:
    Added gift category print logic and expanded Gift class helper functions.

---
**Patch Notes @ V3.0**
Note:
    Added isDateVaild() and updated editCus() with date validation.

---
**V4.0.cpp**
updated as at 22/04/2024
transaction class added

modded R3 and its component: not yet complete

---
**V5.01.cpp**
backup as of 23-04-2024

---
**V5.1.cpp**

backup as at 23-04-2024 @1852
last update before implementing vector on customer

---
**V6.0.cpp**

backup as at 23-4-2024
implemented vector in class customer

---
**Patch Notes @ V6.1**

Changes made:
  Overall:
    Added more commenting in some functions (include member functions) @AY &23-4-2024 $2309
    Deleted all unused function prototypes @AY &23-4-2024 $2309

    General codeing restructure @AY &24-4-2024 $1648

===============================================
  Class Customer: 
    storing method: object array -> vector (V6.0) @AY &23-4-2024 $2309
    added member function: addCustomer() @AY &23-4-2024 $2309
     Deleted all code related to Class Customer object array @AY &23-4-2024 $2309

    

==============================================
  Functions:
    updated isDateVaild() to Keiji version @AY &24-4-2024 $1642


To Do List:

---
**Patch Notes @ V6.21VS**
Note:
    !!! This version CANNOT RUN YET !!!
    This version is modded V6.2 with some debug and modification, to fit the environment in MS Visual Stdio 2022.
    My MS is running C++14, but I think we have to ask about which version should the test uses.
    Some newer function, optimization can be done in the newer version of C++.
    @AY 25-04-2024

Overall:
    General format restructure for better viewing in MSVS @AY 25-4-2024 1147
Class Customer:
    function setCustomerInfo(): strcpy -> strcpy_s @AY 25-4-2024 1147


Class Gift:
    function setGiftInfo(): strcpy -> strcpy_s @AY 25-4-2024 1147

Function:
    getCurrentDate(): changed from time_t to a struct (class) t. It should just work as before
        (MS suggested me to use localtime_s as again, safty purpose. @AY 25-4-2024 1147

To do List:
    From V6.2:
        1. searchGift is placed within Customer class, as "printTransHistory" does not work otherwise. Have not found a solution yet. @Wing &25-4-2024 00:45
        2. Some questions about isDateValid() @Wing &25-4-2024 01:39
    V6.21VS:
        Class Customer:
            c1) addTransaction():   array<string, 6> dummyRecord; bug: incomplete type is not allowed (@AY I want to change to list initialization {} still dun work) @AY &25-4-2024 1054
                
                ****RE(c1): need to "#include <array>, now in line 149 @Wing 26-4-2024 12:16
            
            c2) V6.2 Transaction related function: addTransaction(), printTransHistory():
                it seems that implementing string array in vector array and access it via index is buggy.
                I do not know what the problem is so I do not know how to fix it yet.
                See the "Errors" section when copy and use debug function. @AY &25-4-2024 1147

                ****RE(c2): line 433 (now 438) had strcpy instead of strcpy_s. Changed it now, can successfully compile on MS VS 2022 afterwards @Wing 26-4-2024 12:21

---
**Patch Notes @ V6.2**

Changes made:
  Overall:
    Added more commenting in some functions (include member functions) @AY &23-4-2024 $2309
    Deleted all unused function prototypes @AY &23-4-2024 $2309

    General codeing restructure @AY &24-4-2024 $1648


===============================================
  Class Customer: 
    storing method: object array -> vector (V6.0) @AY &23-4-2024 $2309
    added member function: addCustomer() @AY &23-4-2024 $2309
    Deleted all code related to Class Customer object array @AY &23-4-2024 $2309



==============================================
  Functions:
    updated isDateVaild() to Keiji version @AY &24-4-2024 $1642


To Do List:

---

**Patch Notes @ V6.22MS**
Note:
    Debugged version of v6.21MS. Can run on MS VS 2022 (VS C++ 2022)

Overall:
    Removed some older patch notes. Just keep the current and previous one is fine I think. Do keep the to-do list and unresolved problem tho @Wing &26-4-2024 01:39
===========================================================================
Class Customer:
    1. RE(c1)  for V6.21MS: need to "#include <array>, now in line 116 @Wing 26-4-2024 12:16
    2. RE(c2)  for V6.21MS: line 405 had strcpy instead of strcpy_s. Changed it now, can successfully compile on MS VS 2022 afterwards @Wing 26-4-2024 12:21

===============================================================================
To do List:
    From V6.2:
        1. searchGift is placed within Customer class, as "printTransHistory" does not work otherwise. Have not found a solution yet. @Wing &25-4-2024 00:45
        2. Some questions about isDateValid() @Wing &25-4-2024 01:39

---
**Patch Notes @ V6.3MS**
Note:
    V7.0 come out soon!!!!!!!!!!! @AY 27-4-2024 0012
Overall:
    call addTransaction() in R4.1 and R4.3 @ROY &26-4-2024 18:07
===========================================================================
Class :
    Customer:
      searchCustomerV(): changed to searchCustomerIndexV() for better understanding, together with related functions @AY &26-04-2024 1844

===============================================================================
To do List (unresolved):
    From V6.22MS:
        1. searchGift is placed within Customer class, as "printTransHistory" does not work otherwise. Have not found a solution yet. @Wing &25-4-2024 00:45
        2. Some questions about isDateValid() @Wing &25-4-2024 01:39
    
    Added this ver:
        1. Redeem Gift not implemented yet @Wing &26-4-2024 18:01
        2. Modify CC needs error message for negative Balance update @Wing &26-4-2024 20:29
                if (newBalance < 0)){
                  cout << "Balance cannot be negative." << endl;
                  return;
                }

---
**Patch Notes @ V7.0**
Note:
    My sanity is fading away...... @AY 27-4-2024 0124
        !!! This version CANNOT RUN YET !!!
      This version is a merge version from V6.3MS and V2_debug_R3 from R123 development Team
      I do have it copy onto the VS, still got some error on compliation. Message is below to do list

Overall:
    Added the R3 from the R123 Team: Keiji, Jason, AY. @AY 27-4-2024 0124
===========================================================================
Update:
  General:
    1.Added function: 
      1.1 deleteCustomerV() done with mod: vector address pass in
      1.2 addNewCustomer() done with mod: vector address pass in
            isDataValid() done
            isFuture() done with mod: VS modding (following getCurrentDateMS())
            assignRank() done
              isLeap() done
              assignDay() done
              calDays() done with mod: : VS modding (following getCurrentDateMS())
            checkCCPointValid() done
      1.3 editCusV() done
      1.4 showRecordsSpecificCustomerV() done

    2. Changed the text before exit the program.
  
  Function:
    getCurrentDateMS(): getCurrentDate() -> getCurrentDateMS() for better indication @AY 27-4-2024 0128
    loadCredit(): just added some idea @AY 27-4-2024 0146

  Class:
    Customer:
      Added a consuctor: Customer() added because VS tell me to "Always initialize a member variable".

Removed:
  compareTime(): deleted and replaed with isFuture() @AY 27-4-2024 0146
===============================================================================
To do List (unresolved):
    From V6.22MS:
        1. searchGift is placed within Customer class, as "printTransHistory" does not work otherwise. Have not found a solution yet. @Wing &25-4-2024 00:45
        2. Some questions about isDateValid() @Wing &25-4-2024 01:39

    From V6.3MS:
        1. Redeem Gift not implemented yet @Wing &26-4-2024 18:01
        2. Modify CC needs error message for negative Balance update @Wing &26-4-2024 20:29
                if (newBalance < 0)){
                  cout << "Balance cannot be negative." << endl;
                  return;
                }
    From V7.0:
      1. Error message: line 1099
        void Customer::addTransaction()
          cannot convert atgument 3 from 'float' to 'std::string'

---

**Patch Notes @ V7.1MS**
Note:
    Debugged to run in MS VS (C++20)


Overall:

===========================================================================
Update:
  General:


  Function:
    deleteCustomerV
        1. Changed to array of pointers pointing to C - strings(L11 p14) because of error In Line 998 of ver 7.0 @Wing &27/4/2024 17:55

    ModifyCC + EarnCC
      1. RE(7.0 to do 1.): Incorrect call of addTransaction(). InfoA and InfoB should be strings. Now fixed @Wing &27/4/2024 17:55


===============================================================================
To do List (unresolved):
    From V6.22MS:
        1. searchGift is placed within Customer class, as "printTransHistory" does not work otherwise. Have not found a solution yet. @Wing &25-4-2024 00:45

    From V6.3MS:
        1. Redeem Gift not implemented yet @Wing &26-4-2024 18:01
        2. Modify CC needs error message for negative Balance update @Wing &26-4-2024 20:29
                if (newBalance < 0)){
                  cout << "Balance cannot be negative." << endl;
                  return;
                }

---
**Patch Notes @ V7.2**
Note:

==============================================
Overall:
    1. Implemented earnCC & modifyCC & show transaction record to cusView menu @Wing &27/4/2024 18:15

===============================================================================
To do List (unresolved):
    From V6.22MS:
        1. searchGift is placed within Customer class, as "printTransHistory" does not work otherwise. Have not found a solution yet. @Wing &25-4-2024 00:45

    From V6.3MS:
        1. Redeem Gift not implemented yet @Wing &26-4-2024 18:01
        2. Modify CC needs error message for negative Balance update @Wing &26-4-2024 20:29
                if (newBalance < 0)){
                  cout << "Balance cannot be negative." << endl;
                  return;
                }
    From v7.2
        1. Transactions performed w/ main menu option "7" can show up in show transaction
            BUT transactions performed w/ earnCC or modifyCC cannot show up in show transaction
            @Wing &27-4-2024 18:47

---
**Patch Notes @ V8.0MS**
Note:

Class:
    1. Gift
        1.1 printGiftInfo updated to not end line so that Function 2. (see below) can be done @Wing &27-4-2024 20:13
==============================================
Functions:
    1. Redeem Gifts
        Partially done. It can now print the requried gifts and show+calculate discounted points for customer @Wing &27-4-2024 20:13

    2. printGiftSpecificInfo
        Moved to outside of class and updated so that it can also print discounted points @Wing &27-4-2024 20:13
    3. editCus()
        Added line to ignore the input bug when going into editCus() and ask for customerID @Andrew &27-4-2024 2101
===============================================================================
To do List (unresolved):
    From V6.22MS:
        1. searchGift is placed within Customer class, as "printTransHistory" does not work otherwise. Have not found a solution yet. @Wing &25-4-2024 00:45

    From V6.3MS:
        1. Redeem Gift not implemented yet @Wing &26-4-2024 18:01
        2. Modify CC needs error message for negative Balance update @Wing &26-4-2024 20:29
                if (newBalance < 0)){
                  cout << "Balance cannot be negative." << endl;
                  return;
                }
    From v7.2
        1. Transactions performed w/ main menu option "7" can show up in show transaction
            BUT transactions performed w/ earnCC or modifyCC cannot show up in show transaction
            @Wing &27-4-2024 18:47

    From v8.0
        1. About Redeem Gift @Wing &27-4-2024 20:28
            1. Not sorted by requried points ascending yet
            2. Not identified gifts that customer can redeem w/o paying extra yet
            3. No 3 try error yet
            4. No Less-than-Required mechanism yet
            5. Need addTransaction @ end
            ===================
            To do w/ calculateDiscountedPoints: @Wing &27-4-2024 20:28
                1. DON'T RETURN A DOUBLE!
                    Return need to be rounded to nearest integer

---
**V8.1 patch notes**
    1. Finished up printing credits

    Things to be done:
        1. Implement retry in [6] Load credits

---
**Patch Notes @ V8.2MS**
Note:

Class:
    1. Gift
        1.1 printGiftInfo updated to not end line so that Function 2. (see
below) can be done @Wing &27-4-2024 20:13
==============================================
Functions:
    1. Redeem Gifts
        Partially done. It can now print the requried gifts and show+calculate
discounted points for customer @Wing &27-4-2024 20:13

    2. printGiftSpecificInfo
        Moved to outside of class and updated so that it can also print
discounted points @Wing &27-4-2024 20:13
    3. editCus()
        Added line to ignore the input bug when going into editCus() and ask for
customerID @Andrew &27-4-2024 2101
===============================================================================
To do List (unresolved):
    From V6.22MS:
        1. searchGift is placed within Customer class, as "printTransHistory" does not work otherwise. Have not found a solution yet. @Wing &25-4-2024 00:45

    From V6.3MS:
        1. +++Done+++Redeem Gift not implemented yet @Wing &26-4-2024 18:01
        2. +++Done+++Modify CC needs error message for negative Balance update @Wing &26-4-2024 20:29 
        if (newBalance < 0)){ cout << "Balance cannot be negative." << endl; return;}
    From v7.2
        1. +++Done+++Transactions performed w/ main menu option "7" can show up in show transaction BUT transactions performed w/ earnCC or modifyCC cannot show up in show transaction
            @Wing &27-4-2024 18:47

    From v8.0
        1. About Redeem Gift @Wing &27-4-2024 20:28
            1. +++Done+++Not sorted by requried points ascending yet
            2. +++Done+++Not identified gifts that customer can redeem w/o paying extra yet
            3. +++Done+++No 3 try error yet
            4. +++Done+++No Less-than-Required mechanism yet
            5. +++Done+++Need addTransaction @ end
            ===================
            To do w/ calculateDiscountedPoints: @Wing &27-4-2024 20:28
                1. +++Done+++DON'T RETURN A DOUBLE!
                    Return need to be rounded to nearest integer


  Things to be done:
    1. +++Done+++ [Less-Than-Required] greater than required pts case
    2. +++Done+++ Mark which gifts customer have sufficient pts to redeem
    3. +++Done+++Random redeem gift (if have time)

---
latest v8.3MS.cpp