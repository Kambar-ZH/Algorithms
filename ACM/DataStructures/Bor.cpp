#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define For(i, n) for(int i = 0; i < n; ++i)
#define rFor(i, n) for(int i = n - 1; i >= 0; --i)
#define see(i) cout << i << endl
#define look(i) cout << i << " " 
#define look_pair(i, j) cout << i << " " << j << endl
#define vector vector
#define itn int
 
const int MAXN = 1e9;
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};
 
const int letterA = 97;

struct trie
{
	bool flag;
	vector<trie *> buffer;
	trie() {
		buffer = vector<trie *> (26, NULL);
		flag = false;
	}
};


void insert(trie * root, string word) {
	trie * current = root;
	int i = 0;
	for (; i < word.size(); i++) {
		if (current->buffer[word[i] - letterA] == NULL) {
			current->buffer[word[i] - letterA] = new trie();
		}
		current = current->buffer[word[i] - letterA];
	}
	current->flag = true;
}

bool search(trie * root, string word) {
	trie * current = root;
	int i = 0;
	for (; i < word.size(); ++i) {
		if (current->buffer[word[i] - letterA] == NULL) {
			return false;
		}
		current = current->buffer[word[i] - letterA];
	}
	return (current->flag);
}

bool startWith(trie * root, string word) {
	trie * current = root;
	int i = 0;
	for (; i < word.size(); ++i) {
		if (current->buffer[word[i] - letterA] == NULL) {
			return false;
		}
		current = current->buffer[word[i] - letterA];
	}
	return true;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	trie * root = new trie();
	For (i, n) {
		int operation;
		string word;
		cin >> operation >> word;
		if (operation == 1) {
			insert(root, word);
		} else if (operation == 2) {
			search(root, word) ? see("Found one") : see("Ooops, no in stock");
		} else {
			startWith(root, word) ? see("Found one") : see("Ooops, no in stock");
		}
	}	
	return 0;
}