function containsDuplicate(nums: number[]): boolean {
    // new is not mean allowing memory like in CPP but set is technically a class so you need the new keyword to create an instance
    const seen = new Set<number>(); 

    for (const n of nums) {
        if (seen.has(n))
            return (true);
        seen.add(n);
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