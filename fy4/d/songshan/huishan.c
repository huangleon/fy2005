// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������������ɽ���ҿ������룬���ɴ�أ�����������Ȫ���ƣ���ɫ���ģ�
���Ϊ��ɮ�ξ���ʦ�ľ��ᡣ����������������Ϊ���������ļ�ɮһ�г��ҵĵط���
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"shita", 
  "southwest" : __DIR__"talin",
]));
        set("objects", ([
                __DIR__"obj/status" : 1,
		__DIR__"npc/xiangke" : 1,
       ]) );
	set("coor/x",70);
	set("coor/y",30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
