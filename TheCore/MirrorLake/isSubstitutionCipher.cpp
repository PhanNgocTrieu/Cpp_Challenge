/*
A ciphertext alphabet is obtained from the plaintext alphabet by means of rearranging some characters.
For example "bacdef...xyz" will be a simple ciphertext alphabet where a and b are rearranged.

A substitution cipher is a method of encoding where each letter of the plaintext alphabet is replaced with the corresponding
(i.e.having the same index) letter of some ciphertext alphabet.

Given two strings, check whether it is possible to obtain them from each other using some(possibly, different) substitution ciphers.

Example:

For string1 = "aacb"and string2 = "aabc", the output should be
isSubstitutionCipher(string1, string2) = true.

Any ciphertext alphabet that starts with acb... would make this transformation possible.

For string1 = "aa" and string2 = "bc", the output should be
isSubstitutionCipher(string1, string2) = false.
*/







struct CipherValue
{
    char key;
    char value;
};


bool isSubstitutionCipher(string string1, string string2) {

    CipherValue Message_Value[26];
	
	if (string1 == string2)
        return true;

    int index = 0;
	int index_Mess = 0;
    const int length = string1.length();

	for (; index < length; index++)
	{
			int in = 0;
			for (int j = 0; j < index_Mess; j++)
			{
				if (string1[index] == Message_Value[j].key)
				{
					in++;
					if (Message_Value[j].value != string2[index])
						return false;

					
				}
			}
			if (in == 0)
			{
				for (int j = 0; j < index_Mess; j++)
				{
					if (string2[index] == Message_Value[j].value)
					{
						if (string1[index] != Message_Value[j].key)
							return false;
					}
				}
				Message_Value[index_Mess].key = string1[index];
				Message_Value[index_Mess].value = string2[index];
				index_Mess++;
			}
	}

    return true;
}
