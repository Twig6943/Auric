// Copyright BattleDash. All Rights Reserved.

#pragma once

#include <Core/Server.h>
#include <SDK/TypeInfo.h>
#include <API/APIService.h>
#include <Hook/Func.h>

#include <Windows.h>

#define OFFSET_GLOBAL_CLIENT 0x1446CD4B0
#define OFFSET_GLOBAL_SETTINGS_MANAGER 0x1446B4130
//#define OFFSET_GET_CLIENT_INSTANCE 0x14659DE50


namespace Kyber
{
__int64 ClientStateChangeHk(__int64 a1, ClientState currentClientState, ClientState lastClientState);

TL_DECLARE_FUNC(0x1403EE890, __int64, Settings_GetObject, __int64 settingsManager, __int64* a2, const char** identifier);

class Program
{
public:
    Program(HMODULE module);
    ~Program();

    DWORD WINAPI InitializationThread();
    void InitializeGameHooks();


    template<typename T>
    T* GetSettingsObject(const char* identifier)
    {
        __int64 result[2]; 
        __int64 settingsManagerPtr = *reinterpret_cast<__int64*>(OFFSET_GLOBAL_SETTINGS_MANAGER);

        Settings_GetObject(settingsManagerPtr + 0x90, result, &identifier);

        return reinterpret_cast<T*>(*reinterpret_cast<__int64*>(result[0] + 0x8));
    }

    __int64 ChangeClientState(ClientState currentClientState)
    {
        return ClientStateChangeHk(
            *reinterpret_cast<__int64*>(*reinterpret_cast<__int64*>(OFFSET_GLOBAL_CLIENT) + 0x70),
            currentClientState, m_clientState);
    }

    HMODULE m_module;
    APIService* m_api;
    Server* m_server;
    ClientState m_clientState;
    bool m_joining;
};

template<class T>
class Settings
{
public:
    Settings(const char* identifier)
    {
        m_settings = g_program->GetSettingsObject<T>(identifier);
    }

    inline T* operator->()
    {
        return m_settings;
    }

    inline const T* operator->() const
    {
        return m_settings;
    }

    inline operator T*()
    {
        return m_settings;
    }

    inline operator const T*() const
    {
        return m_settings;
    }

private:
    T* m_settings;
};

} // namespace Kyber

extern Kyber::Program* g_program;