// Room: /d/chuenyu/dustyroad.c

inherit ROOM;

void create()
{
        set("short", "���С·");
        set("long", @LONG
ɽ�ڷ��ƳǵĶ�������ʮ��ش���ɽ������һ��С��һ������С·ͨ�����
�ǣ�������С��Ľ��⣬վ�������ƺ�������������С����������������������
һ����������ɽ��������������֣��Ǿ��Ǻ���ɽ��
LONG
        );
        set("exits", ([ 
  		"southwest" : AREA_EASTCOAST"palace_path1",
  		"north" : __DIR__"dustyroad.c",
]));
        set("objects", ([
                __DIR__"npc/flowerseller" : 1,
        ]) );
        set("outdoors", "chuenyu");

	set("coor/x",-30);
	set("coor/y",-50);
	set("coor/z",-20);
	setup();
}
