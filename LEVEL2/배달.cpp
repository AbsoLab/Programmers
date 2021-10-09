#include <vector>
#include <string>
#include <iostream>

using namespace std;

int _N;
int _K;

int road_info[51][51];
bool visit[51];
bool can_dilivery[51];

void dfs(int pre, int length) {

    if (length > _K) return;
    else can_dilivery[pre] = true;

    for (int i=1; i<=_N; ++i) {

        if (pre == 3) {
            printf("visit[%d]: %d | ", i, visit[i]);
            printf("road_info[%d][%d]: %d \n", pre, i, road_info[pre][i]);
        }

        if (visit[i] == true) continue;
        if (road_info[pre][i] == 0) continue;

        visit[i] = true;
        dfs(i, length+road_info[pre][i]);
        visit[i] = false;
    }
}

int solution(int N, vector<vector<int>> road, int K) {

    int answer = 0;

    _N = N;
    _K = K;

    visit[1] = true;

    for (int i=0; i<road.size(); ++i) {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];

        if (road_info[a][b] != 0) {
            c = (road_info[a][b] < c) ? road_info[a][b] : c;
        }

        road_info[a][b] = c;
        road_info[b][a] = c;
    }

    dfs(1,0);

    for (int i=1; i<=N; ++i) {
        if (can_dilivery[i]) {
            answer++;
        }
    }

    return answer;
}

int main(void) {

    int N = 6;
    vector<vector<int>> road = {{1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1}};
    int K = 4;

    int result = solution(N, road, K);

    cout << result << endl;

    return 0;
}