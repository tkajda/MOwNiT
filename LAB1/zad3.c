#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double f(double s, int k) {
    return (double) 1/pow(k,s);
}
float ff(double s, int k){
    return (float) (1/pow(k,s));
}


double dzeta_fw(double s, int n) {
    double sum = 0;
    for(int k = 1; k <= n; k++) {
        sum += f(s,k);
    }
    return sum;
}


double dzeta_bw(double s, int n) {
    double sum = 0;
    for(int k = n; k >= 1; k--) {
        sum += f(s,k);
    }
    return sum;
}


float fdzeta_fw(double s,int n) {
    float sum = 0;
    for(int k = 1; k <= n; k++) {
        sum += ff(s,k);
    }
    return sum;
}


float fdzeta_bw(double s,int n) {
    float sum = 0;
    for(int k = n; k >= 1; k--) {
        sum += ff(s,k);
    }
    return sum;
}


double eta_fw(double s,int n) {
    double sum = 0;
    for (int k = 1; k <= n; k++) {
        if ((k - 1) % 2) {
            sum += f(s, k);
        } else {
            sum -= f(s, k);
        }
    }
    return sum;
}

float feta_fw(double s,int n) {
    float sum = 0;
    for(int k = 1; k <= n; k++) {
        if ((k-1)%2) {
            sum +=ff(s,k);
        }
        else {
            sum -=ff(s,k);
        }
    }
    return sum;
}


double eta_bw(double s,int n) {
    double sum = 0;
    for(int k = n; k >= 1; k--) {
        if ((k-1)%2) {
            sum +=f(s,k);
        }
        else {
            sum -=f(s,k);
        }
    }
    return sum;
}

float feta_bw(double s,int n) {
    float sum = 0;
    for(int k = n; k >= 1; k--) {
        if ((k-1)%2) {
            sum +=ff(s,k);
        }
        else {
            sum -=ff(s,k);
        }
    }
    return sum;
}




int main() {


    double sValues[] = {2, 3.6667, 5, 7.2, 10};
    int sSize = sizeof(sValues)/sizeof(sValues[0]);

    int nValues[] = {50, 100, 200, 500, 1000};
    int nSize = sizeof(nValues) / sizeof(nValues[0]);



    for(int i = 0; i < sSize; i++) {
        double s = sValues[i];
        printf("    %f\n", s);
        for(int j = 0; j < nSize; j++) {
            int n = nValues[j];

            printf("%4d %2.20f   %2.20f   %2.20f   %2.20f\n",
                   n,
                   dzeta_fw(s,n),
                   dzeta_bw(s,n),
                   fdzeta_fw(s,n),
                   fdzeta_bw(s,n));

        }
    }

    printf("\n\n");

    for(int i = 0; i < sSize; i++) {
        double s = sValues[i];
        printf("    %f\n", s);
        for(int j = 0; j < nSize; j++) {
            int n = nValues[j];

            printf("%4d %2.20f   %2.20f   %2.20f   %2.20f\n",
                   n,
                   eta_fw(s,n),
                   eta_bw(s,n),
                   feta_fw(s,n),
                   feta_bw(s,n));

        }
    }

    return 0;
}
