#include <iostream>
#include <string>

class Matrix
{
private:
    int col;
    int row;
    int matrix[20][20];
public:
    Matrix() : col(0), row(0)
    {
        srand(time(0));
        build();
    }
    Matrix(int col, int row) : col{ col }, row{ row }
    {
        srand(time(0));
        build();
    }
    void build()
    {
        for (size_t i = 0; i < col; i++)
        {
            for (size_t j = 0; j < row; j++)
            {
                matrix[i][j] = rand() % 99 + 1;
            }
        }
    }

    friend std::ostream& operator << (std::ostream& o, const Matrix& matrix)
    {
        for (size_t i = 0; i < matrix.col; i++)
        {
            for (size_t j = 0; j < matrix.row; j++)
            {
                o << matrix.matrix[i][j] << " ";
            }
            o << std::endl;
        }
        return o;
    }
    Matrix& operator-(const Matrix& submatrix)
    {
        Matrix diff(col, row);
        for (size_t i = 0; i < col; i++)
        {
            for (size_t j = 0; j < row; j++)
            {
                diff.matrix[i][j] = matrix[i][j] - submatrix.matrix[i][j];
            }
        }
        return diff;
    }
    Matrix& operator*(const Matrix& multmatrix)
    {
        Matrix prod(col, row);
        for (size_t i = 0; i < col; i++)
        {
            for (size_t j = 0; j < row; j++)
            {
                prod.matrix[i][j] = matrix[i][j] * multmatrix.matrix[i][j];
            }
        }
        return prod;
    }

};

int main()
{
    int col = 6;
    int row = 5;

    Matrix matrix1(col, row);
    Matrix matrix2(col, row);
    Matrix matrix3(col, row);
    matrix1.build();
    matrix2.build();
    matrix3.build();

    std::cout << "Matrix 1:\n";
    std::cout << matrix1;
    std::cout << "--------------\n";

    std::cout << "Matrix 2:\n";
    std::cout << matrix2;
    std::cout << "--------------\n";

    Matrix difference = matrix1 - matrix2;
    std::cout << "Matrix 1 - Matrix 2:\n";
    std::cout << difference;
    std::cout << "--------------\n";

    std::cout << "Matrix 3:\n";
    std::cout << matrix3;
    std::cout << "--------------\n";

    std::cout << "Matrix 1 * Matrix 3:\n";
    Matrix production = matrix1 * matrix3;
    std::cout << production;
}