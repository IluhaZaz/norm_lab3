#pragma once
#include <iostream>
#include <memory>
#include <vector>
namespace sequence {
    class Sequence;
    using SequencePtr = std::shared_ptr<Sequence>;
    class Sequence {

    public:
        virtual int get_num() const = 0;

        virtual double get_n_elem(int n) = 0;

        virtual double get_sum(int n) = 0;

        virtual double get_a() const = 0;

        virtual double get_first_mem() const = 0;

        virtual bool equals(SequencePtr other) const = 0;

        virtual SequencePtr clone() const = 0;

        virtual ~Sequence() = default;

    protected:
    
        double _first_member;

        double _a;

        int _num;

        Sequence() = default;

        Sequence(const Sequence&) = default;

        Sequence& operator=(const Sequence&) = default;
    };

    class ArifProgression : public Sequence {

    public:
        int get_num() const override;

        ArifProgression(double a, double first_mem, int num);

        double get_n_elem(int n) override;

        double get_sum(int n) override;

        double get_a() const override;

        double get_first_mem() const override;

        bool equals(SequencePtr other) const override;

        SequencePtr clone() const override;
    };

    class GeomProgression : public Sequence {
    public:
        int get_num() const override;

        GeomProgression(double a, double first_mem, int num);

        double get_n_elem(int n) override;

        double get_sum(int n) override;

        double get_a() const  override;

        double get_first_mem() const override;

        bool equals(SequencePtr other) const override;

        SequencePtr clone() const override;
    };



	class SequenceList {
    private:
        std::vector<SequencePtr> _progs;
	public:
        SequenceList() = default;

        int get_index();

        double get_n_elem(int n);

        double get_sum(int n);

        SequencePtr get_prog_with_max_sum(int n);

        void add_progression(SequencePtr pr);

        SequencePtr operator[](int index) const;

        void remove(int index);

        void insert(int index, SequencePtr sec);

        void overwrite(int index, SequencePtr prog);

        void swap(SequenceList& other);

        SequenceList& operator=(SequenceList rhs);

        SequenceList(const SequenceList& other);
	};

    bool operator==(SequenceList lhs, SequenceList rhs);

    bool operator!=(SequenceList lhs, SequenceList rhs);

    std::ostream& operator<< (std::ostream& out, SequenceList& s);

    std::ostream& operator<< (std::ostream& out, SequencePtr s);
}
