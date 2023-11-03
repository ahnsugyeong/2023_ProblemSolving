#include <iostream>
#include <algorithm>

using namespace std;

bool isValidPassword(string password, int a, int c, int g, int t);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S, P;
    cin >> S >> P;

    string str;
    cin >> str;

    int a, c, g, t;
    cin >> a >> c >> g >> t;

    for (int i = 0; i < P; i++) {
        if (str[i] == 'A') a--;
        if (str[i] == 'C') c--;
        if (str[i] == 'G') g--;
        if (str[i] == 'T') t--;
    }

    int ans = 0;
    for (int i = 0; i < S - P + 1; i++) {
        if (str[i - 1] == 'A') a++;
        if (str[i - 1] == 'C') c++;
        if (str[i - 1] == 'G') g++;
        if (str[i - 1] == 'T') t++;

        if (str[i + P - 1] == 'A') a--;
        if (str[i + P - 1] == 'C') c--;
        if (str[i + P - 1] == 'G') g--;
        if (str[i + P - 1] == 'T') t--;

        if (a <= 0 && c <= 0 && g <= 0 && t <= 0) ans++;
    }

    cout << ans;

    return 0;
}

