/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:11:36 by sokim             #+#    #+#             */
/*   Updated: 2022/12/27 12:41:55 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "iterator_base_types.hpp"
# include <vector>

namespace ft {
template <typename Iter> // T*
class vector_iterator {
public:
	typedef typename iterator_traits<Iter>		traits;

	typedef typename traits::iterator_category	iterator_category;
	typedef typename traits::value_type			value_type;
	typedef typename traits::difference_type	difference_type;
	typedef typename traits::pointer			pointer;
	typedef typename traits::reference			reference;

private:
	Iter	current_;

public:
	/* Default constructor */
	vector_iterator() {}

	explicit vector_iterator(const Iter &current) : current_(current) {}

	/* Copy constructor */
	template <typename I1>
	inline vector_iterator(const vector_iterator<I1> &other) : current_(other.base()) {}

	/* Getter function for current */
	const Iter &base() const { return current_; }

	/* Operator overloading */
	// SECTION Forward iterator requirements
	reference operator*() const { return *current_; }
	pointer operator->() const { return current_; }
	vector_iterator &operator++() {
		++current_;
		return *this;
	}

	vector_iterator operator++(int) {
		vector_iterator	tmp(current_);

		++current_;
		return tmp;
	} // !SECTION

	// SECTION Bidirectional iterator requirements
	vector_iterator &operator--() {
		--current_;
		return *this;
	}

	vector_iterator oprator--(int) {
		vector_iterator	tmp(current_);

		--current_;
		return tmp;
	} // !SECTION

	// SECTION Random access iterator requirements
	reference operator[](const difference_type& n) const { return current_[n]; }
	vector_iterator operator+(const difference_type &n) const {
		vector_iterator tmp(current_ + n);

		return tmp;
	}

	vector_iterator &operator+=(const difference_type &n) {
		current_ += n;
		return *this;
	}

	vector_iterator operator-(const difference_type &n) const {
		vector_iterator tmp(current_ - n);

		return tmp;
	}

	vector_iterator &operator-=(const difference_type &n) {
		current_ -= n;
		return *this;
	} // !SECTION
};

/* Relational operators */
// SECTION Forward iterator requirements
template<typename IterTypeL, typename IterTypeR>
inline bool operator==(const vector_iterator<IterTypeL> &lhs, const vector_iterator<IterTypeR> &rhs) {
	return lhs.base() == rhs.base();
}

template<typename IterTypeL, typename IterTypeR>
inline bool operator!=(const vector_iterator<IterTypeL> &lhs, const vector_iterator<IterTypeR> &rhs) {
	return lhs.base() != rhs.base();
}

template<typename IterType>
inline bool operator==(const vector_iterator<IterType> &lhs, const vector_iterator<IterType> &rhs) {
	return lhs.base() == rhs.base();
}

template<typename IterType>
inline bool operator!=(const vector_iterator<IterType> &lhs, const vector_iterator<IterType> &rhs) {
	return lhs.base() != rhs.base();
} // !SECTION

// SECTION Random access iterator requirements
template<typename IterTypeL, typename IterTypeR>
inline bool operator<(const vector_iterator<IterTypeL> &lhs, const vector_iterator<IterTypeR> &rhs) {
	return lhs.base() < rhs.base();
}

template<typename IterTypeL, typename IterTypeR>
inline bool operator<=(const vector_iterator<IterTypeL> &lhs, const vector_iterator<IterTypeR> &rhs) {
	return lhs.base() <= rhs.base();
}

template<typename IterTypeL, typename IterTypeR>
inline bool operator>(const vector_iterator<IterTypeL> &lhs, const vector_iterator<IterTypeR> &rhs) {
	return lhs.base() > rhs.base();
}

template<typename IterTypeL, typename IterTypeR>
inline bool operator>=(const vector_iterator<IterTypeL> &lhs, const vector_iterator<IterTypeR> &rhs) {
	return lhs.base() >= rhs.base();
}

template<typename IterType>
inline bool operator<(const vector_iterator<IterType> &lhs, const vector_iterator<IterType> &rhs) {
	return lhs.base() < rhs.base();
}

template<typename IterType>
inline bool operator<=(const vector_iterator<IterType> &lhs, const vector_iterator<IterType> &rhs) {
	return lhs.base() <= rhs.base();
}

template<typename IterType>
inline bool operator>(const vector_iterator<IterType> &lhs, const vector_iterator<IterType> &rhs) {
	return lhs.base() > rhs.base();
}

template<typename IterType>
inline bool operator>=(const vector_iterator<IterType> &lhs, const vector_iterator<IterType> &rhs) {
	return lhs.base() >= rhs.base();
} // !SECTION

template<typename IterTypeL, typename IterTypeR>
inline typename vector_iterator<IterTypeL>::difference_type operator-(const vector_iterator<IterTypeL> &lhs, const vector_iterator<IterTypeR> &rhs) {
	return lhs.base() - rhs.base();
}

template<typename IterType>
inline vector_iterator<IterType> operator+(const typename vector_iterator<IterType>::difference_type n, const vector_iterator<IterType> &i) {
	vector_iterator	tmp(n + i.base());

	return tmp;
}
}
#endif
