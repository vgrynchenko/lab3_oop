#pragma once
#pragma once
template<typename T>
class JavaIteratorInterface {
public:

	virtual T Next() = 0;
	virtual bool hasNext() const = 0;
	virtual ~JavaIteratorInterface() {}

};
