// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������������ڳ����Ħ����֮�أ��������Ǻ�����ͽ��Ϊ���������ʤ�أ�
��������ڴ�����������֮ʱ�������㣬�������������ţ�Ϊ��������֮��������
�ִ��Ũ�����ɷ����������Ŀ��������ɴ�������ɽ�����������¡�
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"talin",
  "southdown" : __DIR__"lianhua",
]));
	set("coor/x",65);
	set("coor/y",23);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
