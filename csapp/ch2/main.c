#include <stdio.h>

#define float_bits unsigned int

float_bits float_negate(float_bits f){
    unsigned sign = !(f >> 31);
    unsigned exp = (f >> 22) & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    // if f is Nan
    if (exp == 0xFF && frac != 0){
        sign = f >> 31;
        }
    return (sign << 31) | (exp << 23) | frac;

}

int main(void)
{
    unsigned int negate = float_negate(0xFFFFFFFF);
    printf("The negative of the float number is %.x \n",negate);
}


