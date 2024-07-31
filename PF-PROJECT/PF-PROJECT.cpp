#include <iostream>
#include <string>

using namespace std;

// Function prototypes
void drawSquare(int size, char symbol);
void drawRectangle(int width, int height, char symbol);
void drawTriangle(int size, char symbol, bool upper, bool full);
void drawFullPyramid(int size, char symbol);
void drawDiamond(int size, char symbol);
void drawCircle(int radius, char symbol);
void drawHexagonal(int size, char symbol);

int main() {
    while (true) {
        cout << "Choose a shape to draw:" << endl;
        cout << "1. Square" << endl;
        cout << "2. Rectangle" << endl;
        cout << "3. Triangle" << endl;
        cout << "4. Full pyramid" << endl;
        cout << "5. Diamond" << endl;
        cout << "6. Circle" << endl;
        cout << "7. Hexagonal" << endl;
        cout << "8. Quit" << endl;

        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 8) {
            cout << "You Quit The Program!";
            break;
        }

        int size;
        cout << "Enter the size of the shape (number of rows): ";
        cin >> size;

        char symbol;
        cout << "Enter the symbol to use for the shape: ";
        cin >> symbol;

        switch (choice) {
        case 1:
            drawSquare(size, symbol);
            break;
        case 2:
            cout << "Enter the width of the rectangle: ";
            int width;
            cin >> width;
            cout << "Enter the height of the rectangle: ";
            int height;
            cin >> height;
            drawRectangle(width, height, symbol);
            break;
        case 3:
            cout << "Draw upper or lower triangle? (1 for upper, 2 for full, 3 for lower): ";
            int triangleChoice;
            cin >> triangleChoice;
            if (triangleChoice == 1) {
                drawTriangle(size, symbol, true, false);
            }
            else if (triangleChoice == 2) {
                drawTriangle(size, symbol, false, true);
            }
            else {
                drawTriangle(size, symbol, false, false);
            }
            break;
        case 4:
            drawFullPyramid(size, symbol);
            break;
        case 5:
            drawDiamond(size, symbol);
            break;
        case 6:
            cout << "Enter the radius of the circle: ";
            int radius;
            cin >> radius;
            drawCircle(radius, symbol);
            break;
        case 7:
            drawHexagonal(size, symbol);
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }

    return 0;
}


void drawSquare(int size, char symbol) {
    for (int i = 0; i < size; i++) {
        cout << symbol << " ";
    }
    cout << endl;

    for (int i = 0; i < size - 2; i++) {
        cout << symbol << " ";
        for (int j = 0; j < size - 2; j++) {
            cout << "  ";
        }
        cout << symbol << endl;
    }

    for (int i = 0; i < size; i++) {
        cout << symbol << " ";
    }
    cout << endl;
}


void drawRectangle(int width, int height, char symbol) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            cout << symbol << " ";
        }
        cout << endl;
    }
}

void drawTriangle(int size, char symbol, bool upper, bool full) {
    if (upper) {
        for (int row = 1; row <= size; row++) {
            for (int col = 1; col <= row; col++) {
                cout << symbol << " ";
            }
            cout << endl;
        }
    }
    else if (full) {
        for (int row = 1; row <= size; row++) {
            for (int col = 1; col <= size - row; col++) {
                cout << "  ";
            }
            for (int col = 1; col <= 2 * row - 1; col++) {
                cout << symbol << " ";
            }
            cout << endl;
        }
    }

    else {
        for (int row = size; row >= 1; row--) {
            for (int col = 1; col <= row; col++) {
                cout << symbol << " ";
            }
            cout << endl;
        }
    }
}

void drawFullPyramid(int size, char symbol) {
    for (int row = 1; row <= size; row++) {
        for (int col = 1; col <= size - row; col++) {
            cout << "  ";
        }
        for (int col = 1; col <= 2 * row - 1; col++) {
            cout << symbol << " ";
        }
        cout << endl;
    }
}

void drawDiamond(int size, char symbol) {
    for (int row = 1; row <= size; row++) {
        for (int col = 1; col <= size - row; col++) {
            cout << "  ";
        }
        for (int col = 1; col <= 2 * row - 1; col++) {
            cout << symbol << " ";
        }
        cout << endl;
    }
    for (int row = size - 1; row >= 1; row--) {
        for (int col = 1; col <= size - row; col++) {
            cout << "  ";
        }
        for (int col = 1; col <= 2 * row - 1; col++) {
            cout << symbol << " ";
        }
        cout << endl;
    }
}

void drawCircle(int radius, char symbol) {
    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius) {
                cout << symbol << " ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void drawHexagonal(int size, char symbol) {

    for (int i = 0; i < size; i++) {
        int elem = i + size;
        for (int j = 0; j < elem; j++) {
            if ((j == size + i - 1) || (j == size - i - 1)) {
                cout << symbol;
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }

    // Middle part of hexagonal
    for (int i = 0; i < size - 2; i++) {
        for (int j = 0; j < size * 2 - 1; j++) {
            if (j == 0 || j == size * 2 - 2) {
                cout << symbol;
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }


    // Lower part of hexagonal
    for (int i = size - 1; i >= 0; i--) {
        int elem = i + size;
        for (int j = 0; j < elem; j++) {
            if ((j == size + i - 1) || (j == size - i - 1)) {
                cout << symbol;
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}