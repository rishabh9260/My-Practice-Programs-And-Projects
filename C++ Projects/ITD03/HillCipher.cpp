#include<stdio.h>
#include<iostream>
#define N 3

using namespace std;

int modInverse(int a, int m)
{ 
    a=a%m; 
    for(int x=-m;x<m;x++) 
       if((a*x)%m==1) 
          return x;
    return 1;
} 

void getCofactor(int A[N][N], int temp[N][N], int p, int q, int n) 
{ 
    int i = 0, j = 0; 

    for (int row = 0; row < n; row++) 
    { 
        for (int col = 0; col < n; col++) 
        { 
            if (row != p && col != q) 
            { 
                temp[i][j++] = A[row][col]; 

                if (j == n - 1) 
                { 
                    j = 0; 
                    i++; 
                } 
            } 
        } 
    } 
} 
  
int determinant(int A[N][N], int n) 
{ 
    int D = 0;
    if (n == 1) 
        return A[0][0]; 
  
    int temp[N][N]; 
  
    int sign = 1;

    for (int f = 0; f < n; f++) 
    { 
        getCofactor(A, temp, 0, f, n); 
        D += sign * A[0][f] * determinant(temp, n - 1); 
  
        sign = -sign; 
    } 
  
    return D; 
} 

void adjoint(int A[N][N],int adj[N][N]) 
{ 
    if (N == 1) 
    { 
        adj[0][0] = 1; 
        return; 
    } 

    int sign = 1, temp[N][N]; 
  
    for (int i=0; i<N; i++) 
    { 
        for (int j=0; j<N; j++) 
        {
            getCofactor(A, temp, i, j, N); 
  
            sign = ((i+j)%2==0)? 1: -1; 

            adj[j][i] = (sign)*(determinant(temp, N-1)); 
        } 
    } 
} 

bool inverse(int A[N][N], int inverse[N][N]) 
{ 
    int det = determinant(A, N);
    if (det == 0) 
    { 
        cout << "Singular matrix, can't find its inverse"; 
        return false; 
    } 
 
    det = modInverse(det, 26);
    int adj[N][N]; 
    adjoint(A, adj); 

    for (int i=0; i<N; i++) 
        for (int j=0; j<N; j++) 
            inverse[i][j] = (adj[i][j]*(det))%26; 
  
    return true; 
} 
int check(int x)
{
    if (x % 3 == 0)
        return 0;
 
    int a = x / 3;
    int b = 3 * (a + 1);
    int c = b - x;
 
    return c;
}
 
int main(int argc, char **argv)
{
    int l, i, j;
    int temp1;
    int k[3][3];
    int p[3][1];
    int c[3][1];
    int inv[3][3];
    char ch;
    bool inv_check;
    cout << "\nThis cipher has a key of length 9. ie. a 3*3 matrix.\nEnter the 9 character key. ";
 
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            scanf("%c", &ch);
            if (65 <= ch && ch <= 91)
                k[i][j] = (int) ch % 65;
            else
                k[i][j] = (int) ch % 97;
        }
    }

    inv_check = inverse(k, inv);
    if(!inv_check)
    {
        cout<<"\nInvalid Key! Exiting!!";
        return 0;
    }

    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            cout << k[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "\nEnter the length of string to be encoded(without spaces). ";
    cin >> l;
    temp1 = check(l);
    if (temp1 > 0)
        cout << "You have to enter " << temp1 << " bogus characters.";
 
    char pi[l + temp1];
    cout << "\nEnter the string. ";
    for (i = 0; i < l + temp1; ++i)
    {
        cin >> pi[i];
    }
    int temp2 = l;
    int n = (l + temp1) / 3;
    int temp3;
    int flag = 0;
    int count;
    string s = "";
    cout << "\n\nThe encoded cipher is : ";
 
    while (n > 0)
    {
        int x = 0;
        count = 0;
        for (i = flag; i < flag + 3; ++i)
        {
            if (65 <= pi[i] && pi[i] <= 91)
                temp3 = (int) pi[i] % 65;
            else
                temp3 = (int) pi[i] % 97;
 
            p[count][0] = temp3;
            count = count + 1;
        }
 
        int k1;
        for (i = 0; i < 3; ++i)
            c[i][0] = 0;
 
        for (i = 0; i < 3; ++i)
        {
            for (j = 0; j < 1; ++j)
            {
                for (k1 = 0; k1 < 3; ++k1)
                    c[i][j] += k[i][k1] * p[k1][j];
            }
        }
        for (i = 0; i < 3; ++i)
        {
            c[i][0] = c[i][0] % 26;
            s += ((char) (c[i][0] + 97));
            printf("%c ", (char) (c[i][0] + 97));
        }
        n = n - 1;
        flag = flag + 3;
        x++;
    }
    cout<<"\nThe decoded string is: ";
    int a=0;
    string ans;
    while(a<s.size())
    {
        for(i=0;i<3;i++)
        {
            int sum = 0;
            int temp = a;
            for(j=0;j<3;j++)
            {
                sum += ((inv[i][j] + 26)%26*(s[temp++]-'a')%26)%26;
                sum = sum%26;
            }
            ans+=(sum+'a');
        }
        a+=3;
    }
    int f=ans.size()-1;
    while(ans[f]=='x')
    {
        f--;
    }
    for(i=0;i<=f;i++)
    {
        cout<<ans[i];
    }
}