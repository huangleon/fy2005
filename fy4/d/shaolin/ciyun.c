// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����Ϊ�����֣�ΪŮ��������������������Ҳ�ͻķ��ˣ��������ʯ����
����������ˡ����ж�����ġ���������������һ��������������ɮ�ڳ��۱�����
���������о������б��ģ�������ۡ�
LONG
        );
        set("exits", ([ 
  		"west" : __DIR__"bei4",
	]));
        set("objects", ([
                __DIR__"npc/bookmonk" : 1,
       ]) );
	set("coor/x",30);
	set("coor/y",-80);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
