#include <bits/stdc++.h>
using namespace std;

class NaiveBayes
{
private:
    // <class id, class probility> <C, P(C)>
    unordered_map<int, double> classes;
    // <class id, <attribute id, probability>> <C, <x, P(x|C)>>
    unordered_map<int, unordered_map<int, double>> attriPerClass;
    vector<string> fname, cname;
    unordered_map<int, unordered_map<string, int>> amap;

public:
    // input: vector< pair < class id, attribute id>> , f_size is the number of Features
    NaiveBayes(vector<vector<int>> &data, vector<string> features, vector<string> classvals, unordered_map<int, unordered_map<string, int>> attrimap, int f_size)
    {
        fname = features;
        cname = classvals;
        amap = attrimap;
        for (auto entry : data)
        {
            if (classes.find(entry[0]) == classes.end())
            {
                classes[entry[0]] = 1;
                unordered_map<int, double> prob_x_c;
                attriPerClass[entry[0]] = prob_x_c;
            }
            else
            {
                classes[entry[0]]++;
            }
            for (int i = 1; i <= f_size; i++)
            {
                if (attriPerClass[entry[0]].find(entry[i]) == attriPerClass[entry[0]].end())
                {
                    attriPerClass[entry[0]][entry[i]] = 1;
                }
                else
                {
                    attriPerClass[entry[0]][entry[i]]++;
                }
            }
        }

        for (auto c : attriPerClass)
        {
            cout << "\n\nProbabilities for Class " << cname[c.first] << ": " << endl
                 << endl;
            for (auto entry : c.second)
            {
                string s;
                int val = entry.first;
                int x = 0;
                for (int i = 0; i < f_size; i++)
                {
                    auto result = find_if(amap[i].begin(), amap[i].end(), [val](const auto &mo) { return mo.second == val; });
                    if (result != amap[i].end())
                    {
                        x = i;
                        s = result->first;
                    }
                }
                entry.second /= classes[c.first];
                cout << "P(" << fname[x] << " = " << s << " | C = " << cname[c.first] << ") = " << entry.second << endl;
                attriPerClass[c.first][entry.first] = entry.second;
            }
            classes[c.first] /= data.size();
            cout << "Class P(C = " << cname[c.first] << ") = " << classes[c.first] << endl
                 << endl;
        }
    }
    // predict class with attributes vector<attribute ids>
    void predict(vector<int> attributes)
    {
        int maxc = -1;
        double maxp = 0;
        for (auto c : classes)
        {
            // p(C|x) = p(C)*p(x1|C)*p(x2|C)*…
            double pCx = c.second;
            for (int i = 0; i < attributes.size(); i++)
            {
                pCx *= attriPerClass[c.first][attributes[i]];
            }
            if (pCx > maxp)
            {
                maxp = pCx;
                maxc = c.first;
            }
        }
        cout << "\nPredicted Class : " << cname[maxc] << "\nP(C | X) = " << maxp << endl;
    }
};

int main()
{
    unordered_map<string, int> classmap;
    unordered_map<int, unordered_map<string, int>> attrimap;

    int f = 0, c = 0, n = 0;

    cout << "Enter Number of Features: ";
    cin >> f;

    vector<string> features(f, "");
    for (int i = 0; i < f; i++)
    {
        cout << "\nEnter Feature " << (i + 1) << ": ";
        cin >> features[i];
    }

    cout << "\nEnter Number of Classes: ";
    cin >> c;

    vector<string> classes(c, "");
    for (int i = 0; i < c; i++)
    {
        string s;
        cout << "\nEnter Class " << (i + 1) << ": ";
        cin >> s;
        classes[i] = s;
        classmap[s] = i;
    }

    cout << "\nEnter Number of Entries: ";
    cin >> n;
    //Stores values as [class id, feature 1 attribute id, feature 2 attribute id....] [C, x1, x2, x3.....]
    vector<vector<int>> dataset;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "\n----ENTRY " << (i + 1) << "----";
        vector<int> dataEntry((f + 1), 0);
        for (int j = 0; j < f; j++)
        {
            string s;
            cout << "\nEnter value of " << features[j] << ": ";
            cin >> s;
            if (attrimap[j].find(s) == attrimap[j].end())
            {
                attrimap[j][s] = k++;
            }
            dataEntry[j + 1] = attrimap[j][s];
        }
        cout << "\nEnter the Class it belongs: ";
        string s;
        cin >> s;
        dataEntry[0] = classmap[s];
        dataset.push_back(dataEntry);
    }

    NaiveBayes mymodel(dataset, features, classes, attrimap, f);

    vector<int> v1(f, 0);
    cout << "\n\nEnter the Data for making prediction of class: ";
    for (int i = 0; i < f; i++)
    {
        cout << "\nEnter value of " << features[i] << ": ";
        string s;
        cin >> s;
        v1[i] = attrimap[i][s];
    }

    mymodel.predict(v1);

    return 0;
}