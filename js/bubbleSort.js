const sort = arr => {
    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < arr.length - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                let temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
};

let arr = [1, 6, 4, 9, 7, 3, 9, 6, 4, 5, 6, 7, 3, 8];
let arr1 = [1];
let arr2 = [];

sort(arr);
sort(arr1);
sort(arr2);
console.log(arr);
