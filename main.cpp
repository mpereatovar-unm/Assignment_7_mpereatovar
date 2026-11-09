
//Source code for the Electric_Field and Magnetic_Field classes
//
//

#include <iostream>  // For cout and endl
#include <cmath>     // For sqrt()
using namespace std;

// Class to store and calculate electric field values
class Electric_Field {
private:
    double *E;  // Pointer to an array for x, y, and z

public:
    // Default constructor: creates an array with all values at 0
    Electric_Field() { E = new double[3]{0, 0, 0}; }

    // Constructor: creates an array with given x, y, z values
    Electric_Field(double x, double y, double z) { E = new double[3]{x, y, z}; }

    // Destructor: frees the memory used by the array
    ~Electric_Field() { delete[] E; }

    // Setters: change the x, y, and z values
    void setX(double x) { E[0] = x; }
    void setY(double y) { E[1] = y; }
    void setZ(double z) { E[2] = z; }

    // Getters: return the x, y, and z values
    double getX() { return E[0]; }
    double getY() { return E[1]; }
    double getZ() { return E[2]; }

    // Calculates the magnitude using sqrt(x^2 + y^2 + z^2)
    double calculateMagnitude() { return sqrt(E[0]*E[0] + E[1]*E[1] + E[2]*E[2]); }

    // Calculates the inner product by adding the squared components
    double innerProduct() { return E[0]*E[0] + E[1]*E[1] + E[2]*E[2]; }
};

// Class to store and calculate magnetic field values
class Magnetic_Field {
private:
    double *B;  // Pointer to an array for x, y, and z

public:
    // Default constructor: starts all components at 0
    Magnetic_Field() { B = new double[3]{0, 0, 0}; }

    // Constructor: assigns the given x, y, z values
    Magnetic_Field(double x, double y, double z) { B = new double[3]{x, y, z}; }

    // Destructor: deletes the array to free memory
    ~Magnetic_Field() { delete[] B; }

    // Setters: change the magnetic field components
    void setX(double x) { B[0] = x; }
    void setY(double y) { B[1] = y; }
    void setZ(double z) { B[2] = z; }

    // Getters: return each magnetic field component
    double getX() { return B[0]; }
    double getY() { return B[1]; }
    double getZ() { return B[2]; }

    // Calculates the magnitude of the magnetic field
    double calculateMagnitude() { return sqrt(B[0]*B[0] + B[1]*B[1] + B[2]*B[2]); }

    // Finds the unit vector by dividing each component by the magnitude
    void unitVector() {
        double m = calculateMagnitude();  // Find the magnitude first
        cout << B[0]/m << ", " << B[1]/m << ", " << B[2]/m << endl;
    }
};

/*Personal notes about the program
The Electric_Field: class is used to store and manage the three components of an electric field:
 x, y, and z. Inside the private section, declared double *E, which is a pointer that will point to an array containing these three values. 
 private is used to prevent the values from being changed directly outside the class. 
 The public section contains the functions that allow to create, modify, and calculate information about the electric field
 The Magnetic_Field: The main difference is that it uses a pointer called B to store the magnetic field components. 
 It also has constructors, a destructor, getters, setters, and a function to calculate the magnitude.
However, instead of calculating the inner product, this class has a function to calculate the unit vector of the magnetic field.*/


// Main function where we create objects and test the classes
int main() {

    // Create an electric field using the default constructor
    Electric_Field E1;

    // Create another electric field with given components
    Electric_Field E2(1e5, 10.9, 1.7e2);

    // Use setters to assign values to E1
    E1.setX(3);
    E1.setY(4);
    E1.setZ(12);

    // Display the magnitude and inner product of both fields
    cout << "E1 magnitude: " << E1.calculateMagnitude() << endl;
    cout << "E1 inner product: " << E1.innerProduct() << endl;
    cout << "E2 magnitude: " << E2.calculateMagnitude() << endl;
    cout << "E2 inner product: " << E2.innerProduct() << endl;

    // Create a magnetic field using the default constructor
    Magnetic_Field B1;

    // Create another magnetic field with given components
    Magnetic_Field B2(2, 3, 6);

    // Use setters to assign values to B1
    B1.setX(1);
    B1.setY(2);
    B1.setZ(2);

    // Display the magnitude and unit vector of both magnetic fields
    cout << "B1 magnitude: " << B1.calculateMagnitude() << endl;
    cout << "B1 unit vector: ";
    B1.unitVector();

    cout << "B2 magnitude: " << B2.calculateMagnitude() << endl;
    cout << "B2 unit vector: ";
    B2.unitVector();

    return 0;  // End the program
}

/* Personal notes about the main function

The main() function is where the program starts running. 
In this lab, two classes to work with electric and magnetic fields in three dimensions. 
Each class stores the x, y, and z components in a dynamically allocated array.

The program creates two electric field objects, E1 and E2, and two magnetic field objects, B1 and B2. 
E1 and B1 use the default constructors, while E2 and B2 are created with specific values. 
Setters are used to change the components and getters to access them. 
The destructors free the allocated memory when the objects are destroyed.
Both classes calculate the magnitude of their fields. 
The electric field class also calculates the inner product, while the magnetic field class finds the unit vector. 
Finally, cout displays the results on the screen.
The main thing to remember is that constructors initialize objects, setters change values, getters return values, and destructors free memory.
*/