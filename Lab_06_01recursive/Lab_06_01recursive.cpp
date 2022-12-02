#include <iostream> 
#include <iomanip> 
#include <time.h> 

using namespace std;

void Generate(int* t, const int n, const int i, const int low, const int high)
{
		t[i] = low + rand() % (high - low + 1);
		if (i < n - 1)
			Generate(t, n, i + 1, low, high);
}

void Display(int* t, const int n, const int i)
{
		cout << t[i] << " ";
		if (i < n - 1)
			Display(t, n, i + 1);
}

int Count(int* t, int count, const int i, const int n)
{
	if (i < n)
	{
		if (t[i] > 0 && i % 4 != 0)
		{
			count++;
			Count(t, count, i + 1, n);
		}
		else
			Count(t, count, i + 1, n);
	}
	else
		return count;
}

int Sum(int* t, int sum, const int i, const int n)
{
	if (t[i] > 0 && i % 4 != 0)
		sum += t[i];
	if (i < n - 1)
		return Sum(t, sum, i + 1, n);
	else
		return sum;
}

void Replace(int* t, const int i, const int n)
{ 
		if (t[i] > 0 && i % 4 != 0)
			t[i] = 0;
		if (i < n - 1)
		    Replace(t, i + 1, n);
}

int main()
{
	srand((unsigned)time(NULL));

	const int n = 20;
	int t[n];
	const int i = 0;
	int count = 0;
	int sum = 0;
	const int low = -14;
	const int high = 7;

	Generate(t, n, i, low, high);
	cout << "Generated array:" << endl;
	cout << "t[20] = { ";
	Display(t, n, i);
	cout << "}" << "\n";
	cout << "Number of matching elements: " << Count(t, count, i, n) << "\n";
	cout << "The sum of the matching elements: " << Sum(t, sum, n, i) << endl << "\n";
	cout << "Replacing matching elements with 0: " << endl;
	cout << "t[20] = { ";
	Replace(t, i, n);
	Display(t, n, i);
	cout << "}";
	cout << endl;

	system("pause");
	return 0;
}