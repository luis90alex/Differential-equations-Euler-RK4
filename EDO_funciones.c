#include "New_Edo_Header.h"

double sigma, b, r, x, y, z, t, h, intensidad;
int i, n;
double caso;
double c1[3],c2[3];

void EULER(double sigma, double b, double r, double x0, double y0, double z0){
	FILE *euler;
	euler = fopen ("Farfan_Fuentealba_Medeiros_EULER.txt", "w");

	printf ("\n\nHAS ESCOGIDO EL METODO DE EULER\n\n");

    printf ("Define el tiempo t considerado: ");
    scanf ("%lf", &t);
    printf ("Define el intervalo discreto h: ");
    scanf ("%lf", &h);

	n = t/h;

    printf ("\nLos parametros del sistema son:\n");
	printf ("Sigma: %lf	b: %lf	r: %lf\n\n", sigma, b, r);

	printf ("Las condiciones iniciales introducidas son:\n");
	printf ("x0: %lf	y0: %lf	z0: %lf\n\n", x0, y0, z0);

	caso=sigma*(sigma+b+3)/(sigma-b-1);
	if(r<=caso){
        if(r<=1){
            printf("\nEstas en el CASO 1\n");
        }
        else{
            printf("\nEstas en el CASO 2\n");
        }
	}
	else{
        printf("\nEstas en el CASO 3\n");
	}

	c1[0]=c1[1]=sqrt(b*(r-1));
	c2[0]=c2[1]=-sqrt(b*(r-1));
	c1[2]=c2[2]=r-1;

    if (r>=1){
        printf("\nLos puntos de equilibrio son:\nC+=(%.10lf,%.10lf, %.10lf)\nC-=(%.10lf, %.10lf, %.10lf)\n",c1[0],c1[1],c1[2],c2[0],c2[1],c2[2]);
    }

    else{
    }

	fprintf (euler, "#PROGRAMA REALIZADO POR:\n   #Adrià Medeiros (NIU:1388403)\n   #Luís Farfan (NIU:1388330)\n   #Lucas Fuentealba(NIU:1388326)\n\n");
	fprintf (euler, "#PARÁMETROS:\n");
	fprintf (euler, "#Sigma: %lf	b: %lf	r: %lf\n\n", sigma, b, r);
    fprintf (euler, "#CONDICIONES INICIALES:\n");
    fprintf (euler, "#x0= %lf    y0= %lf     z0= %lf\n\n", x0, y0, z0);
	fprintf (euler, "#Tiempo		X		Y		Z           |Intensidad\n");
	printf ("\n\nESPERA...\n\n");

	for (i=0; i<=n; i++){
        x = x0 + h*dx(x0, y0);
        y = y0 + h*dy(x0, y0, z0);
        z = z0 + h*dz(x0, y0, z0);
        intensidad = pow(x,2);

		t=i*h;
		fprintf (euler, "%lf	%lf	%lf	%lf     %lf\n", t, x0, y0, z0, intensidad);
		x0 = x;
		y0 = y;
		z0 = z;
	}

	printf ("\n\nLISTO!\n\n");
}

void RK4(double sigma, double b, double r, double x0, double y0, double z0){
    FILE *rk4;
	rk4 = fopen("Farfan_Fuentealba_Medeiros_RK4.txt", "w");
	caso=sigma*(sigma+b+3)/(sigma-b-1);
	double K1, K2, K3, K4, L1, L2, L3, L4, M1, M2, M3, M4; //K con x | L con y | M con z

	printf ("\n\nHAS ESCOGIDO EL METODO DE RUNGE-KUTTA DE ORDEN 4\n\n");

	printf ("Define el tiempo t considerado: ");
	scanf ("%lf", &t);
	printf ("Define el intervalo discreto h: ");
	scanf ("%lf", &h);

	n = t/h;

    printf ("\nLos parametros del sistema son:\n");
	printf ("Sigma: %lf	b: %lf	r: %lf\n\n", sigma, b, r);

	printf ("Las condiciones iniciales introducidas son:\n");
	printf ("x0: %lf	y0: %lf	z0: %lf\n\n", x0, y0, z0);

	if(r<=caso){
        if(r<=1){
            printf("\nEstas en el CASO 1\n");
        }
        else{
            printf("\nEstas en el CASO 2\n");
        }
	}
	else{
        printf("\nEstas en el CASO 3\n");
	}
	c1[0]=c1[1]=sqrt(b*(r-1));
	c2[0]=c2[1]=-sqrt(b*(r-1));
	c1[2]=c2[2]=r-1;

	if (r>=1){
        printf("\nLos puntos de equilibrio son:\nC+=(%.10lf,  %.10lf, %.10lf)\nC-=(%.10lf, %.10lf, %.10lf)\n",c1[0],c1[1],c1[2],c2[0],c2[1],c2[2]);
	}
    else{

    }

	fprintf (rk4, "#PROGRAMA REALIZADO POR:\n   #Adrià Medeiros (NIU:1388403)\n   #Luís Farfan (NIU:1388330)\n   #Lucas Fuentealba(NIU:1388326)\n\n");
	fprintf (rk4, "#PARÁMETROS:\n");
	fprintf (rk4, "#Sigma: %lf	b: %lf	r: %lf\n\n", sigma, b, r);
    fprintf (rk4, "#CONDICIONES INICIALES:\n");
    fprintf (rk4, "#x0= %lf    y0= %lf     z0= %lf\n\n", x0, y0, z0);
	fprintf (rk4, "#Sigma: %lf	b: %lf	r: %lf\n\n", sigma, b, r);
	fprintf (rk4, "#Tiempo		X		Y		Z           |Intensidad\n");

	printf ("\n\nESPERA...\n");

	for (i=0; i<=n; i++){
		K1=dx(x0, y0);
		L1=dy(x0, y0, z0);
		M1=dz(x0, y0, z0);

		K2=dx(x0+(h/2)*K1, y0+(h/2)*L1);
		L2=dy(x0+(h/2)*K1, y0+(h/2)*L1, z0+(h/2)*M1);
		M2=dz(x0+(h/2)*K1, y0+(h/2)*L1, z0+(h/2)*M1);

		K3=dx(x0+(h/2)*K2, y0+(h/2)*L2);
		L3=dy(x0+(h/2)*K2, y0+(h/2)*L2, z0+(h/2)*M2);
		M3=dz(x0+(h/2)*K2, y0+(h/2)*L2, z0+(h/2)*M2);

		K4=dx(x0+h*K3, y0+h*L3);
		L4=dy(x0+h*K3, y0+h*L3, z0+h*M3);
		M4=dz(x0+h*K3, y0+h*L3, z0+h*M3);

		x = x0 + (h/6)*(K1 + 2*K2 + 2*K3 + K4);
		y = y0 + (h/6)*(L1 + 2*L2 + 2*L3 + L4);
		z = z0 + (h/6)*(M1 + 2*M2 + 2*M3 + M4);

		t = i*h;

		intensidad = pow(x,2);

		fprintf (rk4, "%lf	%lf	%lf	%lf             %lf\n", t, x0, y0, z0, intensidad);

		x0 = x;
		y0 = y;
		z0 = z;
	}

	printf ("\n\nLISTO!\n\n");
}

double dx (double x, double y){
	double resultadox;

	resultadox = sigma*(y-x);

	return resultadox;
}

double dy (double x, double y, double z){
	double resultadoy;

	resultadoy = x*(r-z)-y;

	return resultadoy;
}

double dz (double x, double y, double z){
	double resultadoz;

	resultadoz = x*y-b*z;

	return resultadoz;
}

