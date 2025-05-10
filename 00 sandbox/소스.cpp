#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Num_Tree {
    int num; // ��� ��ȣ. ��ǻ� index + 1
    vector<int> sons; // ���� ���
    int target_num; // ���������� �Ǿ�� �ϴ� ��. target ���Ϳ��� Ȯ��.
    // int max; // 1, 2, 3 ���ս� �ִ� ��. ������� 7�� 1�� 7�� �Ἥ ���� �� ������ �ִ밪�� 7. ��ǻ� �׻� target_num�� �����ϹǷ� ���� �ʴ´�.
    int min; // 1, 2, 3 ���ս� �ּ� ��. ������� 7�� 3�� �ι�, 1�� �ѹ� �Ἥ ���� �� ������ �ּҰ��� 3.
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

    int sat_t = 0; // target ���Ϳ��� 0�� �ƴ� ���� ����. �� ������ŭ min�� �����Ͽ��� �Ѵ�.
    for (int i = 0; i < target.size(); i++) {
        if (target[i]) sat_t++;
    }

    vector<int> out_nodes;
    int result = output(full_tree, out_nodes, sat_t);
    if (result == -1) return { -1 };

    make_answer(full_tree, out_nodes, answer);

    return answer;
}