#include <stdio.h>

#define MAX_STRING_LENGTH   250000
#define MAX_BOR_SIZE        250001
#define MAX_STRING_NUMBER   250000
#define MAX_SEQUENCE_LENGTH 250000

char buf[MAX_STRING_LENGTH];
int go[MAX_BOR_SIZE][26];
int num[MAX_STRING_NUMBER];
int enter[MAX_BOR_SIZE];
int leave[MAX_BOR_SIZE];
int x[MAX_SEQUENCE_LENGTH];
int time;

int stack1[MAX_BOR_SIZE];
int stack2[MAX_BOR_SIZE];
int sp;

int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);

    int n;
    scanf("%d", &n);

    int i, j, pos, free;
    free = 1;
    for (i = 0; i < n; i++) {
        scanf("%s", buf);
        pos = 0;
        for (j = 0; buf[j] != '\0'; j++) {
            int k = buf[j] - 'a';
            if (go[pos][k] == 0) {
                go[pos][k] = free++;
            }
            pos = go[pos][k];
        }
        num[i] = pos;
    }

    time = 0;

    stack1[0] = 0;
    stack2[0] = 0;
    sp = 1;
    while (sp > 0) {
        int u = stack1[sp - 1];
        int v = stack2[sp - 1];
        sp--;

        if (v == 26) {
            leave[u] = time++;
            continue;
        }

        if (v == 0) {
            enter[u] = time++;
        }

        stack1[sp] = u;
        stack2[sp] = v + 1;
        sp++;
        if (go[u][v] != 0) {
            stack1[sp] = go[u][v];
            stack2[sp] = 0;
            sp++;
        }
    }

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        x[i]--;
    }

    int ans = 1;
    int ansi = 0;
    int ansj = 1;
    for (i = 0; i < n; ) {
        j = i + 1;

        while (j < n) {
            int low = enter[num[x[j - 1]]];
            int hi = leave[num[x[j - 1]]];
            int a = enter[num[x[j]]];
            int b = leave[num[x[j]]];

            if ((low == a) && (hi == b)) {
                break;
            }

            if ((low <= a) && (b <= hi)) {
                j++;
                continue;
            }
            break;
        }

        if (ans < j - i) {
            ans = j - i;
            ansi = i;
            ansj = j;
        }

        i = j;
    }

    printf("%d %d\n", ansi + 1, ansj);
    return 0;
}
