#include <iostream>


long long gcd_cross(long long goal, long long divisor, long long target, long long iterations){
	if ((goal - target) % divisor == 0) return (goal - target) / divisor + iterations;
	else return -1;
}

long long answer(long long aStart, long long eStart, long long aEnd, long long eEnd){
	long long iterations = 0;
	while (aEnd >= aStart && eEnd >= eStart){
		if (aEnd > eEnd){
			if (eStart == eEnd) return gcd_cross(aEnd, eEnd, aStart, iterations);
			iterations += aEnd / eEnd;
			aEnd %= eEnd;
		}
		else if (eEnd > aEnd){
			if (aStart == aEnd) return gcd_cross(eEnd, aEnd, eStart, iterations);
			iterations += eEnd / aEnd;
			eEnd %= aEnd;
		}
		else if (aStart == aEnd && eStart == eEnd) return iterations;
		else return -1;
	}
	return -1;
}

int main(){

	long long a, b, c, d;
	std::cin >> a >> b >> c >> d;

	std::cout << answer(a, b, c, d);

}