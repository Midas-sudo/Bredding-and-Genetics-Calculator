#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substring(char s[], char sub[], int p, int l);

void main()
{
    char macho[50];
    char femea[50];
    int mA[2][2]= {{0,0,0,0},{0,0,0,0}};
    int mB[2][2]= {{0,0,0,0},{0,0,0,0}};
    int mC[2][2]= {{0,0,0,0},{0,0,0,0}};
    int mD[2][2]= {{0,0,0,0},{0,0,0,0}};

    int fA[2][2]= {{0,0,0,0},{0,0,0,0}};
    int fB[2][2]= {{0,0,0,0},{0,0,0,0}};
    int fC[2][2]= {{0,0,0,0},{0,0,0,0}};
    int fD[2][2]= {{0,0,0,0},{0,0,0,0}};

    int A[2][2]= {{0,0,0,0},{0,0,0,0}};
    int B[2][2]= {{0,0,0,0},{0,0,0,0}};
    int C[2][2]= {{0,0,0,0},{0,0,0,0}};
    int D[2][2]= {{0,0,0,0},{0,0,0,0}};

    int hi[2][2]= {{0,0,0,0},{0,0,0,0}};
    int hm[2][2]= {{0,0,0,0},{0,0,0,0}};


    printf("Insere Cruzamento do Macho:\n");
    gets(macho);
    printf("Insere Cruzamento do Macho:\n");
    gets(femea);


    char inicio1[3];


    substring(femea, inicio1, 0, 2);
    char ro[3] = "Ro";
    char si[3] = "Si";
    int iro = strcmp(inicio1,ro);
    int isi = strcmp(inicio1,si);
    if(iro==0){
        rot(macho, femea, mA, mB, mC, mD);
    }else{
    m_sel(macho, mA, mB, mC, mD);
    f_sel(femea, fA, fB, fC, fD, hm);
    }

    if(isi==0){
        if(strlen(macho)== 15){
                hi[0][0] = 2*(mA[0][0] * mB[0][0]);
                hm[0][0] = 2*(mA[0][0] * mB[0][0]);
                hi[0][1] = ((mA[0][1]/2) * (mB[0][1]/2));
                hm[0][1] = ((mA[0][1]/2) * (mB[0][1]/2));
        }else{
                hi[0][0] = 2*(mA[0][0] * mB[0][0] * mC[0][0]);
                hm[0][0] = 2*(mA[0][0] * mB[0][0] * mC[0][0]);
                hi[0][1] = ((mA[0][1]/2) * (mB[0][1]/2) * (mC[0][1]/2));
                hm[0][1] = ((mA[0][1]/2) * (mB[0][1]/2) * (mC[0][1]/2));
        }

    }else{
        char tipo1, tipo2, tipo3, tipo4;
        if((strlen(macho) == 1) && strlen(femea) !=1 ){
            tipo1 = macho[0];
            tipo3 = femea[3];
            tipo4 = femea[4];
            if ((tipo1 != tipo3) && (tipo1 != tipo4)){
                hi[0][0]=1;
                hi[0][1]=1;
            }else if (((tipo1 == tipo3) && (tipo1!=tipo4))||((tipo1 != tipo3) && (tipo1 == tipo4))){
                hi[0][0]=1;
                hi[0][1]=2;
            }
        }else if((strlen(macho) != 1) && strlen(femea) == 1){
            tipo1 = macho[3];
            tipo2 = macho[4];
            tipo3 = femea[0];
            if ((tipo1 != tipo3) && (tipo2 != tipo3)){
                hi[0][0]=1;
                hi[0][1]=1;
            }else if (((tipo1 == tipo3) && (tipo2!=tipo3))||((tipo1 != tipo3) && (tipo2 == tipo3))){
                hi[0][0]=1;
                hi[0][1]=2;
            }
        }else if((strlen(macho) != 1) && strlen(femea) != 1){
            tipo1 = macho[3];
            tipo2 = macho[4];
            tipo3 = femea[3];
            tipo4 = femea[4];
            if ((tipo1 != tipo3) && (tipo1 != tipo4) && (tipo3 != tipo3) && (tipo2 != tipo4)){
                hi[0][0]=1;
                hi[0][1]=1;
            }else if (((tipo1 == tipo3) && (tipo2!=tipo4))||((tipo1 != tipo3) && (tipo2 == tipo4))||((tipo1 == tipo4) && (tipo2!=tipo3))||((tipo1 != tipo4) && (tipo2 == tipo3))){
                hi[0][0]=3;
                hi[0][1]=4;
            }

        }
    }
//////////////////


    if(mA[0][0]==0 && fA[0][0]!=0){
        A[0][0]= fA[0][0];
        A[0][1]= fA[0][1];
    }else if(mA[0][0]!=0 && fA[0][0]==0){
        A[0][0]= mA[0][0];
        A[0][1]= mA[0][1];
    }else if(mA[0][0]!=0 && fA[0][0]!=0){
        addFraction(mA, fA, A);
    }
    if(mB[0][0]==0 && fB[0][0]!=0){
        B[0][0]= fB[0][0];
        B[0][1]= fB[0][1];
    }else if(mB[0][0]!=0 && fB[0][0]==0){
        B[0][0]= mB[0][0];
        B[0][1]= mB[0][1];
    }else if(mB[0][0]!=0 && fB[0][0]!=0){
        addFraction(mB, fB, B);
    }
    if(mC[0][0]==0 && fC[0][0]!=0){
        C[0][0]= fC[0][0];
        C[0][1]= fC[0][1];
    }else if(mC[0][0]!=0 && fC[0][0]==0){
        C[0][0]= mC[0][0];
        C[0][1]= mC[0][1];
    }else if(mC[0][0]!=0 && fC[0][0]!=0){
        addFraction(mC, fC, C);
    }
    if(mD[0][0]==0 && fD[0][0]!=0){
        D[0][0]= fD[0][0];
        D[0][1]= fD[0][1];
    }else if(mD[0][0]!=0 && fD[0][0]==0){
        D[0][0]= mD[0][0];
        D[0][1]= mD[0][1];
    }else if(mD[0][0]!=0 && fD[0][0]!=0){
        addFraction(mD, fD, D);
    }



    printf("\n\n-----Resultados Finais:-----\n\n");

    printf("     || gA - %d/%d ||\n", A[0][0], A[0][1]);
    printf("     || gB - %d/%d ||\n", B[0][0], B[0][1]);
    printf("     || gC - %d/%d ||\n", C[0][0], C[0][1]);
    printf("     || gD - %d/%d ||\n", D[0][0], D[0][1]);

    printf("     || mA - %d/%d ||\n", fA[1][0], fA[1][1]);
    printf("     || mB - %d/%d ||\n", fB[1][0], fB[1][1]);
    printf("     || mC - %d/%d ||\n", fC[1][0], fC[1][1]);
    printf("     || mD - %d/%d ||\n", fD[1][0], fD[1][1]);

    printf("     || hi - %d/%d ||\n", hi[0][0], hi[0][1]);
    printf("     || hm - %d/%d ||\n", hm[0][0], hm[0][1]);

    printf("----------------------------\n");




    main();
}

void m_sel(char macho[], int mA[2][2], int mB[2][2], int mC[2][2], int mD[2][2]){
    char inicio[3];
    substring(macho, inicio, 0, 2);
    char f1[3] = "F1";
    char f2[3] = "F2";
    char si[3] = "Si";

    char aa[3] = "A(";
    char bb[3] = "B(";
    char cc[3] = "C(";
    char dd[3] = "D(";

    int if1 = strcmp(inicio,f1);
    int if2 = strcmp(inicio,f2);
    int isi = strcmp(inicio,si);

    int iaa = strcmp(inicio,aa);
    int ibb = strcmp(inicio,bb);
    int icc = strcmp(inicio,cc);
    int idd = strcmp(inicio,dd);

    if(if1 == 0){
        m_gen1(macho, mA, mB, mC, mD);
    }else if(if2 == 0){
        m_gen2(macho, mA, mB, mC, mD);
    }else if(isi == 0){
        m_sint(macho, mA, mB, mC, mD);
    }else if((inicio == aa)||((inicio == 'B('))||((inicio == 'C('))||((inicio == 'D('))){
        //m_trip(macho, mA, mB, mC, mD);
    }else{
        m_puro(macho, mA, mB, mC, mD);
    }
}

void f_sel(char femea[], int fA[2][2], int fB[2][2], int fC[2][2], int fD[2][2], int hm[2][2]){
    char inicio[3];
    substring(femea, inicio, 0, 2);
    char f1[3] = "F1";
    char f2[3] = "F2";
    char si[3] = "Si";
    char ro[3] = "Ro";
    char aa[3] = "A(";
    char bb[3] = "B(";
    char cc[3] = "C(";
    char dd[3] = "D(";

    int if1 = strcmp(inicio,f1);
    int if2 = strcmp(inicio,f2);
    int isi = strcmp(inicio,si);
    int iro = strcmp(inicio,ro);
    int iaa = strcmp(inicio,aa);
    int ibb = strcmp(inicio,bb);
    int icc = strcmp(inicio,cc);
    int idd = strcmp(inicio,dd);

    if(if1 == 0){
        f_gen1(femea, fA, fB, fC, fD, hm);
    }else if(if2 == 0){
        f_gen2(femea, fA, fB, fC, fD, hm);
    }else if(isi == 0){
        f_sint(femea, fA, fB, fC, fD, hm);
    }else if((iaa == 0)||((ibb == 0))||((icc == 0))||((idd == 0))){
        //f_trip(femea, fA, fB, fC, fD);
    }else{
        f_puro(femea, fA, fB, fC, fD, hm);
    }
}

void m_puro(char macho[], int mA[2][2], int mB[2][2], int mC[2][2], int mD[2][2]){
    char serie = macho[0];
    switch(serie){
    case 'A':
        mA[0][0]++;
        mA[0][1]=+2;
        break;
    case 'B':
        mB[0][0]++;
        mB[0][1]=+2;
        break;
    case 'C':
        mC[0][0]++;
        mC[0][1]=+2;
        break;
    case 'D':
        mD[0][0]++;
        mD[0][1]=+2;
        break;
    }
}


void f_puro(char femea[], int fA[2][2], int fB[2][2], int fC[2][2], int fD[2][2], int hm[2][2]){
    char serie = femea[0];
    switch(serie){
    case 'A':
        fA[0][0]++;
        fA[0][1]=+2;
        fA[1][0]++;
        fA[1][1]++;
        break;
    case 'B':
        fB[0][0]++;
        fB[0][1]=+2;
        fB[1][0]++;
        fB[1][1]++;
        break;
    case 'C':
        fC[0][0]++;
        fC[0][1]=+2;
        fC[1][0]++;
        fC[1][1]++;
        break;
    case 'D':
        fD[0][0]++;
        fD[0][1]=+2;
        fD[1][0]++;
        fD[1][1]++;
        break;
    }
}

void m_gen1(char macho[], int mA[2][2], int mB[2][2], int mC[2][2], int mD[2][2]){
    char serie1 = macho[3];
    char serie2 = macho[4];

    switch(serie1){
    case 'A':
        mA[0][0]++;
        mA[0][1]=+4;
        break;
    case 'B':
        mB[0][0]++;
        mB[0][1]=+4;
        break;
    case 'C':
        mC[0][0]++;
        mC[0][1]=+4;
        break;
    case 'D':
        mD[0][0]++;
        mD[0][1]=+4;
        break;
    }

    switch(serie2){
    case 'A':
        mA[0][0]++;
        mA[0][1]=+4;
        break;
    case 'B':
        mB[0][0]++;
        mB[0][1]=+4;
        break;
    case 'C':
        mC[0][0]++;
        mC[0][1]=+4;
        break;
    case 'D':
        mD[0][0]++;
        mD[0][1]=+4;
        break;
    }

}


void f_gen1(char femea[], int fA[2][2], int fB[2][2], int fC[2][2], int fD[2][2], int hm[2][2]){
    char serie1 = femea[3];
    char serie2 = femea[4];

    switch(serie1){
    case 'A':
        fA[0][0]++;
        fA[0][1]=+4;
        fA[1][0]++;
        fA[1][1]=+2;
        hm[0][0]++;
        hm[0][1]++;
        break;
    case 'B':
        fB[0][0]++;
        fB[0][1]=+4;
        fB[1][0]++;
        fB[1][1]=+2;
        hm[0][0]++;
        hm[0][1]++;
        break;
    case 'C':
        fC[0][0]++;
        fC[0][1]=+4;
        fC[1][0]++;
        fC[1][1]=+2;
        hm[0][0]++;
        hm[0][1]++;
        break;
    case 'D':
        fD[0][0]++;
        fD[0][1]=+4;
        fD[1][0]++;
        fD[1][1]=+2;
        hm[0][0]++;
        hm[0][1]++;
        break;
    }
    switch(serie2){
    case 'A':
        fA[0][0]++;
        fA[0][1]=+4;
        fA[1][0]++;
        fA[1][1]=+2;
        break;
    case 'B':
        fB[0][0]++;
        fB[0][1]=+4;
        fB[1][0]++;
        fB[1][1]=+2;
        break;
    case 'C':
        fC[0][0]++;
        fC[0][1]=+4;
        fC[1][0]++;
        fC[1][1]=+2;
        break;
    case 'D':
        fD[0][0]++;
        fD[0][1]=+4;
        fD[1][0]++;
        fD[1][1]=+2;
        break;
    }

}


void m_gen2(char macho[], int mA[2][2], int mB[2][2], int mC[2][2], int mD[2][2]){
    char serie1 = macho[3];
    char serie2 = macho[4];

    switch(serie1){
    case 'A':
        mA[0][0]++;
        mA[0][1]=+4;
        break;
    case 'B':
        mB[0][0]++;
        mB[0][1]=+4;
        break;
    case 'C':
        mC[0][0]++;
        mC[0][1]=+4;
        break;
    case 'D':
        mD[0][0]++;
        mD[0][1]=+4;
        break;
    }

    switch(serie2){
    case 'A':
        mA[0][0]++;
        mA[0][1]=+4;
        break;
    case 'B':
        mB[0][0]++;
        mB[0][1]=+4;
        break;
    case 'C':
        mC[0][0]++;
        mC[0][1]=+4;
        break;
    case 'D':
        mD[0][0]++;
        mD[0][1]=+4;
        break;
    }

}


void f_gen2(char femea[], int fA[2][2], int fB[2][2], int fC[2][2], int fD[2][2], int hm[2][2]){
    char serie1 = femea[3];
    char serie2 = femea[4];

    switch(serie1){
    case 'A':
        fA[0][0]++;
        fA[0][1]=+4;
        fA[1][0]++;
        fA[1][1]=+2;
        hm[0][0]++;
        hm[0][1]=+2;
        break;
    case 'B':
        fB[0][0]++;
        fB[0][1]=+4;
        fB[1][0]++;
        fB[1][1]=+2;
        hm[0][0]++;
        hm[0][1]=+2;
        break;
    case 'C':
        fC[0][0]++;
        fC[0][1]=+4;
        fC[1][0]++;
        fC[1][1]=+2;
        hm[0][0]++;
        hm[0][1]=+2;
        break;
    case 'D':
        fD[0][0]++;
        fD[0][1]=+4;
        fD[1][0]++;
        fD[1][1]=+2;
        hm[0][0]++;
        hm[0][1]=+2;
        break;
    }
    switch(serie2){
    case 'A':
        fA[0][0]++;
        fA[0][1]=+4;
        fA[1][0]++;
        fA[1][1]=+2;
        break;
    case 'B':
        fB[0][0]++;
        fB[0][1]=+4;
        fB[1][0]++;
        fB[1][1]=+2;
        break;
    case 'C':
        fC[0][0]++;
        fC[0][1]=+4;
        fC[1][0]++;
        fC[1][1]=+2;
        break;
    case 'D':
        fD[0][0]++;
        fD[0][1]=+4;
        fD[1][0]++;
        fD[1][1]=+2;
        break;
    }

}


void m_sint(char macho[], int mA[2][2], int mB[2][2], int mC[2][2], int mD[2][2]){
    int size = strlen(macho);
    char shorty[size];
    substring(macho, shorty, 6, size-6);
    int counter = 0;
    int counter1 = 0;
    int counter2 = 0;
    char A1[10] = "";
    char B1[10] = "";
    char C1[10] = "";
    char D1[10] = "";
    char A2[10] = "";
    char B2[10] = "";
    char C2[10] = "";
    char D2[10] = "";
    int check[4] = {0,0,0,0};

    while((isdigit(shorty[counter]))||shorty[counter]== '/'){
            if(shorty[counter]== '/'){
                check[0]++;
                counter++;
                continue;
            }
            if(check[0] == 1){
                A2[counter2] = shorty[counter];
                counter++;
                counter2++;
            }else{
                A1[counter1] = shorty[counter];
                counter++;
                counter1++;

            }
    }
    counter++;
    counter1=0;
    counter2=0;
    while((isdigit(shorty[counter]))||shorty[counter]== '/'){
            if(shorty[counter]== '/'){
                check[1]++;
                counter++;
                continue;
            }
            if(check[1] == 1){
                B2[counter2] = shorty[counter];
                counter++;
                counter2++;
            }else{
                B1[counter1] = shorty[counter];
                counter++;
                counter1++;

            }

    }
    counter++;
    counter1=0;
    counter2=0;
    while((isdigit(shorty[counter]))||shorty[counter]== '/'){
            if(shorty[counter]== '/'){
                check[2]++;
                counter++;
                continue;
            }
            if(check[2] == 1){
                C2[counter2] = shorty[counter];
                counter++;
                counter2++;
            }else{
                C1[counter1] = shorty[counter];
                counter++;
                counter1++;

            }
    }
    counter++;
    counter1=0;
    counter2=0;
    while((isdigit(shorty[counter]))||shorty[counter]== '/'){
            if(shorty[counter]== '/'){
                check[3]++;
                counter++;
                continue;
            }
            if(check[3] == 1){
                D2[counter2] = shorty[counter];
                counter++;
                counter2++;
            }else{
                D1[counter1] = shorty[counter];
                counter++;
                counter1++;

            }
    }

    int a1 = atoi(A1);
    int a2 = atoi(A2);
    int b1 = atoi(B1);
    int b2 = atoi(B2);
    int c1 = atoi(C1);
    int c2 = atoi(C2);
    int d1 = atoi(D1);
    int d2 = atoi(D2);


    mA[0][0]= a1;
    mB[0][0]= b1;
    mC[0][0]= c1;
    mD[0][0]= d1;

    mA[0][1]= a2*2;
    mB[0][1]= b2*2;
    mC[0][1]= c2*2;
    mD[0][1]= d2*2;

}


void f_sint(char femea[], int fA[2][2], int fB[2][2], int fC[2][2], int fD[2][2]){
    int size = strlen(femea);
    char shorty[size];
    substring(femea, shorty, 6, size-6);
    int counter = 0;
    int counter1 = 0;
    int counter2 = 0;
    char A1[10] = "";
    char B1[10] = "";
    char C1[10] = "";
    char D1[10] = "";
    char A2[10] = "";
    char B2[10] = "";
    char C2[10] = "";
    char D2[10] = "";
    int check[4] = {0,0,0,0};

    while((isdigit(shorty[counter]))||shorty[counter]== '/'){
            if(shorty[counter]== '/'){
                check[0]++;
                counter++;
                continue;
            }
            if(check[0] == 1){
                A2[counter2] = shorty[counter];
                counter++;
                counter2++;
            }else{
                A1[counter1] = shorty[counter];
                counter++;
                counter1++;

            }
    }
    counter++;
    counter1=0;
    counter2=0;
    while((isdigit(shorty[counter]))||shorty[counter]== '/'){
            if(shorty[counter]== '/'){
                check[1]++;
                counter++;
                continue;
            }
            if(check[1] == 1){
                B2[counter2] = shorty[counter];
                counter++;
                counter2++;
            }else{
                B1[counter1] = shorty[counter];
                counter++;
                counter1++;

            }

    }
    counter++;
    counter1=0;
    counter2=0;
    while((isdigit(shorty[counter]))||shorty[counter]== '/'){
            if(shorty[counter]== '/'){
                check[2]++;
                counter++;
                continue;
            }
            if(check[2] == 1){
                C2[counter2] = shorty[counter];
                counter++;
                counter2++;
            }else{
                C1[counter1] = shorty[counter];
                counter++;
                counter1++;

            }
    }
    counter++;
    counter1=0;
    counter2=0;
    while((isdigit(shorty[counter]))||shorty[counter]== '/'){
            if(shorty[counter]== '/'){
                check[3]++;
                counter++;
                continue;
            }
            if(check[3] == 1){
                D2[counter2] = shorty[counter];
                counter++;
                counter2++;
            }else{
                D1[counter1] = shorty[counter];
                counter++;
                counter1++;

            }
    }

    int a1 = atoi(A1);
    int a2 = atoi(A2);
    int b1 = atoi(B1);
    int b2 = atoi(B2);
    int c1 = atoi(C1);
    int c2 = atoi(C2);
    int d1 = atoi(D1);
    int d2 = atoi(D2);


    fA[0][0]= a1;
    fB[0][0]= b1;
    fC[0][0]= c1;
    fD[0][0]= d1;

    fA[0][1]= a2*2;
    fB[0][1]= b2*2;
    fC[0][1]= c2*2;
    fD[0][1]= d2*2;

    fA[1][0]= a1;
    fB[1][0]= b1;
    fC[1][0]= c1;
    fD[1][0]= d1;

    fA[1][1]= a2;
    fB[1][1]= b2;
    fC[1][1]= c2;
    fD[1][1]= d2;

}



void rot(char macho[],char femea[], int mA[2][2], int mB[2][2], int mC[2][2], int mD[2][2]){
    char inicio = macho[0];
    int h[2][2]={{0,0,0,0},{0,0,0,0}};
    if(strlen(femea)==7){
            char membro1 = femea[4];
            char membro2 = femea[6];
            h[0][0]=2;
            h[0][1]=3;
            switch(inicio){
            case 'A':
                if((membro2 == 'B')){
                    mA[0][0]=2;
                    mA[0][1]=3;
                    mB[0][0]=1;
                    mB[0][1]=3;

                    mA[1][0]=1;
                    mA[1][1]=3;
                    mB[1][0]=2;
                    mB[1][1]=3;
                }
                else if((membro2 == 'C')){
                    mA[0][0]=2;
                    mA[0][1]=3;
                    mC[0][0]=1;
                    mC[0][1]=3;

                    mA[1][0]=1;
                    mA[1][1]=3;
                    mC[1][0]=2;
                    mC[1][1]=3;
                }
                else if((membro2 == 'D')){
                    mA[0][0]=2;
                    mA[0][1]=3;
                    mD[0][0]=1;
                    mD[0][1]=3;

                    mA[1][0]=1;
                    mA[1][1]=3;
                    mD[1][0]=2;
                    mD[1][1]=3;
                }
                break;
            case 'B':
                if((membro1 == 'A')){
                    mB[0][0]=2;
                    mB[0][1]=3;
                    mA[0][0]=1;
                    mA[0][1]=3;

                    mB[1][0]=1;
                    mB[1][1]=3;
                    mA[1][0]=2;
                    mA[1][1]=3;
                }
                else if((membro2 == 'C')){
                    mB[0][0]=2;
                    mB[0][1]=3;
                    mC[0][0]=1;
                    mC[0][1]=3;

                    mB[1][0]=1;
                    mB[1][1]=3;
                    mC[1][0]=2;
                    mC[1][1]=3;
                }
                else if((membro2 == 'D')){
                    mB[0][0]=2;
                    mB[0][1]=3;
                    mD[0][0]=1;
                    mD[0][1]=3;

                    mB[1][0]=1;
                    mB[1][1]=3;
                    mD[1][0]=2;
                    mD[1][1]=3;
                }
                break;
            case 'C':
                if((membro1 == 'A')){
                    mC[0][0]=2;
                    mC[0][1]=3;
                    mA[0][0]=1;
                    mA[0][1]=3;

                    mC[1][0]=1;
                    mC[1][1]=3;
                    mA[1][0]=2;
                    mA[1][1]=3;
                }
                else if((membro1 == 'B')){
                    mC[0][0]=2;
                    mC[0][1]=3;
                    mB[0][0]=1;
                    mB[0][1]=3;

                    mC[1][0]=1;
                    mC[1][1]=3;
                    mB[1][0]=2;
                    mB[1][1]=3;
                }
                else if((membro2 == 'D')){
                    mC[0][0]=2;
                    mC[0][1]=3;
                    mD[0][0]=1;
                    mD[0][1]=3;

                    mC[1][0]=1;
                    mC[1][1]=3;
                    mD[1][0]=2;
                    mD[1][1]=3;
                }
                break;
            case 'D':
                 if((membro1 == 'A')){
                    mD[0][0]=2;
                    mD[0][1]=3;
                    mA[0][0]=1;
                    mA[0][1]=3;

                    mD[1][0]=1;
                    mD[1][1]=3;
                    mA[1][0]=2;
                    mA[1][1]=3;
                }
                else if((membro1 == 'B')){
                    mD[0][0]=2;
                    mD[0][1]=3;
                    mB[0][0]=1;
                    mB[0][1]=3;

                    mD[1][0]=1;
                    mD[1][1]=3;
                    mB[1][0]=2;
                    mB[1][1]=3;
                }
                else if((membro1 == 'C')){
                    mD[0][0]=2;
                    mD[0][1]=3;
                    mC[0][0]=1;
                    mC[0][1]=3;

                    mD[1][0]=1;
                    mD[1][1]=3;
                    mC[1][0]=2;
                    mC[1][1]=3;
                }
                break;
            default:
                printf("ERRO");
                exit(0);
            }
    }else if(strlen(femea)==9){
            char membro1 = femea[4];
            char membro2 = femea[6];
            char membro3 = femea[8];
            h[0][0]=6;
            h[0][1]=7;
            switch(inicio){
            case 'A':
                if((membro2 == 'B')&&(membro3 == 'C')){
                    mA[0][0]=4;
                    mA[0][1]=7;
                    mB[0][0]=1;
                    mB[0][1]=7;
                    mC[0][0]=2;
                    mC[0][1]=7;

                    mA[1][0]=1;
                    mA[1][1]=7;
                    mB[1][0]=2;
                    mB[1][1]=7;
                    mC[1][0]=4;
                    mC[1][1]=7;
                }
                else if((membro2 == 'C')&&(membro3 == 'D')){
                    mA[0][0]=4;
                    mA[0][1]=7;
                    mC[0][0]=1;
                    mC[0][1]=7;
                    mD[0][0]=2;
                    mD[0][1]=7;

                    mA[1][0]=1;
                    mA[1][1]=7;
                    mC[1][0]=2;
                    mC[1][1]=7;
                    mD[1][0]=4;
                    mD[1][1]=7;
                }
                else if((membro2 == 'B')&&(membro3 == 'D')){
                    mA[0][0]=4;
                    mA[0][1]=7;
                    mB[0][0]=1;
                    mB[0][1]=7;
                    mD[0][0]=2;
                    mD[0][1]=7;

                    mA[1][0]=1;
                    mA[1][1]=7;
                    mB[1][0]=2;
                    mB[1][1]=7;
                    mD[1][0]=4;
                    mD[1][1]=7;
                }
                break;
            case 'B':
                if((membro1 == 'A')&&(membro3 == 'C')){
                    mA[0][0]=2;
                    mA[0][1]=7;
                    mB[0][0]=4;
                    mB[0][1]=7;
                    mC[0][0]=1;
                    mC[0][1]=7;

                    mA[1][0]=4;
                    mA[1][1]=7;
                    mB[1][0]=1;
                    mB[1][1]=7;
                    mC[1][0]=2;
                    mC[1][1]=7;
                }
                else if((membro2 == 'C')&&(membro3 == 'D')){
                    mD[0][0]=2;
                    mD[0][1]=7;
                    mB[0][0]=4;
                    mB[0][1]=7;
                    mC[0][0]=1;
                    mC[0][1]=7;

                    mD[1][0]=4;
                    mD[1][1]=7;
                    mB[1][0]=1;
                    mB[1][1]=7;
                    mC[1][0]=2;
                    mC[1][1]=7;
                }
                else if((membro1 == 'A')&&(membro3 == 'D')){
                    mA[0][0]=2;
                    mA[0][1]=7;
                    mB[0][0]=4;
                    mB[0][1]=7;
                    mD[0][0]=1;
                    mD[0][1]=7;

                    mA[1][0]=4;
                    mA[1][1]=7;
                    mB[1][0]=1;
                    mB[1][1]=7;
                    mD[1][0]=2;
                    mD[1][1]=7;
                }
                break;
            case 'C':
                if((membro1 == 'A')&&(membro2 == 'B')){
                    mA[0][0]=1;
                    mA[0][1]=7;
                    mB[0][0]=2;
                    mB[0][1]=7;
                    mC[0][0]=4;
                    mC[0][1]=7;

                    mA[1][0]=2;
                    mA[1][1]=7;
                    mB[1][0]=4;
                    mB[1][1]=7;
                    mC[1][0]=1;
                    mC[1][1]=7;
                }
                else if((membro1 == 'B')&&(membro3 == 'D')){
                    mD[0][0]=1;
                    mD[0][1]=7;
                    mB[0][0]=2;
                    mB[0][1]=7;
                    mC[0][0]=4;
                    mC[0][1]=7;

                    mD[1][0]=2;
                    mD[1][1]=7;
                    mB[1][0]=4;
                    mB[1][1]=7;
                    mC[1][0]=1;
                    mC[1][1]=7;
                }
                else if((membro1 == 'A')&&(membro3 == 'D')){
                    mD[0][0]=1;
                    mD[0][1]=7;
                    mA[0][0]=2;
                    mA[0][1]=7;
                    mC[0][0]=4;
                    mC[0][1]=7;

                    mD[1][0]=2;
                    mD[1][1]=7;
                    mA[1][0]=4;
                    mA[1][1]=7;
                    mC[1][0]=1;
                    mC[1][1]=7;
                }
                break;
            /*case 'D':
                 if((membro1 == 'A')){
                    mD[0][0]=2;
                    mD[0][1]=3;
                    mA[0][0]=1;
                    mA[0][1]=3;

                    mD[1][0]=1;
                    mD[1][1]=3;
                    mA[1][0]=2;
                    mA[1][1]=3;
                }
                else if((membro1 == 'B')){
                    mD[0][0]=2;
                    mD[0][1]=3;
                    mB[0][0]=1;
                    mB[0][1]=3;

                    mD[1][0]=1;
                    mD[1][1]=3;
                    mB[1][0]=2;
                    mB[1][1]=3;
                }
                else if((membro1 == 'C')){
                    mD[0][0]=2;
                    mD[0][1]=3;
                    mC[0][0]=1;
                    mC[0][1]=3;

                    mD[1][0]=1;
                    mD[1][1]=3;
                    mC[1][0]=2;
                    mC[1][1]=3;
                }
                break;*/
            default:
                printf("ERRO");
                exit(0);
            }
    }


    printf("\n\n-----Resultados Finais:-----\n\n");

    printf("     || gA - %d/%d ||\n", mA[0][0], mA[0][1]);
    printf("     || gB - %d/%d ||\n", mB[0][0], mB[0][1]);
    printf("     || gC - %d/%d ||\n", mC[0][0], mC[0][1]);
    printf("     || gD - %d/%d ||\n", mD[0][0], mD[0][1]);

    printf("     || mA - %d/%d ||\n", mA[1][0], mA[1][1]);
    printf("     || mB - %d/%d ||\n", mB[1][0], mB[1][1]);
    printf("     || mC - %d/%d ||\n", mC[1][0], mC[1][1]);
    printf("     || mD - %d/%d ||\n", mD[1][0], mD[1][1]);

    printf("     || hi - %d/%d ||\n", h[0][0], h[0][1]);
    printf("     || jm - %d/%d ||\n", h[0][0], h[0][1]);

    printf("----------------------------\n");

main();
}



























// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}



//Function to add two fractions
void addFraction(int num1[2][2], int num2[2][2], int num3[2][2])
{
    // Finding gcd of den1 and den2
    num3[0][1] = gcd(num1[0][1],num2[0][1]);

    // Denominator of final fraction obtained
    // finding LCM of den1 and den2
    // LCM * GCD = a * b
    num3[0][1] = (num1[0][1]*num2[0][1]) / num3[0][1];

    // Changing the fractions to have same denominator
    // Numerator of the final fraction obtained
    num3[0][0] = (num1[0][0])*(num3[0][1]/num1[0][1]) + (num2[0][0])*(num3[0][1]/num2[0][1]);
}












void substring(char s[], char sub[], int p, int l) {
   int c = 0;

   while (c < l) {
      sub[c] = s[p+c];
      c++;
   }
   sub[c] = '\0';

}




