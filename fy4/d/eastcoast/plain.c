// searoad.c
inherit ROOM;
void create()
{
        set("short", "ƽԭ·");
        set("long", @LONG
��������򶫣����ƽ�ƽ��·������Сʯ�ӣ��������ȥ��������Ϊ�ѽš���
���Ե���ľԽ��Խ�٣������ƻ����������Ҹ��ط���Ϣһ�¡�
LONG
        );
        set("exits", ([ 
  		"east" : __DIR__"searoad",
  		"west" : __DIR__"troad4",
	]));
        set("outdoors", "tieflag");
	set("coor/x",980);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

