#include <stdio.h>

int pronadji_velicinu_stringa(char str[]) {
    int size = 0;
    for(int i = 0; i < 100; i++){
        if(str[i] != '\0'){
            size++;
        } else{
            break;
        }
    }

    return size;
}

void pretvori_u_velika(char str[]){
    for(int i=0; str[i]!='\0'; i++)
    {

        if(str[i]>='a' && str[i]<='z')
        {
            str[i] = str[i] - 32;
        }
    }
}

// automatski mijenja velicinu stringa
void ukloni_praznine(char str[], int* final){
    int count = 0;
    for (int i = 0; str[i]; i++){
        if (str[i] != ' '){
            if(str[i] == 'w' || str[i] == 'W'){
                str[i] = 'V';
            }
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
    *final = count;
}

void ukloni_praznine_bigrama(char str[], int* final){
    int count = 0;
    for (int i = 0; str[i]; i++){
        if (str[i] != ' '){
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
    *final = count;
}

// automatski mijenja velicinu stringa
void ukloni_duplikate(char str[], int n, int* final)
{

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; str[j] != '\0'; j++)
        {
            if(str[j] == str[i])
            {
                for(int k = j; str[k] != '\0'; k++)
                {
                    str[k] = str[k + 1];
                    *final = k;
                }
            }
        }
    }

}

// automatski mijenja velicinu stringa
char napravi_bigram(char str[], char temp[], int* final){
    char pom_1;
    char pom_2;
    int kontrolna = 0;
    int index = 0;
    int broj_karaktera=0;

    for(int i=0; i < 100; i=i+2){
        if(str[i] == '\0'){
            break;
        }
        else{
        if(str[i] != str[i+1]){
            pom_1 = str[i];
            pom_2 = str[i+1];
            temp[index++] = pom_1;
            temp[index++] = pom_2;
            temp[index++] = ' ';
        }
        else{
            pom_1 = str[i];
            pom_2 = 'X';
            temp[index++] = pom_1;
            temp[index++] = pom_2;
            temp[index++] = ' ';
            i = i - 1;
        }}
    }

    while (temp[kontrolna] != '\0'){
        broj_karaktera++;
        kontrolna++;
    }

    if(broj_karaktera % 2 == 0){
         temp[kontrolna] = '\0';
        *final = broj_karaktera;
    }else{
        temp[kontrolna] = 'X';
        temp[kontrolna+1] = '\0';
        broj_karaktera++;
        *final = broj_karaktera;
    }

    return temp;
}

char napravi_bigram_input(char str[], char temp[], int* final){
    int index = 0;
    for(int i = 0; i < 100; i = i + 2){
        if(str[i] == '\0'){
            break;
        }
        if(str[i] != ' ' && str[i+1] != ' '){
            temp[index++] = str[i];
            temp[index++] = str[i+1];
            temp[index++] = ' ';
        }
    }
    *final = index;
    printf("U funkciji size: %d\n", index);
    return  temp;
}



int main() {
    // Programmieren macht Spass
    char string[100];
    char string_za_bigram[100];
    char bigram[100];

    char bigram_input[100];
    char bigram_input_temp[100];
    int bigram_input_size = 0;
    int string_size = 0;
    int string_bigram_size = 0;
    int bigram_size = 0;
    char alpha[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','Y','Z'};
    char matrica[5][5];
    int count = 0; // index za bigram_kodirano niz
    char a, b;
    char a_mat; // slovo u matrici koje odgovara slovu prvog bigrama (a)
    char b_mat; // slovo u matrici koje odgovara slovu drugog bigrama (b)
    int a_mat_i; // kordinata prvog slova u matrici (i)
    int a_mat_j; // kordinata prvog slova u matrici (j)
    int b_mat_i; // kordinata drugog slova u matrici (i)
    int b_mat_j; // kordinata drugog slova u matrici (j)
    int temp_kor;
    int flag_a = 0;
    int flag_b = 0;
    int flag_control = 0;
    int i, j;
    ///////// za dekodiranje
    char c;
    char d;
    printf("Unesi string: ");
    gets(string);
    fflush(stdin);
    printf("Unesi bigram: ");
    gets(string_za_bigram);
    int h = pronadji_velicinu_stringa(&string_za_bigram[0]);
    printf("%d\n", h);
    pretvori_u_velika(string);
    ukloni_praznine(string, &string_size);
    ukloni_duplikate(string, string_size, &string_size);
    printf("Velicina halo welta %d\n",pronadji_velicinu_stringa(&string[0]));
    ///////////////////////////////////////////////////////
    pretvori_u_velika(string_za_bigram);
    ukloni_praznine_bigrama(string_za_bigram, &bigram_size);
    napravi_bigram(&string_za_bigram[0], &bigram[0], &bigram_size);

    printf("String: %s\n", string);
    printf("String za bigram: %s\n", string_za_bigram);
    printf("Bigram: %s\n", bigram);


    char bigram_kodirano[bigram_size];

    for(int i = 0; i < 100; i++){
        if(alpha[i] == '\0'){
            break;
        }
        string[string_size++] = alpha[i];
    }

    string_size = pronadji_velicinu_stringa(string);
    ukloni_duplikate(string, string_size, &string_size);


    // popuni prvo parne pozicije matrice
    int index = 0;
    for(int i = 0; i < 5; i++){
        if(index <= 13){
            for(int j = 0; j < 5; j++){
                if((i + j) % 2 == 0){
                    matrica[i][j] = string[index++];
                }
            }}
    }
    // popuni zatim neparne pozicije matrice
    for(int i = 0; i < 5; i++){
        if(index <= 25){
            for(int j = 0; j < 5; j++){
                if((i + j) % 2 != 0){
                    matrica[i][j] = string[index++];
                }
                printf("%c ", matrica[i][j]);
            }}
        printf("\n");
    }

    // kodiranje
    for(int k = 0; k < bigram_size-1; k++) {
        flag_control = 0;
        if(bigram[k] != ' ' && bigram[k+1] != ' ') {
            a = bigram[k];
            b = bigram[k + 1];

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (a == matrica[i][j]) {
                        a_mat_i = i;
                        a_mat_j = j;
                        break;
                    }
                }
            }

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (b == matrica[i][j]) {
                        b_mat_i = i;
                        b_mat_j = j;
                        break;
                    }
                }
            }

            //ToDo
            // prvi slucaj
            // u istom su retku
            if (flag_control == 0){
                if (a_mat_i == b_mat_i) {
                    flag_control = 1;
                    if (a_mat_j == 4) {
                        a_mat_j = 0;
                        flag_a = 1;

                    }
                    if (flag_a != 1) {
                        if (a_mat_j != 4) {
                            a_mat_j++;
                        }
                    }

                    if (b_mat_j == 4) {
                        b_mat_j = 0;
                        flag_b = 1;
                    }
                    if (flag_b != 1) {
                        if (b_mat_j != 4) {
                            b_mat_j++;
                        }
                    }
                    a = '\0';
                    b = '\0';
                    a = matrica[a_mat_i][a_mat_j];
                    b = matrica[b_mat_i][b_mat_j];
                    bigram_kodirano[count++] = a;
                    bigram_kodirano[count++] = b;
                    bigram_kodirano[count++] = ' ';
                }

        }
            // drugi slucaj
            // u istom su stupcu
            if(flag_control == 0){
            if(a_mat_j == b_mat_j){
                flag_control = 2;
                if(a_mat_i == 4){
                    a_mat_i = 0;
                    flag_a = 1;

                }
                if(flag_a != 1){
                    if(a_mat_i != 4){
                        a_mat_i++;
                    }
                }

                if(b_mat_i == 4){
                    b_mat_i = 0;
                    flag_b = 1;
                }
                if(flag_b != 1) {
                    if (b_mat_i != 4) {
                        b_mat_i++;
                    }
                }
                a = '\0';
                b = '\0';
                a = matrica[a_mat_i][a_mat_j];
                b = matrica[b_mat_i][b_mat_j];
                bigram_kodirano[count++] = a;
                bigram_kodirano[count++] = b;
                bigram_kodirano[count++] = ' ';
            }

            }
            // treci slucaj
            if (flag_control == 0){
            temp_kor = a_mat_j;
            a_mat_j = b_mat_j;
            b_mat_j = temp_kor;
            a = '\0';
            b = '\0';
            a = matrica[a_mat_i][a_mat_j];
            b = matrica[b_mat_i][b_mat_j];
            bigram_kodirano[count++] = a;
            bigram_kodirano[count++] = b;
            bigram_kodirano[count++] = ' ';
    }

        }

    }

    printf("Kodirani niz: %s\n", bigram_kodirano);
//////////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("Unesi chiper text: ");
    gets(bigram_input);
    fflush(stdin);
    pretvori_u_velika(&bigram_input[0]);
    printf("%d", pronadji_velicinu_stringa(&bigram_input[0]));
    napravi_bigram_input(&bigram_input[0], &bigram_input_temp[0], &bigram_input_size);
    printf("SIZE %d", bigram_input_size);
    printf("%s\n", bigram_input_temp);

    char bigram_dekodirano[bigram_input_size];
    count = 0;
    flag_a = 0;
    flag_b = 0;
    // dekodiranje
    printf("------ %d\n", bigram_input_size);
    for(int k = 0; k < bigram_input_size-1; k++) {
        flag_control = 0;
        if(bigram_input_temp[k] != ' ' && bigram_input_temp[k+1] != ' ') {
            a = bigram_input_temp[k];
            b = bigram_input_temp[k + 1];

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (a == matrica[i][j]) {
                        a_mat_i = i;
                        a_mat_j = j;
                        break;
                    }
                }
            }

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (b == matrica[i][j]) {
                        b_mat_i = i;
                        b_mat_j = j;
                        break;
                    }
                }
            }
            // prvi slucaj
        if(flag_control == 0){
            if(a_mat_i == b_mat_i){  // ako su u istom redu
                if(a_mat_j == 0){
                    flag_a = 1;
                    a_mat_j = 4;
                }
                if(flag_a != 1){
                    if(a_mat_j != 0){
                        a_mat_j--;
                        flag_a = 0;
                    }
                }
                if(b_mat_j == 0){
                    flag_b = 1;
                    b_mat_j = 4;
                }
                if(flag_b != 1){
                    if(b_mat_j != 0){
                        b_mat_j--;
                        flag_b = 0;
                    }
                }
                a = '\0';
                b = '\0';
                a = matrica[a_mat_i][a_mat_j];
                b = matrica[b_mat_i][b_mat_j];
                bigram_dekodirano[count++] = a;
                bigram_dekodirano[count++] = b;
                bigram_dekodirano[count++] = ' ';
                flag_control = 1;

            }
        }
        // drugi slucaj
            if(flag_control == 0){
                if(a_mat_j == b_mat_j){

                    if(a_mat_i == 0){
                        a_mat_i = 4;
                        flag_a = 1;

                    }
                    if(flag_a != 1){
                        if(a_mat_i != 0){
                            a_mat_i--;
                            flag_a = 0;
                        }
                    }

                    if(b_mat_i == 0){
                        b_mat_i = 4;
                        flag_b = 1;
                    }
                    if(flag_b != 1) {
                        if (b_mat_i != 0) {
                            b_mat_i--;
                            flag_b = 0;
                        }
                    }
                    a = '\0';
                    b = '\0';
                    a = matrica[a_mat_i][a_mat_j];
                    b = matrica[b_mat_i][b_mat_j];
                    bigram_dekodirano[count++] = a;
                    bigram_dekodirano[count++] = b;
                    bigram_dekodirano[count++] = ' ';
                    flag_control = 1;
                }
            }

            // treci slucaj
            if (flag_control == 0){
                temp_kor = a_mat_j;
                a_mat_j = b_mat_j;
                b_mat_j = temp_kor;
                a = '\0';
                b = '\0';
                a = matrica[a_mat_i][a_mat_j];
                b = matrica[b_mat_i][b_mat_j];
                bigram_dekodirano[count++] = a;
                bigram_dekodirano[count++] = b;
                bigram_dekodirano[count++] = ' ';
                flag_control = 1;
            }


        }
    }


    printf("Bigram dekodirano: %s", bigram_dekodirano);


    // Programmieren macht Spass
    // vbnytkpspfqbtmnhsjeunlcscs
    return 0;
}
