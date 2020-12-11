//
// Created by cigan on 10.12.2020.
//

#ifndef EPLUSPLUS_MATRIX_H
#define EPLUSPLUS_MATRIX_H

template <class Type> class AbstractMatrixTypeObject {

public:
    AbstractMatrixTypeObject() = default;

    virtual unsigned int GetLineOfMatrix() {};
    virtual void SetLineOfMatrix(unsigned int line) {}

    virtual unsigned int GetColumnOfMatrix() {};
    virtual void SetColumnOfMatrix(unsigned int column) {}

    virtual Type ** GetMatrix() {}
    virtual void SetMatrix(Type ** Array) {}

    ~AbstractMatrixTypeObject() = default;
};

template <class Type> class MatrixType : public AbstractMatrixTypeObject<Type> {

private:
    unsigned int _line {};
    unsigned int _column {};

    Type ** Matrix = (Type **) malloc(_line * sizeof(Type));

public:

    MatrixType() {

        for (int iterator = 0; iterator < length; ++iterator)
            this->Matrix[iterator] = (Type *) malloc(this->_line * sizeof(Type));
    }

    unsigned int GetLineOfMatrix() override {

        return this->_line;
    }

    void SetLineOfMatrix(unsigned int line) override {

        this->_line = line;
    }

    unsigned int GetColumnOfMatrix() override {

        return this->_column;
    }

    void SetColumnOfMatrix(unsigned int column) override {

        this->_column = column;
    }


    Type ** GetMatrix() override {

        return this->Matrix;
    }

    void SetMatrix(Type ** Array) override {

        this->Matrix = Array;
    }

    ~MatrixType() = default;
};

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
