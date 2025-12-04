function search(nums: number[], target: number): number {
    
    function binarySearch(start: number, end: number) : number {
        if (start > end)
            return (-1);

        let mid = Math.floor((start + end) / 2);
        if (nums[mid] === target)
            return (mid)
        else if (nums[mid] < target)
            return (binarySearch(mid + 1, end));
        else 
            return(binarySearch(start, mid - 1));
    }

    return (binarySearch(0, nums.length - 1));
}

// function main() {
//     let nums: number[] = [0, 2, 6, 8, 9, 13, 33, 46];
//     console.log(search(nums, 13)); 
// }

// main();