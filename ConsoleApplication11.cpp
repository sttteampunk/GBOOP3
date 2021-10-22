#include <iostream>

using namespace std;

void obzac()
{
    std::cout << "\n\n//============================================================================//\n\n";
}

//task1
class Figure 
{
protected:
    virtual void area() = 0; 
};

class Parallelogram : protected Figure
{
protected:
    double base; 
    double height;
public:
    Parallelogram(double x_base, double v_height) : base(x_base), height(v_height) {}
    void area() override 
    {
        cout << "The parallelogram square is " << base * height << endl;
    }
  
};

class Circle : protected Figure
{
public:
    double radius;   
    double P;       
public:
    Circle(double x_radius, double v_p) : radius(x_radius), P(v_p = 3.14) {} 
    void area() override
    {
        cout << "The square of the circle is " << 3.14 * (radius * radius) << endl;
    }
};

class Rectangle : protected Parallelogram 
{
public:
    Rectangle(double x_base, double v_height) : Parallelogram(x_base, v_height) {}
    void area() override
    {
        cout << "The rectangle square is " << base * height << endl;
    }
};

class Square : protected Parallelogram 
{
public:
    Square(double x_base, double v_height) : Parallelogram(x_base, v_height) {}
    void area() override
    {
        cout << "The square of square is " << base * height << endl;
    }
};

class Rhombus : protected Parallelogram
{
public:
    Rhombus(double x_base, double v_height) : Parallelogram(x_base, v_height) {}
    void area() override
    {
        cout << "The rhombus square is " << base * height << endl;
    }
};

//task2
class Car
{
protected:
    string company, model;
public:
    Car() {}

    Car(string inputCompany, string inputModel) : company(inputCompany), model(inputModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "\n" << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }
    virtual ~Car()
    {
        cout << "\nДеструктор сработал!";
    }

};

class PassengerCar : virtual protected Car
{
public:

    PassengerCar() {}
    PassengerCar(string inputCompany, string inputModel) : Car(inputCompany, inputModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "\n" << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }
    ~PassengerCar()
    {
        cout << "\nДеструктор сработал!";
    }
};

class Bus : virtual protected Car
{
public:

    Bus() {}
    Bus(string inputCompany, string inputModel) : Car(inputCompany, inputModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "\n" << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }
    ~Bus()
    {
        cout << "\nДеструктор сработал!";
    }
};

class Minivan : public PassengerCar, public Bus
{
public:

    Minivan() {}
    Minivan(string inputCompany, string inputModel) : Car(inputCompany, inputModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "\n" << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }
    ~Minivan()
    {
        cout << "\nДеструктор сработал!";
    }
};

//task3
class Fraction
{
protected:
    double numerator, denominator; 
public:
    Fraction() {}
    Fraction(double iNumerator, double iDenominator) : numerator(iNumerator), denominator(iDenominator)
    {
        if (denominator == 0) denominator = 0.00000001; 
    }
    friend Fraction operator+(const Fraction& d1, const Fraction& d2); 
    friend Fraction operator-(const Fraction& d1, const Fraction& d2);
    friend Fraction operator*(const Fraction& d1, const Fraction& d2);
    friend Fraction operator/(const Fraction& d1, const Fraction& d2);
    friend Fraction operator-(const Fraction& d1); 

    

    double getNumerator() 
    {
        return numerator;
    }

    double getDenominator()
    {
        return denominator;
    }

    void Print()
    {
        cout << "Numerator:" << numerator << " denominator:" << denominator << endl;
    }

};

Fraction operator+(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator + d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator-(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator - d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator*(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.numerator, d1.denominator * d2.denominator);
}

Fraction operator/(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.numerator * d2.denominator, d1.denominator * d2.numerator);
}

Fraction operator-(const Fraction& d1)
{
    return Fraction(-d1.numerator, d1.denominator);
}

bool operator==(Fraction& d1, Fraction& d2) 
{
    if ((d1.getNumerator() == d2.getNumerator()) && (d1.getDenominator() == d2.getDenominator())) return true;
    else return false;
}

bool operator!=(Fraction& d1, Fraction& d2)
{
    if (d1 == d2) return false;
    else return true;
}

bool operator<(Fraction& d1, Fraction& d2)
{
    if ((d1.getNumerator() / d1.getDenominator()) < (d2.getNumerator() / d2.getDenominator())) return true;
    else return false;
}

bool operator>(Fraction& d1, Fraction& d2)
{
    if ((d1.getNumerator() / d1.getDenominator()) > (d2.getNumerator() / d2.getDenominator())) return true;
    else return false;
}

bool operator<=(Fraction& d1, Fraction& d2) 
{
    if (!(d1 > d2)) return true;
    else return false;
}

bool operator>=(Fraction& d1, Fraction& d2) 
{
    if (!(d1 < d2)) return true;
    else return false;
}


int main()
{
    {
        //task1
        obzac();
        double x_base;
        double v_height;
        cout << "Parallelogram\n" << "entered first value: ";
        cin >> x_base;
        cout << "entered second value: ";
        cin >> v_height;
        Parallelogram paral(x_base, v_height);
        paral.area();

        double x_radius;
        double P = 3.1415;
        cout << "Circle\n" << "entered radius: ";
        cin >> x_radius;
        Circle circ(x_radius, P);
        circ.area();

        cout << "Rectangle\n" << "entered first value: ";
        cin >> x_base;
        cout << "entered second value: ";
        cin >> v_height;
        Rectangle rect(x_base, v_height);
        rect.area();

        cout << "Square\n" << "entered first value: ";
        cin >> x_base;
        cout << "entered second value: ";
        cin >> v_height;
        Square squar(x_base, v_height);
        squar.area();

        cout << "Rombus\n" << "entered first value: ";
        cin >> x_base;
        cout << "entered second value: ";
        cin >> v_height;
        Rhombus romb(x_base, v_height);
        romb.area();

    }
    
    {
        //task2
        obzac();
        Car* car = new Car("lada", "samara");
        PassengerCar* passengercar = new PassengerCar("porche", "911");
        Bus* bus = new Bus("audi", "Q5");
        Minivan* minivan = new Minivan("tesla", "cybertruck");
        delete car;
        delete passengercar;
        delete bus;
        delete minivan;
    }

    {
        //task 3
        obzac();
        Fraction d1(6, 7);
        Fraction d2(3, 6);
        (d1 + d2).Print();
        (d1 - d2).Print();
        (d1 * d2).Print();
        (d1 / d2).Print();
        (-d1).Print();    
        if (d1 == d2) cout << "\nFraction 1 == Fraction 2";
        if (d1 != d2) cout << "\nFraction 1 != Fraction 2";
        if (d1 > d2) cout << "\nFraction 1 > Fraction 2";
        if (d1 <= d2) cout << "\nFraction 1 <= Fraction 2";
        if (d1 < d2) cout << "\nFraction 1 < Fraction 2";
        if (d1 >= d2) cout << "\nFraction 1 >= Fraction 2";       
    }
}