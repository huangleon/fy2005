// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��Ų���");
        set("long", @LONG
�Ƿ��س��е�С�꣬��������ۣ���һ�����Ǵ�������ĵط���һ��Ƴ��
������Ʈ���������������к�ɫ�Ĵ��֣�
	�� �� �� �̣���ר���������ԭ��
LONG
        );
        set("exits", ([ 
  	"northwest" : __DIR__"dengfeng",
	]));
        set("objects", ([
                __DIR__"npc/bu_waiter" : 1,
       ]) );
	set("coor/x",-590);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
