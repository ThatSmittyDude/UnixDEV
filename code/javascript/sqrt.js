const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function calculateSquareRoot(number) {
    if (number < 0) {
        return "Invalid input: square root of negative numbers is not a real number.";
    }
    return Math.sqrt(number);
}

function getInput() {
    rl.question("Enter a number to calculate its square root: ", (input) => {
        const inputNumber = parseFloat(input); // Convert the input to a float

        if (!isNaN(inputNumber)) {
            const result = calculateSquareRoot(inputNumber);
            console.log(`The square root of ${inputNumber} is ${result}`);
        } else {
            console.log("Invalid input: please enter a valid number.");
        }
        
        rl.close(); // Close the readline interface
    });
}

// Call the function to prompt the user
getInput();
