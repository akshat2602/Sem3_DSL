#include <iostream>

using namespace std;

const int D = 3;

class Job {
private:
	string job_title;
	int job_number;
	static int job_count;
public:
	Job(string job = "") {
		job_title = job;
	}
	void setData() {
		cout << "Enter Job Title: "; cin >> job_title;
		job_number = job_count++;
	}
	string getTitle() {
		return job_title;
	}
	int getJobNumber() {
		return job_number;
	}
	friend ostream& operator << (ostream&, Job);
};

int Job::job_count = 1;

ostream& operator << (ostream& dout, Job i) {
	dout << "Job Number: " << i.job_number << endl;
	dout << "Job Title: " << i.job_title << endl;
	return dout;
}

template <class T>
class Queue {
private:
	T arr[D];
	int front, rear;
public:
	Queue() {
		front = -1;
		rear = -1;
	}
	bool isEmpty() {
		return (front == -1 &&
		        rear == -1);
	};
	bool isFull() {
		int temp = (rear + 1) % D;
		return (temp == front);
	};
	T Front() { return arr[front]; }
	void Push(T x) {
		if (isEmpty()) {
			front = rear = 0;
			arr[front] = x;
			return;
		}

		if (!isFull()) {
			rear = (rear + 1) % D;
			arr[rear] = x;
		}
	}
	void Pop() {
		if (isEmpty()) return;

		if (front == rear) {
			front = rear = -1;
			return;
		}
		front = (front + 1) % D;
	}
	void PrintQu() {
		if (isEmpty())
			return;

		int i = front;
		while (true) {
			cout << arr[i];
			if (i == rear) break;
			i = (i + 1) % D;
		}
	}
};

int main() {
	Queue<Job> qu;

	while (true) {
		cout << "\nWhat do you want to do??\n";
		cout << "Enter\n\t1 to add job to queue.\n\t2 to get current job.\n\t3 to finish the current job.\n\t4 to print queue\n\t0 to exit.\n:";
		int choice = 0; cin >> choice;
		if (choice == 1) {
			if (qu.isFull())
				cout << "Failed to add a job. Queue is already full.\n";
			else {
				Job temp_job;
				temp_job.setData();
				qu.Push(temp_job);
				cout << "Job Added Successfully.\n";
			}
		}
		else if (choice == 2) {
			if (qu.isEmpty())
				cout << "No Jobs are in the queue.\n";
			else {
				cout << "The details of current job are as follows:\n";
				cout << qu.Front();
			}
		}
		else if (choice == 3) {
			qu.Pop();
			cout << "Job finished Successfully.\n";
		}
		else if (choice == 4) {
			cout << "Printing Queue: \n";
			qu.PrintQu();
		}
		else if (choice == 0)
			break;
		else
			cout << "INVALID CHOICE. Try Again.\n";
	}
	return 0;
}