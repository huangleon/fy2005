// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����ͤ");
        set("long", @LONG
����Сͤ���¶�����ͤ��֮���ǰ��˸ߵ����ˣ�����������Ϣ���ƣ�Ҳ���Է�
ֹ����׹�����¡���ɽ���괦������֮�У�������ȥ�����Ī�⣬ʱ���Ƿ�ƽ�˾�
��һƬ����ʱ�沨����ӿ�������ſա�������������ϴ���ַˣ����㣬�����ƽ�
����ȫ�����ַˡ��� 
LONG
        );
    set("exits", ([ 
		"northeast" : __DIR__"guangming",
	]));
    set("objects", ([
    	__DIR__"npc/monk" : 1,
    ]) );
        set("indoors", "huangshan");
	set("coor/x",-100);
	set("coor/y",-20);
	set("coor/z",30);
	set("no_lu_letter",1);
	setup();
        replace_program(ROOM);
}
