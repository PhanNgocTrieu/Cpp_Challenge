/* Easy

Codewriting

300

Determine if the given character is a digit or not.

Example

For symbol = '0', the output should be
isDigit(symbol) = true;
For symbol = '-', the output should be
isDigit(symbol) = false.
*/

bool isDigit(char symbol) {
    int c = symbol;
    if  (c < 48 || c > 57)
        return false;
    return true;
}
