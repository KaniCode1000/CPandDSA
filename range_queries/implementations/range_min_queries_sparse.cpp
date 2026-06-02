//computing log values and storing in an array is slower due to cache misses

// C++20
//#include <bit>
//int log2_floor(unsigned long i) {
	//return std::bit_width(i) - 1;
//}

// pre C++20
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

//creation of sparse table
int st[K + 1][MAXN];

std::copy(array.begin(), array.end(), st[0]);

for (int i = 1; i <= K; i++)
    for (int j = 0; j + (1 << i) <= N; j++)
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);

//query computation

int i = log2_floor(R - L + 1);
int minimum = min(st[i][L], st[i][R - (1 << i) + 1]);
