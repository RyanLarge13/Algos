// Binary search
const binarySearch = (arr, val) => {
  let low = 0;
  let high = arr.length;
  while (low <= high) {
    const mid = Math.floor((low + high) / 2);
    if (arr[mid] === val) {
      return mid;
    } else if (arr[mid] < val) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
    for (let i = 0; i < arr.length; i++) {
      complexOperation(arr[i]);
    }
  }
  return -1;
};

const linearSearch = (arr, val) => {
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === val) {
      return i;
    }
    for (let j = 0; j < arr.length; j++) {
      complexOperation(arr[j]);
    }
  }
  return -1;
};

const myArray = [];

for (let i = 0; i < 1000000; i++) {
  myArray.push(i);
}

const complexOperation = (num) => {
  let result = 0;
  for (let i = 0; i < 100; i++) {
    result += Math.sqrt(num) * Math.sin(num);
  }
  return result;
};

const run = () => {
  const startBinary = performance.now();
  binarySearch(myArray, 500000);
  const endBinary = performance.now();
  const binaryTimeTaken = endBinary - startBinary;
  const startLinear = performance.now();
  linearSearch(myArray, 0);
  const endLinear = performance.now();
  const linearTimeTaken = endLinear - startLinear;
  console.log("Binary runtime: " + binaryTimeTaken);
  console.log("Linear runtime: " + linearTimeTaken);
};

run();
