/**
 * underscore.cpp header file
 */

namespace underscore {

	/*
	 * Collection functions.
	 */

	template <class List, class Func> 
		Func each(List& list, Func fn) {
			for ( auto itr : list ) {
				fn(itr);
			}
			return fn; 
		}

	template <class TList, class OItr, class TFunc>
		TFunc map(TList& list, OItr oitr, TFunc fn) {
			for ( auto itr : list ) {
				*oitr = fn(itr);
				++oitr;
			}
			return fn;
		}

	template <class TList, class TFunc, class TMemo>
		TMemo reduce(TList& list, TFunc fn, TMemo memo) {
			for ( auto itr : list ) {
				memo = fn(itr, memo);
			}
			return memo;
		}

	template <class TList, class TFunc, class TMemo>
		TMemo reduceRight(TList& list, TFunc fn, TMemo memo) {
			;
		}

	template <class TList, class TVal>
	TVal *find(TList& list, TVal val) {
		auto found = std::find(list.begin(), list.end(), val);
		if ( found == list.end() ) {
			return nullptr; // c++11
		} else {
			return &(*found);
		}
	}

	template <class TList, class TOItr, class TPredicate>
		 TPredicate filter(TList& list, TOItr oitr, TPredicate predicate) {
			 for ( auto itr : list ) {
				 if ( predicate(itr) ) {
					 *oitr = itr;
					 ++oitr;
				 }
			 }
			 return predicate;
		 }

	template <class TList, class TPredicate>
	bool all(TList& list, TPredicate predicate) {
		for ( auto itr : list ) {
			if ( !predicate(itr) ) {
				return true;
			}
		}
		return false;
	}
	

	template <class TList, class TOItr, class TPredicate>
	void reject(TList& list, TOItr oitr, TPredicate predicate) {
		for ( auto itr : list ) {
			if ( !predicate(itr) ) {
				*oitr = itr;
				++oitr;
			}
		}
		// prefer erase ?
	}

	template <class TList, class TPredicate>
	bool any(TList& list, TPredicate predicate) {
		for ( auto itr : list ) {
			if ( predicate(itr) ) {
				return true;
			}
		}
		return false;
	}

	template <class TList, class TVal>
	bool contains(TList& list, TVal val) {
		//return find(list, [&](TList::iterator i){ return *i==val; }) != nullptr;
		return true;
	}

	template <class TList, class TOItr, class TPropertyName>
	TOItr pluck(TList list, TOItr oitr, TPropertyName propertyName) {
		for ( auto itr : list ) {
			*oitr = itr.propertyName; // FIXME do not work
			++oitr;
		}
		return oitr;
	}

	template <class TItr, class TList, class TFunc>
	void sortBy(TList& list, TFunc fn) {
		std::sort(list.begin(), list.end(), 
				[&](TItr i, TItr j) { return fn(i) > fn(j);} );
		// typeof(fn(i)) has operator> ???
	}

	template <class TList, class TMultiMap, class TFunc>
	TMultiMap &groupBy(TList& list, TMultiMap& map, TFunc fn) {
		for ( auto itr : list ) {
			map.insert({fn(itr), itr});
		}
		return map; 
	}


	template <class TList, class TMap, class TKey>
	TMap &indexBy(TList& list, TMap& map, TKey key) {
		for ( auto itr : list ) {
			if ( itr[key] ) {
				map.insert({key, itr});
			}
		}
		return map;
	}

	template <class TList, class TMap, class TFunc>
	TMap &countBy(TList& list, TMap& map, TFunc fn) {
		for ( auto itr : list ) {
			auto key = fn(itr);
			if ( map.end() == map.find(key) ) {
				map[key] = 1;
			} else {
				map[key]++;
			}
		}
		return map;
	}
	
	template <class TList>
	TList& shuffle(TList& list) {
		TList out(list.size());
		return out;
		// TODO impl
	}

	template <class TList>
	TList& sample(TList& list, std::size_t n=1) {
		TList out(0);
		if ( n > list.size() ) {
			return out;
		}
		out.resize(n);
		return out;
		// TODO impl
	}
	
	/*
	 * Array functions
	 */
	template <class TArray, class TRet>
	TRet first(TArray& array) {
		return *(array.begin());
	}

	template <class TOItr, class TVal>
	void initial(TOItr oitr, int size, TVal val = 0) {
		std::fill_n(oitr, size, val);
	}

}; // namespace underscore
