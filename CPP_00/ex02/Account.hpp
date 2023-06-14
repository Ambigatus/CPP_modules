// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

# define DEFAULT "\033[0;39m"
# define B_RED "\033[1;31m"
# define B_BLUE "\033[1;94m"
# define B_YELLOW "\033[1;33m"
# define B_GREEN "\033[1;32m"
# define B_PINK "\033[1;35m"
# define B_PURPURE "\033[1;35m"
# define B_TURQUOISE "\033[36;1m"

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );

	Account( int initial_deposit );
	~Account( void );

	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */


/* The line #pragma once is a preprocessor directive in C++ that ensures a header
file is included only once during the compilation process. It serves as a header
guard or include guard to prevent multiple inclusions of the same header file, 
which can lead to compilation errors due to redefinition of symbols.

When a header file is included using #pragma once, the preprocessor checks if it 
has already been included in the current translation unit. If it has, the subsequent
 inclusion is ignored, saving compilation time and avoiding potential issues related
  to redeclarations or multiple definitions.

Using #pragma once is an alternative to the traditional header guards that use
 conditional compilation directives like #ifndef and #define. It offers a simpler
  and more efficient way to ensure single inclusion of a header file.

It's important to note that #pragma once is a non-standard directive but is widely
 supported by modern compilers. While it is generally safe to use, some developers
  and projects still prefer the traditional header guard method for compatibility
   reasons across different compilers and environments. */