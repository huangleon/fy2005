// road0.c
// QCed and modified by TIE@FY2
inherit ROOM;
void create()
{
        set("short", "ɽ��С·");
        set("long", @LONG
����ɽɫ������������·����������̦޺������������е�����������ɽ��ɣ�
�Ĳ�û����·�߹�ľ������ÿ�Թ�ľ�϶������˳�������ľ�̣�ľ���ϻ����Ÿ�
����ɫ�Ĳ�����
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"road1",
  "westdown" : __DIR__"road",
]));
        set("outdoors", "qianfo");
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",-20);
	setup();
        replace_program(ROOM);
}
