#include <iostream>

using namespace std;

// 각지점의 명칭, 77 place가 있음
const int place_max = 77;
const string names[] = {	// place_max entries
	"Cir01",	"Cir02",	"Cir03",	"Cir04",	"Cir05",	"Cir06",	"Cir07",	"Cir08",
	"Cir09",	"Cir10",	"Cir11",	"Cir12",	"Cir13",										// 13
	"NE01",		"NE02",		"NE03",		"NE04",		"NE05",		"NE06",		"NE07",		"NE08",
	"NE09",		"NE10",		"NE11",		"NE12",		"NE13",		"NE14",								// 14
	"NW01",		"NW02",		"NW03",		"NW04",		"NW05",		"NW06",		"NW07",		"NW08",
	"NW09",		"NW10",		"NW11",		"NW12",		"NW13",		"NW14",								// 14
	"SE01",		"SE02",		"SE03",		"SE04",		"SE05",		"SE06",		"SE07",		"SE08",
	"SE09",		"SE10",		"SE11",		"SE12",		"SE13",		"SE14",		"SE15",		"SE16",
	"SE17",		"SE18",		"SE19",																	// 19
	"SW01",		"SW02",		"SW03",		"SW04",		"SW05",		"SW06",		"SW07",		"SW08",
	"SW09",		"SW10",		"SW11",		"SW12",		"SW13",		"SW14",		"SW15",		"SW16",
	"SW17"																							// 17, total 77
};
// 시작점 종점의 index
int start_i, end_i;
//
// names안에서 'str'의 index를 찾는 routine
// 없을 땐 place_max를 return
//
int find_index_in_names(const string str) {
	int start_ind = 0;
	int end_ind = place_max - 1;
	while (true) {
		int temp_ind = end_ind - start_ind; // temp_ind = 조사할 갯수 - 1
		if (temp_ind == 0) {	// 조사할 이름이 오직 한개
			if (str == names[start_ind])	return start_ind;
			else							return place_max;
		}
		if (temp_ind == 1) {	// 조사할 이름이 두개
			if (str == names[start_ind])	return start_ind;
			if (str == names[end_ind])		return end_ind;
			else							return place_max;
		}
		// 조사 대상이 3개 이상
		temp_ind = start_ind + temp_ind / 2; // temp_ind = 대충 중간값 
		if (str > names[temp_ind]) start_ind = temp_ind + 1;
		else                       end_ind = temp_ind;
	}
}

//
// 한 지점(names[])에서 갈 수 있는 다음장소(names의 index) 그리고 그곳 까지 거리(meter)를
// names list 순서에 따라 구분 않고 나열(ways[]), 
// 따라서 한 지점에 연결된 길을 ways[]에서 구하기위해
// 그 아래있는 name2ways 필요
//
struct street {
	int next_place;
	int distance;
};
const street ways[] = {
	{	35,	157	},{	 1,	39	},{	21,	160	},					// "Cir01"에서 갈 수 있는 곳, 35(=="NW09") 157(거리) 등등 3개
	{	 0,	41	},{	 2,	194	},{	 3,	205	},{	 6,	207	},		// "Cir02"에서 갈 수 있는 곳,  0(=="Cir01") 등등 4개
	{	 1,	188	},{	 6,	139	},{	 7,	135	},{	40,	84	},		// "Cir03"에서 갈 수 있는 곳,  1(=="Cir02") 등등 4개
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
	{	28,	145	},{	30,	52	},{	 3,	169	},
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
// 위의 ways는 names에 따라 구분하지 않았기에
// 각 names[i]에 해당하는 ways의 시작점과 갈 수 있는 길(ways) 갯수가 필요
// 
// name2ways는
// names의 index에 해당하는 길을 ways에서 찾기위한 시작index 및 갯수를 알려주는 data
//
// 예로 names[2]("Cir03")에서 갈 수 있는 길은
// name2way[2]가 {7,4}이므로(아래를 보세요)  Cir03(index 2)에 해당하는 ways data는
//    ways[name2ways[2].w_start], 즉 ways[7]에서 시작해
//         name2ways[2].w_length, 즉 4개 있음 ways[7], ways[8], ways[9], ways[10]
//

struct name_street {
	int w_start;
	int w_length;
};
const name_street name2ways[] = {
	{  0,3	},	{  3,4	},	{  7,4	},	{ 11,4	},	{ 15,3	},	{ 18,4	},	{ 22,8	},	{ 30,4	},
	{ 34,3	},	{ 37,4	},	{ 41,4	},	{ 45,4	},	{ 49,3	},	{ 52,3	},	{ 55,3	},	{ 58,3	},
	{ 61,4	},	{ 65,3	},	{ 68,3	},	{ 71,5	},	{ 76,3	},	{ 79,4	},	{ 83,4	},	{ 87,3	},
	{ 90,3	},	{ 93,4	},	{ 97,4	},	{101,3	},	{104,3	},	{107,3	},	{110,4	},	{114,3	},
	{117,3	},	{120,5	},	{125,3	},	{128,4	},	{132,5	},	{137,3	},	{140,3	},	{143,3	},
	{146,4	},	{150,3	},	{153,4	},	{157,3	},	{160,4	},	{164,4	},	{168,4	},	{172,4	},
	{176,3	},	{179,3	},	{182,3	},	{185,3	},	{188,3	},	{191,4	},	{195,4	},	{199,3	},
	{202,4	},	{206,3	},	{209,3	},	{212,3	},	{215,3	},	{218,3	},	{221,3	},	{224,4	},
	{228,4	},	{232,4	},	{236,5	},	{241,3	},	{244,3	},	{247,3	},	{250,4	},	{254,3	},
	{257,5	},	{262,3	},	{265,3	},	{268,3	},	{271,3	}
};

//
// 정리하면
//
// const int		place_max,	지점수 77
// const string		names[],	지점 이름
//
// struct street {next_place<int>, distance<int in meter>}
// const  street ways[], names에 따라 정열된 (이웃,거리)list
// 
// struct name_street {int w_start;int w_length}
// const  name_street name2ways[], names index와 ways의 연결 고리
//
// 위의 data는 상태에 따라 바뀔 확율이 적으므로(예외 ways.distance는 '거리'만이 아니라
// 교통 상태에 따라 바뀌는 운행 coast가 될 수 있음) const로 설정 함
//

//
// 다음 navigation algorithm은
// 
// 시작점을 시작으로하여
// 
// 갈 수 있는 지점들을 찾아
// front chain에 올림차순으로 sort하여 넣고 시작점을 '처리했음(touched)'으로 기입하고
// front chain의 점들은 'front chain임(in_front_chain)'으로 표기함.
// 
// front chain의 첫점을 대상으로 위와 같은 작업을 계속하면 각 점들은
// '처리했음', 'front chain임' 그리고 '처리 안함(not_touched)' 즉
// 시작점을 포함하는 지역(touched, 원의 안쪽 부분), 그지역의 경계(in_front_chain)
// 그리고 아직 처리 안한점(not_touched)들의 집합으로 구분됨.
// 
// front chain의 첫점(거리가 재일 짧은점)이 종착점이면 이 algorithm은 끝내고
// 
// 출력routine이 시작됨
// 
// 한 지점에서 갈 수 있는 지점들을 찾아 front chain에 넣을 때
// 갈 수 있는 지점이 'touched'일 경우
// 전에 계산된 '시작점에서 touched 지점까지 거리'가
// '새로 계산되는 거리'보다 짧을 수 없으므로
// 무시(front_chain에 넣을 필요 없음) 하고(김명호 생각)
// 'not_touched'일 경우 front_chain에 위치를 찾아 끼워 넣어야하고
// 'in_front_chain'일 경우 새로 계산되는 거리가
// 전에 계산된 거리가 짧을 경우
// front chain에서 삭제 후
// 새로 계산되는 거리에 따라 front chain에 삽입
//

//
// 그에 필요한 data
//
enum   p_state {
	not_touched,	// place가 처리 되지 않았음 
	in_front_chain,// place가 front chain에 있음
	touched
};		// place가 처리 됐음
struct p_data {
	p_state p_stat;			// status
	int		come_from;		// 어느 지점에서 왔나, navi 출력시 필요
	int		pre_chain;		// front chain에서 앞
	int		post_chain;		// front chain에서 뒤
	int		dist_f_start;	// 시작점으로 부터 거리
};
p_data	plc[place_max]{};
p_data	chain_start;	// front chain의 시작, dummy struct p_data, only post_chain used

//
// const int		place_max,	지점수 77
// const string		names[],	지점 이름
//
// struct street {next_place<int>, distance<int in meter>}
// const  street ways[], names에 따라 정열된 (이웃,거리)list
// 
// struct name_street {int w_start;int w_length}
// const  name_street name2ways[], names index와 ways의 연결 고리
//
// enum   p_state	{ not_touched, in_front_chain, touched };
// struct p_data	{ p_state p_stat;	int come_from; int	pre_chain; int post_chain; int	dist_f_start;};
// p_data plc [place_max], chain_start;
//
void plc_init() {
	for (int i = 0; i < place_max; i++) {
		plc[i].p_stat = not_touched;
		// plc[i].come_from = i;
		// plc[i].pre_chain = i;
		// plc[i].post_chain = i;
		// plc[i].dist_f_start = 0;
	}
	chain_start.post_chain = start_i;
	//
	plc[start_i].p_stat = in_front_chain;
	plc[start_i].come_from = start_i;
	plc[start_i].pre_chain = start_i;
	plc[start_i].post_chain = start_i;
	plc[start_i].dist_f_start = 0;
}

void insert_front_chain(int ind, int neighbor_ind, int new_dist_f_start) {
	int post_ind;
	while(post_ind = plc[ind].post_chain != ind) {
		if (new_dist_f_start <= plc[post_ind].dist_f_start) {
			// insert neighbor btw. post_ind and ind
			plc[neighbor_ind].pre_chain = ind;
			plc[neighbor_ind].post_chain = post_ind;
			plc[ind].post_chain = neighbor_ind;
			plc[post_ind].pre_chain = neighbor_ind;
			return;
		}
		ind = post_ind; // next in front chain
	}
	// front chain 끝 값 보다 큰 경우 끝에 삽입
	plc[ind].post_chain = neighbor_ind;
	plc[neighbor_ind].post_chain = neighbor_ind;
	plc[neighbor_ind].pre_chain = ind;
	return;
}

void find_way() {
	// ind는 처리해야 할 front chain의 첫 지점 index
	// ind가 end_i이면 길을 찾은 것
	while (int ind = chain_start.post_chain != end_i) {
		// ind가 가리키는 지점에서 갈 수 있는 곳들을 조사
		int ways_ind = name2ways[ind].w_start;
		int ways_end = name2ways[ind].w_length + ways_ind;
		int cur_dist_f_start = plc[ind].dist_f_start;
		for (; ways_ind < ways_end; ways_ind++) {
			// neighbor_ind는 ind로 부터 갈 수 있는 곳
			int neighbor_ind = ways[ways_ind].next_place;
			int new_dist_f_start = ways[ways_ind].distance + cur_dist_f_start;
			// n_i_ptr neighbor_ind data를 가르키는 pointer
			p_data* n_i_ptr = &(plc[neighbor_ind]);
			p_state p_st;
			if ((p_st = n_i_ptr->p_stat) != touched) {
				// in_front_chain 또는 not_touched
				if (p_st == not_touched) {
					n_i_ptr->p_stat = in_front_chain;
					n_i_ptr->come_from = ind;
					n_i_ptr->dist_f_start = new_dist_f_start;
					// insert neighbor_ind to front chain
					insert_front_chain(ind, neighbor_ind, new_dist_f_start);
				}
				else {
					// neighbor가 이미 front chain에 있음
					if (new_dist_f_start < n_i_ptr->dist_f_start) {
						// 새로운 길이 더 짧으므로 caine 속 연결을 끊고
						int temp = n_i_ptr->pre_chain;
						if (n_i_ptr->post_chain == neighbor_ind) { // chain의 끝에 있을 때
							plc[temp].post_chain = temp;
						}
						else { // chain 중간
							int temp2 = n_i_ptr->post_chain;
							plc[temp].post_chain = temp2;
							plc[temp2].pre_chain = temp;
						}
						// 새 data로 chain에 삽입
						n_i_ptr->come_from = ind;
						n_i_ptr->dist_f_start = new_dist_f_start;
						// insert neighbor_ind to front chain
						insert_front_chain(ind, neighbor_ind, new_dist_f_start);
					}
				}
			}
		}
	}
}

void disp_way() {
	// p_data plc안에 come_from은 있지만 start_i로 부터
	// 출력하려면 순서를 뒤 바꿔야 함
	int father				= plc[end_i].come_from;
	int grand_father		= plc[father].come_from;
	int son					= end_i;
	plc[end_i].come_from	= end_i;
	while (father != son) {
		int temp = grand_father;
		plc[father].come_from = son;
		son = father;
		father = grand_father;
		grand_father = plc[temp].come_from;
	}
	if (start_i == end_i) cout << "출발점과 종점이 같습니다." << endl;
	else {
		int index = start_i;
		cout << "출발 점 : " << names[index] << "\n";
		index = plc[index].come_from;
		int next = plc[index].come_from;
		while (index != end_i) {
			cout << names[index] << "\t" << plc[index].dist_f_start << "m\n";
			index++;
		}
		cout << "종점  " << names[index] << " 까지 거리는 " << plc[index].dist_f_start << "m 입니다.\n";
	}
}

int main() {
	string start_str, end_str; // 문자 data, 시작 끝 지점
	while (true) {
		cout << "출발점을 입력하세요." << endl;
		cin >> start_str;
		start_i = find_index_in_names(start_str);
		if (start_i < place_max) {
			while (true) {
				cout << "종착점을 입력하세요.\n";
				cin >> end_str;
				end_i = find_index_in_names(end_str);
				if (end_i < place_max) {
					find_way();
					disp_way();
					break; // 두번째 while로 부터 break
				}
			}
		}
		cout << "계속 할까요(Y/N).\n";
		cin >> start_str;
		if (start_str[0] == 'N') break; // 첫번째 while로 부터 break
		if (start_str[0] == 'n') break; // 첫번째 while로 부터 break
	}
	return 0;
}