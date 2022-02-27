class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string res;
        int num1_real, num1_imaginary;
        int num2_real, num2_imaginary;
        int res_real, res_imaginary;
        
        num1_real = stoi(num1.substr(0, num1.find('+')));
        num1_imaginary = stoi(num1.substr(num1.find('+') + 1, num1.find('i')));
        num2_real = stoi(num2.substr(0, num2.find('+')));
        num2_imaginary = stoi(num2.substr(num2.find('+') + 1, num2.find('i')));

        res_real = num1_real * num2_real - num1_imaginary * num2_imaginary;
        res_imaginary = num1_real * num2_imaginary + num2_real * num1_imaginary;
        res.append(std::to_string(res_real));
        res.push_back('+');
        res.append(std::to_string(res_imaginary));
        res.push_back('i');

        return res;
    }
};

