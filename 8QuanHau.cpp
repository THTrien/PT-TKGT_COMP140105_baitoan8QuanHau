#include<bits/stdc++.h>
using namespace std;

const int MaxN = 1 + 1e5;

int n;
bool mark[3][MaxN];
vector<int> res;

void Try(int row){
    if(row == n + 1){
        for(int i = 0 ; i < n ; ++i) cout << i + 1 << " " << res[i] << endl;
        exit(0); 
        // Khi chỉ cần in ra 1 đáp án nên ta sẽ thoát khỏi chương trình ngay tại đây.
       // Nếu cần tất cả đáp án ta sẽ không dùng exit(0)
    }
    for(int col = 1 ; col <= n ; ++col){
        // Do hiệu của chỉ số hàng và cột có thể âm nên ta cộng thêm n 
        int mainDiagonal = row - col + n, subDiagonal = row + col;
        // mark[0][]: cột
        // mark[1][]: đường chéo chính
        // mark[2][]: đường chéo phụ
        if(mark[0][col] || mark[1][mainDiagonal] || mark[2][subDiagonal]) continue;
        mark[0][col] = 1;
        mark[1][mainDiagonal] = 1;
        mark[2][subDiagonal] = 1;
        res.push_back(col);
        Try(row + 1);
        res.pop_back();
        mark[0][col] = 0;
        mark[1][mainDiagonal] = 0;
        mark[2][subDiagonal] = 0;
    }
}

int main(){
    cout << "Cách đặt quân hậu "<< endl;
    cin >> n;
    Try(1);

    return 0;
}


