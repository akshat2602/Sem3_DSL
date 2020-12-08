#include <iostream>

using namespace std;

const int D = 2;

class Job {
private:
	string data;
	int priority;
public:
	Job(string data="", int priority=0) {
		this->data = data;
		this->priority = priority;
	}
	void setData() {
		cout << "Enter data: "; cin >> data;
		cout << "Enter Priority: "; cin >> priority;
	}
	string getData() {
		return data;
	}
	int getPriority() {
		return priority;
	}
	friend bool operator <= (Job , Job );
	friend ostream& operator << (ostream& dout, Job i);
};

bool operator <= (Job i1, Job i2) {
	return (i1.priority <= i2.priority);
}

ostream& operator << (ostream& dout, Job i) {
	dout << "Data: " << i.data << endl;
	dout << "Priority: " << i.priority << endl;
	return dout;
}

// max - heap implementation
template <class T>
class PriorityQueue {
private:
	T arr[D];
	int n, max_ele_idx;
	void updateMaxEleIdx() {
		for (int i = 0; i < n; i++) {
			if (arr[max_ele_idx] <= arr[i])
				max_ele_idx = i;
		}
	}
public:
	PriorityQueue() { n = 0; }
	int getSize() { return n; }
	bool isEmpty() { return (n < 1); }
	bool isFull() { return (n == D); }
	T Top() { return arr[max_ele_idx]; }
	void Push(T x) {
		if (!isFull()) {
			n++;
			arr[n-1] = x;
			updateMaxEleIdx();
		}
	}
	void Pop() {
		if (isEmpty()) return;
		swap(arr[max_ele_idx], arr[n-1]);
		n--;
		updateMaxEleIdx();
	}
	void Print() {
		if (isEmpty()) cout << "Empty List.\n";

		for (int i = 0; i < n; i++)
			cout << arr[i];
	}
};

int main() {
	PriorityQueue<Job> pq;

	while (true) {
		cout << "\nWhat do you want to do??\n";
		cout << "Enter\n\t1 to add in the list.\n\t2 to get from the list.\n\t3 to remove from the list.\n";
		cout << "\t4 to print list\n\t0 to exit.\n:";
		int choice = 0; cin >> choice;
		if (choice == 1) {
			if (pq.isFull())
				cout << "Queue is full.\n";
			else {
				Job temp_Job;
				temp_Job.setData();
				pq.Push(temp_Job);
				cout << "Job added Successfully\n";
			}
		}
		else if (choice == 2) {
			if (pq.isEmpty())
				cout << "List is empty.\n";
			else 
				cout << pq.Top();
		}
		else if (choice == 3) {
			if (pq.isEmpty()) cout << "List is empty.\n";
			else {
				pq.Pop();
				cout << "Removed Successfully.\n";
			}
		}
		else if (choice == 4) {
			cout << "The List is:\n";
			pq.Print();
		}
		else if (choice == 0)
			break;
		else 
			cout << "INVALID INPUT. Try Again.\n";
	}

	return 0;
}