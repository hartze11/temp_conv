#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

  int DR = 3.1415926 / 180;
  int RD = 1 / DR;

  int B5_lat = 40;
  int L5_long = 105;
  int H_timezone = -7;
  int M_month = 11;
  int D_day = 22;

  B5_lat = DR * B5_lat;

  float C3, C2, C, SD, N, L0, HR, MR, R1, CD, SC;

  N = (275 * M_month / 9) - 2 * ((M_month + 9) / 12) + D_day - 30;
  L0 = 4.8771 + 0.0172 * (N + 0.5 - L5_long / 360);
  C = 0.03342 * sin(L0 + 1.345);
  C2 = RD * atan(tan(L0 + C)) - (atan(0.9175 * tan(L0 + C))-C);
  SD = 0.3978 * sin(L0 + C);
  CD = sqrt(1 - SD * SD);
  SC = (SD * sin(B5_lat) + 0.0145) / (cos(B5_lat) * CD);

  if (fabsf(SC) <= 1) {
    C3 = RD * atan(SC / sqrt(1 - SC*SC));
    R1 = 6 - H_timezone - (L5_long + C2 + C3) / 15;
    HR = (int) R1;
    MR = (int) (R1 - HR)*60;
    printf("Sunrise at: %f:%f", HR, MR);
  }

  return 0;
}
