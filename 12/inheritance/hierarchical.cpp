// Converted from hierarchical.text

/**
 * HIERARCHICAL: Multiple classes are derived from one base class
 *              A
 *              |
 *         -----------
 *         |    |    |
 *         B    C    D
 * Where A is base class and B,C,D are derived classes.
 */

/**
 * EXAMPLE: Multiple types of vehicles derive from one base class
 */
class Vehicle {
  protected:
    int numberPlateNo;
    float weight; // Of the vehicle
    float maxFuel;
    int numWheels; // Number of wheels

  public:
    /**
     * @param npn Numberplate number
     * @param w Weight of the vehicle
     * @param m Max fuel
     */
    Vehicle(int npn, float w, float m) {
      numberPlateNo = npn;
      weight = w;
      maxFuel = m;
    }
};

class DviChakrika: public Vehicle {
  public:
    DviChakrika(int npn, float w, float m): Vehicle(npn, w, m) {
      numWheels = 2;
    }
};

class TriChakrika: public Vehicle {
  public:
    TriChakrika(int npn, float w, float m): Vehicle(npn, w, m) {
      numWheels = 3;
    }
};

/**
 * HYBRID: Combination of multiple and hierarchical
 *                  A
 *                  |
 *             -----------
 *             |    |    |
 *             B    C    D
 *               \/   \/
 *               E     F
 * Where A, B, C, D, E, F are all classes.
 */
