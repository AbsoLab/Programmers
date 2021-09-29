#include <vector>
#include <string>
#include <iostream>

#include <algorithm>
using namespace std;

vector<char> menu;
vector<char> v;

vector<string> _orders;
vector<vector<string>> course_menu(21);
int max_menu[21];
int length;

void dfs(int start) {

    if (v.size() == length) {
        int count = 0;
        for (int i=0; i<_orders.size(); ++i) {
            string str = _orders[i];
            int c_count = 0;
            for (int j=0; j<v.size(); ++j) {
                char c = v[j];
                for (int k=0; k<str.length(); ++k) {
                    if (str[k] == c) {
                        ++c_count;
                    }
                }
            }
            if (c_count == length) {
                ++count;
            }
        }

        // 2�� �̻��̸� �ڽ� �ĺ� �߰�
        if (max_menu[length] <= count && count >= 2) {
            if (max_menu[length] < count) {
                course_menu[length].clear();
                max_menu[length] = count;
            }
            string str = "";
            for (int i=0; i<v.size(); ++i) {
                str += v[i];
            }
            course_menu[length].push_back(str);
        }

        return;
    }

    for (int i=start+1; i<menu.size(); ++i) {
        v.push_back(menu[i]);
        dfs(i);
        v.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    
    vector<string> answer;
    _orders = orders;

    // �ֹ��� �޴� üũ
    bool checked_menu[26] = {0, };
    for (int i=0; i<_orders.size(); ++i) {
        for (int j=0; j<_orders[i].size(); ++j) {
            checked_menu[_orders[i][j] - 'A'] = true;
        }
    }
    // �ֹ��� �޴��� ���� ���Ϳ� �ֱ�
    for (int i=0; i<26; ++i) {
        if (checked_menu[i]) {
            menu.push_back('A' + i);
        }
    } 
    // 1�� �ڽ� �ĺ� ����
    for (int i=0; i<course.size(); ++i) {
        length = course[i];
        dfs(-1);
    }
    // ���� �ڽ� �ĺ� ����
    for (int i=0; i<course_menu.size(); ++i) {
        for (int j=0; j<course_menu[i].size(); ++j) {
            answer.push_back(course_menu[i][j]);
        }
    }
    // �������� ����
    sort(answer.begin(), answer.end());

    return answer;
}

int main(void) {

    vector<string> orders = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
    vector<int> course = {2, 3, 5};

    vector<string> result = solution(orders, course);
    
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << " ";
    } cout << endl;

    return 0;
}