#include <iostream>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N;
int P[1000], I[1000], O[1000];

// Set up : Functions Declaration
void postorder(int sp, int ep, int si, int ei);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int T; cin >> T;

    while (T--) {
        cin >> N;
        for (int i=0; i<N; i++)
            cin >> P[i]; /* 전위순회 결과 */
        for (int i=0; i<N; i++) {
            cin >> I[i]; /* 중위순회 결과 */
            O[I[i]] = i; /* O[i] = i번 노드의 중위순회 결과 인덱스 */
        }

        // Control : Output
        postorder(0, N-1, 0, N-1);
        cout << endl;
    }
}

// Helper Functions
void postorder(int sp, int ep, int si, int ei)
/* 전위순회 결과 : P[sp] ~ P[ep]
 * 중위순회 결과 : O[si] ~ O[ei]
 * 이를 통해 현재노드를 찾고
 * 루트노드의 왼쪽 서브트리와 오른쪽 서브트리를 방문 후
 * 현재 트리의 루트노드를 출력 (후위순회) */
{
    int v = P[sp]; /* node */
    int idx = O[v];
    int ln = idx - si;
    int rn = ei - idx;

    /* 왼쪽 서브트리
     * 전위순회 결과 : P[lsp] ~ P[lep]
     * 중위순회 결과 : O[lsi] ~ O[lei] */
    int lsp = sp+1, lep = sp+ln, lsi = si, lei = idx-1;
    if (lsp <= lep && lsi <= lei) /* v.left != Ø */
        postorder(lsp, lep, lsi, lei);

    /* 오른쪽 서브트리
     * 전위순회 결과 : P[rsp] ~ R[rep]
     * 중위순회 결과 : O[rsi] ~ O[rei] */
    int rsp = ep-rn+1, rep = ep, rsi = idx+1, rei = ei;
    if (rsp <= rep && rsi <= rei) /* v.right != Ø */
        postorder(rsp, rep, rsi, rei);

    cout << v << ' '; /* printf(id number of v); */
}