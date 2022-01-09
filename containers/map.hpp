#ifndef MAP_HPP
# define MAP_HPP

# include <stdexcept>

# include "../iterators/map_iterator.hpp"
# include "../iterators/map_rev_iterator.hpp"

namespace ft
{
  template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<pair<const Key, T>>
  class map
  {
    public: 
      /* Member types */
      typedef Key                               key_type;
      typedef T                                 mapped_type;
      typedef ft::pair<key_type, mapped_type>   value_type;
      typedef Compare                           key_compare;
      class value_compare : publid std::binary_function<value_type, value_type, bool>
      {
        protected:
          key_compare     comp;
          value_compare(Compare c) : comp(c) {}
        
        public:
          typedef bool          result_type;
          typedef value_type    first_argument_type;
          typedef value_type    second_argument_type;

          bool operator()(const value_type& x, const value_type& y) const
          {
            return comp(x.first, y.first);
          }
      }
      typedef Alloc                             allocator_type;
      typedef allocator_type::reference         reference;
      typedef allocator_type::const_reference   const_reference;
      typedef allocator_type::const_pointer     const_pointer;
      typedef long int                          difference_type;
      typedef size_t                            size_type;

      /* Member functions */
      // 1. Copilien form
      explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {}

      template <class InputIterator>
      map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {}

      map(const map& x) {}

      ~map() {}
      map&      operator=(const map& x) {}

      // 2. Iterators
      iterator                begin() {}
      const_iterator          begin() const {}
      iterator                end() {}
      const_iterator          end() const {}
      reverse_iterator        rbegin() {}
      const_reverse_iterator  rbegin() const {}
      reverse_iterator        rend() {}
      const_reverse_iterator  rend() const {}

      // 3. Capacity
      bool                    empty() const {}
      size_type               size() const {}
      size_type               max_size() const {}

      // 4. Element access
      mapped_type&    operator[](const key_type& k) {}

      // 5. Modifiers
      pair<iterator,bool>     insert(const value_type& val) {}
      iterator                insert(iterator position, const value_type& val) {}

      template <class InputIterator>
      void                    insert(InputIterator first, InputIterator last) {}

      void                    erase(iterator position) {}
      size_type               erase(const key_type& k) {}
      void                    erase(iterator first, iterator last) {}
      void                    swap(map& x) {}
      void                    clear() {}

      // 6. Observers
      key_compare             key_comp() const {}
      value_compare           value_comp() const {}

      // 7. Operations
      iterator                find(const key_type& k) {}
      const_iterator          find(const key_type& k) const {}
      size_type               count(const key_type& k) const {}
      iterator                lower_bound(const key_type& k) {}
      const_iterator          lower_bound(const key_type& k) const {}
      iterator                upper_bound(const key_type& k) {}
      const_iterator          upper_bound(const key_type& k) const {}
      pair<const_iterator,const_iterator>   equal_range(const key_type& k) const {}
      pair<iterator,iterator>               equal_range(const key_type& k) {}

      // 8. Allocator
      allocator_type          get_allocator() const {}
  };
}

#endif