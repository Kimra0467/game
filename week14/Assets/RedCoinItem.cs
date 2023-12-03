using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class RedCoinItem : MonoBehaviour
{
    void OnTriggerEnter(Collider collider)
    {
        if (collider.gameObject.name == "Ball")
        {
            GameObject.Find("GameManager").SendMessage("RedCoinStart");
            Destroy(gameObject);
        }
    }

    // void DestroyObstacles()
    // {
    //     GameObject[] obstacles = GameObject.FindGameObjectsWithTag("Obstacle");
    //     for (int i = 0; i < obstacles.Length; i++)
    //     {
    //         Destroy(obstacles[i]);
    //     }
    // }
    // Start is called before the first frame update
    void Start()
    {
    }
    // Update is called once per frame
    void Update()
    {
    }
}