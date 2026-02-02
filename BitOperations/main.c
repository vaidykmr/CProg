#include <stdio.h>

int main()
{
    int x = 0x1;
    int n = 2;
    x = x | (1 << n);
    
    printf("Setting nth bit in x : 0x%x \n", x);

    x = x & (~ (1 << n));

    printf("Clearing nth bit in x : 0x%x \n", x);

    int y = 1 << 31;
    printf("y : 0x%x \n", y);

    long int z = 0x8000000000000000;
    printf("z : 0x%lx \n", z >> 63);

    int a = 0x80000000;
    printf("z : 0x%x \n", a >> 31);   // Perform arithmetic right shift operation due to signed nature



    // Toggling a bit

    int b = 0xa1;
    n = 5;

    b = b ^ (1 << n);

    printf("Toggling nth bit in b : 0x%x \n", b);



    unsigned int v = 0x00001111;
    int count = 0;
    while (v != 0)
    {
        count += (v & 1);
        v = v >> 1;
    }

    printf("%d \n", count);

    // Kerningan's algorithm

    v = 0x00001111;
    count = 0;

    while (v)
    {
        v &= (v-1);
        count++;
    }


    // -1 is calculated using 2's complement. So (-v) = ~v + 1

    printf("%d \n", count);

    v = 0x00001111;
    count = 0;

    unsigned int check = 0U;

    for (int i = 0; i < 32; i++)
    {
        check = v & (1U << i);
        if (check)
            count++;
    }

    printf("%d \n", count);


    unsigned char c = 0b11110000;

    unsigned char r = 0;

    for (int i = 0; i < 8; i++)
    {
        // printf("0b%b \n", c);
        r <<= 1;
        r |= (c & 1);
        //printf("0b%b \n", r);
        c >>= 1;
    }

    printf("0b%b \n", r);



    // Creating a look up table

    unsigned char rev_bits[256];

    for (int i = 0; i < 256; i++)
    {
        unsigned char element = i;
        unsigned char v = 0;
        for (int bit = 0; bit < 8; bit++)
        {
            v <<= 1;
            v |= (element & 1);
            element >>= 1;
        }

        rev_bits[i] = v;
    }

    for (int i = 0; i < 256; i++)
    {
        printf(" i: %d 0b%b \n", i, rev_bits[i]);
    }


    unsigned int bb = 0x12345678;

    unsigned int result = rev_bits[bb & 0xFF] << 24 | rev_bits[(bb >> 8) & 0xFF] << 16 | rev_bits[(bb >> 16) & 0xFF] << 8 | rev_bits[(bb >> 24) & 0xFF] ; 

    printf("0b%b \n", result);



    // Rotating the bits

    // Rotating the bits from left to right

    unsigned char dd = 0b10011010;
    dd = ((dd << 2) | (dd >> (8-2)));
    printf("Rotating the bits from left to right = 0b%b \n", ((dd << 2) | (dd >> (8-2))));


    // Setting up bit mask

    int nn = 4;
    for (int i = 1; i <= nn; i++)
    {
        printf("0b%b \n", ((1 << i) - 1));
    }


    // Turning the right most bit off
    
    
    // Approach 1:

    unsigned char cc = 0b00101100;
    unsigned char cc_copy = cc;
    unsigned char rightMostBitFlag = 0;

    int countFlag = 0;
    while (rightMostBitFlag == 0)
    {
        countFlag++;
        rightMostBitFlag = cc & 1;
        cc >>= 1;
    }


    printf("0b%b \n", cc_copy ^ (1 << (countFlag - 1)));


    // Approach 2:

    cc = 0b00101100;

    int pos = -1;

    for (int i = 0; i < 8; i++)
    {
        if ( (cc >> i) & 1)
        {
            pos = i;
            break;
        }
    }

    printf("0b%b \n", cc ^ (1 << pos));


    pos = -1;

    for (int i = 0; i < 8; i++)
    {
        if ((cc << i) & 0x80)
        {
            pos = i;
            break;
        }
    }

    printf("0b%b \n", cc ^ (1 << (7 - pos)));



    unsigned char q = 100;
    unsigned char w = -q;

    printf("%u \n",w);

    return 0;
}