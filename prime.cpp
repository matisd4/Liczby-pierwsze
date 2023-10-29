#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <fstream>

using namespace std;

void prime1(int n) {
    int ile = 0;
    for(int i = 2; i <= n; i++) 
    {
        int dzielniki = 1; // dzielnikiem kazdej liczby calkowitej jest 1
        for(int j = 2; j <= i; j++)
        {
            if(i % j == 0) {
                dzielniki++;
            }
        }
        if(dzielniki == 2) {
            ile++;
        }
    }
    cout << '\t' << ile;

}

void prime2(int n) {
    int ile = 1; //2 jest liczba pierwsza
    for(int i = 3; i <= n; i++) 
    {
        int dzielniki = 1; // dzielnikiem kazdej liczby calkowitej jest 1
        if(i % 2 == 0) {
            continue;
        }
        for(int j = 3; j <= i; j+=2) 
        {
            if(i % j == 0) {
                dzielniki++;
            }
            if(dzielniki > 2) {
                break;
            }
        }
        if(dzielniki == 2) {
            ile++;
        }
    }
    cout << '\t' << ile;

}

void prime3(int n) {
    int ile = 1; //2 jest liczba pierwsza
    for(int i = 3; i <= n; i++)
    {
        if(i % 2 == 0) {
            continue;
        }
        int dzielniki = 2;
        for(int j = 3; j <= sqrt(i); j+=2)
        {
            if(i % j == 0){
                dzielniki++;
            }
            if(dzielniki > 2) {
                break;
            }
        }
        if(dzielniki == 2){
            ile++;
        }
    }
    cout << '\t' << ile;
}

void eratostenes(int n)
{
    int ile = 0;
    vector <int> v(n+1, 1);
    for(int i = 2; i*i <= n; i++)
    {
        if(v[i]) {
            for(int j = i*2; j <= n; j += i)
            {
                v[j] = 0;
            }
        }
    }
    for(int i = 2; i <= n; i++)
    {
        if(v[i]) {
            ile++;
        }
    }
    cout << '\t' << ile;
}

int main() {

    int n = 1000;

    ofstream zapis("dane.txt");

    for(int j = 0; j < 4; j++) {
        for(int i = 0; i < 4; i++) {
            auto begin = std::chrono::high_resolution_clock::now();
            if(i == 0) prime1(n);
            if(i == 1) prime2(n);
            if(i == 2) prime3(n);
            if(i == 3) eratostenes(n);
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            zapis << elapsed.count() * 1e-9 << '\t';
        }
        zapis << '\n';
        n *= 10;
    }

    zapis.close();

    return 0;
}