#include <stdio.h>
static unsigned long mx_pow(int n, int pow) {
    unsigned long result = 1;
    if (pow < 0)
    	return 1;
    if (pow == 0)
    	return 1;
    for (int i = 0; i < pow; i++)
    	result *= n;
    return result;
}

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long result = 0;
    int len = 0;
    int j = 0;
    while(hex[len])
    	len++;
    
    for (int i = len - 1; i >= 0; i--) {
    	if (hex[i] >= 48 && hex[i] <= 57) 
            result +=  (hex[i] - '0') * mx_pow(16, j);
    	
        else if (hex[i] >= 97 && hex[i] <= 102) 
            result += (hex[i] - 87) * mx_pow(16, j);
        
        else if (hex[i] >= 65 && hex[i] <= 70) 
            result += (hex[i] - 55) * mx_pow(16, j);
        
        else
        	return 0;
        j++;
    }

    return result;
}
