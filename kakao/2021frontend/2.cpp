function solution(m, v) {
    var answer = 0;
    
    // 테트리스 공간
    let blocks = [v[0]];
    
    for(let i=1; i<v.length; i++){
        let temp = v[i];
        
        // 새로운 요소가 담길 idx
        // 공간을 확인
        let idx = blocks.length;
        while(idx > 0 && (m-blocks[idx-1])>=temp){
            idx--;
        }
        
        // 공간이 없다면 새로 삽입 | 있다면 길이 추가
        if(idx == blocks.length){
            blocks.push(temp);
        } else {
            blocks[idx] += temp;
        }
    }
    
    answer = blocks.length;
    
    return answer;
}
