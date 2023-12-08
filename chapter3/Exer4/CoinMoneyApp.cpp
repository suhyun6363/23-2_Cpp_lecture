// 연습문제 3을 발전시킴
// remove print and get_value member function
// type conversion
#include <iostream>
using std::cout; using std::endl;
using std::ostream;

class CoinMoney
{
public:
	CoinMoney() : c50(0), c100(0), c500(0)
	{}

	CoinMoney(int c, int cc, int ccc)
		: c50(c), c100(cc), c500(ccc)
	{}

	virtual ~CoinMoney()
	{}
	explicit operator int() const
	{
		return (50 * c50 + 100 * c100 + 500 * c500);
	}
	// Exer4
	explicit CoinMoney(int totalPrice)
	{
		c500 = totalPrice / 500;
		int remainPrice; 
		remainPrice = totalPrice % 500;

		c100 = remainPrice / 100;
		remainPrice %= 100;

		c50 = remainPrice / 50;
		remainPrice %= 50;

		if (remainPrice > 0)
		{
			cout << remainPrice << "원 남았습니다." << endl;
		}
	}

	int get_c50() const { return c50; }
	int get_c100() const { return c100; }
	int get_c500() const { return c500; }

	void set_c50(int c) { c50 = c; }
	void set_c100(int cc) { c100 = cc; }
	void set_c500(int ccc) { c500 = ccc; }
protected:
	int c50;
	int c100;
	int c500;
};

CoinMoney add(const CoinMoney& m1, const CoinMoney& m2)
{
	CoinMoney sum;
	sum.set_c50(m1.get_c50() + m2.get_c50());
	sum.set_c100(m1.get_c100() + m2.get_c100());
	sum.set_c500(m1.get_c500() + m2.get_c500());
	return sum;
}

ostream& operator<<(ostream& os, const CoinMoney& m)
{
	os << "50원 " << m.get_c50() << "개, "
		<< "100원 " << m.get_c100() << "개, "
		<< "500원 " << m.get_c500() << "개, "
		<< "총 " << int(m) << "원" << endl;	 // Exer
	return os;
}

int main()
{
	CoinMoney m1;
	CoinMoney m2{ 2, 3, 4 };
	m1 = CoinMoney(4752);		// Exer4
	cout << "m1 = " << m1;
	cout << "m2 = " << m2;
	int value = int(m2);		
	cout << "m2는 총 " << value << "원" << endl;

	system("pause");
	return 0;
}