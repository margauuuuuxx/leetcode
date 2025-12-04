function singleNumber(nums: number[]): number {
    let result = 0;
    
    for (let i = 0; i < nums.length; i++) {
        result = result ^ nums[i]; // XOR operation
    }

    return (result);
};

// function main() {
//     const nums: number[] = [2, 4, 4, 2, 5];

//     console.log(singleNumber(nums));
// }

// main();