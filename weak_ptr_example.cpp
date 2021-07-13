/*Weak_ptr solves cyclic references explainer */

#include <iostream>
#include <memory>
#include <string>

class Family {
private : 
	std::string name_;
public:
	std::weak_ptr<Family> partner; 

	Family(std::string name) : name_(name) {
		std::cout << "Hello from " << name_ << std::endl;
	}
	~Family() {
		std::cout << "Goodbye from " << name_ << std::endl;
	}
};


class Manager{
public:
	std::string name_;
	Manager(std::string name) : name_(name) {
		std::cout << "Hello from " << name_ << std::endl;
	}
	~Manager() {
		std::cout << "Goodbye from " << name_ << std::endl;
	}
};

int main()
{
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
	}

	std::cout << std::endl;
	std::shared_ptr<Manager> pScott = std::make_shared<Manager>("Micheal");
	std::weak_ptr<Manager> pDwight(pScott);
	std::cout << "pScott.use_count() = " << pScott.use_count() << std::endl;
	std::cout << "pDwight.use_count() = " << pDwight.use_count() << std::endl;
	std::cout << "pDwight.expired() = " << pDwight.expired() << std::endl;

	if (std::shared_ptr<Manager> pRyan = pDwight.lock()) {
		std::cout << "pScott: " << pScott->name_ << std::endl;
		std::cout << "pRyan.use_count(): " << pRyan.use_count() << std::endl;
	}
	else {
		std::cout << "Call didnt go through" << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "pScott.use_count(): " << pScott.use_count() << std::endl;
	pScott.reset();
	std::cout << "pScott.reset()" << std::endl;
	std::cout << "pDwight.expired() = " << pDwight.expired() << std::endl;

	if (std::shared_ptr<Manager> pDavid = pDwight.lock()) {
		std::cout << "pScott: " << pScott->name_ << std::endl;
		std::cout << "pDavid.use_count(): " << pDavid.use_count() << std::endl;
	}
	else {
		std::cout << "Call didnt go through" << std::endl;
	}

	return 0;

}

