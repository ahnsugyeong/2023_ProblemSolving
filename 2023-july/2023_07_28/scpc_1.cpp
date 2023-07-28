#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, N, A, B;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> A >> B;

        int max_boxes = 0;

        // B개의 사과를 사용하고 남은 사과는 A개의 사과를 사용하여 채우는 방식
        for (int b_count = N / B; b_count >= 0; b_count--) {
            int remaining_apples = N - (b_count * B);

            // 남은 사과가 0이 아니고, A개의 사과로 채울 수 없으면 skip
            if (remaining_apples % A != 0) {
                continue;
            }

            int a_count = remaining_apples / A;

            int total_boxes = a_count + b_count;
            max_boxes = max(max_boxes, total_boxes);
        }

        cout << "Case #" << i + 1 << "\n";
        cout << max_boxes << "\n";
    }
    return 0;
}