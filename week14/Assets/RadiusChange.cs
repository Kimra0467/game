using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RadiusChange : MonoBehaviour
{
SphereCollider myCollider = new SphereCollider();
// Start is called before the first frame update
void Start()
{
Rigidbody myRigidbody = GetComponent<Rigidbody>();
Debug.Log("UseGravity: " + myRigidbody.useGravity);
myCollider = GetComponent<SphereCollider>();
}
// Update is called once per frame
void Update()
{
myCollider.radius = myCollider.radius + 0.01f;
}
}
