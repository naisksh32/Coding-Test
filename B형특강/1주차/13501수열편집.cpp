#include <iostream>
using namespace std;


int ans;

struct Node {
	int data;
	Node* next;

	Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
	Node* head;

public:
	LinkedList() : head(nullptr) {}

	void push_back(int val) {
		Node* newNode = new Node(val);

		if (head == nullptr) {
			head = newNode;
			return;
		}

		Node* curr = head;
		while (curr->next != nullptr) {
			curr = curr->next;
		}

		curr->next = newNode;
	}

	void push_front(int val) {
		Node* newNode = new Node(val);

		newNode->next = head;

		head = newNode;
	}

	void clear() {
		Node* curr = head;
		while (curr != nullptr) {
			Node* temp = curr;
			curr = curr->next;
			delete temp;
		}
		head = nullptr;
	}

	void insert_at(int idx, int val) {
		if (idx == 0) {
			push_front(val);
			return;
		}

		Node* curr = head;
		// 삽입할 위치의 "바로 앞(idx-1)" 노드까지 이동
		for (int i = 0; i < idx - 1 && curr != nullptr; i++) {
			curr = curr->next;
		}

		// 인덱스가 범위를 벗어났다면 무시 (또는 맨 뒤에 추가 등 문제 조건에 맞게 처리)
		if (curr == nullptr) return;

		Node* newNode = new Node(val);
		newNode->next = curr->next; // 새 노드가 뒷부분을 연결
		curr->next = newNode;       // 앞부분이 새 노드를 연결
	}

	void delete_at(int idx) {
		if (head == nullptr) return;

		if (idx == 0) {
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}

		Node* curr = head;
		// 삭제할 위치의 "바로 앞(idx-1)" 노드까지 이동
		for (int i = 0; i < idx - 1 && curr != nullptr; i++) {
			curr = curr->next;
		}

		// 삭제할 노드가 없거나, 인덱스 범위를 벗어났다면 무시
		if (curr == nullptr || curr->next == nullptr) return;

		Node* temp = curr->next;       // 삭제할 노드
		curr->next = temp->next;       // 앞 노드와 다다음 노드 연결
		delete temp;                   // 타겟 노드 삭제
	}

	void change_at(int idx, int val) {
		Node* curr = head;
		// 변경할 노드(idx)까지 바로 이동
		for (int i = 0; i < idx && curr != nullptr; i++) {
			curr = curr->next;
		}

		if (curr == nullptr) return; // 범위 밖이면 무시

		curr->data = val; // 데이터 덮어쓰기
	}

	int get_at(int idx) {
		Node* curr = head;
		// 찾고자 하는 노드(idx)까지 바로 이동
		for (int i = 0; i < idx && curr != nullptr; i++) {
			curr = curr->next;
		}

		// 범위를 벗어났으면 -1 반환
		if (curr == nullptr) return -1;

		return curr->data;
	}

	~LinkedList() {
		clear();
	}
};

LinkedList list;

int N, M, L;

void init() {
	list.clear();
}
void input() {
	cin >> N >> M >> L;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		list.push_back(n);
	}
}
void solve() {
	for (int m = 0; m < M; m++) {
		char cmd;
		cin >> cmd;

		int idx, num;

		switch (cmd) {
		case 'I':
			cin >> idx >> num;
			list.insert_at(idx, num);
			break;

		case 'D':
			cin >> idx;
			list.delete_at(idx);
			break;

		case 'C':
			cin >> idx >> num;
			list.change_at(idx, num);
			break;
		}
	}

	ans = list.get_at(L);
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();
		input();
		solve();

		cout << '#' << t << ' ' << ans << '\n';
	}

	return 0;
}