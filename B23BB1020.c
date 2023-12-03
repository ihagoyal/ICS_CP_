#include <stdio.h>
#include <math.h>


double linear_eq();
double quadratic_eq();
double cubic_eq();
double exponential_eq();
double linearSystem_eq();

int main() {
    char name;
    printf("Welcome to maths equation solver");
    printf("Enter your name:");
    scanf("%s",&name);
    int mCond;

    do {
        printf("\nLets start with the equation solver %s\n",name);
        printf("1. Solve Equations\n");
        printf("2. Exit the program\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &mCond);
        int eqCond;
        switch (mCond) {
            case 1:
                printf("\nChoose one from the Equation Solving Menu %s\n",name);
                printf("1. Linear Equation (ax + b = 0)\n");
                printf("2. Quadratic Equation (ax^2 + bx + c = 0)\n");
                printf("3. Cubic Equation \n");
                printf("4. Exponential Equation (a * exp(b * x) = c)\n");
                printf("5. Linear System (2x2)\n");
                printf("6. Back to Main Menu\n");

                printf("Enter your choice (1, 2, 3, 4, or 5) %s: ",name);
                scanf("%d", &eqCond);

                switch (eqCond) {
                    case 1:
                        linear_eq();
                        break;
                    case 2:
                        quadratic_eq();
                        break;
                    case 3:
                        cubic_eq();
                        break;
                    case 4:
                        exponential_eq();
                        break;
                    case 5:
                        linearSystem_eq();
                        break;
                    case 6:
                        printf("Returning to the main menu.\n");
                        break;
                    default:
                        printf("Invalid choice for equation solving. Please select 1, 2, 3, 4, or 5.\n");
                }
                break;
            case 2:
                printf("Program Exit\n");
                printf("ThankYou for using equation solver %s",name);
                return 0.0;
                break;
                

            default:
                printf("Invalid choice. Please select 1, 2, or 3.\n");
        }

    } while (mCond != 3);

    return 0;
}

double linear_eq() {
    double a, b;
    printf("\nEnter 'a' and 'b' for the linear equation (ax + b = 0):\n");
    printf("Enter 'a': ");
    scanf("%lf", &a);
    printf("Enter 'b': ");
    scanf("%lf", &b);

    if (a == 0) {
        if (b == 0) {
            printf("Infinite solutions (any value of x will satisfy the equation).\n");
        } else {
            printf("No solution (the equation is inconsistent).\n");
        }
    } else {
        double solution = -b / a;
        printf("Solution: x = %lf\n", solution);
    }
    return 0.0;
}

double quadratic_eq() {
    double a, b, c;
    printf("\nEnter 'a', 'b', and 'c' for the quadratic equation (ax^2 + bx + c = 0):\n");
    printf("Enter 'a': ");
    scanf("%lf", &a);
    printf("Enter 'b': ");
    scanf("%lf", &b);
    printf("Enter 'c': ");
    scanf("%lf", &c);

    double disc = b * b - 4 * a * c;

    if (a == 0) {
        printf("This is not a valid quadratic equation (a cannot be 0).\n");
    } else if (disc > 0) {
        double root1 = (-b + sqrt(disc)) / (2 * a);
        double root2 = (-b - sqrt(disc)) / (2 * a);
        printf("Solutions: x1 = %lf, x2 = %lf\n", root1, root2);
    } else if (disc == 0) {
        double root = -b / (2 * a);
        printf("Double root: x = %lf\n", root);
    } else {
        printf("No real solutions (discriminant is negative).\n");
    }
    return 0.0;
}
double cubic_eq() {
    double a, b, c, d;
    printf("\nEnter 'a', 'b', 'c', and 'd' for the cubic equation (ax^3 + bx^2 + cx + d = 0):\n");
    printf("Enter 'a': ");
    scanf("%lf", &a);
    printf("Enter 'b': ");
    scanf("%lf", &b);
    printf("Enter 'c': ");
    scanf("%lf", &c);
    printf("Enter 'd': ");
    scanf("%lf", &d);
    if (a == 0) {
        printf("This is not a valid cubic equation (a cannot be 0).\n");
        return 0.0;
    }

    // Cardano's formula for solving cubic equations
    double p = c / a - (b * b) / (3 * a * a);
    double q = (2 * b * b * b) / (27 * a * a * a) - (b * c) / (3 * a * a) + d / a;

    double delta = q * q / 4 + p * p * p / 27;

    if (delta > 0) {
        double A = -cbrt(-q / 2 + sqrt(delta));
        double B = -cbrt(-q / 2 - sqrt(delta));
        double root = A + B - b / (3 * a);
        printf("Solution: x = %lf\n", root);
    } else if (delta == 0) {
        double root = -2 * cbrt(-q / 2) - b / (3 * a);
        printf("Triple root: x = %lf\n", root);
    } else {
        double r = sqrt(-(p * p * p) / 27);
        double theta = acos(-q / (2 * r));
        double root1 = 2 * cbrt(r) * cos(theta / 3) - b / (3 * a);
        double root2 = 2 * cbrt(r) * cos((theta + 2 * M_PI) / 3) - b / (3 * a);
        double root3 = 2 * cbrt(r) * cos((theta - 2 * M_PI) / 3) - b / (3 * a);
        printf("Solutions: x1 = %lf, x2 = %lf, x3 = %lf\n", root1, root2, root3);
    }
    return 0.0;
}

double exponential_eq() {
    double a, b, c;
    printf("\nEnter 'a', 'b', and 'c' for the exponential equation (a * exp(b * x) = c):\n");
    printf("Enter 'a': ");
    scanf("%lf", &a);
    printf("Enter 'b': ");
    scanf("%lf", &b);
    printf("Enter 'c': ");
    scanf("%lf", &c);

    if (a == 0) {
        printf("No solution (a cannot be 0 in an exponential equation).\n");
    } else {
        double sol = log(c / a) / b;
        printf("Solution: x = %lf\n", sol);
    }
    return 0.0;
}

double linearSystem_eq() {
    double a1, b1, c1, a2, b2, c2;
    printf("\nEnter coefficients for the first linear equation (a1x + b1y = c1):\n");
    printf("Enter 'a1': ");
    scanf("%lf", &a1);
    printf("Enter 'b1': ");
    scanf("%lf", &b1);
    printf("Enter 'c1': ");
    scanf("%lf", &c1);

    printf("Enter coefficients for the second linear equation (a2x + b2y = c2):\n");
    printf("Enter 'a2': ");
    scanf("%lf", &a2);
    printf("Enter 'b2': ");
    scanf("%lf", &b2);
    printf("Enter 'c2': ");
    scanf("%lf", &c2);

    double det = a1 * b2 - a2 * b1;

    if (det == 0) {
        printf("The system has no unique solution (lines are parallel or coincide).\n");
    } else {
        double x = (c1 * b2 - c2 * b1) / det;
        double y = (a1 * c2 - a2 * c1) / det;
        printf("Solution: x = %lf, y = %lf\n",x,y);
    }
    return 0.0;
}
