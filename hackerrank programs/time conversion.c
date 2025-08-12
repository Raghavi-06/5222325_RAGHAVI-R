#include <stdio.h>
#include <string.h>

int main() {
    char s[11]; // Stores the input string, e.g."07:05:45PM"
    scanf("%s", s);

    // Get the AM/PM indicator
    char am_pm = s[8];

    // Get the first two characters of the hour
    char first_digit = s[0];
    char second_digit = s[1];

    // Handle PM cases
    if (am_pm == 'P') {
        if (first_digit == '1' && second_digit == '2') {
            // It's 12 PM (noon), no change needed to the hour
        } else {
            // For PM times from 1 to 11, add 12 to the hour
            s[0] += 1;
            s[1] += 2;
        }
    }
    // Handle AM cases
    else {
        if (first_digit == '1' && second_digit == '2') {
            // It's 12 AM (midnight), convert to "00"
            s[0] = '0';
            s[1] = '0';
        } else {
            // For AM times from 1 to 11, no change needed to the hour
        }
    }

    // Null-terminate the string to remove the AM/PM part
    s[8] = '\0';
    
    // Print the final result
    printf("%s\n", s);
    
    return 0;
}
