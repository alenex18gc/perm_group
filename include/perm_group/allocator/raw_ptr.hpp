#ifndef PERM_GROUP_ALLOCATOR_RAW_PTR_HPP
#define PERM_GROUP_ALLOCATOR_RAW_PTR_HPP

#include <perm_group/allocator/allocator.hpp>
#include <perm_group/permutation/permutation.hpp>

namespace perm_group {

template<typename Perm>
struct raw_ptr_allocator {
	using perm_type = Perm;
	using pointer = Perm*;
	using const_pointer = const Perm*;

	pointer make(std::size_t n) {
		return new Perm(perm_group::make_perm<Perm>(n));
	}

	pointer make_identity(std::size_t n) {
		return new Perm(perm_group::make_identity_perm<Perm>(n));
	}

	template<typename UPerm>
	pointer copy(std::size_t n, UPerm &&p) {
		return new Perm(perm_group::copy_perm<Perm>(n, std::forward<UPerm>(p)));
	}

	void release(std::size_t n, const_pointer p) {
		delete p;
	}
};

} // namespace perm_group

#endif /* PERM_GROUP_ALLOCATOR_RAW_PTR_HPP */