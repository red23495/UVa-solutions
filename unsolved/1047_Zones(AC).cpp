#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
map<int, int> commonAreas;
int poles[25], n, toBuild, m, t, temp, c=1, bestLocations;

void printLocations(int Locations) {
    for (int i=0 ; i<n ; i++) if(Locations & (1 << i)) {
        printf(" %d", i+1);
    }
}

int main() {
    while (scanf("%d %d", &n, &toBuild), (n || toBuild) ) {
        commonAreas.clear();

        for (int i=0 ; i<n ; i++)
            scanf("%d", &poles[i]);

        scanf("%d", &m);

        for (int i=0 ; i<m ; i++) {
            scanf("%d", &t);
            int p = 0;
            for (int j=0 ; j<t ; j++) {
                scanf("%d", &temp);
                temp--;
                p |= (1 << temp);
            }
            scanf("%d", &temp);
            commonAreas[p] = temp;
        }

        int maxArea = -1e9;
        for (int s=0 ; s < (1 << n) ; s++) if(__builtin_popcount(s) == toBuild) {
            int actualArea = 0;

            for (int i=0 ; i<n ; i++) {
                if (s & (1 << i)) {
                    actualArea += poles[i];
                }
            }

            for(auto it :commonAreas) {
                int asdf = __builtin_popcount(s & it.first);
                if (asdf >= 2)
                actualArea -= (asdf - 1) * it.second;
            }

            if (actualArea > maxArea) {
                maxArea = actualArea;
                bestLocations = s;
            }
        }

        printf("Case Number  %d\n", c++);
        printf("Number of Customers: %d\n", maxArea);
        printf("Locations recommended:"); printLocations(bestLocations);
        printf("\n\n");
    }
}
