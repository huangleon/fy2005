
inherit ROOM;

void create()
{
        set("short", "ʯ·");
        set("long", @LONG
ʯ·�ϲ������٣�ƽ��Ǭ����ʯ�壬�����·����궼�����߶�����һ�㱩¶��
���֮�¡�������һƬ���������֣��������з���¥������Ҳ��һƬ���֣���Լ
����ˮ֮��������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"sriver",
  "east" : __DIR__"huding",
]));
        set("outdoors", "palace");

	set("coor/x",20);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

