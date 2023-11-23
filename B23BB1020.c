#include <stdio.h>
#include <math.h>
void linear()
{
    double a, b;
    printf("Enter 'a' and 'b' for the linear equation (ax + b = 0):\n");
    printf("Enter 'a': ");
    scanf("%lf", &a);
    printf("Enter 'b': ");
    scanf("%lf", &b);

    if (a == 0)
    {
        if (b == 0)
        {
            printf("Infinite solutions (any value of x will satisfy the equation).\n");
        }
        else
        {
            printf("No solution (the equation is inconsistent).\n");
        }
    }
    else
    {
        double solution = -b / a;
        printf("Solution: x = %lf\n", solution);
    }
}
void quadratic()
{
    double a, b, c;
    printf("Enter 'a', 'b', and 'c' for the quadratic equation (ax^2 + bx + c = 0):\n");
    printf("Enter 'a': ");
    scanf("%lf", &a);
    printf("Enter 'b': ");
    scanf("%lf", &b);
    printf("Enter 'c': ");
    scanf("%lf", &c);

    double discriminant = b * b - 4 * a * c;

    if (a == 0)
    {
        printf("This is not a valid quadratic equation (a cannot be 0).\n");
    }
    else if (discriminant > 0)
    {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Solutions: x1 = %lf, x2 = %lf\n", root1, root2);
    }
    else if (discriminant == 0)
    {
        double root = -b / (2 * a);
        printf("Double root: x = %lf\n", root);
    }
    else
    {
        printf("No real solutions (discriminant is negative).\n");
    }
}
int main()
{
    int query;
    printf("Math Equation Solver\n");
    printf("1. Linear Equation (ax + b = 0)\n");
    printf("2. Quadratic Equation (ax^2 + bx + c = 0)\n");
    printf("3. Exit the program\n");
    printf("Enter your choice (1,2 or 3): ");
    scanf("%d", &query);

    if (query == 1)
    {
        linear();
    }
    else if (query == 2)
    {
        quadratic();
    }
    else if(query == 3)
    {
        printf("Program Exit");
        return 0;
    }
    else
    {
        printf("Invalid choice. Please select 1 for linear or 2 for quadratic equations.\n");
    }

}
