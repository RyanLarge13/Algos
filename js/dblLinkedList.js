class Link {
    constructor(prev, nxt, value) {
        this.prev = prev;
        this.nxt = nxt;
        this.value = value;
    }
}

class DblLinkedList {
    constructor() {
        this.head = new Link(null, null, 0);
    }
    insert(value) {
        if (!this.head) {
            this.head = new Link(null, null, 0);
        }
        if (!this.head.nxt) {
            const newLink = new Link(this.head, this.head, value);
            this.head.prev = newLink;
            this.head.nxt = newLink;
            return;
        }
        const next = this.head.nxt;
        const newLink = new Link(this.head, next, value);
        next.prev = newLink;
        this.head.nxt = newLink;
        return;
    }
    find(value) {
        if (!this.head || !this.head.nxt) {
            console.log("Your list is empty");
        }
        let currentLink = this.head.nxt;
        let index = 0;
        while (currentLink !== this.head) {
            if (currentLink.value === value) {
                console.log(`${value} found at index ${index}`);
                return;
            }
            currentLink = currentLink.nxt;
            index++;
        }
        console.log(`There was no value of ${value} found in your list`);
        return;
    }
    remove(value) {
      if (!this.head || !this.head.nxt) {
        console.log("Your list is empty, nothing to remove");
        return;
      }
    }
    print() {
        if (!this.head || !this.head.nxt) {
            console.log("Your list is empty");
            return;
        }
        let currentLink = this.head.nxt;
        while (currentLink !== this.head) {
            console.log(currentLink.value);
            currentLink = currentLink.nxt;
        }
    }
}

const myDblLinkedList = new DblLinkedList();
myDblLinkedList.insert(0);
myDblLinkedList.insert(10);
myDblLinkedList.insert(20);
myDblLinkedList.insert(0);
myDblLinkedList.find(20);
myDblLinkedList.find(100);
myDblLinkedList.remove(20);
myDblLinkedList.find(20);
myDblLinkedList.print();
