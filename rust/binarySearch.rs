fn binary_search(my_arr: [i32; 10]) {
    println!("First element: {}", my_arr[0]);
}

fn main() {
    let sorted_array: [i32; 10] = [1,2,3,4,5,6,7,8,9,10];
    binary_search(sorted_array)
}