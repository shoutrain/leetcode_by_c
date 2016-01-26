/*
 * best_time_to_buy_and_sell_stock.c
 *
 *  Created on: Jan 15, 2016
 *      Author: rafael
 */

#include "common.h"

int maxProfit(int *prices, int pricesSize) {
	if (NULL == prices || 0 == pricesSize || 1 == pricesSize) {
		return 0;
	}

	int i = 1;
	int min = prices[0];
	int maxProfit = 0;


	for (; i < pricesSize; i++) {
		if (prices[i] >= min) {
			int profit = prices[i] - min;

			if (profit > maxProfit) {
				maxProfit = profit;
			}
		} else {
			min = prices[i];
		}
	}

	return maxProfit;
}

static void _run() {
	int prices[] = { 3, 5, 8, 2, 9, 1, 2 };

	printf("The max profit is: %d\n", maxProfit(prices, sizeof(prices) / sizeof(int)));
}

void best_time_to_buy_and_sell_stock() {
	_run();
}
