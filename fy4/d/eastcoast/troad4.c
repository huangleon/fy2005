// searoad.c
inherit ROOM;
void create()
{
        set("short", "ɽ��С·");
        set("long", @LONG
������������������������б��·���ԵĹ�ľ����������ľ��Խ�ߵ���Խ������
������ȥ��ȻҪ�ߵ������ȥ�ˡ�
LONG
        );
        set("exits", ([ 
  		"west" : __DIR__"troad2",
  		"east" : __DIR__"plain",
	]));
        set("outdoors", "tieflag");
	set("coor/x",870);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
