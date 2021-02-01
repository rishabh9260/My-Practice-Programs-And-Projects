#include <bits/stdc++.h>
using namespace std;

int e = 4, r = 10;
int dst = 0;
string decoded_string = "";
string nyt_code = "";
string fixed_code = "";
string symbol_code = "";

class node
{
public:
    int cnt;
    char data;
    node *left;
    node *right;
    node(char d)
    {
        this->cnt = 0;
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
    node(char d, int c)
    {
        this->cnt = c;
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

int PRINT_TREE(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *tmp = q.front();
        q.pop();
        if (tmp == NULL)
        {
            if (q.size() > 0)
            {
                q.push(NULL);
            }
            cout << '\n';
        }
        else
        {
            cout << "[ " << tmp->data << " " << tmp->cnt << " ]"
                 << " ";
            if (tmp->left != NULL)
            {
                q.push(tmp->left);
            }
            if (tmp->right != NULL)
            {
                q.push(tmp->right);
            }
        }
    }
    return 0;
}
int NYTCODE(node *root, string t)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == '#')
    {
        nyt_code = t;
        return 0;
    }
    NYTCODE(root->left, t + '0');
    NYTCODE(root->right, t + '1');
    return 0;
}

int FIXED_CODE(char c)
{
    int k = (c - 'a') + 1;
    string t = "";
    if (k <= 2 * r)
    {
        k--;
        while (k)
        {
            if (k % 2 == 1)
            {
                t = '1' + t;
            }
            else
            {
                t = '0' + t;
            }
            k = k / 2;
        }
        while (t.size() < (e + 1))
        {
            t = '0' + t;
        }
        fixed_code = t;
        return 0;
    }
    else
    {
        k = k - r - 1;
        while (k)
        {
            if (k % 2 == 1)
            {
                t = '1' + t;
            }
            else
            {
                t = '0' + t;
            }
            k = k / 2;
        }
        while (t.size() < (e))
        {
            t = '0' + t;
        }
        fixed_code = t;
        return 0;
    }
    return 0;
}

int SYMBOL_CODE(node *root, char c, string t)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == c)
    {
        symbol_code = t;
        return 0;
    }
    SYMBOL_CODE(root->left, c, t + '0');
    SYMBOL_CODE(root->right, c, t + '1');
    return 0;
}

int INCREMENT(char c, node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == c)
    {
        int a = root->cnt;
        root->cnt = a + 1;
        return 0;
    }
    INCREMENT(c, root->left);
    INCREMENT(c, root->right);
    int a = 0, b = 0;
    if (root->left != NULL)
    {
        a = root->left->cnt;
    }
    if (root->right != NULL)
    {
        b = root->right->cnt;
    }
    if (root->data == '@')
        root->cnt = a + b;
    return 0;
}
int INSERT(char c, node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == '#')
    {
        root->left = new node('#', 0);
        root->right = new node(c, 1);
        root->data = '@';
        root->cnt = root->left->cnt + root->right->cnt;
        return 0;
    }
    INSERT(c, root->left);
    INSERT(c, root->right);
    int a, b;
    a = 0, b = 0;
    if (root->left != NULL)
    {
        a = root->left->cnt;
    }
    if (root->right != NULL)
    {
        b = root->right->cnt;
    }
    if (root->data == '@')
        root->cnt = a + b;
    return 0;
}

int CHECK(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    CHECK(root->left);
    CHECK(root->right);
    if (root->left != NULL && root->right != NULL)
    {
        if (root->left->cnt > root->right->cnt)
        {
            node *temp1 = root->left;
            node *temp2 = root->right;
            root->left = temp2;
            root->right = temp1;
        }
    }
    return 0;
}

int DECODE(string encode, node *root)
{
    if (dst == encode.size())
    {
        return 0;
    }
    if (encode[dst] == '0')
    {
        if (root->left != NULL)
        {
            dst++;
            DECODE(encode, root->left);
        }
        else
        {
            if (root->data == '#')
            {
                int c = 0;
                int k = 0;
                while (dst < encode.size() && c < e)
                {
                    k = k * 2;
                    if (encode[dst] == '1')
                    {
                        k++;
                    }
                    dst++;
                    c++;
                }
                if (k < r)
                {
                    if (dst < encode.size())
                    {
                        k = k * 2;
                        if (encode[dst] == '1')
                        {
                            k++;
                        }
                        dst++;
                    }
                }

                decoded_string += (char(k + 'a'));
            }
            else
            {
                decoded_string += (root->data);
            }
        }
    }
    else
    {
        if (root->right != NULL)
        {
            dst++;
            DECODE(encode, root->right);
        }
        else
        {
            if (root->data == '#')
            {
                int c = 0;
                int k = 0;
                while (dst < encode.size() && c < e)
                {
                    k = k * 2;
                    if (encode[dst] == '1')
                    {
                        k++;
                    }
                    dst++;
                    c++;
                }
                if (k < r)
                {
                    if (dst < encode.size())
                    {
                        k = k * 2;
                        if (encode[dst] == '1')
                        {
                            k++;
                        }
                        dst++;
                    }
                }
                else
                {
                    k = k + r;
                }

                decoded_string += (char(k + 'a'));
            }
            else
            {
                decoded_string += (root->data);
            }
        }
    }
    return 0;
}
int main()
{
    string s;
    cout << "Enter the string to be encoded: ";
    cin >> s;
    bool encode_visited[26];
    memset(encode_visited, false, sizeof encode_visited);
    // '#' for nyt node
    // '@' internal node
    node *encode_root = new node('#');
    string encoded_string = "";
    for (int i = 0; i < s.size(); i++)
    {
        nyt_code = "";
        fixed_code = "";
        symbol_code = "";
        if (!encode_visited[s[i] - 'a'])
        {
            NYTCODE(encode_root, "");
            FIXED_CODE(s[i]);
            encoded_string += nyt_code;
            encoded_string += fixed_code;
            INSERT(s[i], encode_root);
            encode_visited[s[i] - 'a'] = true;
        }
        else
        {
            SYMBOL_CODE(encode_root, s[i], "");
            encoded_string += symbol_code;
            INCREMENT(s[i], encode_root);
        }
        CHECK(encode_root);
        //PRINT_TREE(encode_root);
    }

    cout << "\nThe encoded string is " << encoded_string << '\n';

    bool decode_visited[26];
    memset(decode_visited, false, sizeof decode_visited);
    node *decode_root = new node('#');
    while (dst < encoded_string.size())
    {
        DECODE(encoded_string, decode_root);
        int h = decoded_string.size();
        char c = decoded_string[h - 1];
        if (!decode_visited[c - 'a'])
        {
            INSERT(c, decode_root);
            decode_visited[c - 'a'] = true;
        }
        else
        {
            INCREMENT(c, decode_root);
        }
        CHECK(decode_root);
        //PRINT_TREE(decode_root);
    }
    cout << "\nThe string after decoding is " << decoded_string << '\n';
}