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
    int M; // Размер матрицы MxM
    cin>>M;
    if(M>5||M<2){ //Проверка на 2<=M<=5
        cout<<"Неверная величина матрицы"<<endl;
        return 0;
    }
    int array [M][M]; // Создали матрицу размером MxM
    string CMND;
    cout<<"Если хотите ввести значения матрицы самостоятельно-напишите + "
          ", если нет , то напишите любой другой символ/комбинацию символов"<<endl;
    cin>>CMND;
    if(CMND=="+"){
        int b;// Используется для проверки вводимых значений
        cout<<"Вводите целые числа из диапозона [1,100]"<<endl;
        for(int i=0;i<M;i++){
         for(int j=0;j<M;j++){
             cin>>b;
             if(b>=1&&b<=100){
                 array[i][j]=b;
             }else{
                 cout<<"Неверно введеное значение"<<endl;
                 return 0;
             }
         }
        }
        cout<<"Матрица заполнена"<<endl;
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
        cout<<"Массив заполнен"<<endl;
    }
    vector <int> toSort;// вектор для элементов побочной оси
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            if(array[i][j]==array[i][M-1-i]){    //Запись элементов побочной оси в вектор
                toSort.push_back(array[i][j]);
            }else{
                array[i][j]*=-1;  //Умножение остальных элементов на -1
            }
        }
    }
    sort(toSort.begin(),toSort.end()); //Сортировка по возрастанию элементов вектора
    for(int i=0;i<M;i++){
        array[i][M-1-i]=toSort[M-1-i];  //Запись элементов побочной оси из вектор по убыванию
    }
    cout<<"Матрица отформатирована"<<endl;
    cout<<"Введите N"<<endl;
    int N;//N-номер минимума;
    cin>>N;
    if(N>M){
        cout<<"Неверно введеный номер минимума"<<endl;
    }else{
        cout<<N<<" минимум "<<toSort[N-1]<<endl;
    }

    cout<<"Результат обработки матрицы: "<<endl;
    for(int i=0;i<M;i++){ //Вывод отформатированной матрицы
        for(int j=0;j<M;j++){
            cout<<setw(3)<<array[i][j]<<" ";
        }
        cout<<endl;
    }

}
