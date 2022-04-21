百度网盘token地址
https://openapi.baidu.com/oauth/2.0/authorize?response_type=token&client_id=AVPyRVuMPRRehbMxROzsFmEXotMEmQ9x&redirect_uri=oob&scope=basic,netdisk&display=popup&state=xxx

返回的token地址
https://openapi.baidu.com/oauth/2.0/login_success#expires_in=2592000&access_token=123.292b21a8e596ae6d754e44814aa77522.YnzAOZwxdEWjQ-jb5tHau4s69mUYb7NRBhFxknD.NeTJ6g&session_secret=&session_key=&scope=basic+netdisk&state=xxx


浏览器获取的token
access_token=123.292b21a8e596ae6d754e44814aa77522.YnzAOZwxdEWjQ-jb5tHau4s69mUYb7NRBhFxknD.NeTJ6g


access_token=123.b9e3c6ed808809b6fbf1f79de16dd266.Y7_EQlxc7sz_ILwAojPcYKSasmdcf_bT-Vp7qg5.2YuBBg



https://pan.baidu.com/rest/2.0/xpan/file?method=precreate&access_token=123.b9e3c6ed808809b6fbf1f79de16dd266.Y7_EQlxc7sz_ILwAojPcYKSasmdcf_bT-Vp7qg5.2YuBBg&path=/apps/test/test.jpg&size=91037&rtype=1&isdir=0&autoinit=1&block_list=[""]

https://pan.baidu.com/rest/2.0/xpan/file?method=precreate&access_token=123.b9e3c6ed808809b6fbf1f79de16dd266.Y7_EQlxc7sz_ILwAojPcYKSasmdcf_bT-Vp7qg5.2YuBBg

"{
    "autoinit": 1,
    "block_list": [
        ""
    ],
    "isdir": 0,
    "path": "/apps/test/test.jpg",
    "rtype": 1,
    "size": 647103
}
"

"{
    "autoinit": 1,
    "block_list": [
        "98d02a0f54781a93e354b1fc85caf488"
    ],
    "isdir": 0,
    "path": "/apps/test/test.jpg",
    "rtype": 1,
    "size": 647103
}
"