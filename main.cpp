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
    int M; // ������ ������ MxM
    cin>>M;
    if(M>5||M<2){ //�஢�ઠ �� 2<=M<=5
        cout<<"����ୠ� ����稭� ������"<<endl;
        return 0;
    }
    int array [M][M]; // ������� ������ ࠧ��஬ MxM
    string CMND;
    cout<<"�᫨ ��� ����� ���祭�� ������ ᠬ����⥫쭮-������ + "
          ", �᫨ ��� , � ������ �� ��㣮� ᨬ���/��������� ᨬ�����"<<endl;
    cin>>CMND;
    if(CMND=="+"){
        int b;// �ᯮ������ ��� �஢�ન �������� ���祭��
        cout<<"������ 楫� �᫠ �� ��������� [1,100]"<<endl;
        for(int i=0;i<M;i++){
         for(int j=0;j<M;j++){
             cin>>b;
             if(b>=1&&b<=100){
                 array[i][j]=b;
             }else{
                 cout<<"����୮ �������� ���祭��"<<endl;
                 return 0;
             }
         }
        }
        cout<<"����� ���������"<<endl;
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
        cout<<"���ᨢ ��������"<<endl;
    }
    vector <int> toSort;// ����� ��� ����⮢ ����筮� ��
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            if(array[i][j]==array[i][M-1-i]){    //������ ����⮢ ����筮� �� � �����
                toSort.push_back(array[i][j]);
            }else{
                array[i][j]*=-1;  //��������� ��⠫��� ����⮢ �� -1
            }
        }
    }
    sort(toSort.begin(),toSort.end()); //����஢�� �� �����⠭�� ����⮢ �����
    for(int i=0;i<M;i++){
        array[i][M-1-i]=toSort[M-1-i];  //������ ����⮢ ����筮� �� �� ����� �� �뢠���
    }
    cout<<"����� ���ଠ�஢���"<<endl;
    cout<<"������ N"<<endl;
    int N;//N-����� �����㬠;
    cin>>N;
    if(N>M){
        cout<<"����୮ ������� ����� �����㬠"<<endl;
    }else{
        cout<<N<<" ������ "<<toSort[N-1]<<endl;
    }

    cout<<"������� ��ࠡ�⪨ ������: "<<endl;
    for(int i=0;i<M;i++){ //�뢮� ���ଠ�஢����� ������
        for(int j=0;j<M;j++){
            cout<<setw(3)<<array[i][j]<<" ";
        }
        cout<<endl;
    }

}
