#include <iostream>
#include <string>
#include <fstream>
#include <bitset>

using namespace std;


string soma(string a, string b)
{
    string result = ""; 
    int s = 0;         
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
        s += ((i >= 0)? a[i] - '0': 0);
        s += ((j >= 0)? b[j] - '0': 0);

        result = char(s % 2 + '0') + result;
        s /= 2;
 
        i--; j--;
    }
    return result;
}


string multiplicacao(string a, string b)
{  
    string  result= "0"; 
    string temp="0";  
    int shifter = 0;   
    int j = b.size() - 1;

    while (j >= 0)
    {
        if (b[j] == '1')
        { 
            temp = a;
            temp.append(shifter, '0');
            result = soma(result, temp);
        }
        ++shifter; 
        j--;
    }

    return result;

}


int main(){
  string operacao;
  string num1, num2;

  cout << "-------------------------------" << endl;
  cout << " Digite a operacao que deseja :" << endl;
  cout << "              + , * ,          " <<endl;
  cin >> operacao;
  cout << "-------------------------------" << endl;
  cout << " Digite o primeiro numero binario  :" << endl;
  cin >> num1;
  cout << "-------------------------------" << endl;
  cout << " Digite o segundo numero binario  : "<<endl;
  cin >> num2 ;
  cout << "-------------------------------" << endl;

  if(operacao == "+"){
    cout << soma(num1, num2) << endl;
  }
  else if(operacao == "*"){
    cout << multiplicacao(num1, num2) << endl;
    }
}
 
