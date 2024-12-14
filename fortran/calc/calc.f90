PROGRAM calc
	IMPLICIT NONE
	DOUBLE PRECISION :: num1, num2, result
	INTEGER :: choice

	PRINT *, "CALC"
	PRINT *, "==== ==== ==== ====|"
	PRINT *, "1. Addition"
	PRINT *, "==== ==== ====    =|"
	PRINT *, "2. Subtraction"
	PRINT *, "==== ==== ====   = |"
	PRINT *, "3. Multiplication"
	PRINT *, "==== ==== ====   ==|"
	PRINT *, "4. Division"
	PRINT *, "==== ==== ====  =  |"
	PRINT *, "5. Square"
	PRINT *, "==== ==== ====  = =|"
	PRINT *, "6. Square Root"
	PRINT *, "==== ==== ====  == |"
	PRINT *, "7. Qube"
	PRINT *, "==== ==== ====  ===|"
	PRINT *, "Enter operation (1-7): "
	READ *, choice

	IF(choice == 1 .or. choice == 2 .or. choice == 3 .or. choice == 4)then
		PRINT *, "Enter first number: "
		READ *, num1
		PRINT *, "Enter second number: "
		READ *, num2
	ELSE
		PRINT *, "Enter number: "
		READ *, num1
	END IF

	SELECT CASE (choice)

	CASE (1)
		result = num1 + num2
		PRINT *, result
	CASE (2)
		result = num1 - num2
		PRINT *, result
	CASE (3)
		result = num1 * num2
		PRINT *, result
	CASE (4)
		IF(num2 /= 0)then
			result = num1 / num2
			PRINT *, result
		ELSE
			PRINT *, "Divide by zero error"
		END IF
	CASE (5)
		result = num1 * num1
		PRINT *, result
	CASE (6)
		result = SQRT(num1)
		PRINT *, result
	CASE (7)
		result = num1 * num1 * num1
		PRINT *, result
	CASE DEFAULT
		PRINT *, "Invalid operation"
	END SELECT
END PROGRAM calc
