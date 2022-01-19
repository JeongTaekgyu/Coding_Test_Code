def solution(participant, completion):
    answer = ''

    participant.sort()
    completion.sort()

    for i in range(len(completion)):
        if completion[i] != participant[i]:
            return participant[i]

    answer = participant[len(completion)]
    return answer


participant = ["leo", "mis", "taek", "mis"]
completion = ["mis", "taek", "leo"]

print(solution(participant, completion))