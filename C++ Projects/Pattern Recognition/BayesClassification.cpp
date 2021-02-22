#include <bits/stdc++.h>
using namespace std;

int getIndex(vector<string> c, string f)
{
    auto it = find(c.begin(), c.end(), f);
    int index = 0;
    if (it != c.end())
    {
        index = it - c.begin();
    }
    else
    {
        return -1;
    }
    return index;
}

int main()
{
    string feature;
    cout << "Enter Feature Name: ";
    getline(cin, feature);
    int c = 0, n = 0, v = 0;
    cout << "\nEnter number of classes: ";
    cin >> c;
    cout << "\nEnter number of feature values: ";
    cin >> v;
    vector<string> classes(c, ""), values(v, "");
    vector<int> c_sum(c, 0), v_sum(v, 0);
    cout << "\nEnter the number of entries you wish to provide: ";
    cin >> n;
    cout << "\nEnter your entries as \'feature value\' space \'class name\'\n";
    vector<vector<int>> mat(v, vector<int>(c, 0));
    int v_count = 0, c_count = 0;
    for (int f = 0; f < n; f++)
    {
        string a, b;
        cin >> a >> b;
        int i = 0, j = 0;
        if (getIndex(values, a) != -1)
        {
            i = getIndex(values, a);
            v_sum[i]++;
        }
        else
        {
            values[v_count] = a;
            i = v_count++;
            v_sum[i]++;
        }
        if (getIndex(classes, b) != -1)
        {
            j = getIndex(classes, b);
            c_sum[j]++;
        }
        else
        {
            classes[c_count] = b;
            j = c_count++;
            c_sum[j]++;
        }
        mat[i][j]++;
    }

    cout << "\n\nValues Inputted:\n\n";
    for (int i = 0; i < v + 1; i++)
    {
        for (int j = 0; j < c + 1; j++)
        {
            if (i == 0 && j == 0)
                cout << setw(10) << feature;
            else if (i == 0)
                cout << setw(10) << classes[j - 1];
            else if (j == 0)
                cout << setw(10) << values[i - 1];
            else
                cout << setw(10) << mat[i - 1][j - 1];
        }
        cout << endl;
    }

    cout << "\n\nThe Probabilities are: \n";
    vector<vector<double>> probabilities(v, vector<double>(c, 0));
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < c; j++)
        {
            double prb = ((double)mat[i][j]) / c_sum[j];
            prb *= (((double)c_sum[j]) / n) / (((double)v_sum[i]) / n);
            probabilities[i][j] = prb;
            cout << setprecision(3) << "P(" << classes[j] << " | " << values[i] << ") = " << prb << "\n";
        }
        cout << endl;
    }

    string test;
    cout << "\n\nEnter the value of " << feature << " for getting the class: ";
    cin >> test;
    int x = getIndex(values, test);
    int y = max_element(probabilities[x].begin(), probabilities[x].end()) - probabilities[x].begin();
    cout << "The class " << test << " belongs to is \"" << classes[y] << "\"\n\n";
    return 0;
}