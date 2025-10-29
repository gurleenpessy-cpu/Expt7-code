// Code (a):- Insert a node in BST

#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
struct Node {
int key;
struct Node *left, *right;
};
struct Node* new Node(int item) {
struct Node* temp = (struct Node*)malloc(size of(struct Node));
temp-&gt;key = item;
temp-&gt;left = temp-&gt;right = NULL;
return temp;
}
struct Node* insert(struct Node* node, int key) {
if (node == NULL) return new Node(key);

if (key &lt; node-&gt;key)
node-&gt;left = insert(node-&gt;left, key);
else if (key &gt; node-&gt;key)
node-&gt;right = insert(node-&gt;right, key);

return node;
}

void inorder(struct Node* root) {
if (root != NULL) {
inorder(root-&gt;left);
printf(&quot;%d &quot;, root-&gt;key);
inorder(root-&gt;right);
}
}

int main() {
struct Node* root = NULL;
int n, val;

printf(&quot;Enter number of nodes to insert: &quot;);
scanf(&quot;%d&quot;, &amp;n);

printf(&quot;Enter %d values:\n&quot;, n);
for (int i = 0; i &lt; n; i++) {
scanf(&quot;%d&quot;, &amp;val);
root = insert(root, val);
}

printf(&quot;Inorder traversal after insertion:\n&quot;);

inorder(root);

return 0;
}

// Code B:- Delete a node from BST

#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

struct Node {
int key;
struct Node *left, *right;
};

struct Node* newNode(int item) {
struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
temp-&gt;key = item;
temp-&gt;left = temp-&gt;right = NULL;
return temp;
}

struct Node* insert(struct Node* node, int key) {
if (node == NULL) return newNode(key);
if (key &lt; node-&gt;key)
node-&gt;left = insert(node-&gt;left, key);
else if (key &gt; node-&gt;key)
node-&gt;right = insert(node-&gt;right, key);
return node;
}

struct Node* minValueNode(struct Node* node) {
struct Node* current = node;
while (current &amp;&amp; current-&gt;left != NULL)
current = current-&gt;left;
return current;
}

struct Node* deleteNode(struct Node* root, int key) {
if (root == NULL) return root;

if (key &lt; root-&gt;key)
root-&gt;left = deleteNode(root-&gt;left, key);
else if (key &gt; root-&gt;key)
root-&gt;right = deleteNode(root-&gt;right, key);
else {
if (root-&gt;left == NULL) {
struct Node* temp = root-&gt;right;
free(root);
return temp;
} else if (root-&gt;right == NULL) {
struct Node* temp = root-&gt;left;
free(root);
return temp;
}
struct Node* temp = minValueNode(root-&gt;right);
root-&gt;key = temp-&gt;key;
root-&gt;right = deleteNode(root-&gt;right, temp-&gt;key);
}

return root;
}

void inorder(struct Node* root) {
if (root != NULL) {
inorder(root-&gt;left);
printf(&quot;%d &quot;, root-&gt;key);
inorder(root-&gt;right);
}
}

int main() {
struct Node* root = NULL;
int n, val, del;

printf(&quot;Enter number of nodes to insert: &quot;);
scanf(&quot;%d&quot;, &amp;n);

printf(&quot;Enter %d values:\n&quot;, n);
for (int i = 0; i &lt; n; i++) {
scanf(&quot;%d&quot;, &amp;val);
root = insert(root, val);

}

printf(&quot;Inorder before deletion:\n&quot;);
inorder(root);

printf(&quot;\nEnter value to delete: &quot;);
scanf(&quot;%d&quot;, &amp;del);
root = deleteNode(root, del);

printf(&quot;Inorder after deletion:\n&quot;);
inorder(root);

return 0;
}

// Code C :- Inorder transversal

#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;

struct Node {
int key;
struct Node *left, *right;
};

struct Node* newNode(int item) {
struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
temp-&gt;key = item;
temp-&gt;left = temp-&gt;right = NULL;
return temp;
}

struct Node* insert(struct Node* node, int key) {
if (node == NULL) return newNode(key);
if (key &lt; node-&gt;key)

node-&gt;left = insert(node-&gt;left, key);
else if (key &gt; node-&gt;key)
node-&gt;right = insert(node-&gt;right, key);
return node;
}

void inorder(struct Node* root) {
if (root != NULL) {
inorder(root-&gt;left);
printf(&quot;%d &quot;, root-&gt;key);
inorder(root-&gt;right);
}
}

int main() {
struct Node* root = NULL;
int n, val;

printf(&quot;Enter number of nodes: &quot;);
scanf(&quot;%d&quot;, &amp;n);

printf(&quot;Enter %d values:\n&quot;, n);
for (int i = 0; i &lt; n; i++) {
scanf(&quot;%d&quot;, &amp;val);
root = insert(root, val);
}

printf(&quot;Inorder Traversal of BST:\n&quot;);
inorder(root);

return 0;
}

