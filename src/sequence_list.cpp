
#include <sequences/sequence.h>
#include <stdexcept>
#include <limits.h>
#include <iostream>
using namespace std;
using namespace sequence;



void SequenceList::add_progression(SequencePtr pr) {
    _progs.push_back(pr);
}

sequence::SequencePtr sequence::SequenceList::operator[](int index) const
{
    if (index < 0 || this->_progs.size() <= index) {
        throw out_of_range("[Sequence::operator[]] Index is out of range.");
    }
    return _progs.at(index);
}

void sequence::SequenceList::remove(int index)
{
    _progs.erase(_progs.begin() + index);

}

double SequenceList::get_n_elem(int n) {
	if (n <= 0)
		throw invalid_argument("[Sequence::get_n_elem] Negative number of progression member.");
	if (this->get_index() == 0)
		throw runtime_error("[Sequence::get_n_elem] Empty sequence.");
	for (int i = 0; i < this->get_index(); i++) {
		n -= _progs[i]->get_num();
		if (n <= 0) {
			return _progs[i]->get_n_elem(abs(n) + 1);
		}
	}
	return _progs[this->get_index() - 1]->get_n_elem(n + _progs[this->get_index() - 1]->get_num());
}

double SequenceList::get_sum(int n)
{
	if (n <= 0)
		throw invalid_argument("[Sequence::get_sum] Negative number of progression member.");
	if (this->get_index() == 0)
		throw runtime_error("[Sequence::get_sum] Empty sequence.");
	double sum = 0;
	for (int i = 0; i < this->get_index(); i++) {
		for (int j = 1; j <= _progs[i]->get_num(); j++) {
			sum += _progs[i]->get_n_elem(j);
			n--;
			if (n == 0)
				return sum;
		}
	}
}

sequence::SequencePtr SequenceList::get_prog_with_max_sum(int n) {
	SequencePtr pr = _progs[0];
	if (n <= 0)
		throw invalid_argument("[Sequence::get_max_sum] Negative number.");
	double max = _progs[0]->get_sum(n);
	for (int i = 1; i < this->get_index(); i++) {
		if (_progs[i]->get_sum(n) >= max)
		{
			max = _progs[i]->get_sum(n);
			pr = _progs[i];
		}
	}
	return pr;
}

int SequenceList::get_index()
{
	return _progs.size();
}

bool sequence::operator==(SequenceList lhs, SequenceList rhs)
{
	if (lhs.get_index() != rhs.get_index())
		return false;
	for (int i = 0; i < lhs.get_index(); i++) {
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}

bool sequence::operator!=(SequenceList lhs, SequenceList rhs)
{
	return !(lhs == rhs);
}

std::ostream& sequence::operator<< (std::ostream& out, SequenceList& sec)
{
	bool flag = 1;
	for (int i = 0; i < sec.get_index(); i++)
	{
		for (int j = 1; j <= sec[i]->get_num(); j++) {
			if (flag == 1)
				std::cout << sec[i]->get_n_elem(j);
			else
				std::cout << ", " << sec[i]->get_n_elem(j);
			flag = 0;
		}
		std::cout << "   ";
	}
	return out;
}

void sequence::SequenceList::insert(int index, SequencePtr sec)
{
	_progs.insert(_progs.begin() + index, sec);
}

sequence::SequenceList::SequenceList(const SequenceList& other)
{
	_progs.reserve(other._progs.size());
	for (const auto& ptr: other._progs) {
		_progs.push_back(ptr->clone());
	}
}

void sequence::SequenceList::swap(SequenceList& other)
{
	std::swap(this->_progs, other._progs);
}

SequenceList& sequence::SequenceList::operator=(SequenceList rhs)
{
	rhs.swap(*this);
	return *this;
}