#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class TheTournamentDivTwo {
public:
	int find(vector <int>);
	};

	int TheTournamentDivTwo::find(vector <int> points) {
		int res=0;
			int i, oneCnt=0;
				
					sort(points.rbegin(), points.rend());
						for (i=0; i<points.size(); i++)
							{
									res += points[i] / 2;
											oneCnt += points[i] % 2;
												}
													if (! oneCnt % 2)
															return res + oneCnt/2;
																else
																		return -1;
																		}
int main()
{
}
