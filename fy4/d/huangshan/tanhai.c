// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "̽����");
        set("long", @LONG
��ľ��ϡ�裬·�߲�ʱð���Ĺ���ȴ������ɫ���е���׳ͦ�Σ��е���ȶ�
�ˣ����������־�ϲ����Զ��һ�øߴ������б����ɽʯ�ԣ�һï�ܵ�֦��̽��Σ
�£�����������ãã��������һֻ�ޱ�̽��ãã���ƺ���
LONG
        );
        set("exits", ([ 
  "northeast"  : __DIR__"jiyu",
  "southeast" : __DIR__"guanyin",

]));
        set("outdoors", "huangshan");
	set("coor/x",-60);
	set("coor/y",20);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
