
inherit ROOM;

void create()
{
        set("short", "��Ұ");
        set("long", @LONG
����һ���ޱߵĻ�Ұ�أ�ɽ�Ƶ�������ͻȻ���ĵ����������಻��������
������ȥ��ɳĮ�Ļ���С·������������ԶԶ������������֮һ��[33m��ɽ[32m���ڣ�����
��ɽ��ֱ��������Ρ��׳���������򱱱����ޱ��޼ʵĴ�[33mɳĮ[32m��
LONG
        );
    set("exits", ([ 
        "north" : __DIR__"roadp",
		"southup" : __DIR__"chenxiang3",
        "northwest" : AREA_HUASHAN"road1",
	]));
        set("outdoors", "chenxiang");

	set("coor/x",-10);
	set("coor/y",70);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}

