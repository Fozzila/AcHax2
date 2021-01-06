#include "Offsets.h"
const float PI = 3.14159265359f;
float Get3DDistance(Vector3 playerPosition, Vector3 enemyPosition)
{
    return sqrt(pow(enemyPosition.x - playerPosition.x, 2.0f) + pow(enemyPosition.y - playerPosition.y, 2.0f) + pow(enemyPosition.z - playerPosition.z, 2.0f));
}
bool WorldToScreen(Vector3 pos, Vector2& screen, float matrix[16], int windowWidth, int windowHeight)
{

    //Matrix-vector Product, multiplying world(eye) coordinates by projection matrix = clipCoords
    Vector4 clipCoords;
    clipCoords.x = pos.x * matrix[0] + pos.y * matrix[4] + pos.z * matrix[8] + matrix[12];
    clipCoords.y = pos.x * matrix[1] + pos.y * matrix[5] + pos.z * matrix[9] + matrix[13];
    clipCoords.z = pos.x * matrix[2] + pos.y * matrix[6] + pos.z * matrix[10] + matrix[14];
    clipCoords.w = pos.x * matrix[3] + pos.y * matrix[7] + pos.z * matrix[11] + matrix[15];

    if (clipCoords.w < 0.1f)
        return false;

    Vector3 NDC;
    NDC.x = clipCoords.x / clipCoords.w;
    NDC.y = clipCoords.y / clipCoords.w;
    NDC.z = clipCoords.z / clipCoords.w;

    //Transform to window coordinates
    screen.x = (windowWidth / 2 * NDC.x) + (NDC.x + windowWidth / 2);
    screen.y = -(windowHeight / 2 * NDC.y) + (NDC.y + windowHeight / 2);
    return true;
}
float Get2DDistance(Vector2 pos1, Vector2 pos2)
{
    int sub1 = pow(pos1.x - pos2.x, 2);
    int sub2 = pow(pos1.y - pos2.y, 2);
    int add1 = sub1 + sub2;
    return sqrt(add1);
}
Vector3 CalcAngle(const Vector3& src, const Vector3& dst)
{
    Vector3 angle;

    angle.x = -atan2f(dst.x - src.x, dst.y - src.y) / PI * 180.0f + 180.0f;
    angle.y = asinf((dst.z - src.z) / Get3DDistance(src, dst)) * 180.0f / PI;
    angle.z = 0.0f;

    return angle;
}