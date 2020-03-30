#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>

#define Nmax 10005

using std::cin;
using std::cout;
using std::string;
using std::fstream;
using std::ifstream;
using std::ios;

// stiu ca e cam polluting asa, dar am zis sa fac cum ati zis la curs

/*
char* strfind(const char* s, const char* f)
{
    int i = 0;
    int l = strlen(f);
    while (i < l)
    {
        int j = 0;
        int aux = i;
        int l2 = strlen(s);
        while (f[i] == s[j] && j < l2)
        {
            j++;
            i++;
        }
        if (j == strlen(s))
        {
            return const_cast<char*>(&f[aux]);
        }
    i++;
    }
    return NULL;
}
*/

char* my_strfind(const char* s, const char* f)
{
    int i = 0;

    while (*(s + i) != NULL)
    {
        if (*(s + i) == *f)
        {
            int j = 0;        // sau pe do-while
            while (*(s + i + j) != NULL && *(s + i + j) == *(f + j))
                j++;
            if (*(s + i + j) == '\0') return const_cast <char*> (f + i);
            // daca iese de
        }
        i++; // nu o sa pierd caractere de comparat asa, pentru ca: supposedly iese de pe 
        // a doua ramura din ultimul if, cele 2 caractere de comparat stiu sigur ca sunt
        // diferite, fapt afirmat chiar de a doua conditie din ultimul if
    }
    return NULL;
}

    /*
    while(s[i] != NULL)
    {
        if (s[i] == *f) return s + i;
    }
    */
    // return &(f + i);
    // return (f + i);
    
    //return const_cast <char*> (s + i);


//minim

struct a
{
    bool v1;
    int v2;
    char* v3 = new char[100];
    long v4;
    double v5;
    long double v6;
};

//maxim

struct b
{
    bool v1 = true;
    int v2 = 100;
    char v3[100];
    long v4 = -1;
    double v5 = 4.20;
    long double v6;
};

void ex2()
{
    a ob1;
    b ob2;
    cout << "obiect de tip a: " << sizeof(ob1) << '\n';
    cout << "obiect de tip b: " << sizeof(ob2) << '\n';
}

int my_strlen(const char* s)
{
    int i = 0;
    //while (*(s+i)) i++; // daca fac asa, o sa stie datorita compiler ului ca trebuie sa compare cu '\0' si nu cu nullptr sau NULL sau 0 sau altele...?
    // merge si varianta de deasupra, doar ca am comentat-o, pentru ca poate mai jos nu o sa mearga si na... sa fiu consistent in cod, adica in modeul in care aleg sa implementez
    while( *(s+i) != '\0')
    
    return i;
}

/*
    Nu se preciza daca sa se insereze la sfarsit sau sa se suprascrie, asa ca am suprascris, in sensul clasic al "strcpy"
*/
char* my_strcpy(char* s1, const char* s2) // s1 -> destinatie, s2 -> sursa
{
    /*
    int ls1 = strlen(s1); // lungime s1
    int j = 0; // index de parcurgere a lui s2
    do
    {
        //s1[ls1+j] = s2[j];        // pe do-while o sa imi copieze si terminatorul de sir 
        *(s1 + ls1 + j) = *(s2 + j);
    } //while (s2[j] != '\0');
    //while (*(s2 + j) != '\0');
    while (*(s2 + j));              
    */

    int i = 0;
    do
    {
        s1[i] = s2[i];
        i++;
    } while (*(s2 + i) != '\0');

    return s1;
}

class Account
{
private:

    double money = 100;

public:

    void plata(const double& price)
    {
        money -= price;

        // nu stiu sigur daca asa se facea, but here it goes:
        fstream f1;                                        // stream pt un fisier
        fstream f2;                                        // stream pt un alt fisier

        f1.open("date_out.txt", ios::app);      
        f2.open("bani.txt", ios::app);          // le deschid pentru append

        f1 << "OUT " << price << " " << money << '\n';
        f2 << money << '\n';

        f1.close();
        f2.close();
    }

    void incasare(const double& price)
    {
        money += price;

        fstream f1;
        fstream f2;

        f1.open("date_out.txt", ios::app);
        f2.open("bani.txt", ios::app);          // le deschid pentru append

        f1 << "IN " << price << " " << money << '\n';
        f2 << money << '\n';

        f1.close();
        f2.close();
    }

    void sold_disponibil()
    {
        cout << "Sold: " << money;
    }

    void read_istoric()
    {

        ifstream myReadFile;
        myReadFile.open("date_out.txt");

        int var;
        char output[100];
        if (myReadFile.is_open())               // daca nu apare vreo eroare la deschidere
            while (!myReadFile.eof())           // cat timp nu se ajunge la eof ( stiam ca nu e bine sa ne folosim de eof, dar era la indemana rezolvarea asta )
            {
                myReadFile >> output;
                if (atoi(output) > 0)
                    var = atoi(output);
            }

        money = var;
        myReadFile.close();
    }
};

void calc_pi()
{

    /*
    double lower_bound = 0;
    double upper_bound = Nmax;
    
    std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
    std::default_random_engine re;
    
    //double a_random_double = unif(re)
    int inside = 0;
    int n = 1000;
    for (int i = 0; i < n; i++)
    {
        double x = unif(re);
        double y = unif(re);
        cout << x << " " << y << '\n';
        cin.get();
        cout << "trece 1" << '\n';
        if (sqrt(x * x + y * y) <= 1)
        {
            inside += 1; cout << " trece 2" << '\n';
        }
    }
    cout << inside << '\n';
    double pi = 4 * inside;
    cout << pi << '\n';
    */

    int inside = 0;
    //int n = 1000;
    //int n2 = 10000; // zece mii
    //int n3 = 100000; // o suta de mii
    //int n4 = 1000000; // un milion
    //int n4 = 10 000 000; // zece milioane
    int n5 = 100000000; // zece milioane
    // cu cat e mai mare 
    for (int i = 0; i < n5; i++)
    {
        double x = static_cast<double> (rand()) / static_cast <float>(RAND_MAX);
        double y = static_cast<double> (rand()) / static_cast <float>(RAND_MAX);
        //cout << x << " " << y << '\n';
        ///cin.get();
        //cout << "trece 1" << '\n';
        if (sqrt(x * x + y * y) <= 1)
        {
            inside += 1; //cout << " trece 2" << '\n';
        }
    }
    double pi = 4 * inside / double(n5);
    cout << pi << '\n';

    /*
    int inside = 0;
    int n = Nmax;
    
    
    for (int i = 0; i < n; i++)
    {
        //double x = rand();
        //double y = rand();
 //       float x = static_cast <float> (rand() / (static_cast <float>()RAND_MAX / );
    
    }
    */
}

int main()
{
    a* vpa[10]; // vector de pointeri catre obiecte de tip a 
    b* vpb[10]; // vector de pointeri catre obiecte de tip b

    a oba0, oba1, oba2, oba3, oba4, oba5, oba6, oba7, oba8, oba9; // obiect de tip a de index 0, ...
    vpa[0] = &oba0;  vpa[1] = &oba1; vpa[2] = &oba0; vpa[3] = &oba3;  vpa[4] = &oba4;
    vpa[5] = &oba5;  vpa[6] = &oba6;  vpa[7] = &oba7;  vpa[8] = &oba8;  vpa[9] = &oba9;

    b obb0, obb1, obb2, obb3, obb4, obb5, obb6, obb7, obb8, obb9; // obiect de tip b de index 0 ...
    vpb[0] = &obb0;  vpb[1] = &obb1; vpb[2] = &obb0; vpb[3] = &obb3;  vpb[4] = &obb4;
    vpb[5] = &obb5;  vpb[6] = &obb6;  vpb[7] = &obb7;  vpb[8] = &obb8;  vpb[9] = &obb9;

    /*
    a pa = vpa;
    cout << a << '\n';
    cout << ++a << '\n';
    */

    //cout << ++p->i

    /*
    const char *aux = "";
    cout << my_strlen(aux) << '\n'; // expected: 0
    const char *aux2 = "123";
    cout << my_strlen(aux2) << '\n'; // expected: 3
    const char *aux3 = "biblioteca";
    cout << my_strlen(aux3) << '\n'; // expected: 10
    */
    
    /*
    char str1[Nmax] = "ce faci?";
    const char str2[Nmax] = "bine tu?";
    cout << str1 << '\n';
    char* p = my_strcpy(str1, str2);
    cout << p << '\n';
    */

    /*
    */

    char* q = my_strfind("abc", "abcdef");
    cout << q << '\n';


//    calc_pi();
    return 0;
}