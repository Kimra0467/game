using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Shooter : ObstacleMove
{
    public GameObject stone;
    float delta = 0.01f; // 변수 추가

    void OnCollisionEnter(Collision collision)
    {
        Vector3 direction = transform.position - collision.gameObject.transform.position;
        direction = direction.normalized * 1000;
        collision.gameObject.GetComponent<Rigidbody>().AddForce(direction);
    }

    float timeCount = 0;

    new void Update()
    {
        base.Update();
        timeCount += Time.deltaTime;
        if (timeCount > 3)
        {
            //Debug.Log("돌을 던져라");
            Instantiate(stone, transform.position, Quaternion.identity);

            timeCount = 0;
        }

        float newXPosition = transform.localPosition.x + delta;
        transform.localPosition = new Vector3(newXPosition, transform.localPosition.y,
            transform.localPosition.z);

        if (transform.localPosition.x < -9)
        {
            delta = -0.01f;
        }
        else if (transform.localPosition.x > 9)
        {
            delta = -0.01f;
        }
    }
}