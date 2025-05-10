#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Num_Tree {
    int num; // 노드 번호. 사실상 index + 1
    vector<int> sons; // 하위 노드
    int target_num; // 최종적으로 되어야 하는 값. target 벡터에서 확인.
    // int max; // 1, 2, 3 조합시 최대 값. 예를들어 7은 1을 7번 써서 만들 수 있으니 최대값은 7. 사실상 항상 target_num과 동일하므로 쓰지 않는다.
    int min; // 1, 2, 3 조합시 최소 값. 예를들어 7은 3을 두번, 1을 한번 써서 만들 수 있으니 최소값은 3.
    vector<bool> path;
    int counter;
};

int make_min(int target) {
    if (target == 0) return 0;
    return ((target - 1) / 3) + 1;
}

int output(vector<Num_Tree>& full_tree, vector<int>& out_nodes, int sat_t) {
    int satisfy = 0;

    while (true) {
        int node = 1;
        while (true) {
            if (full_tree[node - 1].sons.size() == 0) {
                out_nodes.push_back(node);
                //cout << node << '\n';
                full_tree[node - 1].counter++;
                if (full_tree[node - 1].counter > full_tree[node - 1].target_num) {
                    return -1;
                }
                if (full_tree[node - 1].counter == full_tree[node - 1].min) {
                    satisfy++;
                    if (satisfy == sat_t) return 0;
                }
                break;
            }
            if (full_tree[node - 1].sons.size() == 1) {
                node = full_tree[node - 1].sons[0];
                continue;
            }
            for (int i = 0; i < full_tree[node - 1].sons.size(); i++) {
                if (full_tree[node - 1].path[i] == false) continue;
                if (i == full_tree[node - 1].path.size() - 1) {
                    for (int j = 0; j < full_tree[node - 1].path.size(); j++) {
                        full_tree[node - 1].path[j] = true;
                    }
                    node = full_tree[node - 1].sons[i];
                    break;
                }
                full_tree[node - 1].path[i] = false;
                node = full_tree[node - 1].sons[i];
                break;
            }
        }
    }
}

void make_answer(vector<Num_Tree>& full_tree, vector<int>& out_nodes, vector<int>& answer) {
    vector<vector<int>> v_numbers(full_tree.size(), vector<int>(0));

    for (int i = 0; i < out_nodes.size(); i++) {
        if (full_tree[out_nodes[i] - 1].counter == 1)
            answer.push_back(full_tree[out_nodes[i] - 1].target_num);
        else {
            if (v_numbers[out_nodes[i] - 1].size() > 0) {
                answer.push_back(v_numbers[out_nodes[i] - 1][0]);
                v_numbers[out_nodes[i] - 1].erase(v_numbers[out_nodes[i] - 1].begin());
                continue;
            }

            int cnt = full_tree[out_nodes[i] - 1].counter;
            int tgn = full_tree[out_nodes[i] - 1].target_num;
            int diff = 3 * cnt - tgn;
            vector<int> temp(cnt, 3);
            v_numbers[out_nodes[i] - 1] = temp;

            if (diff == 0) {
                answer.push_back(v_numbers[out_nodes[i] - 1][0]);
                v_numbers[out_nodes[i] - 1].erase(v_numbers[out_nodes[i] - 1].begin());
                continue;
            }
            int idx = 0;
            while (diff) {
                if (v_numbers[out_nodes[i] - 1][idx] > 1) {
                    v_numbers[out_nodes[i] - 1][idx]--;
                    diff--;
                }
                else {
                    idx++;
                    v_numbers[out_nodes[i] - 1][idx]--;
                    diff--;
                }
            }
            answer.push_back(v_numbers[out_nodes[i] - 1][0]);
            v_numbers[out_nodes[i] - 1].erase(v_numbers[out_nodes[i] - 1].begin());
            continue;
        }
    }
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;

    sort(edges.begin(), edges.end());
    vector<Num_Tree> full_tree(edges.size() + 1);

    for (int i = 0; i < edges.size(); i++) {
        full_tree[i].num = i + 1;
        full_tree[edges[i][0] - 1].sons.push_back(edges[i][1]);
        full_tree[edges[i][0] - 1].path.push_back(true);
        full_tree[i].target_num = target[i];
        full_tree[i].min = make_min(target[i]);
        full_tree[i].counter = 0;
    }
    full_tree[edges.size()].num = edges.size() + 1;
    full_tree[edges.size()].target_num = target[edges.size()];
    full_tree[edges.size()].min = make_min(target[edges.size()]);

    int sat_t = 0; // target 벡터에서 0이 아닌 항의 개수. 그 개수만큼 min을 만족하여야 한다.
    for (int i = 0; i < target.size(); i++) {
        if (target[i]) sat_t++;
    }

    vector<int> out_nodes;
    int result = output(full_tree, out_nodes, sat_t);
    if (result == -1) return { -1 };

    make_answer(full_tree, out_nodes, answer);

    return answer;
}