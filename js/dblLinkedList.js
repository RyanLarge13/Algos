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
        if (!this.head.next) {
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
    print() {}
}

const myDblLinkedList = new DblLinkedList();
