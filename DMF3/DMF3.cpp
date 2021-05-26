#include <iostream>
#include <vector>

using namespace std;

int action, err = 0;

vector<pair<int, int>> mas_c;


void Action()               /*Функция, отвечающая за выбор операции*/
{
    //system("pause");
    //system("cls");
    cout << endl;
    // cout << "\nViberite operaciyu: \n1)Ob'edinenie \n2)Peresechenie\n 3)Raznost'\ n4)Symmetricheskaya raznost'\n" <<
      //   "5)Inversia \n 6)Kompozicia \n 7)Obraz\n 8)Proobraz\n9)Suzhenie\n10)Prodolzhenie\n0)Exit\n";
    cout << "Viberite operaciyu:" << endl;
    cout << "1)Ob'edinenie" << endl;
    cout << "2)Peresechenie" << endl;
    cout << "3)Raznost'" << endl;
    cout << "4)Symmetricheskaya raznost'" << endl;
    cout << "5)Inversia" << endl;
    cout << "6)Kompozicia" << endl;
    cout << "7)Obraz" << endl;
    cout << "8)Proobraz" << endl;
    cout << "9)Suzhenie" << endl;
    cout << "10)Prodolzhenie" << endl;
    cout << "0) Exit" << endl;
    cin >> action; //Выбор операции
}

vector<int> ReadM(vector<int> mas) {
    int num;
    cin >> num;
    if (num <= 25 && num >= 0) {//Ввод множества X
        if (num != 0) {
            cout << "Vvedite elementy mnozhestva: ";
            for (int i = 0; i < num; i++) {
                int m;
                cin >> m;
                if (m >= 1 && m <= 50) {
                    if (find(mas.begin(), mas.end(), m) == mas.end()) {
                        mas.push_back(m);
                    }
                    else { cout << "Povtorenie elementa"; exit(0); }
                }
                else { cout << "ERROR! VIHOD ZA PREDELY!\n"; exit(0); }
            }
        }

    }
    return mas;
}

vector<pair<int, int>> Read(vector<pair<int, int>> mas) {
    int num;
    cin >> num;                                   //Ввод графика А

    if (num <= 25 && num >= 0) {
        if (num != 0) {
            cout << "Vvedite elementy graphika: ";
            for (int i = 0; i < num; i++) {
                int a; int b;
                cin >> a >> b;                             //Ввод элементов графика А
                if (a >= 1 && a <= 50 && b >= 1 && b <= 50) {
                    if (find(mas.begin(), mas.end(), make_pair(a, b)) == mas.end())
                        mas.push_back(make_pair(a, b));
                    else { cout << "Povtorenie elementa\n"; exit(0); }
                }
                else {
                    cout << "ERROR! VIHOD ZA PREDELY!\n"; exit(0);
                }

            }
        }
    }
    else {
        cout << "ERROR!\n";
        exit(0);
    }
    return mas;
}

void PrintM(vector<int> mas) {
    cout << "{";
    for (int i = 0; i < mas.size(); i++)
    {
        cout << mas[i];
        if (i != mas.size() - 1)
        {
            cout << ',';
        }
    }
    cout << '}';
}

void Print(vector<pair<int, int>> mas) {
    cout << "{";
    for (int i = 0; i < mas.size(); i++)
    {
        cout << '<' << mas[i].first << ',' << mas[i].second << '>';
        if (i != mas.size() - 1)
        {
            cout << ',';
        }
    }
    cout << '}';
}

void Compare(vector<int> mas1, vector<int> mas2, vector<pair<int, int>> para) {

    for (int j = 0; j < para.size(); j++) {
        if ((find(mas1.begin(), mas1.end(), para[j].first) == mas1.end()) || (find(mas2.begin(), mas2.end(), para[j].second) == mas2.end()))
        {
            cout << "Sootvetstvie sozdat' nevozmozhno!\n"; exit(0);
            err++;
        }
    }

}

vector <int> ObedM(vector<int>mas1, vector<int> mas2) {
    vector <int> mas;
    for (int i = 0; i < mas1.size(); i++) {                    //Выбираем 1, 2,..., mas_a  элемент из А
        mas.push_back(mas1[i]);                              //Записваем выбранный элемент в C
    }
    for (int i = 0; i < mas2.size(); i++) {                     //Выбираем 1, 2,..., mas_b элемент из B
        if (find(mas.begin(), mas.end(), mas2[i]) == mas.end()) {        //Выбираем 1, 2,..., mas_a элемент из C, если выбранные элементы B и C не равны, то
            mas.push_back(mas2[i]);                                   //Выбранный элемент из В записывается в C
        }
    }
    return mas;
}

void Obed(vector < pair<int, int>> mas1, vector < pair<int, int>> mas2) {
    for (int i = 0; i < mas1.size(); i++) {                    //Выбираем 1, 2,..., mas_a  элемент из А
        mas_c.push_back(mas1[i]);                              //Записваем выбранный элемент в C
    }
    for (int i = 0; i < mas2.size(); i++) {                     //Выбираем 1, 2,..., mas_b кортеж из B
        if (find(mas_c.begin(), mas_c.end(), mas2[i]) == mas_c.end()) {        //Выбираем 1, 2,..., mas_a кортеж из C, если выбранные элементы B и C не равны, то
            mas_c.push_back(mas2[i]);                                   //Выбранный кортеж из В записывается в C
        }
    }
}

vector <int> PerecM(vector<int>mas1, vector<int> mas2) {
    vector <int> mas;
    for (int i = 0; i < mas2.size(); i++) {                                         //Выбираем 1, 2,..., mas_a  элемент из А
        if (find(mas1.begin(), mas1.end(), mas2[i]) != mas1.end()) {          //Выбираем 1, 2,..., mas_b элемент из В, если выбранные элементы B встречается в А,то
            mas.push_back(mas2[i]);                                              //Выбранный элемент из B записывается в D
        }
    }
    return mas;
}

void Perec(vector < pair<int, int>> mas1, vector < pair<int, int>> mas2) {
    for (int i = 0; i < mas2.size(); i++) {                                         //Выбираем 1, 2,..., mas_a  кортеж из А
        if (find(mas1.begin(), mas1.end(), mas2[i]) != mas1.end()) {          //Выбираем 1, 2,..., mas_b кортеж из В, если выбранные кортежи B встречается в А,то
            mas_c.push_back(mas2[i]);                                              //Выбранный кортеж из B записывается в D
        }
    }
}

vector<int> RaznM(vector<int>mas1, vector<int> mas2) {
    vector <int> mas;
    for (int i = 0; i < mas1.size(); i++)                                       //Выбираем 1, 2,..., mas_a  элемент из А
    {
        if (find(mas2.begin(), mas2.end(), mas1[i]) == mas2.end())           //Выбираем 1, 2,..., mas_b элемент из В, если выбранный элемент А не встречается в В, то                                           
        {
            mas.push_back(mas1[i]);                                    //Выбранный элемент из A записывается в E
        }
    }
    return mas;
}

vector<int> SR(vector<int> mas1, vector<int> mas2) {
    vector <int> mas;
    for (int i = 0; i < mas1.size(); i++)                                       //Выбираем 1, 2,..., mas_a  элемент из А
    {
        if (find(mas2.begin(), mas2.end(), mas1[i]) == mas2.end())           //Выбираем 1, 2,..., mas_b элемент из В, если выбранный элемент А не встречается в В, то                                           
        {
            mas.push_back(mas1[i]);                                    //Выбранный элемент из A записывается в E
        }
    }
    for (int i = 0; i < mas2.size(); i++)                                       //Выбираем 1, 2,..., mas_a  элемент из А
    {
        if (find(mas1.begin(), mas1.end(), mas2[i]) == mas1.end())           //Выбираем 1, 2,..., mas_b элемент из В, если выбранный элемент А не встречается в В, то                                           
        {
            mas.push_back(mas2[i]);                                    //Выбранный элемент из A записывается в E
        }
    }
    return mas;
}
void Razn(vector < pair<int, int>> mas1, vector < pair<int, int>> mas2) {
    for (int i = 0; i < mas1.size(); i++)                                       //Выбираем 1, 2,..., mas_a кортеж из А
    {
        if (find(mas2.begin(), mas2.end(), mas1[i]) == mas2.end())           //Выбираем 1, 2,..., mas_b кортеж из В, если выбранный кортеж А не встречается в В, то
        {
            mas_c.push_back(mas1[i]);                                      //Выбранный кортеж из A записывается в E
        }
    }
}

void Kompot(vector < pair<int, int>> mas1, vector < pair<int, int>> mas2) {
    for (int i = 0; i < mas1.size(); i++) {                                 //Выбираем 1, 2,..., mas_a кортеж из А
        for (int j = 0; j < mas2.size(); j++) {                               //Выбираем 1, 2,..., mas_b кортеж из В,
            if (mas1[i].second == mas2[j].first) {                          //Если второй элемент кортежа из А равен первому элементу кортежа из В, то
                if (find(mas_c.begin(), mas_c.end(), make_pair(mas1[i].first, mas2[i].second)) == mas_c.end())
                    mas_c.push_back(make_pair(mas1[i].first, mas2[j].second));     //Создаем кортеж из полученных элементов и записываем его в С
                else { return; }

            }
        }
    }
}

void Invers(vector < pair<int, int>> mas) {
    for (int i = 0; i < mas.size(); i++) {                             //Выбираем 1, 2,..., mas_a кортеж из множества
        mas_c.push_back(make_pair(mas[i].second, mas[i].first));       //Записываем в множество кортежи, созданные из второго и первого элемента кортежей
    }
}

vector <int> Obraz(vector <int> mas, vector <pair<int, int>> para) {
    vector <int> mas1, mas2;
    cout << "Vvedie moshnost' mnozhestva: ";
    mas1 = ReadM(mas1);

    for (int i = 0; i < mas1.size(); i++) {
        if (find(mas.begin(), mas.end(), mas1[i]) == mas.end()) {
            cout << "Ne yavlyaetsya podmnozhestvom\n";
            exit(0);
        }
    }
    for (int i = 0; i < mas1.size(); i++) {
        for (int j = 0; j < para.size(); j++) {
            if (mas1[i] == para[j].first) {
                if (find(mas2.begin(), mas2.end(), para[j].second) == mas2.end()) {
                    mas2.push_back(para[j].second);
                }
            }
        }
    }
    return mas2;
}

vector <int> Proobraz(vector <int> mas, vector <pair<int, int>> para) {
    vector <int> mas1, mas2;
    cout << "Vvedie moshnost' mnozhestva: ";
    mas1 = ReadM(mas1);

    for (int i = 0; i < mas1.size(); i++) {
        if (find(mas.begin(), mas.end(), mas1[i]) == mas.end()) {
            cout << "Ne yavlyaetsya podmnozhestvom\n";
            exit(0);
        }
    }
    for (int i = 0; i < mas1.size(); i++) {
        for (int j = 0; j < para.size(); j++) {
            if (mas1[i] == para[j].second) {
                if (find(mas2.begin(), mas2.end(), para[j].first) == mas2.end()) {
                    mas2.push_back(para[j].first);
                }
            }
        }
    }
    return mas2;
}

vector <pair<int, int>> SuzhenieX(vector<int> mas, vector <pair<int, int>>para, vector<int> mas_o) {

    vector<pair<int, int>> mas2;

    for (int i = 0; i < mas_o.size(); i++) {
        if (find(mas.begin(), mas.end(), mas_o[i]) == mas.end()) {
            cout << "Ne yavlyaetsya podmnozhestvom\n";
            exit(0);
        }
    }
    for (int i = 0; i < mas_o.size(); i++) {
        for (int j = 0; j < para.size(); j++) {
            if (mas_o[i] == para[j].first) {
                if (find(mas2.begin(), mas2.end(), para[j]) == mas2.end()) {
                    mas2.push_back(para[j]);
                }
            }
        }
    }

    return mas2;
}

vector <pair<int, int>> SuzhenieY(vector<int> mas, vector <pair<int, int>>para, vector<int> mas_o) {

    vector<pair<int, int>> mas2;

    for (int i = 0; i < mas_o.size(); i++) {
        if (find(mas.begin(), mas.end(), mas_o[i]) == mas.end()) {
            cout << "Ne yavlyaetsya podmnozhestvom\n";
            exit(0);
        }
    }
    for (int i = 0; i < mas_o.size(); i++) {
        for (int j = 0; j < para.size(); j++) {
            if (mas_o[i] == para[j].second) {
                if (find(mas2.begin(), mas2.end(), para[j]) == mas2.end()) {
                    mas2.push_back(para[j]);
                }
            }
        }
    }

    return mas2;
}

void Prodolzhenie(vector<pair<int, int>> para1, vector<pair<int, int>> para2, vector<int> mas1, vector<int> mas2, vector<int> mas3, vector<int> mas4) {
    int test1 = 0, test2 = 0, test3 = 0;
    for (int i = 0; i < mas3.size(); i++) {
        if (find(mas1.begin(), mas1.end(), mas3[i]) == mas1.end()) {
            cout << "Prichina: Ne yavlyaetca ravnym mnozhestvom\n";
            break;
        }
        else { test1++; }
    }
    for (int i = 0; i < mas4.size(); i++) {
        if (find(mas2.begin(), mas2.end(), mas4[i]) == mas2.end()) {
            cout << "Prichina: Ne yavlyaetca ravnym mnozhestvom\n";
            break;
        }
        else { test2++; }
    }
    for (int i = 0; i < para1.size(); i++) {
        if (find(para2.begin(), para2.end(), para1[i]) == para2.end()) {
            cout << "Prichina: Ne yavlyaetca podmnozhestvom\n";
            break;
        }
        else { test3++; }
    }


    if (mas1.size() == mas3.size() && test1 == mas1.size() && mas2.size() == mas4.size() && test2 == mas2.size() && test3 == para1.size()) {
        cout << "Yavlyaetca prodolzheniem ";
    }
    else {
        cout << "Ne yavlyaetca prodolzheniem ";
    }
}

int main()
{
    vector <int> mas_x, mas_y, mas_w, mas_z, mas_o, mas_p;
    vector<pair<int, int>> mas_a, mas_b;


    cout << "Vvedite mochnost' mnozhestva X: ";
    mas_x = ReadM(mas_x);

    cout << "Vvedite mochnost' mnozhestva Y: ";
    mas_y = ReadM(mas_y);

    cout << "Vvedite mochnost' graphika A: ";
    mas_a = Read(mas_a);

    cout << "Vozmozhnost' sozdanija sootvetstvija F: \n";
    Compare(mas_x, mas_y, mas_a);
    if (err != 0) { goto ERROR; }
    else {
        cout << "Sootvetstvie F=<A, X, Y>=<";  Print(mas_a); cout << ","; PrintM(mas_x); cout << ","; PrintM(mas_y); cout << ">\n";
    }


    cout << "Vvedite mochnost' mnozhestva W: ";
    mas_w = ReadM(mas_w);

    cout << "Vvedite mochnost' mnozhestva Z: ";
    mas_z = ReadM(mas_z);

    cout << "Vvedite mochnost' graphika B: ";
    mas_b = Read(mas_b);


    cout << "Vozmozhnost' sozdanija sootvetstvija F: \n";
    Compare(mas_w, mas_z, mas_b);
    if (err != 0) { goto ERROR; }
    else {
        cout << "Sootvetstvie P=<B, W, Z>=<";  Print(mas_b); cout << ","; PrintM(mas_w); cout << ","; PrintM(mas_z); cout << ">\n";
    }

    Action();

    while (action != 0) {
        if (action < 9 || action == 13) {
            cout << "Sootvetstvie F=<A, X, Y>=<";  Print(mas_a); cout << ","; PrintM(mas_x); cout << ","; PrintM(mas_y); cout << ">\n";
            cout << "Sootvetstviya P=<B, W, Z>=<";  Print(mas_b); cout << ","; PrintM(mas_w); cout << ","; PrintM(mas_z); cout << ">\n";
        }
        switch (action) {
        case 1:                                                   /*Ob'edinenie*/
            Obed(mas_a, mas_b);
            mas_o = ObedM(mas_x, mas_w);
            mas_p = ObedM(mas_y, mas_z);
            cout << "Ob'edinenie sootvetstvij - L=<C, O, P>=<";  Print(mas_c); cout << ","; PrintM(mas_o); cout << ","; PrintM(mas_p); cout << ">\n";
            Action();                                                  //Вызов меню выбора
            break;

        case 2:                                      /*Peresechenie*/
            Perec(mas_a, mas_b);
            mas_o = PerecM(mas_x, mas_w);
            mas_p = PerecM(mas_y, mas_z);
            cout << "Peresechenie sootvetstvij - L=<C, O, P>=<";  Print(mas_c); cout << ","; PrintM(mas_o); cout << ","; PrintM(mas_p); cout << ">\n";


            Action();                                    //Вызов меню выбора
            break;

        case 3:                                         //*Raznost' 

            cout << "Operacia raznosti dlya sootvetstviy:\n1)dlya F&P \n2)dlya P&f\n";
            cin >> action;
            switch (action) {
            case 1:
                Razn(mas_a, mas_b);
                mas_o = RaznM(mas_x, mas_w);
                mas_p = RaznM(mas_y, mas_z);
                cout << "Raznost' sootvetstvij F&P - L=<C, O, P>=<";  Print(mas_c); cout << ","; PrintM(mas_o); cout << ","; PrintM(mas_p); cout << ">\n";
                break;
            case 2:
                Razn(mas_b, mas_a);
                mas_o = RaznM(mas_w, mas_x);
                mas_p = RaznM(mas_z, mas_y);
                cout << "Raznost' sootvetstvij P&F - L=<C, O, P>=<";  Print(mas_c); cout << ","; PrintM(mas_o); cout << ","; PrintM(mas_p); cout << ">\n";
                break;
            }

            Action();                                                                              //Вызов меню выбора
            break;

        case 4:             //simmetricheskaya rasnost
            Razn(mas_a, mas_b);
            Razn(mas_b, mas_a);
            mas_o = SR(mas_x, mas_w);

            mas_p = SR(mas_y, mas_z);

            cout << "Symmetricheskaya Raznost' sootvetstvij F&P - L=<C, O, P>=<";  Print(mas_c); cout << ","; PrintM(mas_o); cout << ","; PrintM(mas_p); cout << ">\n";


            Action();
            break;

        case 6:     //Kompozicia
            cout << "Operacia kompozicii dlya sootvetstviy:\n1)dlya F&P \n2)dlya P&f\n";
            cin >> action;
            switch (action) {
            case 1:
                Kompot(mas_a, mas_b);
                cout << "Kompozicija' sootvetstvij F&P - L=<C, X, Z>=<";  Print(mas_c); cout << ","; PrintM(mas_x); cout << ","; PrintM(mas_z); cout << ">\n";
                break;
            case 2:
                Kompot(mas_b, mas_a);
                cout << "Kompozicija' sootvetstvij P&F - L=<C, W, Y>=<";  Print(mas_c); cout << ","; PrintM(mas_w); cout << ","; PrintM(mas_y); cout << ">\n";
                break;
            }

            Action();
            break;

        case 5:                           //Inversia 
            cout << "Operacia inversii dlya sootvetstviy:\n1)dlya F \n2)dlya P\n";
            cin >> action;
            switch (action) {
            case 1:
                Invers(mas_a);
                cout << "Inversija sootvetstvija F - L=<C, Y, X>=<";  Print(mas_c); cout << ","; PrintM(mas_y); cout << ","; PrintM(mas_x); cout << ">\n";
                break;
            case 2:
                Invers(mas_b);
                cout << "Inversija sootvetstvija P - L=<C, Z, W>=<";  Print(mas_c); cout << ","; PrintM(mas_z); cout << ","; PrintM(mas_w); cout << ">\n";
                break;
            }

            Action();
            break;

        case 8:              //Proobraz
            cout << "Operacia proobraza dlya sootvetstviya:\n1)dlya F\n2)dlya P\n";
            cin >> action;
            switch (action) {
            case 1:
                cout << "Sootvetstvie F=<A, X, Y>=<";  Print(mas_a); cout << ","; PrintM(mas_x); cout << ","; PrintM(mas_y); cout << ">\n";
                mas_o = Proobraz(mas_y, mas_a);
                cout << "L= "; PrintM(mas_o); cout << "\n";
                break;
            case 2:
                cout << "Sootvetstvie P=<B, W, Z>=<";  Print(mas_b); cout << ","; PrintM(mas_w); cout << ","; PrintM(mas_z); cout << ">\n";
                mas_o = Proobraz(mas_z, mas_b);
                cout << "L= "; PrintM(mas_o); cout << "\n";
                break;
            }
            Action();
            break;

        case 7:              //Obraz
            cout << "Operacia obraza dlya sootvetstviya:\n1)dlya F\n2)dlya P\n";
            cin >> action;
            switch (action) {
            case 1:
                cout << "Sootvetstvie F=<A, X, Y>=<";  Print(mas_a); cout << ","; PrintM(mas_x); cout << ","; PrintM(mas_y); cout << ">\n";
                mas_o = Obraz(mas_x, mas_a);
                cout << "L= "; PrintM(mas_o); cout << "\n";
                break;
            case 2:
                cout << "Sootvetstvie P=<B, W, Z>=<";  Print(mas_b); cout << ","; PrintM(mas_w); cout << ","; PrintM(mas_z); cout << ">\n";
                mas_o = Obraz(mas_w, mas_b);
                cout << "L= "; PrintM(mas_o); cout << "\n";
                break;
            }
            Action();
            break;

        case 9:             //Suzhenie
            cout << "Operacia suzhenia dlya sootvetstviya:\n1)dlya F\n2)dlya P\n";
            cin >> action;
            switch (action) {
            case 1:
                cout << "Sootvetstvie F=<A, X, Y>=<";  Print(mas_a); cout << ","; PrintM(mas_x); cout << ","; PrintM(mas_y); cout << ">\n";

                cout << "Vvedie moshnost' mnozhestva X1: ";
                mas_o = ReadM(mas_o);
                mas_c = SuzhenieX(mas_x, mas_a, mas_o);
                cout << "Suzhenie sootvetstvija F na X - K=<C, X1, Y>=<";  Print(mas_c); cout << ","; PrintM(mas_o); cout << ","; PrintM(mas_y); cout << ">\n";



                break;
            case 2:
                cout << "Sootvetstvie P=<B, W, Z>=<";  Print(mas_b); cout << ","; PrintM(mas_w); cout << ","; PrintM(mas_z); cout << ">\n";

                cout << "Vvedie moshnost' mnozhestva W1: ";
                mas_o = ReadM(mas_o);
                mas_c = SuzhenieX(mas_w, mas_b, mas_o);
                cout << "Suzhenie sootvetstvija P na W - K=<C, W1, Z>=<";  Print(mas_c); cout << ","; PrintM(mas_o); cout << ","; PrintM(mas_z); cout << ">\n";

                break;
            }
            Action();
            break;

        case 10:             //Prodolzhenie
            cout << "Operacia prodolzheniya dlya sootvetstviya:\n1)dlya F\n2)dlya P\n";
            cin >> action;
            switch (action) {
            case 1:

                cout << "Vvedite mochnost' mnozhestva Z: ";
                mas_o = ReadM(mas_o);
                cout << "Vvedite mochnost' mnozhestva U: ";
                mas_p = ReadM(mas_p);
                cout << "Vvedite mochnost' graphika H: ";
                mas_c = Read(mas_c);
                Compare(mas_o, mas_p, mas_c);
                if (err != 0) { goto ERROR; }
                else {
                    cout << "Sootvetstvie C=<H, Z, U>=<";  Print(mas_c); cout << ","; PrintM(mas_o); cout << ","; PrintM(mas_p); cout << ">\n";
                }
                Prodolzhenie(mas_a, mas_c, mas_x, mas_y, mas_o, mas_p);
                cout << "Sootvetstviya F=<A, X, Y>=<";  Print(mas_a); cout << ","; PrintM(mas_x); cout << ","; PrintM(mas_y); cout << ">\n";
                break;
            case 2:
                cout << "Vvedite mochnost' mnozhestva Z: ";
                mas_o = ReadM(mas_o);
                cout << "Vvedite mochnost' mnozhestva U: ";
                mas_p = ReadM(mas_p);
                cout << "Vvedite mochnost' graphika H: ";
                mas_c = Read(mas_c);
                Compare(mas_o, mas_p, mas_c);
                if (err != 0) { goto ERROR; }
                else {
                    cout << "Sootvetstvie C=<H, Z, U>=<";  Print(mas_c); cout << ","; PrintM(mas_o); cout << ","; PrintM(mas_p); cout << ">\n";
                }
                Prodolzhenie(mas_b, mas_c, mas_w, mas_z, mas_o, mas_p);
                cout << "Sootvetstviya P=<B, W, Z>=<";  Print(mas_b); cout << ","; PrintM(mas_w); cout << ","; PrintM(mas_z); cout << ">\n";
                break;
            }
            Action();
            break;
        }

        mas_c.clear();
        mas_c.shrink_to_fit();
        mas_o.clear();
        mas_o.shrink_to_fit();
        mas_p.clear();
        mas_p.shrink_to_fit();

    }
ERROR:
    exit(0);
}