// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����������ǰ����������ʯ�����ߴ���ΰ���ƺ����������������Ĺ�ȥ������
��һ��ʯ�ţ�ǰ������ɽ�ŵ�ĵ�ǣ�̧ͷ�Ѿ����Կ�������������������������
ԾȻ���ԡ�
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"shandan",
  "northeast" : __DIR__"dongshi",
  "northwest" : __DIR__"xishi",
  "southdown" : __DIR__"ent2",
]));
/*        set("objects", ([
                __DIR__"npc/monk3" : 1,
       ]) );*/
        set("outdoors", "shaolin");
	set("coor/x",0);
	set("coor/y",-110);
	set("coor/z",-30);
	setup();
        replace_program(ROOM);
}
