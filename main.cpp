#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
unsigned int PRNG()
{
    static unsigned int seed = 4541;
    seed = (8253729 * seed + 2396403);
    return seed % 32768;
}
int main() {
    int M; // матрица размером MxM
    cin>>M;
    if(M>5||M<2){ //Проверка:  2<=M<=5
        cout<<"Неверный размер матрицы"<<endl;
        return 0;
    }
    int array [M][M]; // создание матрицы размером MxM
    string CMND;
    cout<<"Если хотите заполнить матрицу сами , то введите +, если хотите автоматическое заполнение"<<
    " то, введите любую последовательность символов"<<endl;
    cin>>CMND;
    if(CMND=="+"){
        int b;// Для проверки вводимых значений
        cout<<"Введите значение из диапозона [1,100]"<<endl;
        for(int i=0;i<M;i++){
         for(int j=0;j<M;j++){
             cin>>b;
             if(b>=1&&b<=100){
                 array[i][j]=b;
             }else{
                 cout<<"Введено неверное число"<<endl;
                 return 0;
             }
         }
        }
        cout<<"Матрица отсортирована"<<endl;
    }else{
        int a;
        int b;
        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
                a=PRNG();
                b=round(100*a/32768);
                array[i][j]=b;
            }
        }
        cout<<"Матрица отсортирована"<<endl;
    }
    vector <int> toSort;// вектор для элементов побочной оси
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            if(array[i][j]==array[i][M-1-i]){    //запись элементов побочной оси в вектор
                toSort.push_back(array[i][j]);
            }else{
                array[i][j]*=-1;  //умножение остальных элементов на -1
            }
        }
    }
    sort(toSort.begin(),toSort.end()); //сортировка вектора с элементами побочной оси
    for(int i=0;i<M;i++){
        array[i][M-1-i]=toSort[M-1-i];  //запись элементов побочной оси в порядке убывания
    }
    cout<<"Введите N"<<endl;
    int N;//N-номер минимума
    cin>>N;
    if(N>M){
        cout<<"Неверный номер минимума"<<endl;
    }else{
        cout<<N<<" минимум"<<toSort[N-1]<<endl;
    }

    cout<<"Отсортированная матрица: "<<endl;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            cout<<setw(3)<<array[i][j]<<" ";
        }
        cout<<endl;
    }

}
