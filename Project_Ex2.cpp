#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<queue>
#include<unordered_map>
#include<unordered_set>
//1
////m*n + n*log n + m*n = m*n
//int ConinChange(std::vector<int>& coins, const int amount)
//{
//	if (amount == 0)
//	{
//		return 0;
//	}
//
//	std::vector<bool> table(amount + 1, false);
//	table[0] = true;
//
//	for (int i = 0; i <= amount; ++i)
//	{
//		if (table[i])
//		{
//			for (auto e : coins)
//			{
//				if (i + e <= amount)
//				{
//					table[i + e] = table[i];
//				}
//			}
//		}
//	}
//
//	if (table[amount] == false)
//	{
//		return -1;
//	}
//	std::sort(coins.begin(), coins.end(), [](int i, int j)->bool {return j < i; });
//
//	
//	int temp = amount;
//	int result{};
//	while (temp != 0)
//	{
//		for (auto c : coins)
//		{
//			if (temp - c >= 0)
//			{
//				if (table[temp - c] == true)
//				{
//					temp = temp - c;
//					result++;
//					break;
//				}
//			}
//		}
//	}
//
//	return result;
//}
//m*n
int ConinChange(std::vector<int>& coins, const int amount)
{
	if (amount == 0)
	{
		return 0;
	}

	std::vector<int> v(amount + 1, 9999);
	v[0] = 0;

	for (auto coin : coins)
	{
		for (int i = coin; i <= amount; i++)
		{
			v[i] = std::min(v[i], v[i - coin] + 1);
		}
	}
	if (v[amount] == 9999)
	{
		return -1;
	}
	return v[amount];
}


//m*n*n?
//bool CanWordBreak(const std::string s, const std::vector<std::string>& wordDict)
//{
//	int size = s.size()+1;
//	std::vector<bool> table(size, false);
//	table[0] = true;
//
//	for (int i = 0; i < size; i++)
//	{
//		if (table[i])
//		{
//			for (auto e : wordDict)
//			{
//				if (i + (e.size()) < size)
//				{
//					if (i == s.find(e))
//					{
//						table[i + e.size()] = table[i];
//					}
//				}
//				
//			}
//		}
//	}
//	return table[size-1];
//}

//bool CanWordBreak(const std::string s, const std::vector<std::string>& wordDict)
//{
//	
//	std::vector<bool> table(s.size()+1, false);
//	table[0] = true;
//
//	for (int i = 0; i <= s.size(); i++)
//	{
//		for (auto& word : wordDict)
//		{
//			if (i + word.size() <= s.size() && s.substr(i, word.size()) == word)
//			{
//				table[i + word.size()] = true;
//			}
//		}
//	}
//	return table[s.size()];
//}

bool CanWordBreak(const std::string s, const std::vector<std::string>& wordDict)
{
	std::unordered_set<std::string>set;
	for (auto e : wordDict)
	{
		set.insert(e);
	}

	std::string tempStr = s;
	std::string resStr = s;

	auto index = set.begin();

	while (index != set.end())
	{
		std::string strs = *index;

		int length = set.size();
		int resLength = resStr.size();

		std::string saveStr = resStr;

		tempStr = resStr.substr(0, length);

		if (length > resLength)
		{
			index++;
			continue;
		}
		resStr = resStr.substr(length);

		if (tempStr == strs)
		{
			resStr = resStr;
			index = set.begin();
			if (resStr.empty())
			{
				return true;
			}
		}
		else 
		{
			resStr = saveStr;
			++index;
		}
	}
	return false;
}
	



int MaxProfit(const std::vector<int>& prices)
{
	if (prices.empty()) return 0; // 가격 배열이 비어있으면 이익은 0

	int min_price = prices[0]; // 첫 번째 가격을 최소 가격으로 초기화
	int max_profit = 0; // 최대 이익을 0으로 초기화

	// 가격 배열의 두 번째 요소부터 끝까지 순회
	for (size_t i = 1; i < prices.size(); ++i)
	{
		// 현재 이익을 계산하고 최대 이익을 갱신
		max_profit = std::max(max_profit, prices[i] - min_price);

		// 현재 가격을 이용해 최소 가격 갱신
		min_price = std::min(min_price, prices[i]);
	}

	return max_profit; // 최대 이익 반환
}


////n*n
//int MaxProfit(const std::vector<int>& prices)
//{
//	
//	std::multimap<int, std::pair<int, int>> map;
//	int size = prices.size();
//	for (int i = 0; i< size; i++)
//	{
//		for (int j = i + 1; j < size; j++)
//		{
//			if (prices[j] - prices[i] > 0)
//			{
//				map.insert({ prices[j] - prices[i], {i,j} });
//			}
//		}
//	}
//	
//	return std::max_element(map.begin(), map.end())->first;
//}
// 
//n
int lengthOfLongestSubstring(const std::string& s) 
{
	int len = s.length();

	if (len <= 1) 
	{
		return len;
	}

	std::vector<int> repeat(128, 0);
	int left = 0, right = 0;
	repeat[s[left]]++;

	int answer = 0;
	while (true) {
		if (right == len - 1) {
			break;
		}

		if (right < len - 1 && repeat[s[right + 1]] == 0) {
			repeat[s[++right]]++;
			answer = std::max(answer, right - left + 1);
		}
		else {
			repeat[s[left++]]--;
		}
	}

	return answer;
}
//int LengthOfLongestSubstring(std::string s)
//{
//	int answer{};
//	for (int i{}; i < s.length(); i++)
//	{
//		int count{ 1 };
//		while (s[i + 1] == s[i] + 1)
//		{
//			i++;
//			count++;
//		}
//		if (answer < count) answer = count;
//	}
//	return answer;
//}

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//n
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

	//std::cout << CanWordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"});

	//std::vector<int> x{ 7,6,4,3,1 };
	//std::cout << MaxProfit(x);

	std::string s("pwwkew");
	std::cout << lengthOfLongestSubstring(s);

}
