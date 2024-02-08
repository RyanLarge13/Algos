// const useState = initialValue => {
//     if (initialValue === undefined) {
//         console.log("You must provide an initial value to your state");
//         return;
//     }
//     let newValue = initialValue;
//     const setNewValue = newVal => {
//         newValue = newVal;
//     };
//     const getState = () => newValue;
//     return [getState(), setNewValue];
// };
//
// const [myState, setMyState] = useState(0);
//
// setMyState(2);
//
// console.log(myState);
//

const useState = initialValue => {
    if (initialValue === undefined) {
        console.log("You must provide an initial value to your state");
        return;
    }

    let newValue = initialValue;
    let subscribers = [];

    const setNewValue = newVal => {
        newValue = newVal;
        // Notify subscribers of the state change
        subscribers.forEach(callback => callback(newValue));
    };

    const getState = () => newValue;

    const subscribe = callback => {
        // Add the callback to the subscribers list
        subscribers.push(callback);
        // Return a function to unsubscribe
        return () => {
            subscribers = subscribers.filter(
                subscriber => subscriber !== callback
            );
        };
    };

    // Return both state and setter
    return [getState(), setNewValue, subscribe];
};

// Example usage:
const [myState, setMyState, subscribeToMyState] = useState(0);

// Subscribe to state changes
const unsubscribe = subscribeToMyState(newState => {
    console.log("State changed:", newState);
});

setMyState(2); // This will trigger the subscriber's callback

console.log(myState); // Output: 2

setMyState(5);

console.log(myState)

// Unsubscribe if no longer needed
unsubscribe();
