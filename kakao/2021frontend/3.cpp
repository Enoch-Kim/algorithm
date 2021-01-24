function solution(next_student) {
    if(next_student.length == 1) return 1;
    
    var answer = 0;
    let maxCnt = 0;
    
    // 방문자들 읽은 숫자 카운트하는 Map -> 방문 기록 확인 및 읽은 숫자 확인용
    let visitMap = new Map();
    
    for(let i=0; i<next_student.length; i++){
        
        if(visitMap.has(i+1)){
            continue;
        }        
        
        let readSet = new Set();        // i+1 의 읽은 학생 집합
        let readArr = [i+1];            // i+1 의 읽은 학생 순서를 위한 배열
        let readCnt = 0;
        readSet.add(i+1);
        
        let cycleStu = 0;
        
        let next = next_student[i];
        while(next){
            // 사이클이 있다면 사이클 지점 등록 및 break
            if(readSet.has(next)){
                cycleStu = next;
                break;
            }
            // 이미 기록이 있으면 기록을 사용해서 카운트 증가 및 break;
            if(visitMap.has(next)){
                readCnt = readSet.size + visitMap.get(next);
                break;
            }
            readArr.push(next);
            readSet.add(next);
            next = next_student[next-1];
        }
        
        // 카운트 증가 안됐으면 사이즈로
        if(readCnt == 0){
            readCnt = readSet.size;
        }
        
        
        if(maxCnt <= readCnt){
            answer = i+1;
            maxCnt = readCnt;
        }
        

        for(let i=0; i<readArr.length; i++){
            let temp = readArr[i];
            // 사이클이 있다면 해당 사이클부터는 카운트 같게함
            if(temp == cycleStu){
                for(let j=i; j<readArr.length; j++){
                    visitMap.set(readArr[j], readCnt);
                }
                break;
            } else {
                visitMap.set(temp, readCnt);
                readCnt--;
            }
        }
    }
    
    // 카운트 동일한 가장 나중 번호 뽑음
    for(let i=next_student.length; i>0; i--){
        if(visitMap.get(i) >= maxCnt){
            answer = i;
            break;
        }
    }
    
    
    return answer;
}
