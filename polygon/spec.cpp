#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    long long N, K;
    vector<long long> X, Y;
    long long answer;

    void InputFormat() {
        LINE(N, K);
        LINES(X, Y) % SIZE(N);
    }

    void OutputFormat() {
        LINE(answer);
    }

    void StyleConfig() {
        CustomScorer();
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N && N <= 300);
        CONS(1 <= K && K <= 10 && K <= N);
        CONS(checkInterval(X, Y, -1000000000, 1000000000));
        CONS(checklinear(X, Y));
        CONS(checksame(X, Y));
    }

    void Subtask1() {
		Points(7);

		CONS(N <= 15);
	}

	void Subtask2() {
		Points(11);

		CONS(N <= 80);
	}

	void Subtask3() {
		Points(12);

		CONS(K == 3);
	}

	void Subtask4() {
		Points(13);

		CONS(K == 4);
	}

	void Subtask5() {
		Points(20);

		CONS(checkInterval(X, Y, -1000, 1000));
	}

	void Subtask6() {
		Points(37);
	}

private:
    bool checklinear(vector<long long> &X, vector<long long> &Y){
       for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                for (int k = j+1; k < N; k++) {
                    if ((Y[j] - Y[i])*(X[k] - X[j]) == (Y[k] - Y[j])*(X[j] - X[i])) {
                        return false;
                    }  
                }
            }
        }
        return true;
    }

    bool checksame(vector<long long> &X, vector<long long> &Y){
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                if (X[i] == X[j] && Y[i] == Y[j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool checkInterval(vector<long long> &L, vector<long long> &R, long long left, long long right){
        bool check = 1;
        for(int i = 0; i < N; ++i){
            check &= (left <= L[i] && L[i] <= right && left <= R[i] && R[i] <= right);
        }
        return check;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:

    void BeforeTestCase() {
        X.clear();
        Y.clear();
    }

    void SampleTestCase1() {
        Subtasks({1, 2, 5, 6});
        Input({
            "6 6",
            "-4 2",
            "4 2",
            "4 -2",
            "-4 -2",
            "0 4",
            "0 -4"
        });
        Output({
            "96"
        });
    }

    void SampleTestCase2() {

        Subtasks({1, 2, 5, 6});
        Input({
            "6 6",
            "-4 2",
            "4 2",
            "4 -2",
            "-1 -1",
            "0 4",
            "0 -4"
        });
        Output({
            "0"
        });
    }

    void SampleTestCase3() {
        Subtasks({1, 2, 5, 6});
        Input({
            "8 6",
            "8 0",
            "-8 0",
            "0 8",
            "0 -8",
            "2 2",
            "-2 -2",
            "-2 2",
            "2 -2"
        });
        Output({
            "160"
        });
    }

    void TestGroup1() {

        Subtasks({1, 2, 3, 5, 6 });

        CASE(N = 10, K = 3, RandomInsideSquare(0, 0, 50));
        CASE(N = 10, K = 3, RandomInsideSquare(500, 500, 500));
        CASE(N = 15, K = 3, RandomInsideSquare(0, 0, 50));
        CASE(N = 15, K = 3, RandomInsideSquare(500, 500, 500));
        CASE(N = 15, K = 3, RandomInsideCircle(0, 0, 50));
        CASE(N = 15, K = 3, RandomInsideCircle(500, 500, 500));
    }

    void TestGroup2() {
        Subtasks({ 1, 2, 4, 5, 6 });

        CASE(N = 10, K = 4, RandomInsideSquare(0, 0, 50));
        CASE(N = 10, K = 4, RandomInsideSquare(500, 500, 500));
        CASE(N = 15, K = 4, RandomInsideSquare(0, 0, 50));
        CASE(N = 15, K = 4, RandomInsideSquare(500, 500, 500));
        CASE(N = 14, K = 4, RandomInsideCircle(0, 0, 50));
        CASE(N = 14, K = 4, RandomInsideCircle(500, 500, 500));
    }

    void TestGroup3() {
        Subtasks({ 1, 2, 6 });

        CASE(N = 15, K = 6, RandomInsideSquare(500000000, 500000000, 500000000));
        CASE(N = 15, K = 7, RandomInsideSquare(-500000000, 500000000, 500000000));
        CASE(N = 15, K = 8, RandomInsideSquare(-500000000, -500000000, 500000000));
        CASE(N = 15, K = 9, RandomInsideSquare(500000000, -500000000, 500000000));
        CASE(N = 15, K = 10, RandomInsideSquare(0, 0, 500000000));
        CASE(N = 10, K = 10, RandomInsideCircle(500000000, -500000000, 500000000));
        CASE(N = 11, K = 10, RandomInsideCircle(0, 0, 500000000));
    }

    void TestGroup4() {

        Subtasks({2, 3, 5, 6 });

        CASE(N = 75, K = 3, RandomInsideSquare(0, 0, 1000));
        CASE(N = 80, K = 3, RandomInsideSquare(500, 500, 500));
        CASE(N = 79, K = 3, RandomInsideCircle(0, 0, 1000));
        CASE(N = 77, K = 3, RandomInsideCircle(500, 500, 500));
    }

    void TestGroup5() {

        Subtasks({2, 3, 6 });

        CASE(N = 75, K = 3, RandomInsideSquare(-500000000, -500000000, 500000000));
        CASE(N = 80, K = 3, RandomInsideSquare(500000000, 500000000, 500000000));
        CASE(N = 75, K = 3, RandomInsideCircle(-500000000, -500000000, 500000000));
        CASE(N = 80, K = 3, RandomInsideCircle(500000000, 500000000, 500000000));
    }

    void TestGroup6() {

        Subtasks({2, 4, 5, 6 });

        CASE(N = 75 , K = 4, RandomInsideSquare(0, 0, 1000));
        CASE(N = 80, K = 4, RandomInsideSquare(500, 500, 500));
        CASE(N = 79, K = 4, RandomInsideCircle(0, 0, 1000));
        CASE(N = 77, K = 4, RandomInsideCircle(500, 500, 500));
    }

    void TestGroup7() {
        Subtasks({2, 4, 6 });

        CASE(N = 75, K = 4, RandomInsideSquare(0, 0, 1000000000));
        CASE(N = 80, K = 4, RandomInsideSquare(-500000000, -500000000, 500000000));
        CASE(N = 75, K = 4, RandomInsideCircle(0, 0, 1000000000));
        CASE(N = 80, K = 4, RandomInsideCircle(-500000000, -500000000, 500000000));
    }

    void TestGroup8() {
        Subtasks({3, 5, 6});

        CASE(N = 295, K = 3, RandomInsideSquare(0, 0, 1000));
        CASE(N = 296, K = 3, RandomInsideSquare(-500, -500, 500));
        CASE(N = 297, K = 3, RandomInsideSquare(-500, 500, 500));
        CASE(N = 298, K = 3, RandomInsideSquare(500, -500, 500));
        CASE(N = 299, K = 3, RandomInsideCircle(500, 500, 500));
        CASE(N = 300, K = 3, RandomInsideCircle(0, 0, 500));
    }

    void TestGroup9() {
        Subtasks({3, 6});

        CASE(N = 295, K = 3, RandomInsideSquare(0, 0, 1000000000));
        CASE(N = 296, K = 3, RandomInsideSquare(-500000000, -500000000, 500000000));
        CASE(N = 297, K = 3, RandomInsideSquare(-500000000, 500000000, 500000000));
        CASE(N = 298, K = 3, RandomInsideSquare(500000000, -500000000, 500000000));
        CASE(N = 299, K = 3, RandomInsideCircle(500000000, 500000000, 500000000));
        CASE(N = 300, K = 3, RandomInsideCircle(0, 0, 500000000));
        CASE(N = 275, K = 3, SpiderWeb());
    }

    void TestGroup10() {
        Subtasks({4, 5, 6});

        CASE(N = 295, K = 4, RandomInsideSquare(0, 0, 1000));
        CASE(N = 296, K = 4, RandomInsideSquare(-500, -500, 500));
        CASE(N = 297, K = 4, RandomInsideSquare(-500, 500, 500));
        CASE(N = 298, K = 4, RandomInsideSquare(500, -500, 500));
        CASE(N = 299, K = 4, RandomInsideCircle(500, 500, 500));
        CASE(N = 300, K = 4, RandomInsideCircle(0, 0, 500));
    }

    void TestGroup11() {
        Subtasks({4, 6});

        CASE(N = 295, K = 4, RandomInsideSquare(0, 0, 1000000000));
        CASE(N = 296, K = 4, RandomInsideSquare(-500000000, -500000000, 500000000));
        CASE(N = 297, K = 4, RandomInsideSquare(-500000000, 500000000, 500000000));
        CASE(N = 298, K = 4, RandomInsideSquare(500000000, -500000000, 500000000));
        CASE(N = 299, K = 4, RandomInsideCircle(500000000, 500000000, 500000000));
        CASE(N = 300, K = 4, RandomInsideCircle(0, 0, 500000000));
        CASE(N = 275, K = 4, SpiderWeb());
    }

    void TestGroup12() {
        Subtasks({5, 6});

        CASE(N = 295, K = 6, RandomInsideSquare(0, 0, 1000));
        CASE(N = 296, K = 7, RandomInsideSquare(-500, -500, 500));
        CASE(N = 297, K = 8, RandomInsideSquare(-500, 500, 500));
        CASE(N = 298, K = 9, RandomInsideSquare(500, -500, 500));
        CASE(N = 299, K = 10, RandomInsideCircle(500, 500, 500));
        CASE(N = 300, K = 10, RandomInsideCircle(0, 0, 500));

    }

    void TestGroup13() {
        Subtasks({6});

        CASE(N = 295, K = 6, RandomInsideSquare(0, 0, 1000000000));
        CASE(N = 296, K = 7, RandomInsideSquare(-500000000, -500000000, 500000000));
        CASE(N = 297, K = 8, RandomInsideSquare(-500000000, 500000000, 500000000));
        CASE(N = 298, K = 9, RandomInsideSquare(500000000, -500000000, 500000000));
        CASE(N = 299, K = 10, RandomInsideCircle(500000000, 500000000, 500000000));
        CASE(N = 300, K = 10, RandomInsideCircle(0, 0, 500000000));
        CASE(N = 275, K = 10, SpiderWeb());
    }


private:
    void RandomInsideSquare(long long x, long long y, long long r){
        for(int i = 0; i < N; ++i){
            int xx, yy;
            while (true) {
                xx = rnd.nextInt(x - r, x + r);
                yy = rnd.nextInt(y - r, y + r);
                bool valid = true;
                for (int j = 0; j < i; j++) {
                    for (int k = j+1; k < i; k++) {
                        if ((yy - Y[j])*(xx - X[k]) == (yy - Y[k])*(xx - X[j])) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid) break;
                }
                if (valid) break;
            }

            X.push_back(xx);
            Y.push_back(yy);
        }
    }

    void RandomInsideCircle(long long x, long long y, long long r){
        for(int i = 0; i < N; ++i){
            int xx, yy;
            while (true) {
                xx = rnd.nextInt(x - r, x + r);
                yy = rnd.nextInt(y - r, y + r);

                while((xx - x) * (xx - x) + (yy - y) * (yy - y) > r * r){
                    xx = rnd.nextInt(x - r, x + r);
                    yy = rnd.nextInt(y - r, y + r);
                }
                bool valid = true;
                for (int j = 0; j < i; j++) {
                    for (int k = j+1; k < i; k++) {
                        if ((yy - Y[j])*(xx - X[k]) == (yy - Y[k])*(xx - X[j])) {
                            valid = false;
                            break;
                        }
                    }
                }
                if (valid) break;
            }
   
            X.push_back(xx);
            Y.push_back(yy);
        }
    }

    void SpiderWeb() {
        int a = N/4;
        int b = N/4;
        int c = N/4;
        int d = N - a - b - c;

        //first quadrant
        while (a > 0) {
            int m = rnd.nextInt(1, 100000);
            int x = rnd.nextInt(0, 6969);
            int y = m * x;

            X.push_back(x);
            Y.push_back(y);
            a--;

            if (a == 0) break;

            x = rnd.nextInt(0, 6969);
            y = m * x;

            X.push_back(x);
            Y.push_back(y);
            a--;
        }

        //second quadrant
        while (b > 0) {
            int m = rnd.nextInt(1, 100000);
            int x = rnd.nextInt(0, 6969);
            int y = m * x;

            X.push_back(-x);
            Y.push_back(y);
            b--;

            if (b == 0) break;

            x = rnd.nextInt(0, 6969);
            y = m * x;

            X.push_back(-x);
            Y.push_back(y);
            b--;
        }

        //third quadrant
        while (c > 0) {
            int m = rnd.nextInt(1, 100000);
            int x = rnd.nextInt(0, 6969);
            int y = m * x;

            X.push_back(-x);
            Y.push_back(-y);
            c--;

            if (c == 0) break;

            x = rnd.nextInt(0, 6969);
            y = m * x;

            X.push_back(-x);
            Y.push_back(-y);
            c--;
        }

        //fourth quadrant
        while (d > 0) {
            int m = rnd.nextInt(1, 100000);
            int x = rnd.nextInt(0, 6969);
            int y = m * x;

            X.push_back(x);
            Y.push_back(-y);
            d--;

            if (d == 0) break;

            x = rnd.nextInt(0, 6969);
            y = m * x;

            X.push_back(x);
            Y.push_back(-y);
            d--;
        }
    }
};