#include<iostream>
#include<stdlib.h>
using namespace std;

struct Process {
	int process_id, burst_time, arrival_time, completion_time, turnaround_time, waiting_time;
};

void calculate(Process* p, int n) {
	int sum = 0;
	sum = sum + p[0].arrival_time;
	for(int i = 0; i < n; i++) {
		sum = sum + p[i].burst_time;
		p[i].completion_time = sum;
		p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
		p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
		if(sum < p[i + 1].arrival_time && i < n - 1) {
			int t = p[i + 1].arrival_time - sum;
			sum = sum + t;
		}
	}
}

void sort(Process* p, int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if(p[j].arrival_time > p[j + 1].arrival_time) {
				int temp;
				temp = p[j].burst_time;
				p[j].burst_time = p[j + 1].burst_time;
				p[j + 1].burst_time = temp;

				temp = p[j].arrival_time;
				p[j].arrival_time = p[j + 1].arrival_time;
				p[j + 1].arrival_time = temp;

				temp = p[j].process_id;
				p[j].process_id = p[j + 1].process_id;
				p[j + 1].process_id = temp;
			}
		}
	}
}

void display(Process* p, int n) {
	cout << "Process\tArrival\tBurst\tWaiting\tTurn Around\tCompletion\n";
	for(int i = 0; i < n; i++) {
		cout << " P[" << p[i].process_id << "]\t " << p[i].arrival_time << "\t" << p[i].burst_time << "\t" << p[i].waiting_time << "\t " << p[i].turnaround_time << "\t\t" << p[i].completion_time << "\n";
	}
}

int main() {
	const int num_processes = 5;
	Process processes[num_processes] = {
		{1, 2, 0, 0, 0, 0},
		{2, 3, 1, 0, 0, 0},
		{3, 5, 2, 0, 0, 0},
		{4, 4, 3, 0, 0, 0},
		{5, 6, 4, 0, 0, 0}
	};

	sort(processes, num_processes);
	calculate(processes, num_processes);
	display(processes, num_processes);

	return 0;
}
