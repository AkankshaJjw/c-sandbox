const input = [3,3];
const target= 6;
// output = [0,1];

const twosum = (input, target) => {
    const output = [-1,-1]
    for ( let i = 0; i < input.length; i++) {
        for ( let j = 0; j < input.length; i++) {
            if ((i==j) || (input[i] > target) || (input[j] > target))
                continue;
            if ((input[i] + input[j]) == target)
            {
                output[0] = i;
                output[1] = j;
                return
            }
        }
    }
};

console.log(twoSum(input, target))