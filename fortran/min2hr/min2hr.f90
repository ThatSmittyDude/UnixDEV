PROGRAM MIN2HR
	IMPLICIT NONE
	REAL*4 :: MIN, HR
	
	PRINT *, " "
	PRINT *, "MIN2HR"
	PRINT *, "---- ---- ---- ----"
	PRINT *, "Minutes: "
	READ *, MIN
	HR = MIN / 60
	PRINT *, "Hours: ", HR
END PROGRAM MIN2HR
