#include <iostream>
#include <math.h>
#include "./factorial.hpp"

const float pi = 3.1415926;

class Trigo {
  public:
    long double converted_angle;
    long double raw_angle;
    long double converted_value;
    long double raw_value;

    Trigo(float angleInDeg, int terms) {
      float angle = angleInDeg * (pi / 180);
      raw_angle = angle;

      while (angle > pi || angle < -pi) {
        if (angle > pi) angle -= 2.0*pi;
        if (angle < -pi) angle += 2.0*pi;
      }

      converted_angle = angle;
    }

    void dispAns() {
      cout << "Raw: " << raw_value << endl;
      cout << "Converted: " << converted_value << endl;
    }
};

class Sin: public Trigo {
  public:
    Sin(float angleInDeg, int terms): Trigo(angleInDeg, terms) {
      raw_value = calculate(raw_angle, terms);
      converted_value = calculate(converted_angle, terms);
    }

    long double calculate(float angle, int terms) {
      long double sine = 0;

      for (int i = 0; i < terms; i++) {
        sine += ( pow(angle, 2*i + 1) * pow(-1, i) ) / fact(2*i + 1);
      }

      return sine;
    }
};

class Cos: public Trigo {
  public:
    Cos(float angleInDeg, int terms): Trigo(angleInDeg, terms) {
      raw_value = calculate(raw_angle, terms);
      converted_value = calculate(converted_angle, terms);
    }

    long double calculate(float angle, int terms) {
      long double cosine = 0;

      for (int i = 0; i < terms; i++) {
        cosine += ( pow(angle, 2*i) * pow(-1, i) ) / fact(2*i);
      }

      return cosine;
    }
};

int main() {
  float angle;
  int terms;
  cout << "ANGLE IN DEG SANG: ";
  cin >> angle;

  cout << "KITLE TERMS RE?: ";
  cin >> terms;

  Sin s(angle, terms);
  Cos c(angle, terms);

  cout << "cos" << endl;
  c.dispAns();
  cout << "sin" << endl;
  s.dispAns();
}
