#include <iostream>
#include <vector>
#include <ctime>

//вывод
void print(const std::vector<int>& vec)
{
    for (int v : vec)
        std::cout << v << ' ';
    std::cout << std::endl;
}

//1
void coctail_sort (std::vector<int>& vec)
{
    int zam;
    //int control=vec.size();
    int control;
    int left = 0;
    int right = vec.size() - 1;
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (vec[i] > vec[i + 1]) {
                zam = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = zam;
                control=i;
            }
        }
        right=control;
        for (int i = right; i > left; i--) {
            if (vec[i] < vec[i - 1]) {
                zam = vec[i];
                vec[i] = vec[i - 1];
                vec[i - 1] = zam;
                control=i;
            }
        }
        left=control;
    }
    
}

//2
int forquicksort(std::vector<int> &vec, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = vec[pivotIndex];
    int i = left, j = right;
    int temp;
    while(i <= j)
    {
        while(vec[i] < pivotValue) {
            i++;
        }
        while(vec[j] > pivotValue) {
            j--;
        }
        if(i <= j) {
            temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            i++;
            j--;
        }
        
    }
    return i;
}

void quick_sort(std::vector<int> &vec, int left, int right) {
    if(left < right) {
        int pivotIndex = forquicksort(vec, left, right);
        quick_sort(vec, left, pivotIndex - 1);
        quick_sort(vec, pivotIndex, right);
    }
}

//3
void shell_sort(std::vector<int> &vec, int n)
{
    int zam, j;
    int d = n / 2;
    while (d > 0)
    {
        for (int i = 0; i < n - d; i++)
        {
            j = i;
            while (j >= 0 && vec[j] > vec[j + d])
            {
                zam = vec[j];
                vec[j] = vec[j + d];
                vec[j + d] = zam;
                j--;
            }
        }
        d = d / 2;
    }
}


int main()
{
    srand(time(0));
    std::vector<int> vec;
    std::cout <<"Coctail Sort\n";
    for (int i=0; i<30; i++)
        vec.push_back(rand()%201 - 100);
    print(vec);
    coctail_sort(vec);
    print(vec);
    
    vec.clear();
    
    std::cout <<"Quick Sort\n";
    for (int i=0; i<30; i++)
        vec.push_back(rand()%201 - 100);
    print(vec);
    quick_sort(vec, 0, (vec.size()-1)); //указываю с какого по какой сортировать
    print(vec);
    
    vec.clear();
    
    std::cout <<"Shell Sort\n";
    for (int i=0; i<30; i++)
        vec.push_back(rand()%201 - 100);
    //std::vector<int> myVec{ 0, -1, 2, -3, 4, 1 };
  //  std::cout << vec.size()-1<<"\n";
    print(vec);
    shell_sort(vec, vec.size());
    print(vec);
    return 0;
}
