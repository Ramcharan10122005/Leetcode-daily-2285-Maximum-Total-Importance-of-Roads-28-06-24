int compare(const void* x, const void* y) { return *(int*)x - *(int*)y; }
long long maximumImportance(int n, int** roads, int s, int* cs) {
    int* degree = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < s; i++) {
        int u = roads[i][0], v = roads[i][1];
        degree[u]++;
        degree[v]++;
    }
    qsort(degree, n, sizeof(int), compare);
    long long val = 1, ans = 0;
    for (int i = 0; i < n; i++) {
        ans += val * degree[i];
        val++;
    }
    free(degree);
    return ans;
}
