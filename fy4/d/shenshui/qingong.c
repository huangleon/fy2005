// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�޹�");
        set("long", @LONG
�����ǰ�ˮ����ľ��������г���ƽƽ��Ω��ǽ�϶��˼����һ���ʫ�ʱ�����
�����±������ƺ����������ֱʡ���������
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"huayuan",
  "southeast" : __DIR__"gong",
]));
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
