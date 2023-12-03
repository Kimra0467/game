using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class Stone : MonoBehaviour
{
    Vector3 target;
    // Start is called before the first frame update
    void Start()
    {
        target = GameObject.Find("Ball").transform.position; //위치 지정
    }
    // Update is called once per frame
    void Update()
    {
        transform.position = Vector3.MoveTowards(transform.position, target, 0.01f); //target 방향으로 움직이기
        transform.Rotate(new Vector3(0, 0, 5)); //돌 회전하기
    }
    void OnTriggerEnter(Collider collider)
    {
        Debug.Log(collider.gameObject.name);
        if (collider.gameObject.name == "Ball")
        {
            GameManager gmComponent = GameObject.Find("GameManager").GetComponent<GameManager>();
            gmComponent.RestartGame();
        }
    }
}