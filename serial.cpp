#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <omp.h>
#include <iostream>

using namespace std;
int n = 10000;

int pic[10000][10000][3];

int gray_img[10000][10000];


int dataentry(){
    double start = omp_get_wtime();
    int val1=255;
    int val2=0;
    int val3=128;
    for(int i=0; i<5000; i++){
        for(int j=0; j<10000; j++){
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
    for(int i=5000; i<10000; i++){
        for(int j=0; j<10000; j++){
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
    for(int i=0; i<10000; i++){
        for(int j=0; j<10000; j++){
            int sum = 0;
            for(int k=0; k<3; k++){
                sum = sum + pic[i][j][k];
            }
            sum = sum/3;
            int sum1 = (sum*sum);
            double tanned = atan(sum1);
            //double tann = atan(tanned);
            //int whole = lround(tann*255);
            
            gray_img[i][j] = sum;
        }
    }
    return 0;

}

int display(){
    for(int i=0; i<10000; i++){
        for(int j=0; j<10000; j++){
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
//display();
return 0;
}
