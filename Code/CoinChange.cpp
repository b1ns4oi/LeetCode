// https://leetcode.com/problems/coin-change/
// Memory Limit Exceeded Error
int coinChange(vector<int>& coins, int amount) {
	int n = coins.size();
	int i, j, k;

	vector<vector<int> > aux(amount+1, vector<int>(n+1, 0));

	for (i = 1; i <= amount; ++i) {
		// no coins
		aux[i][0] = -1;

		for (j = 1; j <= n; ++j) {
			if ((k = i - coins[j-1]) < 0 || aux[k][j] == -1)
				aux[i][j] = aux[i][j-1];
			else if (aux[i][j-1] == -1)
				aux[i][j] = 1 + aux[k][j];
			else
				aux[i][j] = std::min(aux[i][j-1], 1 + aux[k][j]);
		}
	}
	return aux[amount][n];
}


// Reference: https://discuss.leetcode.com/topic/32475/c-o-n-amount-time-o-amount-space-dp-solution
int coinChange2(vector<int>& coins, int amount) {
	int n = coins.size();
	int i, j;

	vector<int> aux(amount+1, amount+1);
	aux[0] = 0;

	for (i = 1; i <= amount; ++i) {
		for (j = 0; j < n; ++j) {
			if (coins[j] <= i)
				aux[i] = std::min(aux[i], 1+aux[i-coins[j]]);
		}
	}
	return aux[amount] > amount ? -1 : aux[amount];
}