/*unique_ptr explainer with examples*/

#include <iostream>
#include <memory>

struct MyInt {
	MyInt(int i) : i_(i) {
		std::cout << "Hello from " << i_ << std::endl;
	}
	~MyInt() {
		std::cout << "Goodbye from " << i_ << std::endl;
	}
	int i_;
};

int main()
{
	//Init
	std::unique_ptr<MyInt> up0(new MyInt(1993));
	std::unique_ptr<MyInt> up1(new MyInt(1998));				
	std::unique_ptr<MyInt> up2 = std::make_unique<MyInt>(2011);	//preffered way
	std::unique_ptr<MyInt> up3 = std::make_unique<MyInt>(2014);

	//Observers : 

	// unique_ptr.get()
	std::cout << "up0.get() = " << up0.get() << std::endl;
	std::cout << "up1.get() = " << up1.get() << std::endl;
	std::cout << "up2.get() = " << up2.get() << std::endl;
	std::cout << std::endl;

	// Cant copy unique pointer .Can only be transferred - moved i.e Transfer Ownership 
	std::cout <<"Transfer Ownership up1 to up3"<<std::endl;
	up3 = std::move(up1);										//because up3 already manages object , that obj is first deleted and then transfer up1 to up3 , delete up1
																//in case up3 was empty- nullptr, then we could see only transfer of ownership
	std::cout << "up3.get() = " << up3.get() << std::endl;	
	std::cout << std::endl;

	//unique_ptr.reset()
	std::cout << "reset()" << std::endl;
	up3.reset();
	std::cout << "up3.get() after up3.reset() = " << up3.get() << std::endl;
	std::cout << std::endl;

	//Dont try this at home. 
	MyInt* myint1 = new MyInt(2020);
	std::unique_ptr<MyInt> up4(myint1);
	//Dont try this at home or outside
	//std::unique_ptr<MyInt> up5(myint1);		//Two unique pointers having ownership of same object . recipie for disaster
	std::cout << std::endl;
	
	// get() and release() example
	{	
		std::cout << "get() and release() e.g." << std::endl;
		MyInt * rawPtr = up2.get();									//Not good. Can lead to some mess. Forgetting delete will cause mem leak. Without release , if you delete , then undefined behavior when up2 destructor called. 
																	//Best is to avoid this 
		std::cout << "Before release() --> "  << std::endl;
		std::cout << "rawPtr adddress = " << rawPtr << std::endl;
		std::cout << "rawPtr value = " << rawPtr->i_ << std::endl;	//Note MyInt is struct so we're able to access member
		//MyInt* rawPtr = up2.release();	
		up2.release();												//releases ownership of managed obj of up2. Caller responsible for deleting obj 
		std::cout << "After release() -->" <<  std::endl;
		std::cout << "rawPtr adddress = " << rawPtr << std::endl;
		std::cout << "rawPtr value = " << rawPtr->i_ << std::endl;	//Note MyInt is struct so we're able to access member
		std::cout << "up2.get() = " << up2.get() << std::endl;		//nullptr as up2 
		delete rawPtr;												 
		std::cout << std::endl;
	}

	return 0;

}

