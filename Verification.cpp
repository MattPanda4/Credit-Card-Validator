//
//  main.cpp
//  Credit Card verification program
//
//  Created by Matt on 9/15/21.
//  Copyright © 2021 Matt. All rights reserved.
// AME starts with 34,37, 15 digits
// MasterCard starts with 55,54,53,52,51, 16 digits
// Visa starts with 4, 13 or 16 digits

#include <iostream>
#include <string>
using namespace std;


int main(void) {
    long creditCardNumber;
   
    //asks for credit card number
    do {
        cout << "Enter Credit Card Number: ";
        cin >> creditCardNumber;
    } while (creditCardNumber <= 0);
       long useableCardNumber = creditCardNumber;
       int sum = 0;
       int count = 0;
       long divisor = 10;
       string result;
    
    //1st check
    while (useableCardNumber > 0) {
        int lastdigit = useableCardNumber % 10;
        sum = sum + lastdigit;
        useableCardNumber = useableCardNumber / 100;
    }
    //2nd check
    useableCardNumber = creditCardNumber / 10;
    while (useableCardNumber > 0) {
        int lastDigit = useableCardNumber % 10;
        int multipliedTwo = lastDigit * 2;
        //use luhns algorithm to determine what numbers are being used
        sum = sum + (multipliedTwo % 10) + (multipliedTwo / 10);
        //move two digits over
        useableCardNumber = useableCardNumber / 100;
        
    }
    
    // length of the card number
    useableCardNumber = creditCardNumber;
    while(useableCardNumber != 0) {
       useableCardNumber = useableCardNumber / 10;
        count ++;
    }
    
    //divisor, used to get first or first two digits
    for(int i = 0; i < count - 2; i++) {
        divisor = divisor * 10;
    }
    
    long firstDigit = creditCardNumber / divisor;
    long firstTwoDigits = creditCardNumber / (divisor/10);
    
    //checks to see which card is being used
    if(sum % 10 == 0){
        if(firstDigit == 4 && (count == 13 || count == 16)){
            result = "VISA";
        }
        else if ((firstTwoDigits > 50 && firstTwoDigits < 56) && count == 16){
            result = "MASTERCARD";
        }
        else if((firstTwoDigits == 34 || firstTwoDigits == 37) && count == 15){
            result = "AMERICAN EXPRESS";
        }
        else{
            result = "INVALID";
        }
    }
    else{
        result = "INVALID";
    }
    cout << result << endl;
    return 0;
}
