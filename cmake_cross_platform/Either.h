
#include <optional>
#include <functional>

template<typename L>
struct Left {
	L data;
};

template<typename R>
struct Right {
	R data;
};

template <typename L, typename R>
class Either {
public:

	Either(Left<L>& l) : lv(l), which(true) {}
	Either(Right<R>& r) : rv(r), which(false) {}	
	Either(L l) : lv(l), which(true) {}
	Either(R r) : rv(r), which(false) {}

	std::optional<std::reference_wrapper<L>> left() {
		if (which) {
			return { lv };
		} else {
			return std::nullopt;
		}
	}

	std::optional<std::reference_wrapper<R>> right() {
		if (!which) {
			return { rv };
		}
		else {
			return std::nullopt;
		}
	}

	bool is_left() {
		return which;
	}

	bool is_right() {
		return !which;
	}

private:
	union {
		L lv;
		R rv;
	};

	bool which;
};