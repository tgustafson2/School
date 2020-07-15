/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "GradedActivity.h"

//******************************************************
// Member function GradedActivity::getLetterGrade      *
//******************************************************

char GradedActivity::getLetterGrade() const
{
   char letterGrade; // To hold the letter grade
   
   if (score > 89)
      letterGrade = 'A';
   else if (score > 79)
      letterGrade = 'B';
   else if (score > 69)
      letterGrade = 'C';
   else if (score > 59)
      letterGrade = 'D';
   else
      letterGrade = 'F';
   
   return letterGrade;
}
