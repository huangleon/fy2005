// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����������ɽ�ִ��������е�һ�飬���ϸ�£�����Ʈ�ݣ��������ڱ�������
��ɽ������������ϸ�������������ҵ��������£��������ڣ����ֺ�Ϊ�磬����Ϊ
[33m����ɽ[32m������Ϊ[33m̫��ɽ[32m���ɴ��������棬�����������µ�������ͥ����ѧ��Դ��
----- �����¡�
LONG
        );
        set("exits", ([ 
  "northwest" : AREA_SHAOLIN"ent",
  "southwest" : __DIR__"qimu",
  "east" : __DIR__"shuyuan", 
]));
        set("objects", ([
                __DIR__"npc/monk" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
