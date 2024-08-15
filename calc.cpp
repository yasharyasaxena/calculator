#include <iostream>

using namespace std;

int factorial(int x){
    int fact = 1;
    for(int i = 1; i<=x; i++){
        fact *=i;
    }
    return fact;
}


double pow(double x, int y){
    double result = 1;
    for(int i = 1; i<=y; i++){
        result *= x;
    }
    return result;
}


double sin(double z){
    if(z >= 6.2831853072 || z <= -6.2831853072){
        int x = (int)(z/6.2831853072);
        double frac = (double)(z/6.2831853072) - x;
        z = frac*6.2831853072;
        double result = z;
        double term = z;
        int a = 1000;
        int y = 1;
        for(int i = 1; i < a; ++i){
            double mult =-z*z/((y+1)*(y+2));
            term *= mult;
            result += term;
            y += 2;
        }
        return result;

    }
    else{
        double result = z;
        double term = z;
        int x = 1000;
        int y = 1;
        for(int i = 1; i < x; ++i){
            double mult =-z*z/((y+1)*(y+2));
            term *= mult;
            result += term;
            y += 2;
        }
        return result;
    }
    
}


double cos(double x){
    if(x >= 6.2831853072 || x <= -6.2831853072){
        int z = (int)(x/6.2831853072);
        double frac = (double)(x/6.2831853072) - z;
        x = frac*6.2831853072;
        double result = 1;
        double term = 1;
        int a = 1000;
        for(int i = 1; i < a; ++i){
            double mult =-x*x/((2*i-1)*(2*i));
            term *= mult;
            result += term;
        }
        return result;

    }
    else{
        double result = 1;
        double term = 1;
        int z = 1000;
        for(int i = 1; i < z; ++i){
            double mult =-x*x/((2*i-1)*(2*i));
            term *= mult;
            result += term;
        }
        return result;
    }
}


double sqrt(double x){
    double result = x/2;
    if(x == 0 || x == 1){
        result = x;
        return result;
    }
    else if(x<0){
        cout << "Enter positive number!\n";
    }
    else{
        int y = 100;
        for(int i = 1; i < y; ++i){
            result = result - ((result*result)-x)/(2*result);
        }
        return result;
    }
}


double tan(double x){
    return sin(x)/cos(x);
}


double log(double x){
    double result;
    if(x<1){
        cout<<"Enter x >= 1. \n";
    }
    else{
        while(x>=2){
            x /= 2;
            result += 0.69315;
        }

        int z = 1000;
        for(int i = 1; i < z; ++i){
            result += pow(-1, i-1)*pow(x-1, i)/i;
        }
        return result;
    }
    
}


void quad_eq(double a, double b, double c){       //a = coeff of x^2, b = coeff of x, c = const//
    double sol_1;
    double sol_2;
    double D;
    D = pow(b, 2) - 4*a*c;
    if(D == 0){
        sol_1 = -b/(2*a);
        cout << "The solution is: " << sol_1 << ".\n";
    }
    else if(D<0){
        cout << "The roots are complex.\n";
    }
    else{
        sol_1 = (-b + sqrt(D))/(2*a);
        sol_2 = (-b - sqrt(D))/(2*a);
        cout << "The solutions are: " << sol_1 << " and " << sol_2 << ".\n" ;
    }
}


void linear_eq(double a1, double b1, double c1, double a2, double b2, double c2){       //a = coeff of x, b = coeff of y, c = const//
    if(a1/a2 == b1/b2 && a1/a2 == c1/c2){
        cout << "The equations have infinite soltions.\n";
    }
    else if(a1/a2 == b1/b2 && a1/a2 != c1/c2){
        cout << "The equations have no solution.\n";
    }
    else{
        double D = a1*b2 - a2*b1;
        double D1 = c1*a2 - c2*a1;
        double D2 = c1*b2 - c2*b1;
        cout << "x = " << D1/D << endl;
        cout << "y = " << D2/D << endl;
    }
}


int menu(){
    bool quit = false;
    while(!quit){
        int op;

        cout << "1. Addition \n";
        cout << "2. Substraction \n";
        cout << "3. Multiplication \n";
        cout << "4. Division \n";
        cout << "5. Exponentiation \n";
        cout << "6. Square root \n";
        cout << "7. Logarithm \n";
        cout << "8. Sine \n";
        cout << "9. Cosine \n";
        cout << "10. Tangent \n";
        cout << "11. Solve Quadratic Equation \n";
        cout << "12. Solve Linear Equation in two variable \n";
        cout << "13. Quit \n";
        cout << "Enter the serial number of the operation from the list given above: ";
        cin >> op;

        if(op < 5){
            double a;
            double b;

            cout << "Enter 1st number: \n";
            cin >> a; 

            cout << "Enter 2nd number: \n";
            cin >> b;

            switch(op){
                case 1:
                    cout << "Sum: " << a+b << endl;
                    break;

                case 2:
                    cout << "Diff: " << a-b << endl;
                    break;
                
                case 3:
                    cout << "Product: " << a*b << endl;
                    break;
                
                case 4:
                    cout << "Division: " << a/b << endl;
                    break;
                
            }

        }

        else if(op == 5){
            double a;
            int b;
            
            cout << "Enter Number: \n";
            cin >> a;

            cout << "Enter Power: \n";
            cin >> b;

            cout << "Result: " << pow(a, b) << endl;
        }

        else if(op == 6){
            double a;

            cout << "Enter Number: \n";
            cin >> a;
            
            cout << "Square Root: " << sqrt(a) << endl;
        }

        else if(op == 7){
            double a;

            cout << "Enter Number: \n";
            cin >> a;
            
            cout << "Log: " << log(a) << endl;
        }

        else if(op == 8){
            double a;
            
            cout << "Enter angle in radians: \n";
            cin >> a;

            cout << "Sine: " << sin(a) << endl;
        }

        else if(op == 9){
            double a;
            
            cout << "Enter angle in radians: \n";
            cin >> a;

            cout << "Cosine: " << cos(a) << endl;
        }

        else if(op == 10){
            double a;
            
            cout << "Enter angle in radians: \n";
            cin >> a;

            cout << "Tangent: " << tan(a) << endl;
        }

        else if(op == 11){
            double a;
            double b;
            double c;

            cout << "Enter coeff of x^2: \n";
            cin >> a;

            cout << "Enter coeff of x: \n";
            cin >> b;

            cout << "Enter const: \n";
            cin >> c;

            quad_eq(a,b,c);
        }

        else if(op == 12){
            double a1;
            double b1;
            double c1;
            double a2;
            double b2;
            double c2;

            cout << "Enter coeff of x in equation 1: \n";
            cin >> a1;

            cout << "Enter coeff of y in equation 1: \n";
            cin >> b1;

            cout << "Enter const in equation 1: \n";
            cin >> c1;

            cout << "Enter coeff of x in equation 2: \n";
            cin >> a2;

            cout << "Enter coeff of y in equation 2: \n";
            cin >> b2;

            cout << "Enter const in equation 2: \n";
            cin >> c2;

            linear_eq(a1,b1,c1,a2,b2,c2);
        }
        
        else if(op == 13){
            cout << "Bye! \n";
            quit = true;
        }
    }
    return 0;
}

int main(){
    menu();
}