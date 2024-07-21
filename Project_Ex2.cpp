#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<queue>
//1

int ConinChange(std::vector<int>& coins, const int amount)
{
	if (amount == 0)
	{
		return 0;
	}

	std::vector<bool> table(amount + 1, false);
	table[0] = true;

	for (int i = 0; i <= amount; ++i)
	{
		if (table[i])
		{
			for (auto e : coins)
			{
				if (i + e <= amount)
				{
					table[i + e] = table[i];
				}
			}
		}
	}

	if (table[amount] == false)
	{
		return -1;
	}
	std::sort(coins.begin(), coins.end(), [](int i, int j)->bool {return j < i; });

	int coin = coins[0];
	int temp = amount;
	int coinCont{};
	while (temp != 0)
	{
		for (auto c : coins)
		{
			if (temp - c >= 0)
			{
				if (table[temp - c] == true)
				{
					temp = temp - c;
					coinCont++;
					break;
				}
			}
		}
	}

	return coinCont;
}

bool CanWordBreak(const std::string s, const std::vector<std::string>& wordDict)
{
	int size = s.size()+1;
	std::vector<bool> table(size, false);
	table[0] = true;

	for (int i = 0; i < size; i++)
	{
		if (table[i])
		{
			for (auto e : wordDict)
			{
				if (i + (e.size()) < size)
				{
					if (i == s.find(e))
					{
						table[i + e.size()] = table[i];
					}
				}
				
			}
		}
	}
	return table[size-1];
}

int MaxProfit(const std::vector<int>& prices)
{
	
	std::multimap<int, std::pair<int, int>> map;
	int size = prices.size();
	for (int i = 0; i< size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (prices[j] - prices[i] > 0)
			{
				map.insert({ prices[j] - prices[i], {i,j} });
			}
		}
	}
	
	return (std::max_element(map.begin(), map.end())->second.second) + 1;

}

int LengthOFLongestSubstring(std::string s)
{
	std::string answer;
	answer = s[0];
	for (int i = 1; i < s.size(); i++)
	{
		if (answer.find(s[i]) == -1)
		{
			answer += s[i];
		}
	}

	return answer.size();
}

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int MaxBTDepth(TreeNode* root)
{
	
	if (root == nullptr)
	{
		return 0;
	}
	std::queue<std::pair<TreeNode*, int>> q;
	q.push({root,1});
	int result{};
	while (!q.empty())
	{
		auto node = q.front().first;
		int depth = q.front().second;
		q.pop();

		result = std::max(result, depth);

		if (node->left) { q.push({node->left,depth+1}); }
		if (node->right) { q.push({ node->right,depth + 1 } ); }
	}

	return result;
}
int main()
{

	//std::vector<int> coins{ 1,3,5 };
	//std::cout << ConinChange(coins, 11);

	//std::cout << CanWordBreak("helloword", {"hello", "word"});

	//std::vector<int> x{ 7,1,5,3,6,4 };
	//std::cout << MaxProfit(x);

	//std::string s("abcabcbb");
	//std::cout << LengthOFLongestSubstring(s);

	
}
