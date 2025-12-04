// Definition for singly-linked list.
class ListNode {
    val: number
    next: ListNode | null

    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }

    printList() : void {
        let current: ListNode | null = this;
        let values: number[] = [];
        while (current !== null) {
            values.push(current.val);
            current = current.next;
        }
        console.log(values.join(" -> "));
    }

    add(val: number) : void {
        let current: ListNode = this;
        while (current.next !== null)
            current = current.next;
        current.next = new ListNode(val);
    }
}

function mergeTwoLists(list1: ListNode | null, list2: ListNode | null): ListNode | null {
    const dummy = new ListNode(-1);
    let current = dummy;
    let l1 = list1;
    let l2 = list2;

    while (l1 !== null && l2 != null) {
        if (l1.val < l2.val) {
            current.next = l1;
            l1 = l1.next;
        }
        else {
            current.next = l2;
            l2 = l2?.next;
        }
        current = current.next;
    }

    if (l1 !== null)
        current.next = l1;
    else if (l2 !== null)
        current.next = l2;

    return (dummy.next);
};

// function main() {
//     const list1 = new ListNode(4);
//     list1.add(5);
//     list1.add(23);
//     list1.add(70);
//     console.log("List 1:");
//     list1.printList();

//     const list2 = new ListNode(7);
//     list2.add(8);
//     list2.add(9);
//     list2.add(25);
//     console.log("List 2:");
//     list2.printList();

//     let result = mergeTwoLists(list1, list2);
//     if (result == null)
//         console.log("Result is empty\n");
//     else
//     {
//         console.log("Result:");
//         result.printList();
//     }
// }

// main();