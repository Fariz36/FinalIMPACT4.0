#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;
const int MAXN = 1000;
const int MAXM = 2500;
const int MAXW = 1000000;
const int MAXX = 100000;
const int MAXL = 1000000000;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, M, X, L;
    vector<int> U, V, W;
    long long answer;

    void InputFormat() {
        LINE(N, M, X, L);
        LINES(U, V, W) % SIZE(M);
    }

    void OutputFormat() {
        LINE(answer);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void StyleConfig() {
        CustomScorer();
    }

    void Constraints() {
        CONS(2 <= N && N <= MAXN);
        CONS(N - 1 <= M && M <= min(MAXM, N * (N - 1) / 2));
        CONS(0 <= X && X <= MAXX);
        CONS(0 <= L && L <= MAXL);
        CONS(M == (int)U.size());
        CONS(M == (int)V.size());
        CONS(M == (int)W.size());
        CONS(eachElementBetween(U, 1, N));
        CONS(eachElementBetween(V, 1, N));
        CONS(eachElementBetween(W, 1, MAXW));
        CONS(noSelfLoop(U, V));
        CONS(noRepeatedEdges(U, V));
        CONS(isConnected(U, V));
    }

    void Subtask1() {
        Points(7);

        CONS(L == 0);
        CONS(eachElementBetween(W, 1, 1));
    }

    void Subtask2() {
        Points(14);

        CONS(X == 0);
    }

    void Subtask3() {
        Points(14);

        CONS(0 <= L && L <= 10);
    }


    void Subtask4() {
        Points(12);

        CONS(M == N - 1);
    }

    void Subtask5() {
        Points(22);

        CONS(M == N);
    }

    void Subtask6() {
        Points(31);
    }

private:
    bool eachElementBetween(const vector<int> &v, int lo, int hi) {
        for (int i : v) {
            if (i < lo || i > hi) {
                return false;
            }
        }
        return true;
    }

    bool noSelfLoop(const vector<int> &u, const vector<int> &v) {
        for(int i = 0; i < M; ++i){
            if(u[i] == v[i]){
                return false;
            }
        }
        return true;
    }

    bool noRepeatedEdges(const vector<int> &u, const vector<int> &v) {
        assert((int)u.size() == (int)v.size());

        set<pair<int, int> > edges;
        for(int i = 0; i < M; i++){
            auto findIt = edges.find(make_pair(u[i], v[i]));
            if(findIt != edges.end()){
                return false;
            }
            edges.insert(make_pair(u[i], v[i]));
        }
        return true;
    }

    bool isConnected(const vector<int> &u, const vector<int> &v) {
        vector<vector<int>> adj(N + 1);

        for (int i = 0; i < M; i++) {
            adj[u[i]].push_back(v[i]);
            adj[v[i]].push_back(u[i]);
        }

        vector<bool> visited(N + 1);
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int nxt : adj[cur]){
                if(!visited[nxt]){
                    visited[nxt] = 1;
                    q.push(nxt);
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:

    void SampleTestCase1() {

        Subtasks({ 3, 5, 6 });
        Input({
            "4 4 2 3",
            "1 2 1",
            "2 3 2",
            "3 4 2",
            "1 4 10"
        });
        Output({
            "46"
        });
    }

    void BeforeTestCase() {
        U.clear();
        V.clear();
        W.clear();
    }

    void TestGroup1() {

        Subtasks({ 1, 3, 4, 6 });

        CASE(N = 2,    M = N - 1, X = MAXX, L = 0, randomLine(), generateWeight(1, 1));
        CASE(N = 3,    M = N - 1, X = MAXX, L = 0, randomLine(), generateWeight(1, 1));
        CASE(N = 10,   M = N - 1, X = MAXX, L = 0, randomLine(), generateWeight(1, 1));
        CASE(N = 1000, M = N - 1, X = MAXX, L = 0, randomLine(), generateWeight(1, 1));

        CASE(N = 5,    M = N - 1, X = MAXX, L = 0, randomTree(), generateWeight(1, 1));
        CASE(N = 1000, M = N - 1, X = MAXX, L = 0, randomTree(), generateWeight(1, 1));
        CASE(N = 1000, M = N - 1, X = MAXX, L = 0, randomTree(), generateWeight(1, 1));

        CASE(N = 1000, M = N - 1, X = MAXX, L = 0, randomCaterpillarTree(500), generateWeight(1, 1));
        CASE(N = 1000, M = N - 1, X = MAXX, L = 0, randomSemiStarTree(100, 10), generateWeight(1, 1));
    }

    void TestGroup2() {

        Subtasks({ 1, 3, 5, 6 });

        CASE(N = 1000, M = N, X = MAXX, L = 0, randomGraph(0), generateWeight(1, 1));
        CASE(N = 1000, M = N, X = MAXX, L = 0, randomGraph(1), generateWeight(1, 1));
        CASE(N = 1000, M = N, X = MAXX, L = 0, randomGraph(2), generateWeight(1, 1));
        CASE(N = 1000, M = N, X = MAXX, L = 0, randomGraph(3), generateWeight(1, 1));
        CASE(N = 1000, M = N, X = MAXX, L = 0, randomGraph(4), generateWeight(1, 1));
    }

    void TestGroup3() {

        Subtasks({ 1, 3, 6 });

        CASE(N = 1000, M = 2500, X = MAXX, L = 0, randomGraph(0), generateWeight(1, 1));
        CASE(N = 1000, M = 2500, X = MAXX, L = 0, randomGraph(1), generateWeight(1, 1));
        CASE(N = 1000, M = 2500, X = MAXX, L = 0, randomGraph(2), generateWeight(1, 1));
        CASE(N = 1000, M = 2500, X = MAXX, L = 0, randomGraph(3), generateWeight(1, 1));
    }

    void TestGroup4() {

        Subtasks({ 2, 3, 6 });

        CASE(N = 1000, M = 2500, X = 0, L = rnd.nextInt(1, 10), randomGraph(0), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = 0, L = rnd.nextInt(6, 10), randomGraph(1), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = 0, L = rnd.nextInt(1, 10), randomGraph(2), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = 0, L = rnd.nextInt(6, 10), randomGraph(2), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = 0, L = rnd.nextInt(1, 10), randomGraph(3), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = 0, L = rnd.nextInt(6, 10), randomGraph(3), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = 0, L = rnd.nextInt(1, 10), randomGraph(4), generateWeight(1, MAXW));
    }

    void TestGroup5() {

        Subtasks({ 2, 6 });

        CASE(N = 1000, M = 2500, X = 0, L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(0), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = 0, L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(1), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = 0, L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(2), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = 0, L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(2), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = 0, L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(3), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = 0, L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(4), generateWeight(1, MAXW));
    }

    void TestGroup6() {

        Subtasks({ 3, 4, 6 });

        CASE(N = 1000, M = N - 1, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(1, 10), randomGraph(0), generateWeight(1, MAXW));
        CASE(N = 1000, M = N - 1, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(1, 10), randomGraph(1), generateWeight(1, MAXW));
        CASE(N = 1000, M = N - 1, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(1, 10), randomGraph(2), generateWeight(1, MAXW));
        CASE(N = 1000, M = N - 1, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(1, 10), randomGraph(3), generateWeight(1, MAXW));
        CASE(N = 1000, M = N - 1, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(6, 10), randomGraph(3), generateWeight(1, MAXW));
        CASE(N = 1000, M = N - 1, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(1, 10), randomGraph(4), generateWeight(1, MAXW));
    }

    void TestGroup7() {
        Subtasks({ 3, 5, 6 });

        CASE(N = 1000, M = N, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(1, 10), randomGraph(1), generateWeight(1, MAXW));
        CASE(N = 1000, M = N, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(1, 10), randomGraph(2), generateWeight(1, MAXW));
        CASE(N = 1000, M = N, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(6, 10), randomGraph(2), generateWeight(1, MAXW));
        CASE(N = 1000, M = N, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(1, 10), randomGraph(3), generateWeight(1, MAXW));
        CASE(N = 1000, M = N, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(6, 10), randomGraph(3), generateWeight(1, MAXW));
        CASE(N = 1000, M = N, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(1, 10), randomGraph(4), generateWeight(1, MAXW));
    }

    void TestGroup8() {

        Subtasks({ 3, 6 });

        CASE(N = 1000, M = 2500, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(1, 10), randomGraph(0), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(1, 10), randomGraph(1), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(1, 10), randomGraph(2), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(6, 10), randomGraph(2), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(1, 10), randomGraph(3), generateWeight(1, MAXW));

        CASE(N = 1000, M = 2500, X = rnd.nextInt(MAXX / 2, MAXX), L = 10, randomGraph(1), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = rnd.nextInt(MAXX / 2, MAXX), L = 10, randomGraph(2), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = rnd.nextInt(MAXX / 2, MAXX), L = 10, randomGraph(3), generateWeight(1, MAXW));
    }

    void TestGroup9() {

        Subtasks({ 4, 6 });

        CASE(N = 1000, M = N - 1, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(1), generateWeight(1, MAXW));
        CASE(N = 1000, M = N - 1, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(2), generateWeight(1, MAXW));
        CASE(N = 1000, M = N - 1, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(2), generateWeight(1, MAXW));
        CASE(N = 1000, M = N - 1, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(3), generateWeight(1, MAXW));
        CASE(N = 1000, M = N - 1, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(4), generateWeight(1, MAXW));
    }

    void TestGroup10() {

        Subtasks({ 5, 6 });

        CASE(N = 1000, M = N, X = rnd.nextInt(1, 100),         L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(0), generateWeight(1, MAXW));

        CASE(N = 1000, M = N, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(1), generateWeight(1, MAXW));
        CASE(N = 1000, M = N, X = rnd.nextInt(1, 100),         L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(1), generateWeight(1, MAXW));

        CASE(N = 1000, M = N, X = rnd.nextInt(1, 100),         L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(2), generateWeight(1, MAXW));
        CASE(N = 1000, M = N, X = rnd.nextInt(1, 100),         L = rnd.nextInt(20, 100),        randomGraph(2), generateWeight(1, MAXW));
        CASE(N = 1000, M = N, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(20, 100),        randomGraph(2), generateWeight(1, MAXW));

        CASE(N = 1000, M = N, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(3), generateWeight(1, MAXW));
        CASE(N = 1000, M = N, X = rnd.nextInt(1, 100),         L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(3), generateWeight(1, MAXW));
        CASE(N = 1000, M = N, X = rnd.nextInt(1, 100),         L = rnd.nextInt(20, 100),        randomGraph(3), generateWeight(1, MAXW));
        CASE(N = 1000, M = N, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(20, 100),        randomGraph(3), generateWeight(1, MAXW));

        CASE(N = 1000, M = N, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(20, 100),        randomGraph(4), generateWeight(1, MAXW));

        CASE(N = 1000, M = N, X = rnd.nextInt(1, MAXX), L = rnd.nextInt(MAXL / 2, MAXL), generateSameGradient(N / 2), generateWeight(1, MAXW));
    }

    void TestGroup11() {

        Subtasks({ 6 });

        CASE(N = 1000, M = 2500, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(1), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = rnd.nextInt(1, 100),         L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(1), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = rnd.nextInt(1, 100),         L = rnd.nextInt(20, 100),        randomGraph(1), generateWeight(1, MAXW));

        CASE(N = 1000, M = 2500, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(2), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = rnd.nextInt(1, 100),         L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(2), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = rnd.nextInt(1, 100),         L = rnd.nextInt(20, 100),        randomGraph(2), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(20, 100),        randomGraph(2), generateWeight(1, MAXW));

        CASE(N = 1000, M = 2500, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(MAXL / 2, MAXL), randomGraph(3), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = rnd.nextInt(1, 100),         L = rnd.nextInt(20, 100),        randomGraph(3), generateWeight(1, MAXW));
        CASE(N = 1000, M = 2500, X = rnd.nextInt(MAXX / 2, MAXX), L = rnd.nextInt(20, 100),        randomGraph(3), generateWeight(1, MAXW));

        CASE(N = 982, M = 1000, X = rnd.nextInt(1, MAXX), L = rnd.nextInt(MAXL / 2, MAXL), generateSameGradient(50),  generateWeight(1, MAXW));
        CASE(N = 982, M = 1000, X = rnd.nextInt(1, MAXX), L = rnd.nextInt(11, 100),        generateSameGradient(50),  generateWeight(1, MAXW));
        CASE(N = 998, M = 1000, X = rnd.nextInt(1, MAXX), L = rnd.nextInt(MAXL / 2, MAXL), generateSameGradient(250), generateWeight(1, MAXW));
        CASE(N = 998, M = 1000, X = rnd.nextInt(1, MAXX), L = rnd.nextInt(11, 100),        generateSameGradient(250), generateWeight(1, MAXW));

        int extra, noise;

        extra = 998; noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(1, 20),          L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullBySegment(extra, noise));
        extra = 998; noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(50, 100),        L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullBySegment(extra, noise));
        extra = 998; noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullBySegment(extra, noise));
        extra = 998; noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(1, 20),          L = rnd.nextInt(1, MAXL / 1000),    generateConvexHullBySegment(extra, noise));
        extra = 998; noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(50, 100),        L = rnd.nextInt(1, MAXL / 1000),    generateConvexHullBySegment(extra, noise));
        extra = 998; noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(1, MAXL / 1000),    generateConvexHullBySegment(extra, noise));
        extra = 998; noise = 10;  CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(1, 20),          L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullBySegment(extra, noise));
        extra = 998; noise = 15;  CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullBySegment(extra, noise));
        extra = 998; noise = 100; CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullBySegment(extra, noise));

        extra = rnd.nextInt(200, 800); noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(1, 20),          L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullBySegment(extra, noise));
        extra = rnd.nextInt(400, 700); noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(30, 60),         L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullBySegment(extra, noise));
        extra = rnd.nextInt(500, 900); noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullBySegment(extra, noise));
        extra = rnd.nextInt(600, 800); noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullBySegment(extra, noise));
        extra = rnd.nextInt(200, 700); noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(11, MAXL / 1000),   generateConvexHullBySegment(extra, noise));
        extra = rnd.nextInt(800, 900); noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(1, 20),          L = rnd.nextInt(11, MAXL / 1000),   generateConvexHullBySegment(extra, noise));
        extra = rnd.nextInt(700, 800); noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(1, 1000),        L = rnd.nextInt(11, MAXL / 1000),   generateConvexHullBySegment(extra, noise));
        extra = rnd.nextInt(100, 900); noise = 8;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(40, 70),         L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullBySegment(extra, noise));
        extra = rnd.nextInt(400, 600); noise = 12;  CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullBySegment(extra, noise));
        extra = rnd.nextInt(500, 700); noise = 10;  CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(11, MAXL / 1000),   generateConvexHullBySegment(extra, noise));
        extra = rnd.nextInt(800, 900); noise = 100; CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullBySegment(extra, noise));

        extra = 998; noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(1, 20),          L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullChaotic(extra, noise));
        extra = 998; noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(50, 80),         L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullChaotic(extra, noise));
        extra = 998; noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullChaotic(extra, noise));
        extra = 998; noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(1, 20),          L = rnd.nextInt(1, MAXL / 1000),    generateConvexHullChaotic(extra, noise));
        extra = 998; noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(40, 55),         L = rnd.nextInt(1, MAXL / 1000),    generateConvexHullChaotic(extra, noise));
        extra = 998; noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(1, MAXL / 1000),    generateConvexHullChaotic(extra, noise));
        extra = 998; noise = 10;  CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(1, 20),          L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullChaotic(extra, noise));
        extra = 998; noise = 15;  CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullChaotic(extra, noise));
        extra = 998; noise = 100; CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullChaotic(extra, noise));
        extra = 998; noise = 170; CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullChaotic(extra, noise));

        extra = rnd.nextInt(200, 800); noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(1, 20),          L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullChaotic(extra, noise));
        extra = rnd.nextInt(800, 900); noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(1, 20),          L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullChaotic(extra, noise));
        extra = rnd.nextInt(400, 700); noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(40, 60),         L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullChaotic(extra, noise));
        extra = rnd.nextInt(700, 900); noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullChaotic(extra, noise));
        extra = rnd.nextInt(100, 700); noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullChaotic(extra, noise));
        extra = rnd.nextInt(300, 700); noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(11, MAXL / 1000),   generateConvexHullChaotic(extra, noise));
        extra = rnd.nextInt(300, 600); noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(1, 20),          L = rnd.nextInt(11, MAXL / 1000),   generateConvexHullChaotic(extra, noise));
        extra = rnd.nextInt(200, 900); noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(40, 70),         L = rnd.nextInt(11, MAXL / 1000),   generateConvexHullChaotic(extra, noise));
        extra = rnd.nextInt(100, 500); noise = 0;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(1, 1000),        L = rnd.nextInt(11, MAXL / 1000),   generateConvexHullChaotic(extra, noise));
        extra = rnd.nextInt(200, 600); noise = 8;   CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(1, 20),          L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullChaotic(extra, noise));
        extra = rnd.nextInt(600, 700); noise = 12;  CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullChaotic(extra, noise));
        extra = rnd.nextInt(500, 800); noise = 10;  CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(11, MAXL / 1000),   generateConvexHullChaotic(extra, noise));
        extra = rnd.nextInt(700, 900); noise = 100; CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullChaotic(extra, noise));
        extra = rnd.nextInt(800, 900); noise = 150; CASE(N = 1000, M = N - 1 + extra + noise, X = rnd.nextInt(MAXX / 4, MAXX), L = rnd.nextInt(MAXL / 1000, MAXL), generateConvexHullChaotic(extra, noise));
    }

private:
    void generateWeight(long long left, long long right){
        for(int i = 0; i < M; ++i){
            W.push_back(rnd.nextInt(left, right));
        }
    }

    void randomLine() {
        vector<int> perm(N);
        iota(perm.begin(), perm.end(), 1);

        rnd.shuffle(perm.begin(), perm.end());
        vector<pair<int, int> > edges;
        for (int i = 0; i < N - 1; i++) {
            edges.emplace_back(perm[i], perm[i + 1]);
        }

        rnd.shuffle(edges.begin(), edges.end());
        for (int i = 0; i < N - 1; i++) {
            if (rnd.nextInt(0, 1) == 1) {
                swap(edges[i].first, edges[i].second);
            }
            U.push_back(edges[i].first);
            V.push_back(edges[i].second);
        }
    }

    void randomTree() {
        vector<pair<int, int> > edges;
        for (int i = 2; i <= N; i++) {
            edges.emplace_back(i, rnd.nextInt(1, i - 1));
        }
        rnd.shuffle(edges.begin(), edges.end());

        for (int i = 0; i < N - 1; i++) {
            if (rnd.nextInt(0, 1) == 1) {
                swap(edges[i].first, edges[i].second);
            }
            U.push_back(edges[i].first);
            V.push_back(edges[i].second);
        }
    }

    void randomCaterpillarTree(const int d) {
        vector<int> perm(d);
        iota(perm.begin(), perm.end(), 1);
        rnd.shuffle(perm.begin(), perm.end());
        vector<pair<int, int> > edges;
        for (int i = 0; i < d - 1; i++) {
            edges.emplace_back(perm[i], perm[i + 1]);
        }
        for (int i = d + 1; i <= N; i++) {
            edges.emplace_back(rnd.nextInt(1, d), i);
        }

        vector<int> shf(N);
        iota(shf.begin(), shf.end(), 0);
        rnd.shuffle(shf.begin(), shf.end());
        for (auto &[x, y] : edges) {
            x = shf[x - 1] + 1;
            y = shf[y - 1] + 1;
        }
        rnd.shuffle(edges.begin(), edges.end());
        for (int i = 0; i < N - 1; i++) {
            if (rnd.nextInt(0, 1) == 1) {
                swap(edges[i].first, edges[i].second);
            }
            U.push_back(edges[i].first);
            V.push_back(edges[i].second);
        }
    }

    void randomSemiStarTree(int f, int k){
        vector<int> perm(N);
        iota(perm.begin(), perm.end(), 1);
        rnd.shuffle(perm.begin(), perm.end());

        vector<int> prev_layer;
        prev_layer.push_back(perm[0]);

        bool first = 1;
        int index = 0, cur = N - 1;
        vector<pair<int, int>> edges;
        while(cur > 0){
            vector<int> cur_layer;
            int sz = (int)prev_layer.size();

            if(first){
                first = 0;
                int par = prev_layer.back();
                for(int i = 1; i <= f; ++i){
                    int now = perm[++index];

                    cur_layer.push_back(now);
                    edges.push_back({par, now});
                }
                cur -= f;
            }
            else{
                for(int par : prev_layer){
                    int children = rnd.nextInt(max(0, min(cur, k - 2)), min(cur, k + 2));
                    for(int i = 1; i <= min(cur, children); ++i){
                        int now = perm[++index];

                        cur_layer.push_back(now);
                        edges.push_back({par, now});
                    }
                    cur -= min(cur, children);
                }
            }
            prev_layer = cur_layer;
        }

        for (int i = 0; i < N - 1; i++) {
            if (rnd.nextInt(0, 1) == 1) {
                swap(edges[i].first, edges[i].second);
            }
            U.push_back(edges[i].first);
            V.push_back(edges[i].second);
        }
    }

    void randomTrueStarTree() {
        vector<int> perm(N);
        iota(perm.begin(), perm.end(), 1);
        rnd.shuffle(perm.begin(), perm.end());

        vector<pair<int, int>> edges;
        for(int i = 0; i < N; ++i){
            if(perm[i] != 1){
                edges.push_back({1, perm[i]});
            }
        }

        for (int i = 0; i < N - 1; i++) {
            if (rnd.nextInt(0, 1) == 1) {
                swap(edges[i].first, edges[i].second);
            }
            U.push_back(edges[i].first);
            V.push_back(edges[i].second);
        }
    }

    void randomGraph(int to_use){
        if(to_use == 0){
            randomLine();
        }
        else if(to_use == 1){
            randomTree();
        }
        else if(to_use == 2){
            randomCaterpillarTree(rnd.nextInt(N / 3, N / 2));
        }
        else if(to_use == 3){
            randomSemiStarTree(rnd.nextInt(30, 60), rnd.nextInt(5, 20));
        }
        else if(to_use == 4){
            randomTrueStarTree();
        }

        set<pair<int, int> > edges;
        for(int i = 0; i < N - 1; ++i){
            if(U[i] < V[i]){
                edges.insert(make_pair(U[i], V[i]));
            }
            else{
                edges.insert(make_pair(V[i], U[i]));
            }
        }
        vector<int>().swap(U);
        vector<int>().swap(V);

        while((int)edges.size() < M){
            int nu = rnd.nextInt(1, N - 1);
            int nv = rnd.nextInt(nu + 1, N);

            if(!edges.count(make_pair(nu, nv))){
                edges.insert(make_pair(nu, nv));
            }
        }

        for(auto elem : edges){
            auto cur = elem;
            if (rnd.nextInt(0, 1) == 1) {
                swap(cur.first, cur.second);
            }
            U.push_back(cur.first);
            V.push_back(cur.second);
        }
    }

    void generateConvexHullBySegment(int extra, int noise){
        assert(extra <= N - 2);
        assert(M == N - 1 + extra + noise);

        int Q = MAXW / N;

        set<pair<int, int> > edges;
        vector<int> perm(N);
        iota(perm.begin(), perm.end(), 1);
        rnd.shuffle(perm.begin() + 1, perm.begin() + N - 1);

        assert(perm[0] == 1 && perm.back() == N);

        for(int i = 1; i < N; ++i){
            int weight = rnd.nextInt(Q / 10, Q / 2);
            U.push_back(perm[i - 1]);
            V.push_back(perm[i]);
            W.push_back(weight);
            edges.insert(make_pair(min(U.back(), V.back()), max(U.back(), V.back())));
        }

        pair<int, int> segment;
        for(int i = 1; i <= extra; ++i){
            if(i == 1){
                segment.first = rnd.nextInt(0, N - 3);
                segment.second = segment.first + 2;
            }
            else{
                if(segment.first == 0 && segment.second < N - 1){
                    segment.second++;
                }
                else if(segment.first > 0 && segment.second == N - 1){
                    segment.first--;
                }
                else if(segment.first > 0 && segment.second < N - 1){
                    if(rnd.nextInt(0, 1) == 0){
                        segment.first--;
                    }
                    else{
                        segment.second++;
                    }
                }
                else{
                    assert(false);
                }
            }
            int len = i + 1;
            int weight = rnd.nextInt((len - 1) * Q + 1, len * Q);
            U.push_back(perm[segment.first]);
            V.push_back(perm[segment.second]);
            W.push_back(weight);
            edges.insert(make_pair(min(U.back(), V.back()), max(U.back(), V.back())));
        }

        for(int i = 1; i <= noise; ++i){
            int nu = rnd.nextInt(1, N - 1);
            int nv = rnd.nextInt(nu + 1, N);
            while(edges.count(make_pair(nu, nv))){
                nu = rnd.nextInt(1, N - 1);
                nv = rnd.nextInt(nu + 1, N);
            }
            U.push_back(nu);
            V.push_back(nv);
            W.push_back(rnd.nextInt(1, MAXW));
            edges.insert(make_pair(nu, nv));
        }
    }

    void generateConvexHullChaotic(int extra, int noise){
        assert(extra <= N - 2);
        assert(M == N - 1 + extra + noise);

        int Q = MAXW / N;

        set<pair<int, int> > edges;
        vector<int> perm(N);
        iota(perm.begin(), perm.end(), 1);
        rnd.shuffle(perm.begin() + 1, perm.begin() + N - 1);

        assert(perm[0] == 1 && perm.back() == N);

        for(int i = 1; i < N; ++i){
            int weight = rnd.nextInt(Q / 10, Q / 2);
            U.push_back(perm[i - 1]);
            V.push_back(perm[i]);
            W.push_back(weight);
            edges.insert(make_pair(min(U.back(), V.back()), max(U.back(), V.back())));
        }

        int skipped = 0;
        for(int i = 1; i <= extra; ++i){
            if(rnd.nextInt(1, 100) <= 25){
                skipped++;
                continue;
            }
            int len = i + 1;
            int weight = rnd.nextInt((len - 1) * Q + 1, len * Q);
            pair<int, int> segment;
            segment.first = rnd.nextInt(0, N - 1 - len);
            segment.second = segment.first + len;
            U.push_back(perm[segment.first]);
            V.push_back(perm[segment.second]);
            W.push_back(weight);
            edges.insert(make_pair(min(U.back(), V.back()), max(U.back(), V.back())));
        }

        for(int i = 1; i <= skipped; ++i){
            int len = rnd.nextInt(2, N - 1);
            pair<int, int> segment;
            segment.first = rnd.nextInt(0, N - 1 - len);
            segment.second = segment.first + len;
            int nu = perm[segment.first], nv = perm[segment.second];
            int weight = rnd.nextInt((len - 1) * Q + 1, len * Q);
            while(edges.count(make_pair(min(nu, nv), max(nu, nv)))){
                len = rnd.nextInt(2, N - 1);
                segment.first = rnd.nextInt(0, N - 1 - len);
                segment.second = segment.first + len;
                nu = perm[segment.first]; nv = perm[segment.second];
                weight = rnd.nextInt((len - 1) * Q + 1, len * Q);
            }
            U.push_back(nu);
            V.push_back(nv);
            W.push_back(weight);
            edges.insert(make_pair(min(U.back(), V.back()), max(U.back(), V.back())));
        }

        for(int i = 1; i <= noise; ++i){
            int nu = rnd.nextInt(1, N - 1);
            int nv = rnd.nextInt(nu + 1, N);
            while(edges.count(make_pair(nu, nv))){
                nu = rnd.nextInt(1, N - 1);
                nv = rnd.nextInt(nu + 1, N);
            }
            U.push_back(nu);
            V.push_back(nv);
            W.push_back(rnd.nextInt(1, MAXW));
            edges.insert(make_pair(nu, nv));
        }
    }

    void generateSameGradient(int len){
        assert(M % len == 0);
        assert(N == (M / len) * (len - 1) + 2);
        int num = 1;

        vector<int> perm(N);
        iota(perm.begin(), perm.end(), 1);
        rnd.shuffle(perm.begin() + 1, perm.begin() + N - 1);

        for(int i = 1; i <= M / len; ++i){
            int last = 1;
            for(int j = 1; j < len; ++j){
                U.push_back(last);
                V.push_back(perm[num]);
                last = perm[num];
                num++;
            }
            U.push_back(last);
            V.push_back(N);
        }

        assert(num == N - 1);

        for(int i = 0; i < M; ++i){
            if(rnd.nextInt(0, 1) == 0){
                swap(U[i], V[i]);
            }
        }
    }
};
