#include<bits/stdc++.h>
using namespace std;

void HanoiTower(int num, int from, int by, int to)
{
	if (num == 1) printf("%d %d\n", from, to);
	else
	{
		HanoiTower(num - 1, from, to, by); // 일련의 과정과 관계 없이 1번 -> 2번으로 블록이 2개 이동
		printf("%d %d \n", from, to); // 이후 1번 -> 3번으로 가장 큰 블록 이동
		HanoiTower(num - 1, by, from, to); // 2번 -> 3번으로 "원판들을 이동"
	}
}

int main(void)
{
	int N;
	cin >> N;

	string a = to_string(pow(2, N));
	
	int x = a.find('.');				//pow 함수 결과가 실수형이기에 소수점 찾기
	a = a.substr(0, x);				//소수점 앞자리만 나오게하기
	a[a.length() - 1] -= 1;				//string a에 대한 마지막 위치의 인덱스 값에 -1

	cout << a << endl;

	if(N <= 20)
		HanoiTower(N, 1, 2, 3);

	return 0;
}

/*
https://travelerfootprint.tistory.com/108를 참고했음.
오랜만에 점화식을 봤는데 문제를 풀면서 점화식을 이용해서 최소 값을 구해야겠다는 생각을 못하고
백트래킹을 사용했다가 메모리 초과로 실패

또한 재귀를 구현하는 과정에서 HanoiTower의 from, to, by의 의미를 제대로 파악하지 못함.
문제에서는 블록을 1번에 1개만 움직이는데 재귀 자체는 그냥 블록 (전체) 자체가 어떻게 움직이는지에 대한 흐름을
재귀로 표현함. 그렇기 때문에 위의 주석으로 생각하면 됨.

일련의 재귀를 그냥 그림으로 그려서 판단하는 것이 편하다. 쉽게 말해서
"1개의 원판만 이동" -> printf 혹은 cout을 이용해서 이동 표현.
"원판들의 이동" -> HanoiTower()함수 사용.
*/

/*
그러니까 HanoiTower()는 from에서 to로 이동하는 일련의 과정을 표현하는 함수니까
"원판들이 이동하려면" 마찬가지로 HanoiTower() 함수를 사용해서 일련의 과정에 대한 재귀를 표현해야 한다.
첫번째 매개변수인 num은 정확하게 이동해야하는 원판의 남은 개수를 표현하는 것이다.
*/