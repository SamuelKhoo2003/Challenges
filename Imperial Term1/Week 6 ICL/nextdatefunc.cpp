#include <iostream>
 
bool leap_year(int year){
    bool ly; 

    if(year%4 == 0) { 
        if(year%400 == 0) { 
            ly = true; 
        }
        else if(year%100 == 0) { 
            ly = false; 
        }
        else { 
            ly = true; 
        }
    }

    else { 
        ly = false; 
    }

 
    // TODO: check whether the year is a leap year or not
    // store result in variable ly
 
    return ly;
}
 
void next_date(int d1, int m1, int y1, int& d2, int& m2, int& y2){
    // TODO: d1, m1, y1 are inputs 
    // corresponding to the date d1/m1/y1
    // d2, m2, y2 are outputs that the function must compute
    // corresponding to the date d2/m2/y2 
    // which is meant to be the day after d1/m1/y1

    y2 = y1; 
    m2 = m1;
    d2 = d1; 
    
    if (d1 == 28 && m1 == 2 && not leap_year(y1)) {
        d2 = 1;
        m2++; 
    }
    else if (d1 == 29 && m1 == 2) {
        d2 = 1;
        m2++;
    }
    else if (d1 == 30 && (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)) {
        d2 = 1; 
        m2++; 
    }
    else if (d1 == 31) {
        if (m1 == 12) {
            d2 = 1; 
            m2 = 1; 
            y2++; 
        } 
        else {
            d2 = 1; 
            m2++; 

        }
    }

    else{ 
        d2++; 
    }

    // function leap_year is useful for this task
 
    // do not begin to write code straightaway
    // sketch some diagrams first like we did
    // for the leap year task
 
    // (this function should not print anything)
 
}
 
int main(){
    // TODO: write a main that reads a date from the user,
    // calls function next_date to compute the date 
    // corresponding to the next day, and then prints it
    int d, m, y, newd, newm, newy; 
    std::cout << "Please enter a day, month and year. " << std::endl; 
    std::cin >> d >> m >> y; 
    next_date(d, m, y, newd, newm, newy); 
    std::cout << "The next date is: " << std::endl; 
    std::cout << newd << "/" << newm << "/" << newy << std::endl; 
    

    
}