using namespace std;

int gcd(int a, int b) {
	
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long solution(int w, int h)
{
	long long answer = 0;

	if (gcd(w, h) != 1){
        answer = (long long) w * (long long) h - (w / gcd(w, h) + h / gcd(w, h) - 1) * gcd(w, h);
		return answer;
    }
    else{
        answer = (long long) w * (long long) h - (w + h - 1);       
		return answer;
    }
}
