#ifndef _INSUFFICIENT_FUNDS_EXCEP_H_
#define _INSUFFICIENT_FUNDS_EXCEP_H

class InsufficentFundsException : std::exception{
	public:
		InsufficentFundsException() = default;
		~InsufficentFundsException() = default;

		virtual const char* what() const noexcept {
			return "Insufficent funds. Come back with more money";
		}
};

#endif