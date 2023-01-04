#include <stdio.h>
#include <stdint.h>
#include "mymemcmp.h"

int mymemcmp(const void *s1, const void *s2, size_t n){
    unsigned char *s1_ptr = (char *)s1;
    unsigned char *s2_ptr = (char *)s2;

    int64_t ans = 0;

    
    
    for(int32_t i=0 ; i<n ; i++){
        if(*s1_ptr != *s2_ptr){
            ans = *s1_ptr - *s2_ptr;
            
            break;
        }

        s1_ptr = s1_ptr + 1;
        s2_ptr = s2_ptr + 1;
    }

    return ans;
}