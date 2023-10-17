class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        for (int root = 0; root < n; root++) {
            stack<int> nodes;
            vector<bool> visited(n);
            nodes.push(root);

            while (!nodes.empty()) {
                int top = nodes.top();
                nodes.pop();
                if (top == -1) {
                    continue;
                }

                if (visited[top])
                    return false;

                visited[top] = true;
                nodes.push(leftChild[top]);
                nodes.push(rightChild[top]);
            }

            if (find(visited.begin(), visited.end(), false) == visited.end())
                return true;
        }

        return false;
    }
};