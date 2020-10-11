/* Check if all digits of the given integer are even.

Example

For n = 248622, the output should be
evenDigitsOnly(n) = true;
For n = 642386, the output should be
evenDigitsOnly(n) = false.
*/
bool evenDigitsOnly(int n) {
    
    do {
        int temp = n % 10;
        n = n / 10;
        if  (temp % 2 != 0)
            return false;
    }while (n > 0);
    
    return true;
}

