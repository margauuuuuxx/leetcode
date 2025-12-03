function isAnagram(s: string, t: string): boolean {
    if (t.length !== s.length)
        return (false);

    const frequencyMap: Record<string, number> = {};

    for (const char of s) {
        frequencyMap[char] = (frequencyMap[char] || 0) + 1; 
    }

    for (const char of t) {
        if (!frequencyMap[char])
            return (false);
        frequencyMap[char] -= 1;
    }

    return (true);
};