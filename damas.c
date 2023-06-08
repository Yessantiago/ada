#include <stdio.h>
#include <stdlib.h>

int rechaza(int *T, int m){
    int i;
    for(i=0; i<m; i++){ //mismo renglon
        if(T[i]==T[m]){
            return 1; 
        }
    }

    for ( i = 0; i < m; i++){ //misma columna
        if (m-i== abs (T[m]-T[i])){
            return 1;
        }   
    }
    
    return 0; //acepta

}

void guarda(int *T, int m) {
    int i;

    for (i = 0; i < m; i++) {
        printf("%d ", T[i]);
    }

    printf("\n");
}

int nDamas(int n) {
    int *T, i, m = 0, cuenta = 0;
    T = malloc(n * sizeof(int));

    if(T == NULL) {
        printf("Memoria insufciente\n");
        exit(1);
    }

    T[m] = 0;

    while (m >= 0) {
        if(T[m] >= n && m == 0) break;
        
        if(T[m] >= n && m > 0) {
            T[--m]++; 
            continue;
        }

        if(rechaza(T, m)) {
            T[m]++;
            continue;
        }

        if(m == n - 1) {
            guarda(T, n - 1);
            cuenta++;
            T[m]++;
            continue;
        }

        if(m < n - 1) {
            T[++m] = 0;
            continue;
        }

        return cuenta;
    }    
}

int main( int argc, char **argv){
    int n=8, numsol;
/*     if (argc!=2){
        printf("Uso: ndamas <n>\n"); 
        return 0; 
    }
    n = atoi(argv[1]); */
    numsol = nDamas(n); 
    printf("Total: %d\n", numsol); 
    return 0; 

}