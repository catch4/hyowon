#include <string>
#include <vector>

using namespace std;

int INF = 200000000;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int left = 1;
	int right = INF;

	while (left<=right)
	{
		int mid = (left + right) / 2;
		int cnt = 0;
		bool check=false;

		vector <int> temp;

		for (int i = 0; i < stones.size(); i++) {
			temp.push_back(stones[i] - mid);
		}

		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] <= 0) 
				cnt++;
			else
				cnt = 0;

			if (cnt >= k) {
				check = true;
				break;
			}
		}

		if (check)
			right = mid - 1;
		else
			left = mid + 1;
	}
    
    answer=left;
    
    return answer;
}