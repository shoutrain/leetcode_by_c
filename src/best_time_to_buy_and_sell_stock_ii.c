/*
 * best_time_to_buy_and_sell_stock_ii.c
 *
 *  Created on: Jan 26, 2016
 *      Author: rafael
 */

#include "common.h"

int maxProfitII(int *prices, int pricesSize) {
	if (NULL == prices || 0 == pricesSize || 1 == pricesSize) {
		return 0;
	}

	int i = pricesSize - 1;
	int maxProfit = 0;

	for (; i > 0; i--) {
		int profit = prices[i] - prices[i - 1];

		if (0 < profit) {
			maxProfit += profit;
		}
	}

	return maxProfit;
}

static void _run() {
	int prices[] = { 3, 5, 8, 2, 9, 1, 2 };

	printf("The max profit is: %d\n",
			maxProfitII(prices, sizeof(prices) / sizeof(int)));
}

void best_time_to_buy_and_sell_stock_ii() {
	_run();
}
