
inherit ROOM;

void create()
{
        set("short", "ǧ�ߴ�");
        set("long", @LONG
��ǰһʯ���Ʊ��������������γ�һ���ѷ죬�������ߣ�ֱ����ʮ�ȣ�����
��϶���س�·����ʯ��370�����׿�����ݰ��㣬̤��ʯ��֮�ϣ�����һ���쿪��
�����������
LONG
        );
    set("exits", ([ 
  		"eastup" : __DIR__"canglong",
  		"northdown" : __DIR__"huixin",
	]));
   
    set("outdoors", "huashan");
    set("objects", ([
		__DIR__"npc/monkey2" : 1,
	]));  

	set("coor/x",-15);
	set("coor/y",-50);
	set("coor/z",20);
	setup();
    replace_program(ROOM);
}

