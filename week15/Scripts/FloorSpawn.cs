using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FloorSpawn : MonoBehaviour
{
    public GameObject path_Floor;

    // Start is called before the first frame update
    private void Start()
    {
        for (int i = 0; i < 15; i++)
        {
            SpawnFloor();
        }
    }

    public void SpawnFloor()
    {
        Vector3 direction;

        // 랜덤한 값을 생성하여 방향을 결정
        int randomDirection = Random.Range(0, 3);

        if (randomDirection == 0)
        {
            direction = Vector3.left;
        }
        else if (randomDirection == 1)
        {
            direction = Vector3.forward;
        }
        else
        {
            direction = Vector3.right;
        }

        path_Floor = Instantiate(path_Floor, path_Floor.transform.position + direction, path_Floor.transform.rotation);
    }

    // Update is called once per frame
    void Update()
    {

    }
}
