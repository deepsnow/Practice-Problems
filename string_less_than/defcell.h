#define DEFCELL(EltType, CellType, ListType)	\
typedef struct CellType *ListType;		\
struct CellType {				\
	EltType element;			\
	ListType next;				\
};