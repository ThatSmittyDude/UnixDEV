PROGRAM FORCE
	IMPLICIT NONE
	DOUBLE PRECISION :: F, M, A
	INTEGER :: CHOICE

	PRINT *, "FORCE"
	PRINT *, "==== ==== ==== ===="
	PRINT *, " "
	PRINT *, "SOLVE FOR:"
	PRINT *, " "
	PRINT *, "1. FORCE"
	PRINT *, "-- -- -- --"
	PRINT *, "2. MASS"
	PRINT *, "-- -- -- --"
	PRINT *, "3. ACCELERATION"
	PRINT *, " " 
	PRINT *, "CHOOSE (1-3):"

	READ *, CHOICE
	
	SELECT CASE (CHOICE)

	CASE (1)
		PRINT *, "MASS: "
		READ *, M
		PRINT *, "ACCELERATION: "
		READ *, A
		F = M * A
		PRINT *, "FORCE: "
		PRINT *, F

	CASE (2)
		PRINT *, "FORCE: "
		READ *, F
		PRINT *, "ACCELERATION: "
		READ *, A
		M = F / A
		PRINT *, "MASS: "
		PRINT *, M
	
	CASE (3)
		PRINT *, "FORCE: "
		READ *, F
		PRINT *, "MASS "
		READ *, M
		A = F / M
		PRINT *, "ACCELERATION: "
		PRINT *, A

	CASE DEFAULT 
		PRINT *, "INVALID OPERATION"
	END SELECT
END PROGRAM FORCE
