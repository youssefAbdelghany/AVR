
#ifndef UTILS_H_
#define UTILS_H_

#define GET_BIT(reg,bit_num) (((reg>>bit_num)&1))
#define SET_BIT(reg,bit_num) (reg=((1<<bit_num)|reg))
#define CLR_BIT(reg,bit_num) (reg=((~(1<<bit_num))&reg))
#define ASSIGN_BIT(REG,BIT_NUM,VALUE)		do\
											{\
												REG &= ~(1<<(BIT_NUM));\
												REG |= ((VALUE & 0x01U)<<(BIT_NUM));\
											}while(0)
#define GET_HIGHNIBBLE(reg) ((reg>>4)&15)
#define SET_HIGHNIBBLE(reg) (reg=((~15)|reg))
#define CLR_HIGHNIBBLE(reg) (reg=((15)&reg))
#define ASSIGN_HIGHNIBBLE(REG,VALUE)		do\
											{\
												REG &= ~(0xF0U);\
												REG |= ((VALUE<<4) & 0xF0U);\
											}while(0)

#define GET_LOWNIBBLE(reg) (reg&15)
#define SET_LOWNIBBLE(reg) (reg=(15|reg))
#define CLR_LOWNIBBLE(reg) (reg=((~15)&reg))
#define ASSIGN_LOWNIBBLE(REG,VALUE)			do\
											{\
												REG &= ~(0x0FU);\
												REG |= (VALUE & 0x0FU);\
											}while(0)


#define ROTATELEFT(REG,VALUE)			(REG = (REG << VALUE) | (REG >> ((sizeof(REG)*8)-VALUE)))
#define ROTATERIGHT(REG,VALUE)			(REG = (REG >> VALUE) | (REG << ((sizeof(REG)*8)-VALUE)))
#define COMPLEMENT_BIT(reg,bit_num)        (reg=((1<<bit_num)^reg))
#define COMPLEMENT(reg)                     (reg=reg^0xffff)

#endif // UTILS_H_

