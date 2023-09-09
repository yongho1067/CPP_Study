#include <list>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

// 프로젝트 주제 : 스마트 포인터 ( smart pointer )

class Knight
{
public:
	Knight()
	{
		cout << "기사 생성" << endl;
	}	
	
	~Knight()
	{
		cout << "기사 소멸" << endl;
	}

	void Attack()
	{
		if (_target.expired() == false)
			// 장점 -> 생명주기로 부터 자유로워짐
			// 단점 -> 사용하기 위해서는 명시적으로 체크하고 shared_ptr로 변환하여 사용해야함
		{
			shared_ptr<Knight> sptr = _target.lock();
			sptr->_hp -= _damage;
			cout << "HP : " << sptr->_hp << endl;
		}
	}

public:
	int _hp = 100;
	int _damage = 10;
	weak_ptr<Knight> _target;
};

class RefCountBlock
{
public:
	int _refCount = 1;
	int _weakCount = 1;
};

template<typename T>
class SharedPtr
{
public:
	SharedPtr() { }
	SharedPtr(T* ptr) : _ptr(ptr)
	{
		if (_ptr != nullptr)
		{
			_block = new RefCountBlock();
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	SharedPtr(const SharedPtr& sptr1) : _ptr(sptr1._ptr), _block(sptr1._block)
	{
		if (_ptr != nullptr)
		{
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;

		}
	}

	void operator=(const SharedPtr& sptr)
	{
		_ptr = sptr._ptr;
		_block = sptr._block;

		if (_ptr != nullptr)
		{
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;

		}
	}

	~SharedPtr()
	{
		if (_ptr != nullptr)
		{
			_block->_refCount--;
			cout << "RefCount : " << _block->_refCount << endl;

			if (_block->_refCount == 0)
			{
				delete _ptr;
				//delete _block;
				cout << "데이터 삭제" << endl;
			}
		}
	}

public:
	T* _ptr = nullptr; // 원복 객체의 주소값
	RefCountBlock* _block = nullptr;
};

int main()
{
	/*Knight* k1 = new Knight();
	Knight* k2 = new Knight();

	k1->_target = k2;

	k1->Attack();

	delete k2;

	k1->Attack();*/

	// 스마트 포인터 : 포인터를 알맞는 정책에 따라 관리하는 객체 ( 포인터를 래핑해서 사용 )
	// shared_ptr, weak_ptr, unique_ptr

	/*SharedPtr<Knight> k2;
	{
		SharedPtr<Knight> k1(new Knight());
		k2 = k1;
	}*/

	shared_ptr<Knight> k1 = make_shared<Knight>();
	shared_ptr<Knight> k2 = make_shared<Knight>();

	k1->_target = k2;
	k2->_target = k1;
	
	k1->Attack();
	k1->Attack();
	k1->Attack();

	/*unique_ptr<Knight> uptr = make_unique<Knight>();
	unique_ptr<Knight> upt2 = move(uptr);*/

	


	return 0;
}
