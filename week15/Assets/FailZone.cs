using UnityEngine;
using UnityEngine.SceneManagement;
public class FailZone : MonoBehaviour
{
void OnTriggerEnter(Collider collider)
{
//Debug.Log(collider.gameObject.name);
if (collider.gameObject.name == "Player")
{
SceneManager.LoadScene(0);
}
}
// Start is called before the first frame update
void Start()
{
}
// Update is called once per frame
void Update()
{
}
}