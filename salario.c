#include <stdio.h>

int lerFuncionario(int *exp, int *hc, int *ht, char *func);

int calcularSalario(int exp, int hc, int ht, char func, float *sb, int *hex, float *sl, float *inss, float *ir);

int imprimirFolhaPagamento(float sb, int hex, float sl, float inss, float ir);

int main()
{
    int exp, hc, ht, hex, qtd;
    float sb, sl, inss, ir;
    char func;

    

    do
    {
        printf("Quantidade de funcionarios: \n");
        scanf("%d", &qtd);
        if(qtd <= 0)
        {
            printf("A quantidade de funcionarios deve ser maior que zero! Tente novamente!\n");
        }
    } while (qtd <= 0);
    
    for(int i = 1; i <= qtd; i++)
    {
        printf("=============\nFuncionario %d\n", i);
        lerFuncionario(&exp, &hc, &ht, &func);
        calcularSalario(exp, hc, ht, func, &sb, &hex, &sl, &inss, &ir);
        printf("Folha de pagamento do funcionario %d\n", i);
        imprimirFolhaPagamento(sb, hex, sl, inss, ir);
    }

    return 0;
}

int lerFuncionario(int *exp, int *hc, int *ht, char *func)
{
    do
    {
        printf("- Funcao: ");
        scanf(" %c", func);

        if (*func != 'P' && *func != 'p')
        {
            printf("Dado incorreto, digite novamente\n");
        }
        
    } while (*func != 'P' && *func != 'p');

    do
    {
        printf("- Anos de experiencia: ");
        scanf("%d", exp);

        if (*exp < 0)
        {
            printf("Dado incorreto, digite novamente\n");
        }
        
    } while (*exp < 0);

    do
    {
        printf("- Horas contratadas: ");
        scanf("%d", hc);

        if (*hc <= 0)
        {
            printf("Dado incorreto, digite novamente\n");
        }
        
    } while (*hc <= 0);
    
    do
    {
        printf("- Horas trabalhadas: ");
        scanf("%d", ht);

        if (*ht < 0)
        {
            printf("Dado incorreto, digite novamente\n");
        }
        
    } while (*ht < 0);
}

int calcularSalario(int exp, int hc, int ht, char func, float *sb, int *hex, float *sl, float *inss, float *ir)
{
    int vph;
    if (func == 'P' || func == 'p')
    {
        if (exp <= 2)
        {
            vph = 25;
        }
        else if (exp <= 5)
        {
            vph = 30;
        }
        else
        {
            vph = 38;
        }
    }
    if (func == 'A' || func == 'a')
    {
        if (exp <= 2)
        {
            vph = 45;
        }
        else if (exp <= 5)
        {
            vph = 55;
        }
        else
        {
            vph = 70;
        }
    }
    if (func == 'G' || func == 'g')
    {
        if (exp <= 2)
        {
            vph = 85;
        }
        else if (exp <= 5)
        {
            vph = 102;
        }
        else
        {
            vph = 130;
        }
    }

    *hex = ht - hc;
    *sb = (float) ht * vph;
    
    if (*hex > 0)
    {
        if (*hex <= 13)
        {
            *sb += (float) 0.23 * vph * *hex;
        }
        else if (*hex <= 22)
        {
            *sb += (float) 0.37 * vph * *hex;
        }
        else if (*hex > 22)
        {
            *sb += (float) 0.56 * vph * *hex;
        }
    }

    *inss = *sb * (float) 0.11;
    

    if (*sb <= 1500)
    {
        *ir = 0;
        *sl = *sb - *inss;
    }
    else if(*sb <= 2700)
    {
        *ir = (*sb - *inss) * (float) 0.15;
        *sl = *sb - *inss - *ir;
    }
    else if(*sb <= 4200)
    {
        *ir = (*sb - *inss) * (float) 0.20;
        *sl = *sb - *inss - *ir;
    }
    else if(*sb > 4200)
    {
        *ir = (*sb - *inss) * (float) 0.30;
        *sl = *sb - *inss - *ir;
    }
    
}

int imprimirFolhaPagamento(float sb, int hex, float sl, float inss, float ir)
{
    printf("- Salario bruto...(R$):\t%.2f\n", sb);
    if (hex > 0)
    {
        printf("- Horas excedentes (h):\t%dhr\n", hex);
    }
    printf("- Desconto INSS...(R$):\t%.2f\n", inss);
    printf("- Desconto IR.....(R$):\t%.2f\n", ir);
    printf("- Salario liquido.(R$):\t%.2f\n", sl);
}