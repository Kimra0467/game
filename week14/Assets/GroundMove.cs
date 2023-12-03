using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class GroundMove : MonoBehaviour
{
// Start is called before the first frame update
void Start()
{
}
// Update is called once per frame
void Update()
{
//Debug.Log(Input.GetAxis("Horizontal"));
//Debug.Log(Input.GetAxis("Vertical"));
float zRotation = transform.localEulerAngles.z;
zRotation = zRotation - Input.GetAxis("Horizontal") * 0.1f;
transform.localEulerAngles = new Vector3(10, 0, zRotation);
if (Input.touchCount > 0 || Input.GetMouseButton(0))
{
Debug.Log("Mouse Down" + Input.mousePosition);
if (Input.mousePosition.x < Screen.width / 2)
{
transform.localEulerAngles = new Vector3(10
, 0
, transform.localEulerAngles.z + 0.05f);
}
else
{
transform.localEulerAngles = new Vector3(10
, 0
, transform.localEulerAngles.z - 0.05f);
}
}
}
}