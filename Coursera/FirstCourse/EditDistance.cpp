#include <iostream>
using namespace std;

int output_alignemt(int first_size_const, int second_size_const, int first_size, int second_size, int * D, int first[], int second[])
{
    if (first_size == 0 && second_size == 0)
        return 0;
    if (first_size > 0 && D[first_size * first_size_const + second_size] == D[(first_size - 1) * first_size_const + second_size] + 1)
    {
        output_alignemt(first_size_const, second_size_const, first_size - 1, second_size, D, first, second);
        cout << char(first[first_size - 1]) << " ";
    }
    else if (second_size > 0 && D[first_size * first_size_const + second_size] == D[first_size * first_size_const + second_size - 1] + 1)
    {
        output_alignemt(first_size_const, second_size_const, first_size, second_size - 1, D, first, second);
        cout << "_" << " ";
    }
    else
    {
        output_alignemt(first_size_const, second_size_const, first_size - 1, second_size - 1, D, first, second);
        cout << char(first[first_size - 1]) << " ";
    }
}

int edit_distance(int first_size, int second_size, int first[], int second[])
{
    int D[first_size][second_size];
    for (int i = 0; i < first_size; ++i)
    {
        D[i][0] = i;
    }
    for (int j = 0; j < second_size; ++j)
    {
        D[0][j] = j;
    }
    for (int j = 1; j < second_size; ++j)
    {
        for (int i = 1; i < first_size; ++i)
        {
            int insertion = D[i][j - 1] + 1;
            int deletion = D[i - 1][j] + 1;
            int match = D[i - 1][j - 1];
            int mismatch = D[i - 1][j - 1] + 1;
            if (first[i] == second[j])
                D[i][j] = min(insertion, min(deletion, match));
            else
                D[i][j] = min(insertion, min(deletion, mismatch));
        }
    }
    for (int i = 0; i < first_size; ++i)
    {
        for (int j = 0; j < second_size; ++j)
            {
                cout << D[i][j] << " ";
            }
        cout << endl;
    }
    cout << endl;
    output_alignemt(first_size, second_size, first_size, second_size, *D, first, second);
}

int main()
{
    string first_word, second_word;
    cin >> first_word >> second_word;
    int first[first_word.size() + 1], second[second_word.size()];
    first[0] = 0;
    second[0] = 0;
    int first_size = first_word.size() + 1;
    int second_size = second_word.size() + 1;
    for (int i = 1; i < first_size; ++i)
    {
        first[i] = first_word[i - 1];
    }
    for (int i = 1; i < second_size; ++i)
    {
        second[i] = second_word[i - 1];
    }
    edit_distance(first_size, second_size, first, second);
}