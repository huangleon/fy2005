// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "һ����");
        set("long", @LONG
����ʮ���������ߴ���ʮ���׵�ʯ�ڽ������ţ�һ��ʯ�״����̻����ϣ�����
���������ף�խ��ֻ�а��ף��������գ�����һ�ߡ���Ȼ�ټ����⣬ʯ����ȴ��
����ˬ��������̦��
LONG
        );
        set("exits", ([ 
  "south"  : __DIR__"wenzhu",
  "eastup" : __DIR__"tiandu",
]));
        set("outdoors", "huangshan");
	set("coor/x",-70);
	set("coor/y",40);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
