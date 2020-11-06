#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
#define LL long long
LL b, d, n;
LL p = 7528443412579576937l;
LL mul(LL x, LL y){
	LL ans = 0;
	if(y < 0){LL t = x; x = y; y = t;}  
	if(x < 0 && y < 0) x = -x, y = -y;
	while(y){
		if(y & 1) ans = (ans + x) % p;
		x = (x << 1) % p;
		y >>= 1;
	}
//	cout << ans << endl;
	return ans;
}
LL quickpow(LL x, LL k){
	LL ans = 1;
	while(k){
		if(k & 1)	ans = mul(ans, x);
		x = mul(x, x);
		k >>= 1;
	}
	return ans;
}
LL b1, b2, b3, b4;
void Mquickpow(LL a1, LL a2, LL a3, LL a4, LL k)
{
	b1 = 1, b2 = 0, b3 = 0, b4 = 1;
	while(k){
		if(k & 1){
			b1 = (mul(b1, a1) + mul(b1, a3)) % p;
			b2 = (mul(b1, a2) + mul(b2, a4)) % p;
			b3 = (mul(b3, a1) + mul(b4, a3)) % p;
			b4 = (mul(b3, a2) + mul(b4, a4)) % p;
		}
		a1 = (mul(a1, a1) + mul(a1, a3)) % p;
		a2 = (mul(a1, a2) + mul(a2, a4)) % p;
		a3 = (mul(a3, a1) + mul(a4, a3)) % p;
		a4 = (mul(a3, a2) + mul(a4, a4)) % p;
		k >>= 1;
	}
}
int main(void)
{
	scanf("%lld %lld %lld", &b, &d, &n);
	if(!n)					printf("1\n");
	if(b * b == d)			printf("%lld\n", quickpow(b, n));
	LL x1 = b, x2 = (b * b - d) / 2;  
	Mquickpow(b, (b * b - d) >> 2, 1, 0, n - 1);
	LL xn = (mul(b3, x2) + mul(b4, x1)) % p;
	if(n & 1)	printf("%lld\n", xn);
	else		printf("%lld\n", xn - 1);
	return 0;
}
