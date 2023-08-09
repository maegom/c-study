
#include "GameManager.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    Vector2D    v1, v3;
    POINT   v2;

    v1 = v2;
    v1 += v2;

    v3 = v1 + v2;
    //v3 = v1 + "A";

    if (!CGameManager::GetInst()->Init(hInstance))
    {
        CGameManager::DestroyInst();
        return 0;
    }

    int Result = CGameManager::GetInst()->Run();

    CGameManager::DestroyInst();

    return Result;
}
