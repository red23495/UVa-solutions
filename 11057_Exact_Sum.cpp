#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> books;

int binary_search(int l, int r, int key){
    if(l > r) return r;
    int mid = (l+r)/2;
    if(books[mid] == key) return mid;
    if(books[mid] < key){
        return binary_search(mid+1,r,key);
    }
    return binary_search(l,mid-1,key);
}

int main(){
    int n,p;
    while(cin >> n){
        books.resize(n);
        for(auto& x: books) cin >> x;
        cin >> p;
        sort(books.begin(),books.end());
        //for(auto x: books) cout << x << ' '; cout << endl;
        int index = binary_search(0,n-1,p/2);
        //cout << index << endl;
        int ans,l = index+1;
        while(true){
            ans = binary_search(l,n-1,p - books[index]);
            if(books[ans] == (p - books[index]) && ans != index) break;
            index--;
        }
        cout << "Peter should buy books whose prices are "<<books[index]<<" and "<<books[ans]<<".\n\n";
    }
    return 0;
}
