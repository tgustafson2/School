package gustafson_assignment_6_monthdays;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author tgust
 */
public class MonthDays {
    private int month;
    private int year;
    public MonthDays(int year, int month){
        setMonth(month);
        setYear(year);
    }
    public void setMonth(int month){
        if (month>0&&month<=12){
        this.month=month;}
        else
            throw new IllegalArgumentException("Month must be between 1 and 12. Program Terminating");
    }
    public void setYear(int year){
        if(year>0){
        this.year=year;}
        else
            throw new IllegalArgumentException("Year must be postive. Program Terminating");
    }
    public int getNumberOfDays(){
        int days=0;
        if (month==2){
        if (year%100==0){
            if (year%400==0){
                days=29; 
            }
            else
                days=28;
        }
        else if (year%100!=0){
        if (year%4==0){
            days=29;
        }
        else if (year%4!=0){
            days=28;
        }
        }
        }
        if (month==1||month==3||month==5||month==7||month==8||month==10||month==12){
            days=31;
        }
        else if (month==4||month==6||month==9||month==11){
            days=30;
        }
        return days;
    }
    public int getMonth(){
        return month;
    }
    public int getYear(){
        return year;
    }
}
