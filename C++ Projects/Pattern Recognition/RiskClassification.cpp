#include <bits/stdc++.h>
using namespace std;

class TextClassification
{
    // <class, <word, count of occurences of the word>>
    map<string, map<string, int>> data;
    // <class, <class occurences, words in class>>
    map<string, pair<size_t, size_t>> _class_data;
    size_t vocabulary_count, total_entries;

public:
    TextClassification(vector<pair<string, string>> &);
    vector<double> classify(const string &);
    void risk_calculation(const vector<string> &, const string &);
};

void TextClassification::risk_calculation(const vector<string> &actions, const string &test_data)
{
    auto probabilities = this->classify(test_data);
    vector<vector<double>> loss(_class_data.size(), vector<double>(actions.size(), 0));
    cout << "Enter Loss Function Values\n";
    size_t i(0), j(0);
    for (const auto &[x, y] : data)
    {
        for (const auto &z : actions)
        {
            cout << "\tLoss(" << z << " | " << x << "): ";
            cin >> loss[i][j++];
        }
        i++;
        j = 0;
    }

    cout << "\n\n";
    vector<double> risk(actions.size(), 0.);
    for (size_t i = 0; i < risk.size(); i++)
    {
        for (size_t j = 0; j < data.size(); j++)
            risk[i] += loss[j][i] * probabilities[j];
    }

    cout << "\n\nRisk functions valus are\n";
    for (size_t i = 0; i < actions.size(); i++)
        cout << "Risk(" << actions[i] << " | "
             << "X): " << risk[i] << '\n';
    size_t index = min_element(risk.begin(), risk.end()) - risk.begin();
    cout << "\nThus the action that will be taken is Action " << index + 1 << " that is \'" << actions[index] << "\'\n\n";
}

vector<double> TextClassification::classify(const string &test_data)
{
    vector<double> probabilities(data.size(), 1.00);
    size_t i = 0;
    string s, final_class;
    double max_probability = 0;

    for (auto &[_class, _map] : data)
    {
        stringstream str(test_data);
        while (str >> s)
        {
            double p = 1.00;
            if (_map.find(s) != _map.end())
                p += _map[s];
            probabilities[i] *= p / (double)(_class_data[_class].second + vocabulary_count);
        }
        probabilities[i] *= (double)(_class_data[_class].first) / ((double)total_entries);
        cout << "P(" << _class << " | X) = " << probabilities[i] << '\n';
        if (max_probability < probabilities[i])
        {
            max_probability = probabilities[i];
            final_class = _class;
        }
        i++;
    }
    cout << "\nThe inputted text will belong to " << final_class << " class";
    return probabilities;
}

TextClassification::TextClassification(vector<pair<string, string>> &entries) : data(map<string, map<string, int>>()), _class_data(map<string, pair<size_t, size_t>>()), vocabulary_count(0), total_entries(entries.size())
{
    for (auto [x, y] : entries)
    {
        string s;
        stringstream str(x);
        _class_data[y].first++;
        while (str >> s)
            data[y][s]++;
    }

    map<string, bool> vocabulary;
    for (auto [_class, _map] : data)
        for (auto [_word, _count] : _map)
        {
            vocabulary[_word] = true;
            _class_data[_class].second += _count;
        }

    vocabulary_count = vocabulary.size();
}

int main()
{
    size_t entries_count;
    cout << "Enter number of entries you wish to provide : ";
    cin >> entries_count;

    vector<pair<string, string>> entries;
    entries.reserve(entries_count);

    cout << "\nProvide the entries:";
    for (size_t i = 0; i < entries_count; i++)
    {
        string x, y;
        cout << "\nEntry " << i + 1 << ": ";
        cin.ignore(100, '\n');
        getline(cin, x, '\n');
        cout << "Enter the class: ";
        cin >> y;
        entries.emplace_back(x, y);
    }

    TextClassification textClassification(entries);

    string test_data;
    cout << "\n\nEnter the Test Data(X) for classification: ";
    cin.ignore(100, '\n');
    getline(cin, test_data, '\n');
    cout << '\n';

    size_t actions_count;
    cout << "\nEnter number of actions: ";
    cin >> actions_count;

    vector<string> actions;
    actions.reserve(actions_count);
    for (size_t i = 0; i < actions_count; i++)
    {
        string x;
        cout << "\tEnter the action " << i + 1 << ": ";
        cin >> ws;
        getline(cin, x, '\n');
        actions.emplace_back(x);
    }

    textClassification.risk_calculation(actions, test_data);
}