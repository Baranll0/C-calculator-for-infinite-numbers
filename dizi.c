#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 10000
#define true 1
#define false 0
int sayi1[MAX], sayi2[MAX], topla[MAX];
char s1[MAX], s2[MAX];
int l1, l2;
void sayiTopla(int sayi1[], int sayi2[], char s1[], char s2[], int l1, int l2)
{
	for (l1 = 0; s1[l1] != '\0'; l1++) // Al�nan say�y� integer e �evirme i�lemi diziyle yap�l�yor.
	{
		sayi1[l1] = s1[l1] - '0';
	}
	for (l2 = 0; s2[l2] != '\0'; l2++)
	{
		sayi2[l2] = s2[l2] - '0';
	}
	int tasi = 0; // Toplama i�lemi yap�l�r elde bir sonraki say�y�a aktar�l�r.
	int k = 0;
	int i = l1 - 1;
	int j = l2 - 1;
	for (; i >= 0 && j >= 0; i--, j--, k++)
	{
		topla[k] = (sayi1[i] + sayi2[j] + tasi) % 10;
		tasi = (sayi1[1] + sayi2[j] + tasi) / 10;
	}
	if (l1 > l2)
	{
		while (i >= 0)
		{
			topla[k++] = (sayi1[i] + tasi) % 10;
			tasi = (sayi1[i--] + tasi) / 10;
		}
	}
	else if (l1 < l2)
	{
		while (j >= 0)
		{
			topla[k++] = (sayi2[j] + tasi) % 10;
			tasi = (sayi2[j--] + tasi) / 10;
		}
	}
	else
	{
		if (tasi > 0)
		{
			topla[k++] = tasi;
		}
	}
	while (true) // Burada hangi say�n�n b�y�k oldu�una karar vererek while i�inde toplam sonucu yazd�r�r.
	{
		if (strlen(s2) > strlen(s1))
		{
			printf("%s\n", s2);
			for (i = 0; i < strlen(s2) - strlen(s1); i++)
			{
				printf(" ");
			}
			printf("%s\n+\n", s1);
			for(i=0;i<strlen(s2);i++)
				printf("_");
			printf("\n");
			for (k--; k >= 0; k--)
			{
				printf("%d ", topla[k]);
			}
			break;
		}
		else
		{
			printf(" %s\n", s1);
			for (i = 0; i < strlen(s1) - strlen(s2); i++)
			{
				printf(" ");
			}
			printf(" %s\n+\n", s2);
			for(i=0;i<strlen(s1);i++)
				printf("_");
			printf("\n");
			for (k--; k >= 0; k--)
			{
				printf("%d ", topla[k]);
			}
			break;
		}
	}
}
void sayiCikar(char number1[], char number2[], int num1[], int num2[])
{
	int n = strlen(number1), m = strlen(number2);
	int i;
	for (i = 0; i < n; i++) // Al�nan say�y� integere d�n��t�rme i�lemi yap�l�r.
	{
		num1[i] = number1[n - i - 1] - '0';
	}
	for (i = 0; i < m; i++)
	{
		num2[i] = number2[m - i - 1] - '0';
	}
	int k;
	if (n > m)
	{
		k = n;
	}
	else
	{
		k = m;
	}
	printf("\n");
	if (strlen(number1) > strlen(number2)) // Burada hangi say�n�n basamak say�s� b�y�kse diye kontrol edilir.B�y�k olandan k���k say�y� ��karma i�lemi yap�ld�ktan sonra yazd�rma i�lemi yap�l�r.
	{									   // 1.Say� daha b�y�kse Sayi 2 dekini azalt�p sayi 1 e ekler.Ek durumda da 10 ekler(4-6 gibi i�lemde 4 e 10 ekler )
		printf("%s\n", number1);
		for (i = 0; i < strlen(number1) - strlen(number2); i++)
		{
			printf(" ");
		}
		printf("%s\n-\n", number2);
		for(i=0;i<strlen(number1);i++)
			printf("_");
		printf("\n");
		for (i = 0; i < k; i++)
		{						// Mainly in this part
			num1[i] -= num2[i]; //
			if (num1[i] < 0)
			{				   //
				num1[i + 1]--; //
				num1[i] += 10; //
			}
		}
		i = k;
		while (num1[i] == 0)
			i--;
		if (i < 0)
			printf("0");
		for (; i >= 0; i--)
		{
			printf("%d ", num1[i]);
		}
	}
	else if (strlen(number1) < strlen(number2)) // Burada ise sayi2 nin sayi1 den basamak say�s� olarak b�y�k oldu�u durumu kontrol eder.Ve ayn� i�lemi burada da yapar
	{
		printf("%s\n", number2);
		for (i = 0; i < strlen(number2) - strlen(number1); i++)
		{
			printf(" ");
		}
		printf("%s\n-\n", number1);
		for(i=0;i<strlen(number2);i++)
			printf("_");
		printf("\n");
		for (i = 0; i < k; i++)
		{
			num2[i] -= num1[i];
			if (num2[i] < 0)
			{
				num2[i + 1]--;
				num2[i] += 10;
			}
		}
		i = k;
		while (num2[i] == 0)
			i--;
		if (i < 0)
			printf("0");
		for (; i >= 0; i--)
		{
			printf("%d ", num2[i]);
		}
	}
	else if (strlen(number1) == strlen(number2)) // Geriye tek durum kal�yor: iki say�n�n basamak say�s�n�n e�it olmas� durumu.
	{
		i = 1;
		int j;
		while (i <= k) // Buradan sonraki i�lemlerde say�n�n teker teker basamak de�erlerini kontrol eder.Ve b�y�k olan� k���k olandan ��kard�ktan sonra
		{			   // Return ile sonland�r�r ki a�a��da while den sonra tekrar bi i�lem yapmas�n diye.
			if (num1[k - i] > num2[k - i])
			{
				printf("%s\n", number1);
				printf("%s\n-\n", number2);
				for(i=0;i<strlen(number1);i++)
					printf("_");
				printf("\n");
				for (j = 0; j < k; j++)
				{
					num1[j] -= num2[j];
					if (num1[j] < 0)
					{
						num1[j + 1]--;
						num1[j] += 10;
					}
				}
				j = k;
				while (num1[j] == 0)
					j--;
				if (j < 0)
					printf("0");
				for (; j >= 0; j--)
				{
					printf("%d", num1[j]);
				}
				return 0;
			}
			else if (num2[k - i] > num1[k - i])
			{
				printf("%s\n", number2);
				printf("%s\n-\n", number1);
				for(i=0;i<strlen(number2);i++)
					printf("_");
				printf("\n");
				for (j = 0; j < k; j++)
				{
					num2[j] -= num1[j];
					if (num2[j] < 0)
					{
						num2[j + 1]--;
						num2[j] += 10;
					}
				}
				j = k;
				while (num2[j] == 0)
					j--;
				if (j < 0)
					printf("0");
				for (; j >= 0; j--)
				{
					printf("%d", num2[j]);
				}
				return 0;
			}
			i++;
		}
		printf("%s\n", number2);
		printf("%s\n-\n", number1);
		for(i=0;i<strlen(number2);i++)
			printf("_");
		printf("\n");
		for (j = 0; j < k; j++)
		{
			num2[j] -= num1[j];
			if (num2[j] < 0)
			{
				num2[j + 1]--;
				num2[j] += 10;
			}
		}
		j = k;
		while (num2[j] == 0)
			j--;
		if (j < 0)
			printf("0");
		for (; j >= 0; j--)
		{
			printf("%d", num2[j]);
		}
	}
}
void sayiCarp(char number1[], char number2[], int num1[], int num2[]) // Burada �arpma i�lemi kontrol edilir.
{	// Sonu� [i+j] = num1[i] * num2[j]; bu, esasen s�ras�yla num1[i] 10^i ve num2[j] 10^j'nin �arp�m�d�r.
	// Sonu� num1[i]*num2[j]*10^(i+j) olur. O zaman sonu� tam olarak i+j konumunda, yani s�zde yasa ortaya ��k�yor.
	//  �z� hesaplama y�ntemi ile s�n�rl�d�r
	int result[1000] = {0};
	int n = strlen(number1), m = strlen(number2);
	int i, j;
	for (i = 0; i < n; i++)
	{
		num1[i] = number1[n - i - 1] - '0';
	}
	for (i = 0; i < m; i++)
	{
		num2[i] = number2[m - i - 1] - '0';
	}
	int k = n + m; //�arpma kural�na g�re �arpma sonucunun basamak say�s� m+n i ge�meyecektir.
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			result[i + j] += num1[i] * num2[j]; // result[i+j]=num1[i]*num2[j] i�lemi yap�l�r.
		}										// num1[i] 10^i, num2[j] 10^j ile �arp�l�r ve sonu� num1[i]*num2[j]*10^(i+j) olur
	}											// Sonu� i+j konumunda olur.B�ylece s�zde kural ortaya ��kar ve �z� hesaplama yoluyla s�n�rland�r�l�r.
	for (i = 0; i < k; i++)
	{
		if (result[i] >= 10)
		{
			result[i + 1] += result[i] / 10;
			result[i] %= 10;
		}
	}
	if (strlen(number1) > strlen(number2)) // Burada da say�lar�n basamak say�lar�n� kar��la�t�r�p ekrana yazd�r�l�r.
	{
		printf("%s\n", number1);
		for (i = 0; i < strlen(number1) - strlen(number2); i++)
		{
			printf(" ");
		}
		printf("%s\n*\n", number2);
		for(i=0;i<strlen(number1);i++)
			printf("_");
	}
	else
	{
		printf("%s\n", number2);
		for (i = 0; i < strlen(number2) - strlen(number1); i++)
		{
			printf(" ");
		}
		printf("%s\n*\n", number1);
		for(i=0;i<strlen(number2);i++)
			printf("_");
	}
	printf("\n");
	i = k;
	while (result[i] == 0)
		i--;
	if (i < 0)
		printf("0");
	else
		for (; i >= 0; i--)
		{
			printf("%d ", result[i]);
		}
}
int main()
{
	printf("Kac basamakli ? (En fazla %d): \n", MAX); // Burada basamak say�s� al�n�r. Yukar�daki MAX de�erini y�netici istedi�i �ekilde de�i�tirebilir.
	int max, secim;									  // Ve kullan�c�y� biraz da olsa s�n�rlar.
	char *c;
	scanf("%d", &max);
	if (max > MAX) // Burada s�n�r� ge�memesi i�in kontrol edilir.
	{
		printf("Siniri gectiniz. ");
		return;
	}
	printf("1.TOPLA\n");
	printf("2.CIKAR\n");
	printf("3.CARP \n");
	scanf("%d", &secim); // Kullan�c�n�n yapaca�� i�lem se�ilir.
	int i;
	switch (secim)
	{
		case 1:
			printf("1.Sayi: ");
			scanf("%s", &s1);
			for (i = 0; i < strlen(s1); i++) // Say�y� string olarak ald���m�z i�in ger�ek bir string de�eri girerse diye ASCII kodlar� ile kontrol edilir.
			{								 // Kullan�c�n�n say� d���nda ba�ka karakter girilmesine izin verilmez.
				if (47 < s1[i] && s1[i] > 58)
				{
					printf("Hatali sayi girisi yaptiniz.");
					return 0;
				}
			}
			printf("2.Sayi: ");
			scanf("%s", &s2);
			for (i = 0; i < strlen(s2); i++) // Say�y� string olarak ald���m�z i�in ger�ek bir string de�eri girerse diye ASCII kodlar� ile kontrol edilir.
			{								 // Kullan�c�n�n say� d���nda ba�ka karakter girilmesine izin verilmez.
				if (47 < s2[i] && s2[i] > 58)
				{
					printf("Hatali sayi girisi yaptiniz.");
					return 0;
				}
			}
			sayiTopla(sayi1, sayi2, s1, s2, l1, l2);
			break;
		case 2:
			printf("1.Sayi: ");
			scanf("%s", &s1);
			for (i = 0; i < strlen(s1); i++) // Say�y� string olarak ald���m�z i�in ger�ek bir string de�eri girerse diye ASCII kodlar� ile kontrol edilir.
			{								 // Kullan�c�n�n say� d���nda ba�ka karakter girilmesine izin verilmez.
				if (47 < s1[i] && s1[i] > 58)
				{
					printf("Hatali sayi girisi yaptiniz.");
					return 0;
				}
			}
			printf("2.Sayi: ");
			scanf("%s", &s2);
			for (i = 0; i < strlen(s2); i++)
			{
				if (47 < s2[i] && s2[i] > 58) // Say�y� string olarak ald���m�z i�in ger�ek bir string de�eri girerse diye ASCII kodlar� ile kontrol edilir
				{							  // Kullan�c�n�n say� d���nda ba�ka karakter girilmesine izin verilmez.
					printf("Hatali sayi girisi yaptiniz.");
					return 0;
				}
			}
			sayiCikar(s1, s2, sayi1, sayi2);
			break;
		case 3:
			printf("1.Sayi: ");
			scanf("%s", &s1);
			for (i = 0; i < strlen(s1); i++) // Say�y� string olarak ald���m�z i�in ger�ek bir string de�eri girerse diye ASCII kodlar� ile kontrol edilir
			{								 // Kullan�c�n�n say� d���nda ba�ka karakter girilmesine izin verilmez.
				if (47 < s1[i] && s1[i] > 58)
				{
					printf("Hatali sayi girisi yaptiniz.");
					return 0;
				}
			}
			printf("2.Sayi: ");
			scanf("%s", &s2);
			for (i = 0; i < strlen(s2); i++) // Say�y� string olarak ald���m�z i�in ger�ek bir string de�eri girerse diye ASCII kodlar� ile kontrol edilir
			{								 // Kullan�c�n�n say� d���nda ba�ka karakter girilmesine izin verilmez.
				if (47 < s2[i] && s2[i] > 58)
				{
					printf("Hatali sayi girisi yaptiniz.");
					return 0;
				}
			}
			sayiCarp(s1, s2, sayi1, sayi2);
			break;
		default: // Burada ise �� i�lem d���nda ba�ka se�im yap�lmamas� i�in kontrol edilir.
			printf("Hatali secim yaptiniz.");
			break;
	}
	return 0;
}
