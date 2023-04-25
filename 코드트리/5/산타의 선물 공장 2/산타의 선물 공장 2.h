#pragma once

struct Node {
	int id;
	Node* prev;
	Node* next;
} nodes[100001];

int N, M;
Node heads[100001];
int cnt[100001];

void init(int mN, int mM, int mA[]) {
	N = mN, M = mM;

	// Set list heads.
	for (int i = 1; N >= i; ++i) {
		heads[i].next = &heads[i];
		heads[i].prev = &heads[i];
	}

	// Set list nodes.
	for (int i = 1, b_num; M >= i; ++i) {
		b_num = mA[i - 1];

		nodes[i].id = i;
		nodes[i].prev = heads[b_num].prev;
		nodes[i].next = heads[b_num].prev->next;
		heads[b_num].prev->next = &nodes[i];
		heads[b_num].prev = &nodes[i];

		++cnt[b_num];
	}

	return;
}

int moveAll(int m_src, int m_dst) {
	if (cnt[m_src]) {
		int p_num_front = heads[m_src].next->id, p_num_back = heads[m_src].prev->id;

		// Remove nodes.
		heads[m_src].prev = &heads[m_src];
		heads[m_src].next = &heads[m_src];

		// Insert nodes.
		nodes[p_num_front].prev = &heads[m_dst];
		nodes[p_num_back].next = heads[m_dst].next;
		heads[m_dst].next->prev = &nodes[p_num_back];
		heads[m_dst].next = &nodes[p_num_front];

		// Update count.
		cnt[m_dst] += cnt[m_src];
		cnt[m_src] = 0;
	}

	return cnt[m_dst];
}

int moveFront(int m_src, int m_dst) {
	int p_num_src = 0, p_num_dst = 0;

	// Remove nodes.
	if (cnt[m_src]) {
		// Remove node.
		p_num_src = heads[m_src].next->id;
		nodes[p_num_src].next->prev = &heads[m_src];
		heads[m_src].next = nodes[p_num_src].next;

		// Update count.
		cnt[m_src] -= 1;
	}
	if (cnt[m_dst]) {
		// Remove node.
		p_num_dst = heads[m_dst].next->id;
		nodes[p_num_dst].next->prev = &heads[m_dst];
		heads[m_dst].next = nodes[p_num_dst].next;

		// Update count.
		cnt[m_dst] -= 1;
	}

	// Insert nodes.
	if (p_num_src) {
		// Insert node.
		nodes[p_num_src].prev = &heads[m_dst];
		nodes[p_num_src].next = heads[m_dst].next;
		heads[m_dst].next->prev = &nodes[p_num_src];
		heads[m_dst].next = &nodes[p_num_src];

		// Update count.
		cnt[m_dst] += 1;
	}
	if (p_num_dst) {
		// Insert node.
		nodes[p_num_dst].prev = &heads[m_src];
		nodes[p_num_dst].next = heads[m_src].next;
		heads[m_src].next->prev = &nodes[p_num_dst];
		heads[m_src].next = &nodes[p_num_dst];

		// Update count.
		cnt[m_src] += 1;
	}

	return cnt[m_dst];
}

int moveHalf(int m_src, int m_dst) {
	int p_num_front = heads[m_src].next->id, p_num_back;

	// Find end node.
	Node* node = &heads[m_src];

	for (int ts = cnt[m_src] / 2; ts--; ) {
		node = node->next;
	}

	p_num_back = node->id;

	// Move nodes.
	if (cnt[m_src] / 2) {
		// Remove nodes.
		nodes[p_num_back].next->prev = &heads[m_src];
		heads[m_src].next = nodes[p_num_back].next;

		// Insert nodes.
		nodes[p_num_front].prev = &heads[m_dst];
		nodes[p_num_back].next = heads[m_dst].next;
		heads[m_dst].next->prev = &nodes[p_num_back];
		heads[m_dst].next = &nodes[p_num_front];
	}

	// Update count.
	cnt[m_dst] += cnt[m_src] / 2;
	cnt[m_src] -= cnt[m_src] / 2;

	return cnt[m_dst];
}

int getPresent(int p_num) {
	int a = nodes[p_num].prev->id, b = nodes[p_num].next->id;
	if (!a) {
		a = -1;
	}
	if (!b) {
		b = -1;
	}

	return a + 2 * b;
}

int getBelt(int b_num) {
	int a = heads[b_num].next->id, b = heads[b_num].prev->id, c = cnt[b_num];

	if (!cnt[b_num]) {
		a = -1;
		b = -1;
	}

	return a + 2 * b + 3 * c;
}