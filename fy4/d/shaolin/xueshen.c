// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��ĦԺ�˽������У�����֮���ĵط�������Ϊ���ֵ�һ�������ɣ����µ��Ӵ�
���������ɣ����ٰ��࣬�㶼������Ĺ��͡����ֵ��ӳ�ɽ��֮ǰ��������������
��ʦ˵�������ɴ�ľ���
LONG
        );
        set("exits", ([ 
  "southwest" : __DIR__"cj",
  "northwest" : __DIR__"banruo",
]));
        set("objects", ([
                __DIR__"npc/master_18b" : 1,
       ]) );
	set("coor/x",10);
	set("coor/y",110);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
