#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {

    map<string, string> names;
    vector<string> answer;

    for (int i=0; i<record.size(); ++i) {
  
        vector<string> div;
        int start_pos = 0;
        for (int j=0; j <= record[i].size(); ++j) {
            char c = record[i][j];
            if (c == ' ' || j == record[i].size()) {
                div.push_back(record[i].substr(start_pos, j-start_pos));
                start_pos = j + 1;
            }
        }

        if (div[0] == "Enter" || div[0] == "Change") {

            // Ű�� �� �߰� & �̹� Ű ���� ������ ������Ʈ
            if ((names.insert(make_pair(div[1], div[2]))).second == false) {
                names[div[1]] = div[2];
            }
        }
    }


    for (int i=0; i<record.size(); ++i) {

        vector<string> div;
        int start_pos = 0;
        for (int j=0; j <= record[i].size(); ++j) {
            char c = record[i][j];
            if (c == ' ' || j == record[i].size()) {
                div.push_back(record[i].substr(start_pos, j-start_pos));
                start_pos = j + 1;
            }
        }

        string str;

        if (div[0] == "Enter") {
            str = names[div[1]];
            str += "���� ���Խ��ϴ�.";
            answer.push_back(str);
        } else if (div[0] == "Leave") {
            str = names[div[1]];
            str += "���� �������ϴ�.";
            answer.push_back(str);
        }
    }

    return answer;
}

int main(void) {

    vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};

    vector<string> result = solution(record);
    
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << "\n";
    }

    return 0;
}