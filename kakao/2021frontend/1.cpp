function solution(n, record) {
    var answer = [];
    
    // 각 server에 해당하는 캐릭터를 담는 큐를 가진 배열
    //(최대 9이므로 10개를 생성 -> idx 맞춤)
    let serverMap = [];
    for(let i=0; i<10; i++){
        serverMap.push([]);
    }
    
    for(let i=0; i<record.length; i++){
        // server와 해당 캐릭터를 split으로 나눔
        let temp = record[i].split(' ');
        let server = parseInt(temp[0]);
        let cval = temp[1];
        
        // 최대 5명이기에 for문을 돌아도 문제 없음
        //-> 존재하는지 확인하여 존재하면 넘김
        let isExist = false;
        for(let j=0; j<serverMap[server].length; j++){
            if(serverMap[server][j] == cval){
                isExist = true;
                break;
            }
        }
        if(isExist){
            continue;
        }
        
        // 만약 꽉차면 큐에서 front를 꺼냄
        if(serverMap[server].length == 5){
            serverMap[server].shift();
        }
        // 새로운 요소 삽입
        serverMap[server].push(cval);
    }
    
    // 순서대로 돌며 answer에 추가
    for(let i=0; i<10; i++){
        for(let j=0; j<serverMap[i].length; j++){
            answer.push(serverMap[i][j]);
        }
    }
    
    return answer;
}