#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <omp.h>
#include <iostream>

using namespace std;

int pic[420][420][3];

int gray_img[420][420];


int dataentry(){
    double start = omp_get_wtime();
    int val1=255;
    int val2=0;
    int val3=128;
    for(int i=0; i<210; i++){
        for(int j=0; j<420; j++){
            pic[i][j][0] = val1;
            pic[i][j][1] = val2;
            pic[i][j][2] = val3;
            --val1;
            ++val2;
            ++val3;
            if(val1==0){
                val1=255;
            }
            if(val2==255){
                val2=0;
            }
            if(val3==255){
                val3=128;
            }
        }
    }
        
    val1=255;
    val2=0;
    val3=128;
    for(int i=210; i<420; i++){
        for(int j=0; j<420; j++){
            pic[i][j][0] = val1;
            pic[i][j][1] = val2;
            pic[i][j][2] = val3;
            --val1;
            ++val2;
            ++val3;
            if(val1==0){
                val1=255;
            }
            if(val2==255){
                val2=0;
            }
            if(val3==255){
                val3=128;
            }
        }
    }
    return 0;
}

int grayscaling(){
    for(int i=0; i<420; i++){
        for(int j=0; j<420; j++){
            int sum = 0;
            for(int k=0; k<3; k++){
                sum = sum + pic[i][j][k];
            }
            lround();
            double tanned = atan(sum);

            gray_img[i][j] = sum/3;
        }
    }
    return 0;

}

int display(){
    for(int i=0; i<420; i++){
        for(int j=0; j<420; j++){
            cout << gray_img[i][j];
            cout << " ";
        }
        cout << "\n";
        }
    return 0;
}

int main(){

dataentry();
grayscaling();
display();
return 0;
}