#include<bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.14159265

class Calculator
{
    double A, B;
    double ang=0.0;
    vector<vector<int>> matA, matB;
    int dimAa, dimAb, dimBa, dimBb;
public:
    void get()
    {
        cout << "Enter First Number: ";
        cin >> A;
        cout << "Enter Second Number: ";
        cin >> B;
    }
    void gett()
    {
        cout << "Enter the Angle: ";
        cin >> ang;
    }
    bool chk(int a, int b, int c, int d)
    {
        if(a==c && b==d)
        {
            return true;
        }
        return false;
    }
    int gettin()
    {
        cout << "Enter the dimensions of matrix A: ";
        cin >> dimAa >> dimAb;
        cout << "Enter the dimensions of matrix B: ";
        cin >> dimBa >> dimBb;

        if(dimAb != dimBa)
        {
            return -1;
        }
        else
        {
            matA.resize(dimAa, vector<int> (dimAb, 0));
            matB.resize(dimBa, vector<int> (dimBb, 0));
            return 1;
        }
    }
    int getting()
    {
        cout << "Enter the dimensions of matrix A: ";
        cin >> dimAa >> dimAb;
        cout << "Enter the dimensions of matrix B: ";
        cin >> dimBa >> dimBb;

        if(!chk(dimAa,dimAb,dimBa,dimBb))
        {
            return -1;
        }
        else
        {
            matA.resize(dimAa, vector<int> (dimAb, 0));
            matB.resize(dimBa, vector<int> (dimBb, 0));
            return 1;
        }
    }
    void matrixEntry()
    {
        int aa;
        int k=1;
        for(int i=0; i<dimAa; i++)
        {
            for(int j=0; j<dimAb; j++)
            {
                cout << "Enter the " << k << " element of matrix A: ";
                cin >> aa;
                matA[i][j] = aa;
                k++;
            }
        }

        k=1;
        for(int i=0; i<dimBa; i++)
        {
            for(int j=0; j<dimBb; j++)
            {
                cout << "Enter the " << k << " element of matrix B: ";
                cin >> aa;
                matB[i][j] = aa;
                k++;
            }
        }

        return ;
    }
    void calculateAdd()
    {
        vector<vector<int>> matC(dimAa, vector<int> (dimAb, 0));
        for(int i=0; i<dimAa; i++)
        {
            for(int j=0; j<dimAb; j++)
            {
                matC[i][j] = matA[i][j]+matB[i][j];
            }
        }

        for(int i=0; i<dimAa; i++)
        {
            for(int j=0; j<dimAb; j++)
            {
                cout << matC[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    void calculateSub()
    {
        vector<vector<int>> matC(dimAa, vector<int> (dimAb, 0));
        for(int i=0; i<dimAa; i++)
        {
            for(int j=0; j<dimAb; j++)
            {
                matC[i][j] = matA[i][j]-matB[i][j];
            }
        }

        for(int i=0; i<dimAa; i++)
        {
            for(int j=0; j<dimAb; j++)
            {
                cout << matC[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    void calculateMul()
    {
        vector<vector<int>> matC(dimAa, vector<int> (dimAb, 0));
        for (int i = 0; i < dimAa; i++)
        {
            for (int j = 0; j < dimBb; j++)
            {
                matC[i][j] = 0;

                for (int k = 0; k < dimBa; k++)
                {
                    matC[i][j] += matA[i][k] * matB[k][j];
                }

                cout << matC[i][j] << "\t";
            }

            cout << endl;
        }
    }
    double add()
    {
        return A + B;
    }
    double sub()
    {
        return A - B;
    }
    double mul()
    {
        return A * B;
    }
    double div()
    {
        if (B == 0)
        {
            cout << "Divison By Zero" << endl;
            return INFINITY;
        }
        else
        {
            return A / B;
        }
    }
    double sino()
    {
        return sin(ang*PI / 180);
    }
    double coso()
    {
        return cos(ang*PI / 180);
    }
    double tano()
    {
        return tan(ang*PI / 180);
    }
};


int main()
{

    int choice;
    Calculator cal;

    cout << "Enter 1 to Add 2 Numbers"
         << "\nEnter 2 to Subtract 2 Numbers"
         << "\nEnter 3 to Multiply 2 Numbers"
         << "\nEnter 4 to Divide 2 Numbers"
         << "\nEnter 5 to calculate Sine of an Angle"
         << "\nEnter 6 to calculate Cosine of an Angle"
         << "\nEnter 7 to calculate Tangent of an Angle"
         << "\nEnter 8 to add two matrices"
         << "\nEnter 9 to subtract two matrices"
         << "\nEnter 10 to multiply two matrices"
         << "\nEnter 0 To Exit"
         << "\n";

    do
    {
        cout << "\nEnter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cal.get();
            cout << "Result: " << cal.add() << endl;
        }
        break;
        case 2:
        {
            cal.get();
            cout << "Result: " << cal.sub() << endl;
        }
        break;
        case 3:
        {
            cal.get();
            cout << "Result: " << cal.mul() << endl;
        }
        break;
        case 4:
        {
            cal.get();
            cout << "Result: " << cal.div() << endl;
        }
        break;
        case 5:
        {
            cal.gett();
            cout << "Result: " << cal.sino() << endl;
        }
        break;
        case 6:
        {
            cal.gett();
            cout << "Result: " << cal.coso() << endl;
        }
        break;
        case 7:
        {
            cal.gett();
            cout << "Result: " << cal.tano() << endl;
        }
        break;
        case 8:
        {
            int val = cal.getting();
            if(val==-1)
            {
                cout << "Dimensions incorrect.";
            }
            else
            {
                cal.matrixEntry();
                cal.calculateAdd();
            }
        }
        break;
        case 9:
        {
            int val = cal.getting();
            if(val==-1)
            {
                cout << "Dimensions incorrect.";
            }
            else
            {
                cal.matrixEntry();
                cal.calculateSub();
            }
        }
        break;
        case 10:
        {
            int val = cal.gettin();
            if(val==-1)
            {
                cout << "Dimensions incorrect.";
            }
            else
            {
                cal.matrixEntry();
                cal.calculateMul();
            }
        }
        }
    }
    while (choice >= 1 && choice <= 10);

    return 0;
}
