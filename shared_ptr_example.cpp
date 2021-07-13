/*shared_ptr explainer with examples*/

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class MyInt {
private :
	int i_;
public:
	MyInt(int i) : i_(i) {
		std::cout << "Hello from " << i_ << std::endl;
	}
	~MyInt() {
		std::cout << "Goodbye from " << i_ << std::endl;
	}

};



int main()
{
	{
		//Init
		std::shared_ptr<MyInt> sp1(new MyInt(1998));				//two memory allocations. Mem allocation is costly , use the efficient make_shared		
		std::shared_ptr<MyInt> sp2 = std::make_shared<MyInt>(2011);	//preffered way
		std::cout << "sp2.use_count() = " << sp2.use_count() << std::endl;
		std::shared_ptr<MyInt> sp3(sp2);
		std::cout << "sp2.use_count() = " << sp2.use_count() << std::endl;
		std::cout << std::endl;

		// shared_ptr.get() and .use_count()
		std::cout << "sp1.get() = " << sp1.get() << std::endl;
		std::cout << "sp2.get() = " << sp2.get() << std::endl;
		std::cout << "sp3.get() = " << sp3.get() << std::endl;
		std::cout << std::endl;

		std::cout << "sp3.reset()" << std::endl;
		sp3.reset();
		std::cout << "sp2.use_count() = " << sp2.use_count() << std::endl;
		std::cout << "sp3.use_count() = " << sp3.use_count() << std::endl;
		std::cout << std::endl;

		sp2 = std::make_shared<MyInt>(2020);
		std::cout << "sp2.get() = " << sp2.get() << std::endl;
		std::cout << std::endl;
	}
	//from C++ Std library Book. whoMadeTea ? 

	std::shared_ptr<std::string> pJetha = std::make_shared<std::string>("Jethalal");
	std::shared_ptr<std::string> pDaya(new std::string("Daya"), [](std::string* p) {
		std::cout << "Custom Deleter " <<*p << std::endl;
		delete p;
		});																						//custom deleter for Daya-bhen using lambda function


	std::cout << "pJetha.use_count() = " << pJetha.use_count() << std::endl;
	std::cout << "pDaya.use_count() = " << pDaya.use_count() << std::endl;
	std::cout << std::endl;

	std::vector<std::shared_ptr<std::string>> whoMadeTea;
	
	//suppose they drink tea 5 times a day and we want keep track of whoMadeTea over the span of the day. 
	std::cout << "whoMadeTea log start" << std::endl;
	whoMadeTea.push_back(pJetha);	//early morning
	whoMadeTea.push_back(pDaya);	//breakfast time
	whoMadeTea.push_back(pDaya);	//noon
	whoMadeTea.push_back(pJetha);	//snacks time
	whoMadeTea.push_back(pDaya);	//late evening
	std::cout << "whoMadeTea logged" << std::endl;
	std::cout << std::endl;

	std::cout << "pJetha.use_count() = " << pJetha.use_count() << std::endl;
	std::cout << "pDaya.use_count() = " << pDaya.use_count() << std::endl;
	std::cout << std::endl;


	std::cout << "whoMadeTea ?" << std::endl;
	for (auto &ptr : whoMadeTea)
	{
		std::cout << *ptr << std::endl;
	}
	std::cout << std::endl;

	//edit Object 
	*pDaya = std::string("Daya-ben");

	std::cout << "Name updated . Now whoMadeTea ?" << std::endl;
	for (auto& ptr : whoMadeTea)
	{
		std::cout << *ptr << std::endl;
	}
	std::cout << std::endl;

	//resize the vector
	whoMadeTea.resize(4);

	std::cout << "Next day only 4 times . So whoMadeTea ?" << std::endl;
	for (auto& ptr : whoMadeTea)
	{
		std::cout << *ptr << std::endl;
	}
	std::cout << std::endl;

	std::cout << "pJetha.use_count() = " << pJetha.use_count() << std::endl;
	std::cout << "pDaya.use_count() = " << pDaya.use_count() << std::endl;
	std::cout << std::endl;

	//resize the vector
	whoMadeTea.resize(1);
	pDaya = nullptr;

	std::cout << "Only one time tea. Daya-ben rest . So whoMadeTea ?" << std::endl;
	for (auto& ptr : whoMadeTea)
	{
		std::cout << *ptr << std::endl;
	}
	std::cout << std::endl;

	std::cout << "pJetha.use_count() = " << pJetha.use_count() << std::endl;
	std::cout << "pDaya.use_count() = " << pDaya.use_count() << std::endl;
	std::cout << std::endl;


	return 0;

}

