#include <queue>
using namespace std;

struct Semaphore {
	enum Value { FREE, BUSY };
	Value val;
	queue<Process> wait_queue;
};

void down(Semaphore &s, Process p) {
	if (s.val == Semaphore::FREE) {
		s.val = Semaphore::BUSY;
	} else {
		s.wait_queue.push(p);
		sleep();
	}
}

void up(Semaphore &s) {
	if (s.wait_queue.empty()) {
		s.val = Semaphore::FREE;
	} else {
		Process p = s.wait_queue.front();
		s.wait_queue.pop();
		wakeup(p);
	}
}
