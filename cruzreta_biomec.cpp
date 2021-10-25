#include <stdio.h>
#include <locale.h>
#define MODULO(x) ((x)>=0?(x):-(x))
main(){
	setlocale(LC_ALL,"Portuguese");
		// a	    b	    c	    d		e	    f	    g	      h	     j       k       l      m       o     p
	float xc1[3], yc1[3], xp1[3], yp1[3], xc2[3], yc2[3], xp2[3], yp2[3], mr1[3], mr2[3], br1[3], br2[3], xx[3], yy[3], x[2], y[2], z[2], real[3];
	int i=0;
	do{
		printf("Digite o valor das variáveis (linha %d de 3): \nxc1: ",i+1,i+1);
		scanf("%f",&xc1[i]);
		printf("yc1: ",i+1);
		scanf("%f",&yc1[i]);
		printf("xp1: ",i+1);
		scanf("%f",&xp1[i]);
		printf("yp1: ",i+1);
		scanf("%f",&yp1[i]);
		printf("xc2: ",i+1);
		scanf("%f",&xc2[i]);
		printf("yc2: ",i+1);
		scanf("%f",&yc2[i]);
		printf("xp2: ",i+1);
		scanf("%f",&xp2[i]);
		printf("yp2: ",i+1);
		scanf("%f",&yp2[i]);
		printf("Real: ",i+1);
		scanf("%f",&real[i]);
		i++;
		printf("\n");
	}while(i<3);
	for(i=0; i<3; i++){
	mr1[i] = (yp1[i]-yc1[i])/(xp1[i]-xc1[i]);
	mr2[i] = (yp2[i]-yc2[i])/(xp2[i]-xc2[i]);
	br1[i] = -1*(mr1[i]*xc1[i]-yc1[i]);
	br2[i] = -1*(mr2[i]*xc2[i]-yc2[i]);
	printf("\nLinha %d de 3\nmr1 = %.3f\nmr2 = %.3f\nbr1 = %.3f\nbr2 = %.3f\n",i+1,mr1[i],mr2[i],br1[i],br2[i]);
	xx[i] =(-(mr2[i]*xc2[i]) +yc2[i] + (mr1[i]*xc1[i]) - yc1[i]) / (mr1[i] - mr2[i]);
	yy[i] =(mr1[i]*xx[i])  - (mr1[i]*xc1[i]) + yc1[i];
	}
	x[0] = xx[0];
	x[1] = xx[1];
	y[0] = yy[0];
	y[1] = yy[2];
	z[0] = yy[1];
	z[1] = xx[2];
	printf("\n\nx1 = %.3f\nx2 = %.3f\ny1 = %.3f\ny2 = %.3f\nz1 = %.3f\nz2 = %.3f\n\n",x[0],x[1],y[0],y[1],z[0],z[1]);
	printf("\n\nRecriaçao 3D:\nX = %.3f\nY = %.3f\nZ = %.3f",(x[0]+x[1])/2,(y[0]+y[1])/2,(z[0]+z[1])/2);
	printf("\n\nErro:\nX = %.3f\nY = %.3f\nZ = %.3f",real[0]-((x[0]+x[1])/2),real[1]-((y[0]+y[1])/2),real[2]-((z[0]+z[1])/2));
	printf("\n\nErro absoluto:\nX = %.3f\nY = %.3f\nZ = %.3f",MODULO(real[0]-((x[0]+x[1])/2)),MODULO(real[1]-((y[0]+y[1])/2)),MODULO(real[2]-((z[0]+z[1])/2)));
	printf("\n\nErro total = %.3f",(MODULO(real[0]-((x[0]+x[1])/2))+MODULO(real[1]-((y[0]+y[1])/2))+MODULO(real[2]-((z[0]+z[1])/2)))/3);
}
