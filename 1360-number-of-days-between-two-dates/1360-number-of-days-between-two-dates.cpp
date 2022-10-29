class Solution {
public:
    int isLeapYear(int y){
        
        return (y%4==0 && y%100!=0) || y%400==0;
    }
    int dayInMonth(int y, int m){
        if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) return 31;
        if(m==2){
            if(isLeapYear(y)) return 29;
            return 28;
        }
        return 30;
    }
     int date_to_int(int Y,int M, int D, int minY)
        {
            
            int date = 0;
            for(int y = minY; y < Y; ++y) date += isLeapYear(y) ? 366 : 365;
            for(int m = 1; m < M; ++m) date += dayInMonth(Y,m);
            return date + D;
        }
    int daysBetweenDates(string date1, string date2) {
        int y1 = stoi(date1.substr(0, 4));
        int m1 = stoi(date1.substr(5, 2));
        int d1 = stoi(date1.substr(8, 2));
        
        int y2 = stoi(date2.substr(0, 4));
        int m2 = stoi(date2.substr(5, 2));
        int d2 = stoi(date2.substr(8, 2));
        
        
        
        int minY;
        if(y1<y2) minY=y1;
        else minY = y2;
        
        int days1 = date_to_int(y1,m1,d1,minY);
        int days2  = date_to_int(y2,m2,d2, minY);
        
//         int days = 0;
        
//         while(m1!=1){
//             days-=dayInMonth(y1,m1-1);
//             m1--;
//         }
//         days-=d1;
        
//         while(m2!=1){
//             days+=dayInMonth(y2,m2-1);
//             m2--;
//         }
        
//         days+=d2;
//         if(y1>y2){
//             days=-days;
//             y1 = y1^y2;
//             y2 = y1^y2;
//             y1 = y1^y2;
//         }
//         while(y1!=y2){
    
//             if(isLeapYear(y1)) days+=366;
//             else days+=365;
//             y1++;
//         }
        
        return abs(days2-days1);
        
        
        
        
    }
};