#include <sequences/sequence.h>
#include <cmath>
#include <stdexcept>
#include <cstdio>
#include <memory>
#include <vector>
using namespace std;
using namespace sequence;




GeomProgression::GeomProgression(double a, double first_mem, int num) {
	if (a == 0) {
		throw invalid_argument("[Progression:Progression] Denominator mustn't be zero.");
	}
	if (first_mem == 0) {
		throw invalid_argument("[Progression:Progression] First member mustn't be zero.");
	}
	else {
		_a = a;
		_first_member = first_mem;
		_num = num;
	}
}

ArifProgression::ArifProgression(double a, double first_mem, int num){
	_a = a;
	_first_member = first_mem;
	_num = num;
}


double ArifProgression::get_n_elem(int n) {
	if (n <= 0) {
		throw invalid_argument("[Progression::get_n_elem] Negative number of progression member.");
	}
	return _first_member + _a * (n - 1);
}

double GeomProgression::get_n_elem(int n) {
	if (n <= 0) {
		throw invalid_argument("[Progression::get_n_elem] Negative number of progression member.");
	}
	return _first_member * pow(_a, n - 1);
}


int sequence::ArifProgression::get_num() const
{
	return _num;
}

int sequence::GeomProgression::get_num() const
{
	return _num;
}


bool GeomProgression::equals(SequencePtr other) const {
	const auto downcasted_other = dynamic_pointer_cast<GeomProgression>(other);
	if (downcasted_other == nullptr) {
		return false;
	}
	return (this->get_a() == downcasted_other->get_a()) && (this->get_num() == downcasted_other->get_num()) && (this->get_first_mem() == downcasted_other->get_first_mem());
}

bool ArifProgression::equals(SequencePtr other) const {
	const auto downcasted_other = dynamic_pointer_cast<ArifProgression>(other);
	if (downcasted_other == nullptr) {
		return false;
	}
	return (this->get_a() == downcasted_other->get_a()) && (this->get_num() == downcasted_other->get_num()) && (this->get_first_mem() == downcasted_other->get_first_mem());
}


double ArifProgression::get_sum(int n) {
	if (n <= 0)
		throw invalid_argument("[Progression::get_sum] Negative index.");
	return (2 * _first_member + _a * (n - 1)) / 2 * n;
}

double GeomProgression::get_sum(int n) {
	if (n <= 0)
		throw invalid_argument("[Progression::get_sum] Negative index.");
	if (_a != 1)
		return (_first_member * (1 - pow(_a, n))) / (1 - _a);
	else
		return _first_member * n;
}




double ArifProgression::get_a() const {
	return _a;
}

double GeomProgression::get_a() const {
	return _a;
}

double ArifProgression::get_first_mem() const {
	return _first_member;
}

double GeomProgression::get_first_mem() const {
	return _first_member;
}




std::ostream& sequence:: operator<<(std::ostream& out, SequencePtr s) {
	for (int i = 1; i <= s->get_num(); i++) {
		std::cout << s->get_n_elem(i) << " ";
	}
	return out;
}

void sequence::SequenceList::overwrite(int index, SequencePtr prog)
{
	_progs[index] = prog;
}


SequencePtr sequence::GeomProgression::clone() const
{
	return make_shared<GeomProgression>(_a, _first_member, _num);
}

SequencePtr sequence::ArifProgression::clone() const
{
	return make_shared<ArifProgression>(_a, _first_member, _num);
}

