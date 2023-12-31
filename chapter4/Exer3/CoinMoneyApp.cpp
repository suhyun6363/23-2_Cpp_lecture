//=========================================================
// 응용 과제 1을 발전시킴
// inheritance
//=========================================================
#include <iostream>
#include <string>		
#include <memory>
#include <vector>
#include <algorithm>
using std::string; using std::shared_ptr;
using std::static_pointer_cast;
using std::cout; using std::endl;
using std::ostream;
using std::vector;
using std::find_if;

class CoinMoney
{
public:
	CoinMoney() : c50(0), c100(0), c500(0)
	{ cout << "CoinMoney default ctor" << endl; }

	CoinMoney(int c, int cc, int ccc)
		: c50(c), c100(cc), c500(ccc)
	{ cout << "CoinMoney ctor" << endl; }

	virtual ~CoinMoney()
	{ cout << "CoinMoney dtor" << endl; }

	virtual int get_value() const
	{ return (50 * c50 + 100 * c100 + 500 * c500); }

	int get_c50() const { return c50; }
	int get_c100() const { return c100; }
	int get_c500() const { return c500; }
	void set_c50(int c) { c50 = c; }
	void set_c100(int cc) { c100 = cc; }
	void set_c500(int ccc) { c500 = ccc; }
protected:
	int c50, c100, c500;
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
		<< "총 " << m.get_value() << "원" << endl;
	return os;
}

class MyCoinMoney : public CoinMoney
{
public:
	MyCoinMoney(int nc, int c, int cc, int ccc, string name)
		: CoinMoney(c, cc, ccc),  c10(nc), owner(name)
	{ cout << "MyCoinMoney ctor" << endl; }

	~MyCoinMoney()
	{ cout << "MyCoinMoney dtor" << endl; }

	virtual int get_value() const
	{ return (10 * c10 + 50 * c50 + 100 * c100 + 500 * c500); }
	// friend declaration for operator<<
	friend ostream& operator<<(ostream&, const MyCoinMoney&);

	string get_owner() const {
		return owner;
	}
private:
	int c10;
	string owner;
};
// operator<< overloading
ostream& operator<<(ostream& os, const MyCoinMoney& m)
{
	os << m.owner << ": "
		<< "10원 " << m.c10 << "개, "
		<< "50원 " << m.c50 << "개, "
		<< "100원 " << m.c100 << "개, "
		<< "500원 " << m.c500 << "개, "
		<< "총 " << m.get_value() << "원" << endl;
	return os;
}

int main()
{
	MyCoinMoney m1{ 1, 2, 3, 4, "doohun" };
	MyCoinMoney m2{ 2, 3, 4, 5, "doohun" };
	MyCoinMoney m3{ 3, 4, 2, 1, "doohun" };
	MyCoinMoney m4{ 3, 2, 4, 3, "youngmi" };
	MyCoinMoney m5{ 2, 4, 3, 2, "doohun" };
	MyCoinMoney m6{ 3, 4, 4, 3, "youngmi" };
	vector<MyCoinMoney> vec{ m1, m2, m3, m4, m5, m6 };
	// Exer: lamda
	vector<MyCoinMoney>::iterator it;
	string name = "youngmi";
	it = find_if(vec.begin(), vec.end(), 
		[name] (auto m)
		{ return (m.get_owner() == name ? true : false); });
	if (it != vec.end()) {
		cout << "the first element for " << *it;
	}
	else {
		cout << "소유주가 " << name << "인 원소 존재하지 않음" << endl;
	}

	system("pause");
	return 0;
}