class Matrix{
    public:
     size_t mRows;
     size_t mCols;
    private:
     vector<long long> mdata;
    
    public:
     Matrix(size_t mRows,size_t cols);
     long long& operator()(size_t i,size_t j);
     long long operator()(size_t i,size_t j) const;
     Matrix operator * (const Matrix& B) ;
};

//constructor
Matrix::Matrix(size_t rows,size_t cols)
: mRows(rows),
  mCols(cols),
  mdata(rows * cols){}
//put data
long long& Matrix::operator()(size_t i,size_t j){
    return mdata[i * mCols +j];
}
//get Data
long long Matrix::operator()(size_t i,size_t j) const{
    return mdata[i * mCols +j];
}


// Multiplication operator
Matrix Matrix::operator * (const Matrix& B){
    Matrix C(mRows,B.mCols);
    for(int i=0;i<mRows;++i){
        for(int j=0;j<B.mCols;++j){
            C(i,j) =0;
            for(int k=0;k<B.mCols;++k){
                C(i,j) = ( C(i,j) + mdata[i*mCols+k] * B(k,j) )%1000000007;
            }
        }
    }
    return C;
}

Matrix Exponent(Matrix& A,long long n){
    Matrix res(2,2);
    res(0,0) =1; res(0,1) =0;
    res(1,0) =0; res(1,1) =1;
    while (n>0){
        if(n&1){
            res = res * A;
        }
        A=A*A;
        n=n>>1;
    }
    return res;
}

class Solution {
public:
    int fib(int N) {
        if(N==0) return 0;
        Matrix B(2,1);
    B(0,0) = 1; B(1,0) =0;
    //A^n-1 MAtrix
    Matrix A(2,2);
    A(0,0) =1; A(0,1) =1;
    A(1,0) =1; A(1,1) =0;
    Matrix res(2,1);
    res = Exponent( A, N-1) * B;
    return res(0,0);  
    }
};

