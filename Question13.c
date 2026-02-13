#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    
    int mat[100][100]; 
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    
    while(top <= bottom && left <= right) {
        
        for(int i = left; i <= right; i++) {
            if(!printf("%d ", mat[top][i])) return 1;
        }
        top++;
        
        
        for(int i = top; i <= bottom; i++) {
            if(!printf("%d ", mat[i][right])) return 1;
        }
        right--;
        
        
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                if(!printf("%d ", mat[bottom][i])) return 1;
            }
            bottom--;
        }
        
       
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                if(!printf("%d ", mat[i][left])) return 1;
            }
            left++;
        }
    }
    
    printf("\n");  
}