
class Franc
{
	public:
		int _amount;

		Franc(int amount){
			_amount = amount;
		};

		Franc times(int multiplier){
			return Franc(_amount * multiplier); // 5CHF X 2 = 10CHF
		};

		bool equals(Franc franc){
			return _amount == franc._amount; // equals()
		};

	private:
};