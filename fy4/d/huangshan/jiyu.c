// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "���㱳");
        set("long", @LONG
����һ�γ�Լʮ���ɣ�������ɣ�������գ�������Ԩ��ʯ���м�������״��
�����㱳��ÿ��ɽ��ǿ����վ���������㶼�лᱻ����ߵĸо���ǰ����ν���춼
����·��ͨ��ָ�ľ�����һ�Ρ�
LONG
        );
        set("exits", ([ 
  "northup"  : __DIR__"tiandu",
  "southwest" : __DIR__"tanhai",
  "west" : __DIR__"erxian",

]));
        set("outdoors", "huangshan");
	set("coor/x",-50);
	set("coor/y",30);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
