.name "Rectal Invader"
.comment "Comin' to getya"

l2:		sti r1, %:live, %1
		ld %5, r7;load value into r7 to jump the live command forward 
		or %0, r1, r12 ;load ID into r12 to store in front of the live command
		and %0, %0, r10 ;change carry to true
		; fork %2000
store_live_op_in_reg:
		ld %1, r12

get_live_to_reg:
        ldi %:live, %1, r5
		add r7, r10, r10

store_id_on_board:
        sti r12, r10, %257
store_live_on_board:
        sti r5, r10, %250

live:
		live %1
		st r1, 6
		live %1
        and %0, %0, r16
        fork %50
		zjmp %:get_live_to_reg

