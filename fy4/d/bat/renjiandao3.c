
inherit ROOM;

void create()
{
	set("short", "�˼��");
	set("long", @LONG
ɽ��Խ��Խ����,��ӥ����ͷ���ɹ������������ĺ�Х����
LONG
	);
	set("exits", ([
		"northup"   : __DIR__"jueding",
            "southdown" : __DIR__"renjiandao2", 
	]));
      set("objects", ([
      __DIR__"npc/wei-shi1": 1,
      ]) );

      set("outdoors", "bat");
	set("coor/x",-20);
	set("coor/y",0);
	set("coor/z",60);
	setup();
}

/*
int valid_leave(object me, string dir)
{
        object ob;
        if( dir == "northup" && ob=present("wu shi", this_object()))
        {
                return notify_fail("��������·��"+ob->name()+"��ס�� ��\n");
        }
                return 1;
}
*/