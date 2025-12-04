function containsDuplicate(nums: number[]): boolean {
    const nbrCount: Record<number, number> = {};
    
    for (const n of nums) {
        nbrCount[n] = (nbrCount[n] || 0) + 1;
        if (nbrCount[n] > 1)
            return (true);
    }

    return (false);

};

function main() {
    const nums: number[] = [1, 2, 3];
    const nums2: number[] = [1, 2, 3, 1];

    console.log(containsDuplicate(nums));
    console.log(containsDuplicate(nums2));
}

main();