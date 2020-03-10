#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include<math.h>

#include<vector>
using std::vector;

int int_rand(int min, int max);
bool contains(int x, vector<int> numbers_contains);

int main() {
    srand((unsigned)time(0));

    vector<int> numbers_contains;
    vector<int> numbers_amount;

    int matriz[5][5];

    int min, max;
    cout << "n. min: ";
    cin >> min;

    cout << "n. max: ";
    cin >> max;

    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            matriz[i][j] = int_rand(min, max);


    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if(!contains(matriz[i][j], numbers_contains))
                numbers_contains.push_back(matriz[i][j]);

    for(int number : numbers_contains){
        int amount=0;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(matriz[i][j] == number)
                    amount ++;
            }
        }

        numbers_amount.push_back(amount);
        amount = 0;
    }

    cout << " ----- MATRIZ ------- " << endl;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << matriz[i][j] << ", ";    
        }

        cout << endl;
    }
    cout << " ----------------- " << endl;
    cout << endl;


    for(int i=0; i<numbers_contains.size(); i++){
        cout << numbers_contains[i] << " ";

        for(int j=0; j<numbers_amount[i]; j++){
            cout << "#"; 
        }
        cout << " "  << numbers_amount[i] << endl;
    }

}

int int_rand(int min, int max){
    return rand()%(max-min+1) + min;
}

bool contains(int x, vector<int> numbers_contains){
    for(int number : numbers_contains)
        if(number == x)
            return true;
    
    return false;
}