#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	double W, in, TM1, TM2, TMM, p, GM1, GM2, GMT, GE1, GE2, GET, TE1, TE2, TET;
	FILE *fp, *fp1, *fp2, *fp3;
	in = 0.750;
	p=3.1416;
	fp = fopen("TauMagnetica2.dat","w");
	fp1 = fopen("GammaMagnetica2.dat","w");
	fp2 = fopen("GammaElectrica2.dat","w");
	fp3 = fopen("TauElectrica2.dat","w");
	for(W=0.0;W<=90.0;W+=1.0){
		/*A=W*sqrt(((M*E)/2.0)*(sqrt((S*S)/(E*E*W*W) +1.0) -1.0));*/
		/*A=(S)/(W*E);*/
		TM1 = (2*in*cos((p*W)/180.0));
		TM2 = (in*in*cos((p*W)/180.0)) + sqrt((in*in)-(sin((p*W)/180.0)*sin((p*W)/180.0)));
		TMM = (TM1*TM1)/(TM2*TM2);
		GM1 = -(((in*in)*cos((p*W)/180.0)))+sqrt((in*in)-(sin((p*W)/180.0))*sin((p*W)/180.0));
		GM2 = (((in*in)*cos((p*W)/180.0)))+sqrt((in*in)-(sin((p*W)/180.0))*sin((p*W)/180.0));
		GMT = (GM1*GM1)/(GM2*GM2);
		GE1 = cos((p*W)/180.0)-sqrt((in*in)-(sin((p*W)/180.0)*sin((p*W)/180.0))); 
		GE2 = cos((p*W)/180.0)+sqrt((in*in)-(sin((p*W)/180.0)*sin((p*W)/180.0)));
		GET = (GE1*GE1)/(GE2*GE2);
		TE1 = (2*cos((p*W)/180.0));
		TE2 = cos((p*W)/180.0) + sqrt((in*in)-(sin((p*W)/180.0))*sin((p*W)/180.0));
		TET = (TE1*TE1)/(TE2*TE2);
		fprintf(fp,"%lf %lf \n", W, TMM);
		fprintf(fp1,"%lf %lf \n", W, GMT);
		fprintf(fp2,"%lf %lf \n", W, GET);
		fprintf(fp3,"%lf %lf \n", W, TET);
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	return 0;
}
