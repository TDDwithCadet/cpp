
class Dollar
{
	public:
		Dollar(int amount){
			_amount = amount;
		};

		void times(int multiplier){
			_amount = _amount * multiplier;
		};
		int _amount;

	// private:
};