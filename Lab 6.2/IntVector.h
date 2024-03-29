#ifndef __INTVECTOR_H__
#define __INTVECTOR_H__

using namespace std;

class IntVector {
	private:
		unsigned sz;
		unsigned cap;
		int *data;
	public:
		IntVector();
		IntVector(unsigned size, int value = 0);
		~IntVector();
		unsigned size() const;
		unsigned capacity() const;
		bool empty() const;
		const int & at(unsigned index) const;
		const int & front() const;
		const int & back() const;
};

#endif