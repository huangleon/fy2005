
inherit ROOM;

void create()
{
	set("short", "�˼��");
	set("long", @LONG
����һ����խ��ɽ��,���ű���һ��ɽ����ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	"northup"   : __DIR__"renjiandao2",
        "southdown" : __DIR__"kongdi",
	]));
        set("objects", ([
        __DIR__"npc/wei-shi3": 1,
	]) );
      set("outdoors", "bat");
	set("coor/x",-20);
	set("coor/y",-20);
	set("coor/z",40);
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