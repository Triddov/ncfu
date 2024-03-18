#include <iostream>
#include <vector>

class MoneyCounter
{
private:
	int denomination = 0;
	int amount_banknotes = 0;
	int SumMoney = 0;
	bool den_error = false;

	int sum_money(int denomination, int amount_banknotes) {
		if (den_error == false) {
			int SumMoney = denomination * amount_banknotes;
			return SumMoney;
		}
	}

	bool den_condition(int den) {
		std::vector<int> true_denomination = { 1,2,5,10 };

		for (int i = 0; i < true_denomination.size(); i++) {
			if (den == true_denomination[i]) {
				return true;
			}
		}
		return false;
	}

public:
	MoneyCounter(){
		int den, amo;

		std::cout << "enter denomination of banknotes(1,2,5 or 10)\n";
		std::cin >> den;

		if (den_condition(den)) { denomination = den; }
		else { std::cerr << "invalid denomination of banknotes\n"; den_error = true; }

		if (den_error == false) {
			std::cout << "enter amount of banknotes\n";
			std::cin >> amo;
			amount_banknotes = amo;
		}
	}

	~MoneyCounter() {}

	void balance() {
		std::cout << "Sum of your money: " << sum_money(denomination, amount_banknotes);
	}
};


int main()
{
	MoneyCounter MyMoney;

	MyMoney.balance();

	return 0;
}