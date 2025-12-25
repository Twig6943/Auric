.
> [!WARNING]
> This Injects now! though starting a server will kill it, reason being that some offsets are wrong.
> The base of this is NOT MY CODE, it is a fork of Kyber modified to run on GW1
------
This is simply adding GW1 (potentially GW2) dedicated server support.

* Offsets changed to GW1's (some of them are rough)
* Server joining menu
* Kyber Proxy removed due to issues.
* NAT Punch-Through system
* In-Game server browser (when this works lol)
* Per-player team swapping
* Player kicking/moderation (maybe not possible, can't find the offsets)

What isn't done:
* Lmao like, everything else

Due to security reasons, i'd reccomend keeping multiplayer servers on LAN over things like RadminVPN if things work.

## Credits

Kyber utilizes the following open-source projects:

- [MinHook](https://github.com/TsudaKageyu/minhook)
- [ImGUI](https://github.com/ocornut/imgui)
- [GLFW](https://glfw.org)
- [cpp-httplib](https://github.com/yhirose/cpp-httplib)
- [openssl](https://openssl.org)
- [executors](https://github.com/chriskohlhoff/executors)
- [nlohmann-json](https://github.com/nlohmann/json)
- [Kyber](github.com/ArmchairDevelopers/Kyber)
