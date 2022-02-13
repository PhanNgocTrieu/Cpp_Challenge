// You've intercepted an encrypted message, and you are really curious about its contents.
// You were able to find out that the message initially contained only lowercase English letters,
// and was encrypted with the following cipher:

// Let all letters from 'a' to 'z' correspond to the numbers from 0 to 25, respectively.
// The number corresponding to the ith letter of the encrypted message is
// then equal to the sum of numbers corresponding to
// the first i letters of the initial unencrypted message modulo 26.

// Now that you know how the message was encrypted, implement the algorithm to decipher it.

// Example

// For message  = "taiaiaertkixquxjnfxxdh", the output should be
// cipher26(message) = "thisisencryptedmessage".

// The initial message "thisisencryptedmessage" was encrypted as follows:

// letter 0: t -> 19 -> t;
// letter 1: th -> (19 + 7) % 26 -> 0 -> a;
// letter 2: thi -> (19 + 7 + 8) % 26 -> 8 -> i;
// etc.

#include <iostream>

using namespace std;

/*
algorithm:
taiaiaertkixquxjnfxxdh
0: t = 19 -> t
	sum = 19;
	out: t
	
1: a = 0:
	(sum + number) % 26 = 0
	 -> number = 26 + 0 - sum
		number = 26 - 19 = 7 -> h;
		sum = 19 + 7 = 26;
		
	out: th
	
2: i = 8:
	(33 + ...) % 26 = 8;
	(sum + number) % 26 = 8
	 -> number = 26 + 8 - sum;
		number = 34 - 26 = 8 -> i
		sum = 26 + 8 = 33;
		sum = 33 - 26 = 8;
		
	out :thi
	
3: a = 0:
	(sum + number) % 26 = 0;
	 -> number = 26 + 0 - sum;
		number = 26 - 8 = 18;
		sum = 8 + 16;
	out: this

4: i = 8:
	(sum + number) % 26 = 8;
	 -> number = 26 + 8 - sum;
		number = 34 - 26 = 8;
		sum = 26 + 8 = 34 (>26);
		sum = 32 - 26 = 8;
		
		out: thisi
		
5: a = 0:
	(sum + number) % 26 = 0;
	 -> number = 26 + 0 - sum
		number = 26 - 8 = 18 (s);
		sum = 8 + 18 = 26;
		
		out: thisis

6: e = 4:
	(sum + number) % 26 = 4;
	 -> number = 26 + 4 - sum;
		number = 30 - 26 = 4 (e);
		sum = 26 + 4 > 26
		sum = 30 - 26 = 4;
		
		out: thisise

7: r = 17:
	(sum + number) % 26 = 17;
	 -> number = 26 + 17 - sum;
		number = 43 - 4 = 39; > 26
		-> 39 - 26 = 13;
		sum = 4 + 13 = 17;
		
		out: thisisen;

*/

string cipher26(string message)
{
    string res = "";
    // take first letter
    res += message[0];

    int len = message.length();

    // sum of first number
    int sum = (int)message[0] - 'a';

    for (int idex = 1; idex < len; idex++)
    {
        // take next letter - encrypted
        int encryptedletter = (int)message[idex] - 'a';

        // take reference letter - unencrypted
        int unencryptedLetter = 26 + encryptedletter - sum;

        // checking whether letter is larger than 26 or not
        if (unencryptedLetter >= 26)
        {
            unencryptedLetter = unencryptedLetter - 26;
        }

        res += (char)('a' + unencryptedLetter);

        sum = sum + unencryptedLetter;

        // checking whether sum is larger than 26 or not
        if (sum > 26)
        {
            sum = sum - 26;
        }
        cout << "res: " << res << endl;
    }

    return res;
}

int main()
{
    cout << cipher26("taiaiaertkixquxjnfxxdh") << endl;
    return 0;
}