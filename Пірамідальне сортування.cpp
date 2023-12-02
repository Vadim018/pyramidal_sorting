#include <iostream>
#include <cmath>
using namespace std;

void RestoreHeap(int m[], int father, int last_N)
{
    while (father <= last_N / 2)
    {
        int maxson = 2 * father;
        if (2 * father + 1 <= last_N && m[2 * father] < m[2 * father + 1]) 
            maxson = 2 * father + 1;
        if (m[maxson] > m[father])
        {
            swap(m[maxson], m[father]);
            father = maxson;
        }
        else return;
    }
}

void HeapSort(int m[], int N)
{
    for (int i = N / 2; i >= 1; i--)
        RestoreHeap(m, i, N);
    for (int i = N; i > 1; i--)
    {
        swap(m[1], m[i]); // обмін
        RestoreHeap(m, 1, i - 1);
    }
}

void read_mas(int m[], int& N) // читання масиву
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> m[i];
}

void write_mas(int m[], int N) // виведення масиву
{
    for (int i = 1; i <= N; i++)
        cout << m[i] << " ";
}

int main()
{
    setlocale(LC_ALL, "Ukr");
    int m[255], N;

    read_mas(m, N);
    HeapSort(m, N);
    write_mas(m, N);

    return 0;
}