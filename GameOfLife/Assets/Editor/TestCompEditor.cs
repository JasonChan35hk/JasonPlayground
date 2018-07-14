using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

[CustomEditor(typeof(TestComp))]
[CanEditMultipleObjects]
public class TestCompEditor : Editor {
    public void OnSceneGUI()
    {
        var t = target as TestComp;
        EditorGUI.BeginChangeCheck();
        Vector3 scale = Handles.ScaleHandle(t.transform.localScale, Vector3.zero, Quaternion.identity, 1);
        if (EditorGUI.EndChangeCheck())
        {
            Undo.RecordObject(target, "Scaled ScaleAt Point");
            t.transform.localScale = scale;
        }
    }
}
