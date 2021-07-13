/*Shared_ptr issue with cyclic references explainer */

#include <iostream>
#include <memory>
#include <string>

class Family {
private : 
	std::string name_;
public:
	std::shared_ptr<Family> partner; 

	Family(std::string name) : name_(name) {
		std::cout << "Hello from " << name_ << std::endl;
	}
	~Family() {
		std::cout << "Goodbye from " << name_ << std::endl;
	}
};



int main()
{
	
	std::shared_ptr<Family> pJetha = std::make_shared<Family>("Jethalal");
	std::shared_ptr<Family> pDaya = std::make_shared<Family>("Daya-ben");
	std::cout << "pJetha.use_count() = " << pJetha.use_count() << std::endl;
	std::cout << "pDaya.use_count() = " << pDaya.use_count() << std::endl;
	std::cout << "pJetha.get() = " << pJetha.get() << std::endl;
	std::cout << "pDaya.get() = " << pDaya.get() << std::endl;
	std::cout << std::endl;

	pJetha->partner = pDaya;
	pDaya->partner = pJetha;
	std::cout << "pJetha.use_count() = " << pJetha.use_count() << std::endl;
	std::cout << "pDaya.use_count() = " << pDaya.use_count() << std::endl;
	std::cout << std::endl;

	return 0;

}

