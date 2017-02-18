#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <map> 

std::string prepare(std::string& s)
{
	std::string result;
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	result = s;
	if( (result[result.length() - 1] == '.')||(result[result.length() - 1] ==',')
	   ||(result[result.length() - 1] =='"')||(result[result.length() - 1] =='!')||(result[result.length() - 1] == '?') )
		result.pop_back();
	return result;
}

struct Dict
{
 	std::string key;
	int value;
};

bool cmp(Dict p1, Dict p2)
{
	return p1.value > p2.value;
}

int main(int argc, char **argv)
{
	struct Dict list;
	std::vector<Dict> v;
	std::map<std::string, int> mymap;
	std::map<std::string, int> ::iterator it;
	std::ifstream fin("Warlocks_shadow.txt.txt");
			
	while(!fin.eof())
	{
		std::string word;
		fin >> word;
		word = prepare(word);
	 	mymap[word]++;
	}           
	
	int i = 0;
	
	for(it = mymap.begin(); it != mymap.end(); it++)
	{
		v.push_back(list);
		v.at(i).key = (*it).first;
		v.at(i).value = (*it).second;
		i++;
 	}
 	
 	std::sort(v.begin(), v.end(),cmp);
 	for(i = 0; i <= 50; i++)
 	{
		std::cout << v.at(i).key << " " << v.at(i).value << std::endl;
	}
	return 0;
}

