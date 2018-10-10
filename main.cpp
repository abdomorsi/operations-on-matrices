#include <iostream>
#include <iomanip>
#include <valarray>
#include <fstream>
using namespace std;

//a structure to store the matrix
struct matrix
{
    valarray < int > data;
    int row,col;
};

int arr [1000];
int row , col ;

/************************************************************/

void createMatrix (int row, int col, int num[], matrix& mat);


ostream& operator<< (ostream& out, matrix& mat)
{

  for(int i=0; i < mat.row*mat.col ; i++)

    {
        out << mat.data [i] << " ";

        if((i+1)%mat.col==0){cout << endl;}
    }

  return out;
}

/*************************************************************/

istream& operator>> (istream& in, matrix& mat)

{
    cout << endl << "Enter DIM of matrix = " ;

    in >> row >> col ;

     cout << endl << "Enter the matrix = " << endl;

    for(int i=0; i < row*col ; i++){ in >> arr [i] ;}

    createMatrix(row ,col ,arr,mat );

    return in;
}


/*************************************************************/

matrix operator+ (matrix mat1, matrix mat2)
{
    cin  >> mat2 ;

    matrix mat3;

    createMatrix ( row, col, arr , mat3);

    if(mat1.row==mat2.row && mat1.col==mat2.col)
    {

        for(int i=0; i < row*col ; i++)
            { mat3.data[i]= mat1.data[i] + mat2.data[i];}

    }

    cout << endl << "The Result = "<< endl << mat3;
    return (mat3) ;


}

/*************************************************************/

matrix operator* (matrix mat1, matrix mat2)
{
    cin  >> mat2 ;

    int cR = 0 , cC = 0 , s =0 , j=0 , NI = 1 , i=0 ;

    matrix mat3;

    createMatrix ( row = mat1.row , col = mat2.col , arr , mat3);

    if(mat2.row == mat1.col )
    {
        for ( int cM3 = 0 ; cM3 < mat3.row * mat3.col ; cM3++ )
        {
            for ( int cR = 0 ; i < mat1.row ; cR++  ){

                s += mat1.data[i] * mat2.data[j] ;

                i++;

                j += mat2.col ;

                cC++;

                if ( cC == mat2.col ) { cC = 0 ;  j = NI; NI++; }
            }

            mat3.data[ cM3 ] = s ;

            s = 0 ;

        }


    }

    cout << endl << "The Result = "<< endl << mat3;

    return (mat3) ;


}

/*************************************************************/


matrix operator- (matrix mat1, matrix mat2)
{
    cin  >> mat2 ;

    matrix mat3;

    createMatrix ( row, col, arr , mat3);

    if(mat1.row==mat2.row && mat1.col==mat2.col)
    {
            for(int i=0; i < row*col ; i++)
                { mat3.data[i]= mat1.data[i] - mat2.data[i];}
    }


    cout << endl << "The Result = "<< endl << mat3;
    return (mat3) ;

}

/**************************************************************/

matrix operator+= (matrix mat1, matrix mat2)
{
    cin /* >> mat1 */ >> mat2 ;

    matrix mat3;

    createMatrix ( row, col, arr , mat3);

    if(mat1.row==mat2.row && mat1.col==mat2.col)
    {
            for(int i=0; i < row*col ; i++)
                { mat1.data[i] = mat3.data[i] =  mat1.data[i] + mat2.data[i];}
    }



    cout << endl << "The Result = "<< endl << mat1;
    return (mat1) ;

}

/**************************************************************/

matrix operator-= (matrix mat1, matrix mat2)
{
    matrix mat3;

    createMatrix ( row, col, arr , mat3);

    if(mat1.row==mat2.row && mat1.col==mat2.col)
    {
            for(int i=0; i < row*col ; i++)
            { mat1.data[i] = mat3.data[i] =  mat1.data[i] - mat2.data[i];}
    }


    cout << endl << "The Result = "<< endl << mat3;
    return (mat1) ;

}

/**************************************************************/

matrix operator-= (matrix mat1, int num)
{
    cout << "your num = " ;
    cin >> num ;

    matrix mat3;

    createMatrix ( row, col, arr , mat3);

    for(int i=0; i < row*col ; i++)
        {  mat1.data[i] = mat3.data[i] =  mat1.data[i] - num ; }

    cout << endl << "The Result = "<< endl << mat3;
    return (mat3) ;


}

/**************************************************************/

matrix operator+= (matrix mat1, int num)
{
    cout << "your num = " ;
    cin  >> num ;

    matrix mat3;

    createMatrix ( row, col, arr , mat3 );

    for(int i=0; i < row*col ; i++)
        { mat1.data[i] = mat3.data[i] =  mat1.data[i] + num;}

    cout << endl << "The Result = "<< endl << mat1;

    return (mat1) ;
}

/***************************************************************/

matrix operator* (matrix mat1, int num)
{
    cout << "your num = " ;
    cin  >> num ;

    matrix mat3;

    createMatrix ( row, col, arr , mat3 );

    for(int i=0; i < row*col ; i++)
        { mat1.data[i] = mat3.data[i] =  mat1.data[i] * num;}

    cout << endl << "The Result = "<< endl << mat1;

    return (mat1) ;
}

/***************************************************************/


matrix operator++ (matrix mat1, int)
{
    int num = 1;

    matrix mat3;

    createMatrix ( row, col, arr , mat3);

    for(int i=0; i < row*col ; i++)
        {  mat1.data[i] = mat3.data[i] =  mat1.data[i] + num ; }

    cout << endl << "The Result = "<< endl << mat3;

    return (mat3) ;
}

/***************************************************************/

matrix operator-- (matrix mat1, int)
{
   // cin >> mat1 ;
   int num = 1;

    matrix mat3;

    createMatrix ( row, col, arr , mat3);

    for(int i=0; i < row*col ; i++)
        {  mat1.data[i] = mat3.data[i] =  mat1.data[i] - num ; }

    cout << endl << "The Result = "<< endl << mat3;

    return (mat3) ;
}

/**************************************************************/

bool operator== ( matrix mat1, matrix mat2)
{
    bool ans = false ;

    //cin >>  mat2 ;

    if(mat1.row==mat2.row && mat1.col==mat2.col)
    {
            ans = true ;

            for(int i=0; i < row*col ; i++)
            {
                if ( mat1.data[i] != mat2.data[i] ) { ans = false; break ; }
            }

    }


    return ans ;
}


/**************************************************************/

bool operator!= ( matrix mat1, matrix mat2)
{
    cin >> mat2 ;

    bool ans = false ;

    if(mat1.row==mat2.row && mat1.col==mat2.col)
    {
            ans = true ;

            for(int i=0; i < row*col ; i++)
            {
                if ( mat1.data[i] == mat2.data[i] ) { ans = false; break ; }
            }

    }

    return ans ;

}


/**************************************************************/

bool isSquare ( matrix mat1)
{
    bool ans = false ;

    if( mat1.row == mat1.col ){ ans = true ; }

    return ans ;
}

/**************************************************************/

matrix transpose (matrix mat1)
{
   // cin >> mat1 ;

    matrix mat3;

    createMatrix ( col, row, arr , mat3);

    int  c = 0;

    for ( int i = 0 , j = 0 ; i < row*col ;   i++  ){

        mat3.data[i] = mat1.data[j];
        j+=col;
        if ( j >= row*col ){ j = ++c ;  }

    }
    mat1 = mat3 ;

    cout << endl << "The Result = "<< endl << mat1;

    return (mat1);
}


/**************************************************************/

bool isSymetric ( matrix mat1)
{
    //matrix mat2;

    //createMatrix ( col, row, arr , mat2);
    matrix mat3;

    createMatrix ( col, row, arr , mat3);

    int  c = 0;

    for ( int i = 0 , j = 0 ; i < row*col ;   i++  ){

        mat3.data[i] = mat1.data[j];
        j+=col;
        if ( j >= row*col ){ j = ++c ;  }

    }

    bool ans = false ;

   // mat2 = transpose(mat1) ;

    if( ( mat1 ==  (transpose(mat1)) ) && mat1.col == mat1.row ){ ans = true ; }

    return ans ;
}


/**************************************************************/

bool isIdentity ( matrix mat1 )
{
    bool ans = false ;

    if ( isSquare(mat1) ) {

        for (int i=0 ; i < row*col   ; i+=(mat1.row+1) )
        {
            if ( mat1.data[i] == 1 ) {

                for (int j = i+1 ; j < (i + mat1.col) && j < row*col ; j++ ){

                    if ( mat1.data[j] == 0  ) { ans = true;  }

                    else { ans = false ;   break ; }

                }

            }

            else { ans = false ;  break; }

        }
    }

    return ans ;
}

/**************************************************************/




int main()
{
    cout << endl << "                ((( Operations on Matrices ))) " << endl << endl << endl ;
    int choose = 1 ;
    char type ;
    vector < string > v (17 , "") ;

    cout << "< A > Mathematics Operations " << "< B > Boolean Operations " << " < c > Transpose " << endl << endl  ;
    cout << "  1 >> ( + )  2 Matrices   " << "    1 >> ( == )  2 matrices" << endl;
    cout << "  2 >> ( - )  2 Matrices   " << "    2 >> ( != )  2 matrices" << endl;
    cout << "  3 >> ( * )  2 Matrices   " << "    3 >> ( isSqrt )  matrix" << endl;
    cout << "  4 >> ( + )  int , mat    " << "    4 >> ( isSmtrc ) matrix" << endl;
    cout << "  5 >> ( - )  int , mat    " << "    5 >> ( isIdent ) matrix" << endl;
    cout << "  6 >> ( *  ) int , mat    " << endl;
    cout << "  7 >> ( += ) 2 Matrices   " << endl;
    cout << "  8 >> ( -= ) 2 Matrices   " << endl;
    cout << "  9 >> ( += ) int , mat    " << endl;
    cout << " 10 >> ( -= ) int , mat    " << endl;
    cout << " 11 >> ( ++ ) mat + 1      " << endl;
    cout << " 12 >> ( -- ) mat - 1      " << endl;

    cout << endl <<  " < Q > Quit  " << endl << endl;

    cout << endl << "ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ" << endl ;

    cout << endl << "Enter the Type = " ;
    cin >> type ;




    while ( choose && type != 'Q' )
    {
        matrix mat1 , mat2 , mat3 ;

        //cout << endl << "Enter # operation = ";
        //cin >> choose ;
        //cin >> mat1  ;


        if ( type == 'A'  )
        {
            cout << endl << "Enter # operation = ";
            cin >> choose ;
            cin >> mat1  ;

            if ( choose == 1  ) {
                   mat3 = mat1 + mat2 ;
            }

            else if ( choose == 2  ) {
                   mat3 = mat1 - mat2 ;
            }

            else if ( choose == 3  ) {
                   mat3 = mat1 * mat2 ;
            }


            else if ( choose == 4  ) {

                    int num;
                    mat3 = mat1 ;
                    mat3 += num ;
             }

            else if ( choose == 5  ) {

                    int num;
                   mat3 = mat1 ;
                   mat3 -= num ;

            }

            else if ( choose == 6  ) {

                   int num ;
                   mat3 = mat1 * num;
            }

            else if ( choose == 7  ) {

                     mat1+=mat2 ;

            }

            else if ( choose == 8  ) {

                    mat1-=mat2 ;

            }

            else if ( choose == 9  ) {

                    int num;
                    mat1+=num ;

            }

            else if ( choose == 10  ) {

                    int num;
                    mat1-=num ;

            }

            else if ( choose == 11  ) {

                    mat1++ ;

            }

            else if ( choose == 12  ) {

                    mat1-- ;

            }

        } // big if

        else if ( type == 'B'  )
            {
                cout << endl << "Enter # operation = ";
                cin >> choose ;
                cin >> mat1  ;

                if ( choose == 1 ){

                    cin >> mat2 ;
                    if ( mat1 == mat2 ) { cout << endl << "True" << endl;  }
                    else { cout << endl << "False" << endl;  }

                }

                else if ( choose == 2 ){

                    if ( mat1 != mat2 ) { cout << endl << "True" << endl;  }
                    else { cout << endl << "False" << endl;  }

                }

                else if ( choose == 3 ){

                    if ( isSquare(mat1) ) { cout << endl << "True" << endl;  }
                    else { cout << endl << "False" << endl;  }

                }

                else if ( choose == 4 ){

                    matrix mat2 = transpose(mat1) ;

                    if( ( mat1 ==  mat2 ) &&( mat1.col == mat1.row ) ){ cout << endl << "True" << endl;  }
                    else { cout << endl << "False" << endl;  }

                }

                else if ( choose == 5 ){

                    if ( isIdentity(mat1) ) { cout << endl << "True" << endl;  }
                    else { cout << endl << "False" << endl;  }

                }



            } //if for Bool operations

            else if (type == 'C') { cin >> mat1  ; transpose(mat1);}



            cout << endl << "ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ" << endl << endl  <<  " DONE ! ...   " << endl << "ÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜ" << endl ;

            cout << endl << "Enter the Type = " ;
            cin >> type ;

    } //while






}


void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;

    mat.col = col;

    mat.data.resize ( row * col );

    for(int i = 0; i < row*col ; i++ )
       mat.data [i]= num [i];

}
