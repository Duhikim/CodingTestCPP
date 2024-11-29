#include <iostream>
#include <windows.h> //windows.h 헤더 추가
#pragma comment(lib, "Winmm.lib") //winmm.lib 추가
using namespace std;

//
// project4에서는 모든 data를 array형식으로 처리했으나
// project5에서는 plc data를 pointer를 사용해보려 함
// 
// 한국에서 필요한 기본data는 엄청 많지만(1,000,000이상?)
// 지역에서 길을 찾을 때 검사해야 할 장소의 수는
// 엄청 적을 수 있으므로 매번 전부 초기화 할 필요 없음
//
bool debug	//= true;
			= false;
// 77 지점이 있음
const int plc_max = 77;

//
// 한 지점에서 갈 수 있는 다음장소 그리고 그곳 까지 거리(meter)를
// 장소 list 순서에 따라 구분 않고 나열
//
struct street {
	int neibor; // 갈수있는 이웃
	int dist;	// 그곳까지 거리
};
const street ways[] = {
	{	35,	157	},{	 1,	39	},{	21,	160	},	// 지점 list의 첫번째 지점에서 갈 수 있는 곳{35th 지점, 157m} 등등 3개 data
	{	 0,	41	},{	 2,	194	},{	 3,	205	},{	 6,	207	},
	{	 1,	188	},{	 6,	139	},{	 7,	135	},{	40,	84	},
	{	26,	95	},{	 5,	154	},{	 6,	183	},{	 1,	166	},
	{	26,	150	},{	44,	153	},{	 5,	38	},
	{	 4,	40	},{	10,	161	},{	 6,	125	},{	 3,	146	},
	{	 1,	204	},{	 3,	176	},{	 5,	146	},{	10,	165	},{	11,	205	},{	 9,	160	},{	 7,	133	},{	 2,	179	},
	{	 2,	136	},{	 6,	146	},{	 9,	138	},{	 8,	55	},
	{	40,	167	},{	 7,	50	},{	63,	167	},
	{	 6,	155	},{	11,	114	},{	63,	71	},{	 7,	135	},
	{	 5,	120	},{	44,	106	},{	11,	141	},{	 6,	160	},
	{	 6,	174	},{	10,	127	},{	12,	58	},{	 9,	144	},
	{	11,	58	},{	45,	165	},{	64,	153	},
	{	17,	100	},{	16,	59	},{	14,	93	},
	{	13,	101	},{	15,	59	},{	28,	304	},
	{	14,	59	},{	16,	94	},{	20,	53	},
	{	13,	53	},{	17,	97	},{	19,	52	},{	15,	92	},
	{	18,	52	},{	16,	93	},{	13,	105	},
	{	17,	53	},{	23,	50	},{	19,	85	},
	{	16,	56	},{	18,	89	},{	22,	56	},{	20,	96	},{	33,	326	},
	{	15,	56	},{	19,	89	},{	21,	58	},
	{	20,	54	},{	22,	90	},{	26,	55	},{	 0,	155	},
	{	19,	50	},{	23,	92	},{	25,	51	},{	21,	101	},
	{	18,	51	},{	24,	57	},{	22,	97	},
	{	23,	52	},{	41,	358	},{	25,	97	},
	{	22,	52	},{	24,	96	},{	42,	277	},{	26,	90	},
	{	21,	55	},{	25,	97	},{	 4,	170	},{	 3,	85	},
	{	28,	145	},{	30,	52	},{	31,	169	},
	{	14,	359	},{	29,	52	},{	27,	132	},
	{	28,	52	},{	34,	53	},{	30,	145	},
	{	27,	51	},{	29,	139	},{	33,	54	},{	31,	130	},
	{	27,	174	},{	30,	140	},{	32,	59	},
	{	31,	50	},{	33,	143	},{	37,	55	},
	{	30,	56	},{	19,	360	},{	34,	149	},{	36,	56	},{	32,	127	},
	{	29,	53	},{	35,	59	},{	33,	145	},
	{	34,	58	},{	 0,	170	},{	40,	54	},{	36,	129	},
	{	33,	53	},{	35,	141	},{	66,	289	},{	39,	52	},{	37,	142	},
	{	32,	56	},{	36,	129	},{	38,	51	},
	{	37,	57	},{	39,	149	},{	60,	335	},
	{	36,	56	},{	40,	131	},{	38,	142	},
	{	35,	50	},{	 2,	88	},{	 8,	153	},{	39,	132	},
	{	24,	327	},{	49,	54	},{	 4,	104	},
	{	25,	294	},{	41,	113	},{	47,	57	},{	43,	50	},
	{	42,	50	},{	46,	52	},{	44,	58	},
	{	 4,	179	},{	43,	56	},{	45,	54	},{	10,	106	},
	{	44,	50	},{	46,	53	},{	57,	111	},{	12,	158	},
	{	43,	53	},{	47,	59	},{	55,	59	},{	45,	58	},
	{	42,	59	},{	48,	53	},{	53,	57	},{	46,	52	},
	{	49,	52	},{	51,	59	},{	47,	59	},
	{	41,	59	},{	50,	113	},{	48,	50	},
	{	49,	106	},{	59,	120	},{	52,	57	},
	{	48,	53	},{	52,	54	},{	53,	57	},
	{	51,	52	},{	50,	53	},{	54,	53	},
	{	47,	51	},{	51,	52	},{	54,	58	},{	55,	59	},
	{	53,	57	},{	52,	51	},{	59,	53	},{	56,	59	},
	{	46,	56	},{	53,	59	},{	56,	51	},
	{	55,	53	},{	54,	51	},{	57,	54	},{	72,	302	},
	{	45,	117	},{	56,	55	},{	58,	50	},
	{	57,	57	},{	59,	100	},{	74,	300	},
	{	54,	54	},{	50,	125	},{	58,	115	},
	{	38,	341	},{	61,	150	},{	68,	51	},
	{	62,	56	},{	66,	50	},{	60,	159	},
	{	63,	100	},{	65,	51	},{	61,	50	},
	{	 8,	179	},{	 9,	80	},{	64,	51	},{	62,	114	},
	{	63,	59	},{	12,	166	},{	73,	102	},{	65,	102	},
	{	62,	57	},{	64,	101	},{	72,	110	},{	66,	56	},
	{	61,	59	},{	36,	295	},{	65,	58	},{	71,	103	},{	67,	52	},
	{	66,	57	},{	70,	108	},{	68,	117	},
	{	60,	56	},{	67,	101	},{	69,	104	},
	{	68,	111	},{	70,	102	},{	76,	137	},
	{	67,	104	},{	71,	51	},{	76,	59	},{	69,	54	},
	{	66,	100	},{	72,	56	},{	70,	54	},
	{	65,	100	},{	56,	332	},{	73,	115	},{	75,	57	},{	71,	51	},
	{	64,	110	},{	74,	57	},{	72,	110	},
	{	73,	51	},{	58,	333	},{	75,	113	},
	{	72,	50	},{	74,	110	},{	76,	105	},
	{	70,	57	},{	75,	107	},{	69,	130	}
};

//
// 지명에 관계되는 data 형식
//
const struct place_data {
	string		name;		// 지명이름
	int 			w_start;	// 그 지명에 연결되는 길(ways)의 시작 점
	int			w_nr;		// 그리고 연결된 길의 갯수
};
const place_data plc[plc_max] = {
	{"Cir01",  0, 3},	{"Cir02",  3, 4},	{"Cir03",  7, 4},	{"Cir04", 11, 4},
	{"Cir05", 15, 3},	{"Cir06", 18, 4},	{"Cir07", 22, 8},	{"Cir08", 30, 4},
	{"Cir09", 34, 3},	{"Cir10", 37, 4},	{"Cir11", 41, 4},	{"Cir12", 45, 4},
	{"Cir13", 49, 3},
	{"NE01",  52, 3},	{"NE02",  55, 3},	{"NE03",  58, 3},	{"NE04",  61, 4},
	{"NE05",  65, 3},	{"NE06",  68, 3},	{"NE07",  71, 5},	{"NE08",  76, 3},
	{"NE09",  79, 4},	{"NE10",  83, 4},	{"NE11",  87, 3},	{"NE12",  90, 3},
	{"NE13",  93, 4},	{"NE14",  97, 4},
	{"NW01", 101, 3},	{"NW02", 104, 3},	{"NW03", 107, 3},	{"NW04", 110, 4},
	{"NW05", 114, 3},	{"NW06", 117, 3},	{"NW07", 120, 5},	{"NW08", 125, 3},
	{"NW09", 128, 4},	{"NW10", 132, 5},	{"NW11", 137, 3},	{"NW12", 140, 3},
	{"NW13", 143, 3},	{"NW14", 146, 4},
	{"SE01", 150, 3},	{"SE02", 153, 4},	{"SE03", 157, 3},	{"SE04", 160, 4},
	{"SE05", 164, 4},	{"SE06", 168, 4},	{"SE07", 172, 4},	{"SE08", 176, 3},
	{"SE09", 179, 3},	{"SE10", 182, 3},	{"SE11", 185, 3},	{"SE12", 188, 3},
	{"SE13", 191, 4},	{"SE14", 195, 4},	{"SE15", 199, 3},	{"SE16", 202, 4},
	{"SE17", 206, 3},	{"SE18", 209, 3},	{"SE19", 212, 3},
	{"SW01", 215, 3},	{"SW02", 218, 3},	{"SW03", 221, 3},	{"SW04", 224, 4},
	{"SW05", 228, 4},	{"SW06", 232, 4},	{"SW07", 236, 5},	{"SW08", 241, 3},
	{"SW09", 244, 3},	{"SW10", 247, 3},	{"SW11", 250, 4},	{"SW12", 254, 3},
	{"SW13", 257, 5},	{"SW14", 262, 3},	{"SW15", 265, 3},	{"SW16", 268, 3},
	{"SW17", 271, 3} };

//
// navi algorithm에 사용되는 data형식
//
struct wor_pnt { // means working point data
	int		plc_ind;		// 지점의 index
	int		come_from;		// 어느 지점에서 왔나
	int		go_to;			// 어디로 가는 지
	bool	in_f_chain;     // front chain에 있는지?
	wor_pnt* pre_pnt;		// front chain에서 앞
	wor_pnt* post_pnt;		// front chain에서 뒤
	int		dist_f_start;	// 시작점으로 부터 거리
};
int			used_pnt = 0;		// navi에 사용된 pnt 갯수
wor_pnt		w_pnt[plc_max]{};	// working point data들, used_pnt개 만 사용됨
wor_pnt*	plc2pnt[plc_max]{};	// plc와 w_pnt 연결에 필요한 pointer들
int			start_i, end_i;		// 시작점 종점의 index
wor_pnt*	chain_start;		// front chain의 시작을 가르킴

// program시작시 plc2pnt를 모두 nullptr로 채움
void init_plc2pnt() {for (int i = 0; i < plc_max; i++) plc2pnt[i] = nullptr;}
// 출발점과 도착지점이 입력된 후 뒤
// 전에 사용한 plc2pnt data를 초기화(nullptr)
// chain_start w_pnt[0] 값을 기입
void plc_init() {
	for (int i = 0; i < used_pnt; i++) plc2pnt[w_pnt[i].plc_ind] = nullptr;
	// 출발점(plc[0]) data
	plc2pnt[start_i] = chain_start = &w_pnt[0];
	w_pnt[0] = { start_i, start_i, 0, true, nullptr, nullptr, 0 };
	used_pnt = 1;
}

//
// plc안에서 주어진 이름('str')의 index를 찾는 routine.
// plc[].name에 없을 땐 plc_max를 return
//
int find_index_in_names(const string str) {
	int start_ind	= 0;
	int end_ind		= plc_max - 1;
	while (true) {
		int temp_ind = end_ind - start_ind; // temp_ind = 조사할 갯수 - 1
		if (temp_ind == 0) {	// 조사할 이름이 오직 한개
			if (str == plc[start_ind].name)	return start_ind;
			else							return plc_max;
		}
		if (temp_ind == 1) {	// 조사할 이름이 두개
			if (str == plc[start_ind].name)	return start_ind;
			if (str == plc[end_ind].name)	return end_ind;
			else							return plc_max;
		}
		// 조사 대상이 3개 이상
		temp_ind = start_ind + temp_ind / 2; // temp_ind = 대충 중간값 
		if (str > plc[temp_ind].name)	start_ind = temp_ind + 1;
		else							end_ind = temp_ind;
	}
}

/* data 정리하면
const int plc_max = 77,  77 지점이 있음
struct street {int neibor; int dist;};
const  street ways[plc_max]{}
struct wor_pnt{ // working point
	int		plc_ind;	int come_from;		int go_to;
	bool	in_f_chain;	wor_pnt* pre_pnt;	wor_pnt* post_pnt;
	int		dist_f_start;};
wor_pnt		w_pnt[plc_max]{}
wor_pnt*	plc2pnt[plc_max]{};	// plc와 w_pnt 연결에 필요한 data들
struct place_data {string	name; int w_start; int w_nr;};
place_data plc[plc_max]
int		start_i, end_i;
int		used_pnt = 0;
wor_pnt* chain_start;
*/

// insert_front_chain()은 새로운점(이웃)이 front chain에 삽입 될 때 호출
void insert_front_chain(wor_pnt* neib_pnt) {
	wor_pnt* cur_pnt = chain_start;
	wor_pnt* next_pnt;
	int neib_dist = neib_pnt->dist_f_start;
	// 우선 front chain에서 neighbor의 삽입 위치를 찾고
	while ((next_pnt = cur_pnt->post_pnt) != nullptr) {
		// chain에 비교 않한 다음 점이 있고
		if (neib_dist <= next_pnt->dist_f_start) {
			// 그 점 보다 new_dist가 짧거나 같으면
			// 즉 neighbor까지 거리가 chain의 current point와 next point사이에 넣을 수 있으면
			cur_pnt->post_pnt = neib_pnt;
			next_pnt->pre_pnt = neib_pnt;
			neib_pnt->pre_pnt = cur_pnt;
			neib_pnt->post_pnt = next_pnt;
			return;
		}
		else cur_pnt = next_pnt;
	}
	// chain의 끝 값 보다 큰 경우 chain 끝에 삽입, 
	cur_pnt->post_pnt  = neib_pnt;
	neib_pnt->pre_pnt  = cur_pnt;
	neib_pnt->post_pnt = nullptr;
	return;
	}

// chage_front_chain()은 이미 이웃이 front chain에 있고
// 새 path가 더 짧아 front chain 순서를 변경 할 때
void change_front_chain(wor_pnt* neib_pnt) {
	// 우선 neib_pnt를 front chain에서 빼고
	neib_pnt->pre_pnt->post_pnt = neib_pnt->post_pnt;
	if (neib_pnt->post_pnt != nullptr) // front chain의 꿑이 아니면
		neib_pnt->post_pnt->pre_pnt = neib_pnt->pre_pnt;
	// front chain의 적당한 점을 찾아 삽입
	insert_front_chain(neib_pnt);
	return;
}

// find_way() algorithm은
// 
// 출발점을 front chain에 넣고
// 
// front chain중 출발점으로 부터거리가 제일 짧은 점(chain_start)으로 부터
// 갈 수 있는 지점들을 찾아
// front chain에 올림차순으로 sort하여 넣고
// (동시에 plc2pnt[place index] w_pnt[]의 주소기입)
// 끝으로 chain_start점의 in_f_chain을 false로 처리후 chain start를 다음 점으로
// 
// front chain의 첫점을 대상으로 위와 같은 작업을 계속하면 각 점들은
// '처리했음		(w_pnt[].in_f_chain == false)',
// 'front chain임	(w_pnt[].in_f_chain == true)' 그리고
// '처리 안함		(plc[place index] == nullptr)'의 집합으로 구분됨.
// 
// front chain의 첫점(거리가 재일 짧은점)이 종착점(end_i)이면 이 algorithm은 끝내고
// 출력routine이 시작됨
// 
// 한 지점에서 갈 수 있는 지점들을 찾아 front chain에 넣을 때
// 갈 수 있는 지점이 '처리했음'일 경우
// 전에 계산된 시작점에서 '처리했음' 지점까지 거리가
// '새로 계산되는 거리'보다 짧을 수 없으므로
// 무시(front_chain에 넣을 필요 없음) 하고(김명호 생각)
// '처리 안함'일 경우 front chain에 위치를 찾아 끼워 넣어야하고
// 'front chain임'일 경우 새로 계산되는 거리가
// 전에 계산된 거리보다 짧을 경우
// front chain에서 맞는 위치 찾아 넣음
//

void find_way() {
	// front chain의 첫 지점 index가 end_i이면 길을 찾은 것
	int s_ind; // front chain 첫 지점
	while ((s_ind = chain_start->plc_ind) != end_i) {
		// s_ind가 가리키는 지점에서 갈 수 있는 곳들을 조사
		int ways_ind =			  plc[s_ind].w_start;
		int ways_end = ways_ind + plc[s_ind].w_nr;
		int cur_dist_f_start = chain_start->dist_f_start;
		if (debug) cout << plc[s_ind].name << " is top, dist " << cur_dist_f_start << endl;
		for (; ways_ind < ways_end; ways_ind++) {
			// neib_ind는 ind로 부터 갈 수 있는 곳
			int			neib_ind		 = ways[ways_ind].neibor;
			int			new_dist_f_start = ways[ways_ind].dist + cur_dist_f_start;
			wor_pnt*	neib_pnt		 = plc2pnt[neib_ind];
			if (neib_pnt == nullptr) { // not checked(means 'not_touched' in project4), use new wor_pnt
				wor_pnt* temp_p = &w_pnt[used_pnt++]; // w_pnt 하나 더 사용
				plc2pnt[neib_ind]    = temp_p;
				temp_p->plc_ind      = neib_ind;
				temp_p->come_from    = s_ind;
				temp_p->in_f_chain   = true;
				temp_p->dist_f_start = new_dist_f_start;
				insert_front_chain(temp_p);
				if (debug) cout << " new " << plc[neib_ind].name << " is neighbor " << new_dist_f_start << endl;
			}
			else
			if (neib_pnt->in_f_chain) { // 이미 neib pnt가 front chain에 있고
				if (neib_pnt->dist_f_start > new_dist_f_start) { // 새 거리가 짧으면
					neib_pnt->dist_f_start = new_dist_f_start;
					neib_pnt->come_from	   = s_ind;
					change_front_chain(neib_pnt);
					if (debug) cout << " new " << plc[neib_ind].name << " is neighbor " << new_dist_f_start << endl;
				}
			}
			
		}
		// s_ind 항이 처리 되었으므로
		// front chain에서 제거
		chain_start->in_f_chain = false;
		if (debug) cout << " del " << plc[chain_start->plc_ind].name << endl;
		chain_start = chain_start->post_pnt;
	}
}

void disp_way() {
	// 우선 wor_pnt안에 come_from은 어디로부터 왔는지 표시 하므로
	// start_i로 부터 출력하려면 순서를 뒤 바꿔줘야 함
	wor_pnt* son	= plc2pnt[end_i];
	wor_pnt* father	= plc2pnt[son->come_from];
	son->go_to		= end_i;
	while (father != son) {
		father->go_to = son->plc_ind;
		son = father;
		father = plc2pnt[son->come_from];
	}
	// 지금 부터 start_i로 부터 출력
	if (start_i == end_i) cout << "출발점과 종점이 같습니다." << endl;
	else {
		int index = start_i;
		cout << "출발 점 : " << plc[index].name << "\n";
		index = plc2pnt[index]->go_to;
		while (index != end_i) {
			cout << plc[index].name << "\t" << plc2pnt[index]->dist_f_start << "m\n";
			index = plc2pnt[index]->go_to;
		}
		cout << "종점  " << plc[index].name << " 까지 거리는 " << plc2pnt[index]->dist_f_start << "m 입니다.\n";
	}
}

int main() {
	unsigned long time_s = timeGetTime();
	unsigned long time_e;
	int counter = 100;
	string start_str, end_str; // 문자 data, 시작 끝 지점
	if (debug) time_s = timeGetTime();
	init_plc2pnt();
	while (true) {
		cout << "출발점을 입력하세요." << endl;
		if (debug) start_str = "NW01";
		else
			cin >> start_str;
		start_i = find_index_in_names(start_str);
		if (debug) cout << start_str << start_i << endl;
		if (start_i < plc_max) {
			while (true) {
				cout << "종착점을 입력하세요.\n";
				if (debug) end_str = "Cir07";
				else
					cin >> end_str;
				end_i = find_index_in_names(end_str);
				if (debug) cout << end_str << end_i << endl;
				if (end_i < plc_max) {
					plc_init();
					find_way();
					disp_way();
					break; // 두번째 while로 부터 break
				}
				else {
					cout << "종착점을 못 찼겠읍니다.\n";
					break;
				}
			}
		}
		else {
			cout << "출발점을 못 찼겠읍니다.\n";
		}
		cout << "계속 할까요(Y/N).\n";
		if (debug) {
			if (--counter == 0) {
				time_e = timeGetTime();
				cout << time_e - time_s << "ms 걸렷습니다\n";
				start_str[0] = 'N';
			}
			else {
				cout << counter << endl;
				start_str[0] = 'Y';
			}
		}
		else
			cin >> start_str;
		if (start_str[0] == 'N') break; // 첫번째 while로 부터 break
		if (start_str[0] == 'n') break; // 첫번째 while로 부터 break
	}
	return 0;
}