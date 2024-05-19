//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "AnimationWindow.h"
//------------------------------------------------------------------------------'

// OPPGAVE 1



void inputAndPrintInteger() {
    int n;
    cout << "Skriv inn et tall: ";
    cin >> n;
    cout << "Du skrev: " << n << endl;
}

int inputInteger() {
    int n;
    cout << "Skriv inn et tall: ";
    cin >> n;
    return n;
}

void inputIntegersAndPrintSum() {
    int n = inputInteger();
    int m  = inputInteger();
    int sum = n + m;
    cout << "Summen av tallene: " << sum;
}

bool isOdd(int Tall) {
    if (Tall % 2 != 0) {
        return true;
    }
    return true;
}





void meny() {
    int meny_valg;


    do
    {
        cout << "0) Avslutt" 
        << "1) Printe Tall, " 
        << "2) Returnere Tall,  " 
        << "3) Summere og Printe Tall " 
        << "4) Sjekke oddetall" << endl;
        cout << " Angi valg (0-3): ";
        
        cin >> meny_valg;

        switch (meny_valg){
            case 1:
                inputAndPrintInteger();
                break;
            case 2:
                //int number = inputInteger();
                //cout << "Du skrev: " << number;
                inputInteger();
                break;
            case 3:
                inputIntegersAndPrintSum();
                break;
            case 4: 
                int Tall;
                cout << "Skriv inn et tall: ";
                cin >> Tall;
                cout << isOdd(Tall) << endl;
                break;
            default:
                break;
        }


        
    } while (meny_valg != 0);

}




int main() {
    meny();
}

//e inputInteger siden den gir deg en verdi og krever færre linjer kode




//OPPGAVE 2

//A


int sumHeltall() {
    int mengde;
    cout << "Hvor mange tall skal du summere? ";
    cin >> mengde;
    int sum = 0;

    for (int i = 0; i < mengde ; i++)
    {
        int tall;
        cout << "Skriv inn et tall: ";
        cin >> tall;
        sum += tall; 
    }
    return sum;
}


//B

int sum2Zero() {
    int sum = 0;
    int tall;
    do
    {
        cout << "Skriv inn et tall: ";
        cin >> tall;
        sum += tall; 
    } while (tall != 0);
    return sum;
}


//C) For-løkker når man itererer en kjent mendge, while når du har et premiss for å avslutte løkken


//D)

void NOK2USD(){
    float kurs = 10.41;
    float NOK;
    cout << "Skriv inn et beløp i NOK du ønsker å konvertere til USD: ";
    cin >> NOK;

    while (NOK < 0) {
        cout << "Skriv inn et beløp i NOK du ønsker å konvertere til USD: ";
        cin >> NOK;
    }

    float USD = NOK / kurs;
    //cout << USD << endl;
    cout << "USD: " << fixed << setprecision(2) << USD << endl;
}

//E) Burde ikke bruke int ettersom det er kun heltall, er litt forvirret om de ville vi skal bruke float eller
// double i denne oppgaven siden de snakker om flyttall i forrige oppgave og double i denne?




//G

void gangetabell() {
    int height;
    cout << "Enter height: ";
    cin >> height;

    int width;
    cout << "Enter width: ";
    cin >> width;

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            cout << setw(4) << i*j; 
        }
        cout << endl;
    }
    

}

/*
int main() {
    //cout << sumHeltall() << endl;
    //cout << sum2Zero() << endl;
    //NOK2USD();
    gangetabell();


    return 0;
}

*/

//OPPGAVE 3



double discriminant (double a, double b, double c) {
    double value = pow(b,2) - 4*a*c;
    return value;
}

void printRealRoots (double a, double b, double c) {
    double disc = discriminant(a,b,c);
    if (disc > 0) {
        double x1 = (-b + sqrt(disc))/(2*a);
        double x2 = (-b - sqrt(disc))/(2*a);

        cout << setw(2) << "x = " << x1 << ", " << x2 << endl;
    }

    else if (disc == 0) {
        double x3 = (-b)/(2*a);
        cout << setw(2) << "x = " << x3 << endl;
    }
    else {
        cout << setw(2) << "x has no solutions." << endl;
    }
}

void solveQuadraticEquations(){
    double a;
    double b;
    double c;

    cout << "Lets solve ax^2 + bx + c = 0" << endl;
    cout << "Type in a: ";
    cin >> a;
    cout << "Type in b: ";
    cin >> b;
    cout << "Type in c: ";
    cin >> c;
    
    printRealRoots(a,b,c);
}
/*
int main(){
    solveQuadraticEquations();
}
*/



//OPPGAVE 4


void Pythagoras(){

    AnimationWindow win{100,100,500,500,"Pythagoras"};

    int x1 = 200;
    int y1 = 300;

    int x2 = 400;
    int y2 = 300;
    
    int x3 = 200;
    int y3 = 100;

    Point point1{x1,y1};
    Point point2{x2,y2};
    Point point3{x3,x3};

    win.draw_triangle(point1, point2, point3, Color::red);

    Point q1Point3{100,300};
    Point q1Point4{100,200};

    win.draw_quad(point1, point3, q1Point4, q1Point3, Color::blue);

    Point q2Point3{200,500};
    Point q2Point4{400,500};

    win.draw_quad(point1, point2, q2Point4, q2Point3, Color::green);

    Point q3Point3{480,170};
    Point q3Point4{275,25};

    win.draw_quad(point2, point3, q3Point4, q3Point3, Color::pink);

    

    win.wait_for_close();
}
/*
int main(){
    Pythagoras();
}
*/



//OPPGAVE 5



vector<int> calculateBalance(int innskudd, int rente, int aar) {
    vector<int> bank;
    double saldo = innskudd;
    
    for (int i = 0; i <= aar; i++)
    {
        saldo = innskudd * pow((1 + static_cast<double>(rente)/100),i);
        bank.push_back(saldo);
        //cout << setw(4) << i << " " << saldo << endl;
    }

    return bank;
    
}

void printBalance(vector<int> bank) {
    cout << setw(5) << "År " << "Saldo " << endl;
    for (int j = 0; j <= bank.size() - 1; j++){
        cout << setw(4) << j << " " << bank.at(j) << endl;
    }
}
//D) feilen ligger i at størrelsen til vektoren er 1 større 9, mens høyeste element plass i vektoren er 8 siden tellingen begynner på 0

int main() {
    //printBalance(calculateBalance(1000, 3, 5));
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i <= v.size(); i++) {
        cout << v.at(i) << endl;
    }
}

//c) ser ut som det prøves å skrive ut en vektor i sin helhet og c++ har ingen standdardfunksjon for dette, derfor vi bruker .at() for å skrive ut elementer


