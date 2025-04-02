#include <iostream>
#include <tuple>

using namespace std;

tuple<char, int> shift(string go, tuple<char, int> location){
	tuple <char, int> origin;//인자로 받은 원래 위치를 저장
	get<0>(origin) = get<0>(location);
	get<1>(origin) = get<1>(location);

	if(go == "R"){
		++get<0>(location);//x+1
	}
	else if(go == "L"){
		--get<0>(location); //x-1
	}
	else if(go == "B"){
		--get<1>(location);
	}
	else if(go == "T"){
		++get<1>(location);
	}
	else if(go == "RT"){
		++get<0>(location);
		++get<1>(location);
	}
	else if(go == "LT"){
		--get<0>(location); //x-1
		++get<1>(location);
	}
	else if(go == "RB"){
		++get<0>(location);//x+1
		--get<1>(location);
	}
	else if(go == "LB"){
		--get<0>(location); //x-1
		--get<1>(location);
	}
	return location; //이동한 위치를 반환
}



int main(){

	char x; int y, n;
	cin >> x >> y;
	tuple<char, int>king_xy = make_tuple(x,y);//킹의 위치를 튜플로 받음
	cin >> x >> y;
	tuple<char, int>stone_xy = make_tuple(x,y);//돌의 위치를 튜플로 받음
	cin >> n;

	string go;

	for(int i = 0; i < n; i++){
		cin >> go;
		if(stone_xy == shift(go, king_xy)){//킹이 스톤과 같은 곳을 이동한다면면
			tuple<char, int> new_xy;
			new_xy = shift(go, stone_xy);
			if(get<0>(new_xy) >= 'A' && get<0>(new_xy) <= 'H' && get<1>(new_xy) >=1 && get<1>(new_xy) <=8){
				stone_xy = new_xy; //범위를 벗어나는지 검사 후 스톤 이동
			}
		}

		//스톤 위치와 킹 위치가 다를 때만 이동
		if(stone_xy != shift(go, king_xy)){
			tuple<char, int> new_xy;
			new_xy = shift(go, king_xy);
			if(get<0>(new_xy) >= 'A' && get<0>(new_xy) <='H' && get<1>(new_xy)>=1 && get<1>(new_xy) <= 8){
				king_xy = new_xy;
			}
		}
	}

	cout << get<0>(king_xy) << get<1>(king_xy) << '\n';
	cout << get<0>(stone_xy) << get<1>(stone_xy) << '\n';

	return 0;
}