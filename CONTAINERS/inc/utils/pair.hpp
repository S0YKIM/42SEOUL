/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokim <sokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:06:25 by sokim             #+#    #+#             */
/*   Updated: 2023/01/26 19:29:44 by sokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {
template <typename T1, typename T2>
struct pair {
  typedef T1 first_type;
  typedef T2 second_type;

  first_type first;
  second_type second;

  pair() : first(), second() {}

  template <typename T, typename U>
  pair(const pair<T, U> &other) : first(other.first), second(other.second) {}

  pair(const first_type &a, const second_type &b) : first(a), second(b) {}

  pair &operator=(const pair &other) {
    if (this != &other) {
      first = other.first;
      second = other.second;
    }
    return *this;
  }

  void swap(pair &other) {
    std::swap(first, other.first);
    std::swap(second, other.second);
  }
};

template <typename T1, typename T2>
bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
  return lhs.first == rhs.first && lhs.second == rhs.second;
}

template <typename T1, typename T2>
bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
  return !(lhs == rhs);
}

template <typename T1, typename T2>
bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
  return lhs.first < rhs.first ||
         (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}

template <typename T1, typename T2>
bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
  return rhs < lhs;
}

template <typename T1, typename T2>
bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
  return !(lhs < rhs);
}

template <class _T1, class _T2>
bool operator<=(const pair<_T1, _T2> &lhs, const pair<_T1, _T2> &rhs) {
  return !(rhs < lhs);
}

}  // namespace ft

#endif
