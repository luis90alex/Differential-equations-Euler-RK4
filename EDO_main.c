#include "New_Edo_Header.h"

double sigma, b, r, x, y, z, n, t, h, intensidad;
double inicial_x, inicial_y, inicial_z;

int main (){
    char myname[]="     Adria Medeiros (NIU:1388403)\n     Luis Farfan (NIU:1388330)\n     Lucas Fuentealba (NIU:1388326)\n";
    printf("Programa realizado por\n%s\n",myname);
    char repeticio;
    char procediment;

    printf ("\nBIENVENIDO. ESTE PROGRAMA RESUELVE LAS ECUACIONES DE LORENZ-HAKEN PARA UN LASER.");

    do{
        printf ("\n\nDETERMINA LAS CONSTANTES DEL SISTEMA:\n");
        printf ("Sigma: ");
        scanf ("%lf", &sigma);
        printf ("b: ");
        scanf ("%lf", &b);
        printf ("r: ");
        scanf ("%lf", &r);

        printf ("\nDETERMINA LAS CONDICIONES INICIALES:\n");
        printf ("x0: ");
        scanf ("%lf", &inicial_x);
        printf ("y0: ");
        scanf ("%lf", &inicial_y);
        printf ("z0: ");
        scanf ("%lf", &inicial_z);

        fflush(stdin);

        printf("\n\nELIGE EL PROCEDIMIENTO QUE QUIERES APLICAR:\n- Pulsa 'E' para Euler.\n- Pulsa 'R' para Runge-Kutta 4.\n");
        scanf("%c",&procediment);
        if ( procediment == 'e' || procediment== 'E'){
            EULER(sigma, b, r, inicial_x, inicial_y, inicial_z);
        }
        else{
            if (procediment== 'r' || procediment== 'R'){
                RK4(sigma, b, r, inicial_x, inicial_y, inicial_z);
            }
            else{
                printf("\nPor favor introduce un caracter valido\n");
            }
        }


        fflush(stdin);
        printf("\nDESEAS VOLVER A INICIAR EL PROGRAMA?\n\n- Si no quieres pulsa n.\n- Si  quieres pulsa cualquier otra tecla.\n");
        scanf("%c",&repeticio);

    }while(repeticio !='n' && repeticio !='N');


    system("pause");
    return 0;
}
