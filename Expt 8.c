#include &lt;stdio.h&gt;
#include &lt;ctype.h&gt;

#include &lt;string.h&gt;

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
if (top == MAX - 1)
printf(&quot;Stack Overflow\n&quot;);
else
stack[++top] = c;
}

char pop() {
if (top == -1)
return -1;
else
return stack[top--];
}

int precedence(char c) {
if (c == &#39;^&#39;)

return 3;
else if (c == &#39;*&#39; || c == &#39;/&#39; || c == &#39;%&#39;)
return 2;
else if (c == &#39;+&#39; || c == &#39;-&#39;)
return 1;
else
return 0;
}

int isOperator(char c) {
return (c == &#39;+&#39; || c == &#39;-&#39; || c == &#39;*&#39; || c == &#39;/&#39; || c == &#39;%&#39; || c == &#39;^&#39;);
}

void infixToPostfix(char infix[]) {
char postfix[MAX];
int i = 0, k = 0;
char ch;

while ((ch = infix[i++]) != &#39;\0&#39;) {
if (isalnum(ch)) {
postfix[k++] = ch; // operand
}
else if (ch == &#39;(&#39;) {

push(ch);
}
else if (ch == &#39;)&#39;) {
while (top != -1 &amp;&amp; stack[top] != &#39;(&#39;)
postfix[k++] = pop();
if (top != -1 &amp;&amp; stack[top] == &#39;(&#39;)
pop();
}
else if (isOperator(ch)) {
while (top != -1 &amp;&amp; precedence(stack[top]) &gt;= precedence(ch))
postfix[k++] = pop();
push(ch);
}
}

while (top != -1)
postfix[k++] = pop();

postfix[k] = &#39;\0&#39;;
printf(&quot;\nPostfix Expression: %s\n&quot;, postfix);
}

int main() {

char infix[MAX];
printf(&quot;Enter an Infix Expression: &quot;);
gets(infix);
infixToPostfix(infix);
return 0;
}