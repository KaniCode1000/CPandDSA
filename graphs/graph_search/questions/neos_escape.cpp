#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int total = 1;
    vector<long long> a(n);
    vector<bool> pushed;
    vector<pair<long long, int>> sorted_a;
    for (int i = 0;i<n;i++){
        cin >> a[i];
        pushed.push_back(false);
        sorted_a.push_back({a[i],i});
    }
    sort(sorted_a.begin(),sorted_a.end(),greater<pair<long long,int>>());

    vector<long long> choices;
    pushed[sorted_a[0].second] = true;
    if (sorted_a[0].second > 0){
        choices.push_back(a[sorted_a[0].second-1]);
        pushed[sorted_a[0].second-1] = true;
    }
    if (sorted_a[0].second < n-1){
        choices.push_back(a[sorted_a[0].second+1]);
        pushed[sorted_a[0].second+1] = true;
    }

    make_heap(choices.begin(),choices.end());

    for (int i = 1;i<n;i++){

        if (!choices.empty() && sorted_a[i].first == choices.front()){
            pop_heap(choices.begin(),choices.end());
            choices.pop_back();   
        }
        else{
            total++;
        }
        pushed[sorted_a[i].second] = true;
        if (sorted_a[i].second > 0 && !pushed[sorted_a[i].second-1]){
            choices.push_back(a[sorted_a[i].second-1]);
            pushed[sorted_a[i].second-1] = true;
            push_heap(choices.begin(),choices.end());
        }
        if (sorted_a[i].second < n-1 && !pushed[sorted_a[i].second+1]){
            choices.push_back(a[sorted_a[i].second+1]);
            pushed[sorted_a[i].second+1] = true;
            push_heap(choices.begin(),choices.end());
        }
    }
    cout << total << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}