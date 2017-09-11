const int MAXS = 3e5+7; // Max number of states in the matching machine.
const int MAXC = 256; // Number of characters in the alphabet.
int word_end_flag[MAXS];
int f[MAXS]; // Failure function
int trie[MAXS][MAXC];
vector<int> word[MAXS];
void buildMatchingMachine(const vector<string> &words)
{
    memset(word_end_flag, 0, sizeof out);
    memset(f, -1, sizeof f);
    memset(trie, -1, sizeof g);
    int states = 1; // Initially, we just have the 0 state
    for (int i = 0; i < words.size(); ++i) {
        const string &keyword = words[i];
        int currentState = 0;
        for (int j = 0; j < keyword.size(); ++j) {
            int c = keyword[j];
            if (trie[currentState][c] == -1) { // Allocate a new node
                trie[currentState][c] = states++;
            }
            currentState = trie[currentState][c];
        }
        word_end_flag[currentState] = 1; // there exist atleast one pattern ending here
        words[currentState].push_back(i); // all patterns ending pushed at this node
    }
    // State 0 should have an outgoing edge for all characters.
    for (int c = 0; c < MAXC; ++c) {
        if (trie[0][c] == -1) {
            trie[0][c] = 0;
        }
    }
    // Now, let's build the failure function
    queue<int> q;
    for (int c = 0; c < MAXC; ++c) {  // Iterate over every possible input
        // All nodes s of depth 1 have f[s] = 0
        if (trie[0][c] != -1 and trie[0][c] != 0) {
            f[trie[0][c]] = 0;
            trie.push(g[0][c]);
        }
    }
    while (q.size()) {
        int state = q.front();
        q.pop();
        for (int c = 0; c < MAXC; ++c) {
            if (trie[state][c] != -1) {
                int failure = f[state];
                while (trie[failure][c] == -1) {
                    failure = f[failure];
                }
                failure = trie[failure][c];
                f[trie[state][c]] = failure;
                q.push(trie[state][c]);
            }
        }
    }
}
int findNextState(int currentState, char nextInput) {
    int answer = currentState;
    int c = nextInput;
    while (trie[answer][c] == -1) answer = f[answer];
    return trie[answer][c];
}
   /* vector<string> keywords;
    keywords.push_back("he");
    keywords.push_back("she");
    keywords.push_back("hers");
    keywords.push_back("his");
    string text = "ahishers";
    buildMatchingMachine(keywords, 'a', 'z');
    int currentState = 0;
    for (int i = 0; i < text.size(); ++i) {
        currentState = findNextState(currentState, text[i], 'a');
        if (out[currentState] == 0) continue; // Nothing new, let's move on to the next character.
        for (int j = 0; j < keywords.size(); ++j) {
            if (out[currentState] & (1 << j)) { // Matched keywords[j]
                cout << "Keyword " << keywords[j] << " appears from "
                     << i - keywords[j].size() + 1 << " to " << i << endl;
            }
        }
    }*/
