
inherit ROOM;

void create()
{
	set("short", "�˼��");
	set("long", @LONG
����һ����խ��ɽ�������ű���һ��ɽ����ȥ���˷���һ��������ֱ�̲�񷡣
LONG
	);
	set("exits", ([
		"northup"   : __DIR__"renjiandao3",
            "southdown" : __DIR__"renjiandao1", 
	]));
      set("objects", ([
        __DIR__"npc/wei-shi2": 1,
       ]) );

      set("outdoors", "bat");
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",50);
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