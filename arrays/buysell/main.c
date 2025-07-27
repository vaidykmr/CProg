#include <stdio.h>

//Time complexity = O(n^2)
int maxProfit(int *prices, int priceSize)
{
    int profit = 0;
    int diff = 0;

    for (int i = 0; i < priceSize; i++)
    {
        for (int j = i+1; j < priceSize; j++)
        {
            diff = prices[j] - prices[i];

            if ((diff > profit) && (diff > 0))
            {
                profit = diff;
            }
        }
    }

    return profit;

}

// Time complexity = O(n)
int refactorMaxProfit(int *prices, int pricesSize)
{
    if (pricesSize == 0){
        return 0;
    }

    int minPrice = prices[0];
    int profit = 0;

    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }

        else
        {
            int diff = prices[i] - minPrice;
            if (diff > profit)
            {
                profit = diff;
            }
        }
    }

    return profit;
}

int main()
{
    int prices[6] = {7, 1, 5, 3, 6, 4};
    int *pricesptr = NULL;
    pricesptr = prices;
    //int profit = maxProfit(pricesptr, 5);
    int profit = refactorMaxProfit(pricesptr, 6);

    printf("My profit is %d", profit);
    return 0;
}