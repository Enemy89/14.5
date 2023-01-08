#include <iostream>

bool pupyrkaCheck [12][12] = {{true,true,true,true, true,true,true,true, true,true,true,true},
                              {true,true,true,true, true,true,true,true, true,true,true,true},
                              {true,true,true,true, true,true,true,true, true,true,true,true},
                              {true,true,true,true, true,true,true,true, true,true,true,true},
                              {true,true,true,true, true,true,true,true, true,true,true,true},
                              {true,true,true,true, true,true,true,true, true,true,true,true},
                              {true,true,true,true, true,true,true,true, true,true,true,true},
                              {true,true,true,true, true,true,true,true, true,true,true,true},
                              {true,true,true,true, true,true,true,true, true,true,true,true},
                              {true,true,true,true, true,true,true,true, true,true,true,true},
                              {true,true,true,true, true,true,true,true, true,true,true,true},
                              {true,true,true,true, true,true,true,true, true,true,true,true}};

void viewPupyrka (bool pupyrka[][12]) {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (pupyrka[i][j]) {
                std::cout << "O";
            } else
                std::cout << "X";
        }
        std::cout << std::endl;
    }
}

bool checkPupyrka (bool pupyrka[][12]) {
    int count=0;
    for (int i=0; i<12; ++i) {
        for (int j=0; j<12; ++j) {
            if (pupyrka[i][j]) {
                return false;
            }
            else
                count++;
        }
    }
    if (count==144){
        return true;
    }
}

int countPop=0;
void popPupyrka(int x1, int y1, int x2, int y2) {
    for (int i=x1; i<=x2; ++i) {
        for (int j=y1; j<=y2; ++j) {
            if (pupyrkaCheck[i][j]){
                pupyrkaCheck[i][j]=false;
                countPop++;
            }
        }
    }
}

int main() {
    int x1,x2,y1,y2;
        while(!checkPupyrka(pupyrkaCheck)) {
        viewPupyrka(pupyrkaCheck);
        std::cout<<"Enter the coordinates of the region: "<<std::endl;
        std::cin>>x1>>y1>>x2>>y2;
        if (x1<12 && x2<12 && y1<12 && y2<12 && (x1<x2) && (y1<y2)) {
            popPupyrka(x1, y1, x2, y2);
            while (countPop != 0) {
                std::cout << "POP!" << std::endl;
                countPop--;
            }
        }
        else std::cout<<"Err";
    }
}
