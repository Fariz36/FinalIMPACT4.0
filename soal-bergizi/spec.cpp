#include <tcframe/spec.hpp>
using namespace tcframe;
const long long MAXN = 1000000000000;
const long long MAXp = 1000000;
const long long MAXq = 1000000000000000000;
const long long MAXr = 1000000000000000000;

class ProblemSpec : public BaseProblemSpec {
protected:
    int Q;
    vector<long long> N, p, q, r, answer;

    void InputFormat() {
        LINE(Q);
        LINES(N, p, q, r) % SIZE(Q);
    }

    void OutputFormat() {
        LINES(answer);
    }

    void StyleConfig() {
        CustomScorer();
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= Q && Q <= 10000);

        CONS(eachBetween(N, 0, MAXN));
        CONS(eachBetween(p, 0, MAXp));
        CONS(eachBetween(q, 0, MAXq));
        CONS(eachBetween(r, 1, MAXr));

        CONS((int)N.size() == Q);
        CONS((int)p.size() == Q);
        CONS((int)q.size() == Q);
        CONS((int)r.size() == Q);
    }

    void Subtask1() {
		Points(1);

		CONS(eachBetween(p, 0, 0));
		CONS(eachBetween(q, 0, 0));
	}

	void Subtask2() {
		Points(9);

		CONS(Q == 1);
		CONS(eachBetween(N, 0, 1000000));
	}

	void Subtask3() {
		Points(12);

		CONS(eachBetween(p, 0, 0));
	}

	void Subtask4() {
		Points(15);

        CONS(Q == 1);
        CONS(eachBetween(r, 1000000000000, 1000000000000));
	}

	void Subtask5() {
		Points(15);

        CONS(Q == 1);
        CONS(eachBetween(p, 1, 1));
        CONS(eachBetween(q, 0, 0));
	}

	void Subtask6() {
		Points(11);

		CONS(Q == 1);
	}

	void Subtask7() {
		Points(37);
	}

private:
    bool eachBetween(const vector<long long> &u, long long left, long long right){
        for(long long elem : u){
            if(!(left <= elem && elem <= right)){
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:

    void BeforeTestCase() {
        N.clear();
        p.clear();
        q.clear();
        r.clear();
    }

    void SampleTestCase1() {

        Subtasks({ 7 });
        Input({
            "3",
            "5 4 7 3",
            "20 13 17 19",
            "10000000 7777 2124 3321"
        });
        Output({
            "12",
            "0",
            "19573873"
        });
    }

    void TestGroup1() {

        Subtasks({ 1, 3, 7 });

        CASE(Q = 1000, genN(1, MAXN), genp(0, 0), genq(0, 0), genr(1, MAXr));
        CASE(Q = 1000, genN(MAXN / 4, MAXN), genp(0, 0), genq(0, 0), genr(MAXr / 4, MAXr));
        CASE(Q = 1000, genN(MAXN / 4, MAXN), genp(0, 0), genq(0, 0), genr(1, 1000));
    }

    void TestGroup2() {

        Subtasks({ 2, 6, 7 });

        CASE(Q = 1, genN(1000000, 1000000), genp(1, MAXp), genq(0, MAXq), genr(1, MAXr));
        CASE(Q = 1, genN(1000000, 1000000), genp(1, 1000), genq(0, MAXq), genr(100, 10000));
        CASE(Q = 1, genN(1000000, 1000000), genp(1, 1000), genq(0, MAXq), genr(100, 10000));
        CASE(Q = 1, genN(200000, 1000000),  genp(1, MAXp), genq(0, MAXq), genr(1, MAXr));
        CASE(Q = 1, genN(700000, 1000000),  genp(1, MAXp), genq(0, MAXq), genr(10000, 1000000));

        CASE(Q = 1, genN(1, 1000),     genp(1, MAXp), genq(0, MAXq), genr(1, MAXr));
        CASE(Q = 1, genN(100, 10000),  genp(1, MAXp), genq(0, MAXq), genr(100, 10000));
        CASE(Q = 1, genN(1000, 20000), genp(1, MAXp), genq(0, MAXq), genr(100, 10000));
    }

    void TestGroup3() {

        Subtasks({ 3, 7 });

        CASE(Q = 10000, genN(MAXN - 100, MAXN), genp(0, 0), genq(0, MAXq), genr(1, MAXr));
        CASE(Q = 10000, genN(MAXN - 100, MAXN), genp(0, 0), genq(0, MAXq), genr(1, 10000));
        CASE(Q = 10000, genN(MAXN - 100000, MAXN), genp(0, 0), genq(1000000, 1000000000), genr(1, MAXr));
        CASE(Q = 10000, genN(MAXN - 100000, MAXN), genp(0, 0), genq(1000000, 1000000000), genr(1, 10000));
    }

    void TestGroup4() {

        Subtasks({ 4, 6, 7 });

        long long valr = 1000000000000;
        CASE(Q = 1, genN(MAXN, MAXN), genp(1, MAXp), genq(0, MAXq), genr(valr, valr));
        CASE(Q = 1, genN(MAXN, MAXN), genp(1, MAXp), genq(0, MAXq), genr(valr, valr));

        CASE(Q = 1, genN(MAXN, MAXN), genp(MAXp / 4, MAXp), genq(0, MAXq), genr(valr, valr));
        CASE(Q = 1, genN(MAXN, MAXN), genp(MAXp / 4, MAXp), genq(0, MAXq), genr(valr, valr));

        CASE(Q = 1, genN(MAXN, MAXN),        genp(1, MAXp), genq(MAXq / 2, MAXq), genr(valr, valr));
        CASE(Q = 1, genN(MAXN, MAXN),        genp(1, MAXp), genq(MAXq / 2, MAXq), genr(valr, valr));
        CASE(Q = 1, genN(MAXN - 100, MAXN),  genp(1, MAXp), genq(MAXq / 2, MAXq), genr(valr, valr));
        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(1, MAXp), genq(MAXq / 2, MAXq), genr(valr, valr));

        CASE(Q = 1, genN(MAXN, MAXN),        genp(MAXp / 4, MAXp), genq(MAXq / 2, MAXq), genr(valr, valr));
        CASE(Q = 1, genN(MAXN, MAXN),        genp(MAXp / 4, MAXp), genq(MAXq / 2, MAXq), genr(valr, valr));
        CASE(Q = 1, genN(MAXN - 100, MAXN),  genp(MAXp / 4, MAXp), genq(MAXq / 2, MAXq), genr(valr, valr));
        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(MAXp / 4, MAXp), genq(MAXq / 2, MAXq), genr(valr, valr));
    }

    void TestGroup5() {
        Subtasks({ 5, 6, 7 });

        CASE(Q = 1, genN(MAXN, MAXN), genp(1, 1), genq(0, 0), genr(1, MAXr));
        CASE(Q = 1, genN(MAXN, MAXN), genp(1, 1), genq(0, 0), genr(1, MAXr));

        CASE(Q = 1, genN(MAXN, MAXN), genp(1, 1), genq(0, 0), genr(MAXr / 3, MAXr));
        CASE(Q = 1, genN(MAXN, MAXN), genp(1, 1), genq(0, 0), genr(MAXr / 3, MAXr));

        CASE(Q = 1, genN(MAXN, MAXN), genp(1, 1), genq(0, 0), genr(1, 1000));
        CASE(Q = 1, genN(MAXN, MAXN), genp(1, 1), genq(0, 0), genr(1, 1000));
        CASE(Q = 1, genN(MAXN, MAXN), genp(1, 1), genq(0, 0), genr(100, 1000));
        CASE(Q = 1, genN(MAXN, MAXN), genp(1, 1), genq(0, 0), genr(100, 1000));

        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(1, 1), genq(0, 0), genr(1, 1000));
        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(1, 1), genq(0, 0), genr(1, 1000));

        CASE(Q = 1, genN(MAXN, MAXN), genp(1, 1), genq(0, 0), genr(1, 1));
        CASE(Q = 1, genN(MAXN, MAXN), genp(1, 1), genq(0, 0), genr(1, 1));

        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(1, 1), genq(0, 0), genr(1, 1));
    }

    void TestGroup6() {
        Subtasks({ 6, 7 });

        CASE(Q = 1, genN(MAXN, MAXN), genp(1, MAXp), genq(0, MAXq), genr(1, MAXr));
        CASE(Q = 1, genN(MAXN, MAXN), genp(1, MAXp), genq(0, MAXq), genr(1, MAXr));

        CASE(Q = 1, genN(MAXN, MAXN), genp(1, MAXp), genq(0, MAXq), genr(1000000, 10000000));
        CASE(Q = 1, genN(MAXN, MAXN), genp(1, MAXp), genq(0, MAXq), genr(10000000, 100000000));

        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(1, MAXp), genq(0, MAXq), genr(1, MAXr));
        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(1, MAXp), genq(0, MAXq), genr(1, MAXr));

        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(MAXq / 10, MAXq), genr(MAXr / 10000, MAXr));
        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(MAXq / 10, MAXq), genr(MAXr / 10000, MAXr));

        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(MAXq / 10, MAXq), genr(1, 5000));
        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(MAXq / 10, MAXq), genr(1, 5000));

        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(1000000, 10000000), genr(MAXr / 10000, MAXr));
        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(1000000, 10000000), genr(MAXr / 10000, MAXr));

        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(1000000, 10000000), genr(1, 5000));
        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(1000000, 10000000), genr(1, 5000));

        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(MAXp / 10, MAXp), genq(MAXq / 10, MAXq), genr(MAXr / 10000, MAXr));
        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(MAXp / 10, MAXp), genq(MAXq / 10, MAXq), genr(MAXr / 10000, MAXr));

        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(MAXp / 10, MAXp), genq(MAXq / 10, MAXq), genr(1, 10000));
        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(MAXp / 10, MAXp), genq(MAXq / 10, MAXq), genr(1, 10000));

        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(MAXp / 10, MAXp), genq(1000000, 10000000), genr(MAXr / 10000, MAXr));
        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(MAXp / 10, MAXp), genq(1000000, 10000000), genr(MAXr / 10000, MAXr));

        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(MAXp / 10, MAXp), genq(1000000, 10000000), genr(1, 8000));
        CASE(Q = 1, genN(MAXN - 1000, MAXN), genp(MAXp / 10, MAXp), genq(1000000, 10000000), genr(1, 8000));
    }

    void TestGroup7() {

        Subtasks({ 7 });

        CASE(Q = 10000, genN(MAXN, MAXN), genp(1, MAXp), genq(0, MAXq), genr(1, MAXr));
        CASE(Q = 10000, genN(MAXN, MAXN), genp(1, MAXp), genq(0, MAXq), genr(1, MAXr));

        CASE(Q = 10000, genN(MAXN - 10000, MAXN), genp(1, MAXp), genq(0, MAXq), genr(1, MAXr));

        CASE(Q = 10000, genN(MAXN, MAXN), genp(1, MAXp), genq(0, MAXq), genr(1000000, 10000000));
        CASE(Q = 10000, genN(MAXN, MAXN), genp(1, MAXp), genq(0, MAXq), genr(1000000, 10000000));

        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(1, MAXp), genq(0, MAXq), genr(10000000, 100000000));

        CASE(Q = 10000, genN(MAXN - 10000, MAXN), genp(1, MAXp), genq(0, MAXq), genr(10000000, 100000000));

        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(MAXq / 10, MAXq), genr(MAXr / 10000, MAXr));
        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(MAXq / 10, MAXq), genr(MAXr / 10000, MAXr));

        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(MAXq / 10, MAXq), genr(1, 5000));

        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(MAXq / 10, MAXq), genr(1000000, 10000000));
        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(MAXq / 10, MAXq), genr(1000000, 100000000));

        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(1000000, 10000000), genr(MAXr / 10000, MAXr));
        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(1000000, 10000000), genr(MAXr / 10000, MAXr));

        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(1000000, 10000000), genr(1000000, 50000000));
        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(1000000, 10000000), genr(10000000, 100000000));

        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(1000000, 10000000), genr(1, 5000));
        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(1, 1000), genq(1000000, 10000000), genr(1, 5000));

        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(MAXp / 10, MAXp), genq(MAXq / 10, MAXq), genr(MAXr / 10000, MAXr));
        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(MAXp / 10, MAXp), genq(MAXq / 10, MAXq), genr(MAXr / 10000, MAXr));

        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(MAXp / 10, MAXp), genq(MAXq / 10, MAXq), genr(1, 10000));
        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(MAXp / 10, MAXp), genq(MAXq / 10, MAXq), genr(1, 10000));

        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(MAXp / 10, MAXp), genq(1000000, 10000000), genr(MAXr / 10000, MAXr));
        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(MAXp / 10, MAXp), genq(1000000, 10000000), genr(MAXr / 10000, MAXr));

        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(MAXp / 10, MAXp), genq(1000000, 10000000), genr(100000, 2000000));

        CASE(Q = 10000, genN(MAXN - 1000, MAXN), genp(MAXp / 10, MAXp), genq(1000000, 10000000), genr(128342, 5432287));
    }

private:
    void genN(const long long left, const long long right){
        for(int i = 1; i <= Q; ++i){
            N.push_back(rnd.nextLongLong(left, right));
        }
    }

    void genp(const long long left, const long long right){
        for(int i = 1; i <= Q; ++i){
            p.push_back(rnd.nextLongLong(left, right));
        }
    }

    void genq(const long long left, const long long right){
        for(int i = 1; i <= Q; ++i){
            q.push_back(rnd.nextLongLong(left, right));
        }
    }

    void genr(const long long left, const long long right){
        for(int i = 1; i <= Q; ++i){
            r.push_back(rnd.nextLongLong(left, right));
        }
    }
};
