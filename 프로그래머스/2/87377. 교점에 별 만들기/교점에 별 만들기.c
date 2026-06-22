#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>


// line_rows는 2차원 배열 line의 행 길이, line_cols는 2차원 배열 line의 열 길이입니다.
long long* cal_cross(int* line1, int* line2){
    long long x = (long long)line1[1]*line2[2] - (long long)line1[2]*line2[1];
    long long y = (long long)line1[2]*line2[0] - (long long)line1[0]*line2[2];
    long long mod = (long long)line1[0]*line2[1] - (long long)line1[1]*line2[0];
    
    if(mod == 0) return NULL;
    if(x%mod!=0||y%mod!=0) return NULL;
    
    long long* dot = malloc(sizeof(long long) * 2);
    dot[0] = x/mod;
    dot[1] = y/mod;
    
    return dot;
}
char** solution(int** line, size_t line_rows, size_t line_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    long long** dots = (long long**)malloc((line_rows*line_rows/2)*(sizeof(long long*)));
    long long* dot;
    int index = 0;
    long long x_max = LLONG_MIN;
    long long x_min = LLONG_MAX;
    long long y_max = LLONG_MIN;
    long long y_min = LLONG_MAX;
    
    for(int i=0;i<line_rows - 1;i++){
        for(int j=i+1;j<line_rows;j++){
            dot = cal_cross(line[i], line[j]);
            if(dot != NULL){
                dots[index++] = dot;
                if(dot[0]>x_max) x_max = dot[0];
                if(dot[1]>y_max) y_max = dot[1];
                if(dot[0]<x_min) x_min = dot[0];
                if(dot[1]<y_min) y_min = dot[1];
            }
        }
    }
    int size_x = x_max - x_min + 1;
    int size_y = y_max - y_min + 1;
    char** answer = (char**)malloc(sizeof(char*) * size_y);
    for(int i=0;i<size_y;i++){
        answer[i] = (char*)malloc(sizeof(char) * (size_x + 1));
        for(int j=0;j<size_x;j++){
            answer[i][j] = '.';
        }
        answer[i][size_x] = '\0';
    }
    
    for(int i=0;i<index;i++){
        int row = y_max - dots[i][1];
        int col = dots[i][0] - x_min;

        answer[row][col] = '*';
    }
    
    return answer;
}