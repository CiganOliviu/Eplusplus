//
// Created by cigan on 04.01.2021.
//

#ifndef EPLUSPLUS_IOSYSTEMMATRIX_H
#define EPLUSPLUS_IOSYSTEMMATRIX_H

#include "../DataStructures/OneDimensionalArray.h"

template <class Type> class AbstractIOSystemMatrixObject {

public:
    AbstractIOSystemMatrixObject() = default;

    [[maybe_unused]] virtual MatrixType<Type> ReadMatrix(unsigned int line, unsigned  int column) {}
    [[maybe_unused]] virtual MatrixType<Type> ReadMatrixFromFileWithGivenLength(const char * fileName) {}
    [[maybe_unused]] virtual MatrixType<Type> ReadMatrixFromFile(const char * fileName) {}

    [[maybe_unused]] virtual void OutputMatrix(MatrixType<Type> Matrix) {}
    [[maybe_unused]] virtual void OutputMatrixWithLength(MatrixType<Type> Matrix) {}
    [[maybe_unused]] virtual void OutputMatrixInFileWithLength(MatrixType<Type> Matrix, const char * fileName) {}
    [[maybe_unused]] virtual void OutputMatrixInFile(MatrixType<Type> Matrix, const char * fileName) {}

    ~AbstractIOSystemMatrixObject() = default;
};

template <class Type> class IOSystemMatrix : public AbstractIOSystemMatrixObject<Type> {
private:
    void CheckIfInputFileIsEmpty(std::ifstream &File);
    void CheckIfInputFileIsOpen(std::ifstream &File);
    void CheckIfOutputFileIsOpen(std::ofstream &File);
    bool LineAndLengthArePositive(unsigned int line, unsigned int column) const;
    MatrixType<Type> GetMatrixFromStdin(unsigned int line, unsigned int column) const;
    void PutsMatrixInStdout(MatrixType<Type> Matrix) const;
    int ReadFirstElementFromFile(std::ifstream &File) const;
    MatrixType<Type> GetMatrixWithGivenLengthFromStdFileIn(std::ifstream &File, unsigned int line, unsigned int column) const;
    void PutsMatrixInStdFileOut(std::ofstream &File, MatrixType<Type> Matrix);

public:
    IOSystemMatrix() = default;

    MatrixType<Type> ReadMatrix(unsigned int line, unsigned  int column) override;
    MatrixType<Type> ReadMatrixFromFileWithGivenLength(const char * fileName) override;
    MatrixType<Type> ReadMatrixFromFile(const char * fileName) override;

    void OutputMatrix(MatrixType<Type> Matrix) override;
    void OutputMatrixWithLength(MatrixType<Type> Matrix) override;
    void OutputMatrixInFileWithLength(MatrixType<Type> Matrix, const char * fileName) override;
    void OutputMatrixInFile(MatrixType<Type> Matrix, const char * fileName) override;

    ~IOSystemMatrix() = default;
};

template<class Type> void IOSystemMatrix<Type>::CheckIfInputFileIsEmpty(std::ifstream &File) {

    if (File.tellg() < 0)
        throw std::out_of_range("Unable to read from empty file");

}

template<class Type> void IOSystemMatrix<Type>::CheckIfInputFileIsOpen(std::ifstream &File) {

    if (!File.is_open())
        throw std::runtime_error("Unable to open file");
}

template<class Type> void IOSystemMatrix<Type>::CheckIfOutputFileIsOpen(std::ofstream &File) {

    if (!File.is_open())
        throw std::runtime_error("Unable to open file");
}

template<class Type> bool IOSystemMatrix<Type>::LineAndLengthArePositive(unsigned int line, unsigned int column) const {

    return line >= 0 && column >= 0;
}

template<class Type> MatrixType<Type> IOSystemMatrix<Type>::GetMatrixFromStdin(unsigned int line, unsigned int column) const {

    MatrixType<Type> Result;
    Result.SetLineOfMatrix(line);
    Result.SetColumnOfMatrix(column);
    Result.AllocMatrix();

    for (int it = 0; it < line; ++it)
        for (int jit = 0; jit < column ; ++jit)
            std::cin >> Result.GetMatrix()[it][jit];

    return Result;
}

template<class Type> void IOSystemMatrix<Type>::PutsMatrixInStdout(MatrixType<Type> Matrix) const {

    for (int it = 0; it < Matrix.GetLineOfMatrix(); ++it) {
        for (int jit = 0; jit < Matrix.GetColumnOfMatrix(); ++jit)
            std::cout << Matrix.GetMatrix()[it][jit] << " ";

        NEWLINE();
    }
}

template<class Type> int IOSystemMatrix<Type>::ReadFirstElementFromFile(std::ifstream &File) const {

    int firstElement;

    File >> firstElement;

    return firstElement;
}

template<class Type> MatrixType<Type> IOSystemMatrix<Type>::GetMatrixWithGivenLengthFromStdFileIn(std::ifstream &File, unsigned int line, unsigned int column) const {

    MatrixType<Type> Matrix;
    Matrix.SetLineOfMatrix(line);
    Matrix.SetColumnOfMatrix(column);
    Matrix.AllocMatrix();

    for (int it = 0; it < line; ++it)
        for (int jit = 0; jit < column; ++jit)
            File >> Matrix.GetMatrix()[it][jit];

    return Matrix;
}

template <class Type> void IOSystemMatrix<Type>::PutsMatrixInStdFileOut(std::ofstream &File, MatrixType<Type> Matrix) {

    for (int it = 0; it < Matrix.GetLineOfMatrix(); ++it) {
        for (int jit = 0; jit < Matrix.GetColumnOfMatrix(); ++jit)
            File << Matrix.GetMatrix()[it][jit] << " ";

        File << '\n';
    }
}

template<class Type> MatrixType<Type> IOSystemMatrix<Type>::ReadMatrix(unsigned int line, unsigned  int column) {

    assert(this->LineAndLengthArePositive(line, column));

    MatrixType<Type> Result = this->GetMatrixFromStdin(line, column);

    return Result;
}


template<class Type> MatrixType<Type> IOSystemMatrix<Type>::ReadMatrixFromFileWithGivenLength(const char * fileName) {

    std::ifstream WorkingFile(fileName, std::ios::in);

    this->CheckIfInputFileIsOpen(WorkingFile);
    this->CheckIfInputFileIsEmpty(WorkingFile);

    int line = this->ReadFirstElementFromFile(WorkingFile);
    int column = this->ReadFirstElementFromFile(WorkingFile);

    assert(this->LineAndLengthArePositive(line, column) >= 0);

    MatrixType<Type> Matrix = GetMatrixWithGivenLengthFromStdFileIn(WorkingFile, line, column);

    WorkingFile.close();

    return Matrix;
}

template<class Type> MatrixType<Type> IOSystemMatrix<Type>::ReadMatrixFromFile(const char * fileName) {

}

template<class Type> void IOSystemMatrix<Type>::OutputMatrix(MatrixType<Type> Matrix) {

    assert(this->LineAndLengthArePositive(Matrix.GetLineOfMatrix(), Matrix.GetColumnOfMatrix()));

    this->PutsMatrixInStdout(Matrix);
}

template<class Type> void IOSystemMatrix<Type>::OutputMatrixWithLength(MatrixType<Type> Matrix) {

    assert(this->LineAndLengthArePositive(Matrix.GetLineOfMatrix(), Matrix.GetColumnOfMatrix()));

    std::cout << Matrix.GetLineOfMatrix() << " " << Matrix.GetColumnOfMatrix();

    NEWLINE();

    this->PutsMatrixInStdout(Matrix);
}

template<class Type> void IOSystemMatrix<Type>::OutputMatrixInFileWithLength(MatrixType<Type> Matrix, const char * fileName) {

    assert(this->LineAndLengthArePositive(Matrix.GetLineOfMatrix(), Matrix.GetColumnOfMatrix()));

    std::ofstream WorkingFile(fileName, std::ios::out);

    this->CheckIfOutputFileIsOpen(WorkingFile);

    WorkingFile << Matrix.GetLineOfMatrix() << " " << Matrix.GetColumnOfMatrix() << '\n';

    this->PutsMatrixInStdFileOut(WorkingFile, Matrix);

    WorkingFile.close();
}

template<class Type> void IOSystemMatrix<Type>::OutputMatrixInFile(MatrixType<Type> Matrix, const char * fileName) {

}

template <class Type> class IOSystemMatrixFactoryObject {

public:
    IOSystemMatrixFactoryObject() = default;

    static std::shared_ptr<AbstractIOSystemMatrixObject<Type>> GetIOMatrixObject() {

        AbstractIOSystemMatrixObject<Type> * instance = new IOSystemMatrix<Type>();

        return std::shared_ptr<AbstractIOSystemMatrixObject<Type>>(instance);
    }

    ~IOSystemMatrixFactoryObject() = default;
};

#endif //EPLUSPLUS_IOSYSTEMMATRIX_H
