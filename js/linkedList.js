class Node {
    constructor(next, value) {
        this.next = next;
        this.value = value;
    }
}

class LinkedList {
    constructor() {
        this.head = new Node(null, 0);
    }
    insert(value) {
        if (!this.head) {
            const newLink = new Node(null, value);
            this.head = new Node(newLink, 0);
            return;
        }
        const newLink = new Node(this.head.next, value);
        this.head.next = newLink;
    }
    find(value) {
        if (!this.head) {
            this.head = new Node(null, 0);
            console.log("Your list is empty");
            return;
        }
        let next = this.head.next;
        let index = 0;
        while (next) {
            if (next.value === value) {
                console.log(`Found ${next.value} at index ${index}`);
                return;
            }
            index++;
            next = next.next;
        }
        console.log(`${value} is does not exist in your list`);
        return;
    }
    remove(value) {
        if (!this.head || !this.head.next) {
            console.log("Your list is empty!");
            return;
        }
        let currentLink = this.head.next;
        let nextLink = currentLink.next;
        let prevLink = this.head;
        while (currentLink) {
            if (currentLink.value === value) {
                if (!nextLink) {
                    prevLink.next = null;
                    return;
                }
                prevLink.next = nextLink;
                return;
            }
            prevLink = currentLink;
            currentLink = nextLink;
            nextLink = currentLink?.next;
        }
        console.log(`No list item carries a value of ${value}`);
        return;
    }
    removeAt(index) {
        if (!this.head || !this.head.next) {
            console.log("Your list is empty, no values exist to remove");
            return;
        }
        if (index === 0) {
            const next = this.head.next;
            this.head.next = next.next;
            return;
        }
        let i = 0;
        let currentLink = this.head.next;
        while (i <= index && currentLink) {
            i++;
            prevLink = currentLink;
            currentLink = currentLink.next;
        }
        if (currentLink) {
            prevLink.next = currentLink.next;
            return;
        }
        console.log("No list item at the specified index to delete");
        return;
    }
    print() {
        if (!this.head || !this.head.next) {
            console.log("Your list is empty");
            return;
        }
        let next = this.head.next;
        while (next) {
            console.log(next.value);
            next = next.next;
        }
        return;
    }
}

const myList = new LinkedList();
myList.insert(10);
myList.insert(12);
myList.insert(15);
myList.print();
myList.find(9);
myList.find(10);
myList.find(15);
myList.remove(12);
myList.remove(100);
myList.removeAt(0);
myList.removeAt(0);
myList.print();
