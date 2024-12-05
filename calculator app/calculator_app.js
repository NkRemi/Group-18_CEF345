let display = document.getElementById('display');
let currentOperation = null;
let previousValue = null;

function appendNumber(number) {
    display.value += number;
}

function setOperation(operation) {
    if (display.value === '') return;
    if (currentOperation !== null) calculate();
    currentOperation = operation;
    previousValue = display.value;
    display.value = '';
}

function clearDisplay() {
    display.value = '';
    currentOperation = null;
    previousValue = null;
}

function calculate() {
    if (currentOperation === null || display.value === '') return;
    let result;
    const currentValue = parseFloat(display.value);
    const previous = parseFloat(previousValue);
    switch (currentOperation) {
        case '+':
            result = previous + currentValue;
            break;
        case '-':
            result = previous - currentValue;
            break;
        case '*':
            result = previous * currentValue;
            break;
        case '/':
            result = previous / currentValue;
            break;
        default:
            return;
    }
    display.value = result;
    currentOperation = null;
    previousValue = null;
}
