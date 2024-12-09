const readline = require('readline');

const rl = readline.createInterface({

	input: process.stdin,
	output: process.stdout
});

rl.question('Enter decimal value: ', (decimalNumber) => {
	let binaryNumber = parseInt(decimalNumber).toString(2);
	console.log(binaryNumber);
	rl.close();
});
