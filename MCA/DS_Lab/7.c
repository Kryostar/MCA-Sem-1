// GCD of three numbers
int gcd3(int a, int b)
{
	if (b == 0)
		return a;
	return gcd3(b, a % b);
}
1
{
	int a, b, c;
	system("cls"); // use clrscr();
	printf("Enter three numbers:");
	scanf("%d %d %d", &a, &b, &c);

	system("cls");
	int final = gcd3(a, gcd3(b, c));
	printf("GCD of %d, %d & %d is %d", a, b, c, final);
}
