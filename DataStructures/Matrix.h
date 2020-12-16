//
// Created by cigan on 10.12.2020.
//

#ifndef EPLUSPLUS_MATRIX_H
#define EPLUSPLUS_MATRIX_H

template <class Type> class AbstractMatrixTypeObject {

public:
    AbstractMatrixTypeObject() = default;

    [[maybe_unused]] virtual unsigned int GetLineOfMatrix() {};
    [[maybe_unused]] virtual void SetLineOfMatrix(unsigned int line) {}

    [[maybe_unused]] virtual unsigned int GetColumnOfMatrix() {};
    [[maybe_unused]] virtual void SetColumnOfMatrix(unsigned int column) {}

    [[maybe_unused]] virtual Type ** GetMatrix() {}
    [[maybe_unused]] virtual void SetMatrix(Type Array[][STANDARD_LENGTH]) {}

    ~AbstractMatrixTypeObject() = default;
};

template <class Type> class MatrixType : public AbstractMatrixTypeObject<Type> {

private:
    unsigned int _line {};
    unsigned int _column {};

    Type ** Matrix = (Type **) malloc(_line * sizeof(Type));

public:

    MatrixType() {

        for (int iterator = 0; iterator < this->_line; ++iterator)
            this->Matrix[iterator] = (Type *) malloc(this->_line * sizeof(Type));
    }

    unsigned int GetLineOfMatrix() override;
    void SetLineOfMatrix(unsigned int line) override;

    unsigned int GetColumnOfMatrix() override;
    void SetColumnOfMatrix(unsigned int column) override;

    Type ** GetMatrix() override;
    void SetMatrix(Type Array[][STANDARD_LENGTH]) override;

    ~MatrixType() = default;
};

template<class Type> unsigned int MatrixType<Type>::GetLineOfMatrix() {

    return this->_line;
}

template<class Type> void MatrixType<Type>::SetLineOfMatrix(unsigned int line) {

    this->_line = line;
}

template<class Type> unsigned int MatrixType<Type>::GetColumnOfMatrix() {

    return this->_column;
}

template<class Type> void MatrixType<Type>::SetColumnOfMatrix(unsigned int column) {

    this->_column = column;
}

template<class Type> Type ** MatrixType<Type>::GetMatrix() {

    return this->Matrix;
}

template<class Type> void MatrixType<Type>::SetMatrix(Type Array[][STANDARD_LENGTH]) {

    for (int iterator = 0; iterator < this->_line; ++iterator)
        this->Matrix[iterator] = Array[iterator];
}

template <class Type> class MatrixTypeFactoryObject {

public:
    MatrixTypeFactoryObject() = default;

    static std::shared_ptr<AbstractMatrixTypeObject<Type>> GetMatrixTypeObject() {

        AbstractMatrixTypeObject<Type> * instance = new MatrixType<Type>();

        return std::shared_ptr<AbstractMatrixTypeObject<Type>>(instance);
    }

    ~MatrixTypeFactoryObject() = default;
};

#endif //EPLUSPLUS_MATRIX_H
