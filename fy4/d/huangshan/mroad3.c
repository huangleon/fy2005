// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ɽ·һת�䣬������һ��Сɽ�꣬�˴����滷ɽ�����۾��ǻ�����£�ĹŰأ�
�������춼����Ȼ������һ�����Ƶ�Сʯ��·�������д�����˳ɽ������û������
֮�У�ɽ�İ�������һ��С����
LONG
        );
	set("exits", ([ 
  		"northup" : __DIR__"banshan",
  		"westup" : __DIR__"guanyin",
  		"south" : __DIR__"mroad2",
	]));
    
    set("outdoors", "huangshan");
	set("coor/x",-40);
	set("coor/y",10);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
