#include <iostream>
#include <string>
#include <vector>
using namespace std;

const unsigned int urlVarCount(const string& url)
{
	unsigned short i = 0;
	for (const auto& c : url)
		if (c == '=')
			++i;
	return i;
}

class UrlHolder {
private:
	const string& url;
	vector<string> info;
public:
	UrlHolder(const string& _url)
		: url(_url)
	{
		info.push_back("");
		getInfos();
	}
	const string& getUrl() const { return url; }
	void printInfos() const 
	{
		for (const auto& s : info)
		{
			cout << s << endl;
		}
	}
	void getInfos()
	{
		short vecPos = 0;
		char temp;
		short varExist = url.find('?');
		if (varExist > -1) 
		{
			for (unsigned short i = varExist + 1; i < url.size(); i++)
			{
				if (url.at(i) == '&') 
				{
					info.push_back("");
					vecPos++;
					continue;
				}
				temp = url.at(i);
				info.at(vecPos) += temp;
			}
		}
	}
};

int main(int argc, char** argv)
{
	string link;
	cout << "Enter Link: ";
	cin >> link;
	cin.ignore(); cin.sync(); cin.clear();
	unsigned counter = urlVarCount(link);
	cout << counter << " variables found!" << endl;
	UrlHolder Bucket(link);
	Bucket.printInfos();
	system("pause");
	return 0;
}
