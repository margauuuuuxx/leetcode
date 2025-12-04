class TreeNode {
    val: number
    left: TreeNode | null
    right: TreeNode | null

    constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.left = (left===undefined ? null : left)
        this.right = (right===undefined ? null : right)
    }

    addNode(val: number): void {
        if (val < this.val) {
            if (this.left == null)
                this.left = new TreeNode(val);
            else 
                this.left.addNode(val);
        }
        else {
            if (this.right == null)
                this.right = new TreeNode(val);
            else
                this.right.addNode(val);
        }
    }

    printTree(): void {
        const buildTreeString = (node: TreeNode | null, prefix: string = "", isLeft: boolean = true): string[] => {
            if (!node) return [];

            const valStr = node.val.toString();
            let lines: string[] = [];

            lines.push(prefix + valStr);

            const childPrefix = prefix + (isLeft ? "|  " : "   ");

            if (node.left) {
                const leftLines = buildTreeString(node.left, childPrefix, true);
                lines.push(prefix + "├── " + node.left.val);
                lines = lines.concat(leftLines.slice(1));
            }
            if (node.right) {
                const rightLines = buildTreeString(node.right, childPrefix, false);
                lines.push(prefix + "└── " + node.right.val);
                lines = lines.concat(rightLines.slice(1));
            }
        
            return lines;
        }

        const treeLines = buildTreeString(this);
        console.log(treeLines.join("\n"));
    }
}

function inorderTraversal(root: TreeNode | null): number[] {
    let dummy = root;
    let result: number[] = [];

    function traverse(node: TreeNode | null) {
        if (node == null)
            return;
        traverse(node.left);
        result.push(node.val);
        traverse(node.right);
    }

    traverse(root);
    return (result);
};

// function main() {
//     let tree = new TreeNode(3);
//     tree.addNode(7);
//     tree.addNode(4);
//     tree.addNode(21);
//     tree.addNode(10);
//     tree.printTree();

//     console.log("\n");
//     console.log(inorderTraversal(tree));
// }

// main();