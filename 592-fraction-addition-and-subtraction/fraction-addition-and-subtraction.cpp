class Solution {
public:
    string fractionAddition(string expression) {
        int i = 0, n = expression.size();
        int numerator = 0, denominator = 1;

        while(i < n){
            int sign = 1;

            if(expression[i] == '+' || expression[i] == '-'){
                if(expression[i] == '-'){
                    sign = -1;
                }
                i++;
            }

            int number = 0;
            while(i < n && isdigit(expression[i])){
                number = number*10 + (expression[i] - '0');
                i++;
            }

            number *= sign;
            i++;
            int div = 0;

            while(i<n && isdigit(expression[i])){
                div = div*10 + (expression[i] - '0');
                i++;
            }

            numerator = (numerator * div) + (number * denominator);
            denominator *= div;

            int res = gcd(numerator,denominator);
            numerator /= res;
            denominator /= res;
        }

        return to_string(numerator)+'/'+to_string(denominator);
    }
};