inherit ROOM;

void create()
{
	set("short", "�����¶԰");

	set("long", @LONG
������Ϊ���˧������������ô�������Ǿʹ���ش��ˣ����˧�ĺ���ѧʶ��
�ߣ��ӽ����¶԰����֪����԰�м�ɽ���͵��֣�����������ʯ�����಻�ϣ���
��Ī�⡣ƾ����������Ŀʯ����ᾣ��Ű��֦���ƣ�԰��ƽ̨�����������Ұ��Զ
��Ⱥ�����ơ�
LONG);

	set("type","grassland");
	set("outdoors", "fugui");
	set("exits",([
		"southeast":__DIR__"jinshi",
		"northeast":__DIR__"jinmen",
	]) );
	set("coor/x",30);
	set("coor/y",50);
	set("coor/z",0);
	set("objects" , ([
		__DIR__"npc/guard1":1,
		__DIR__"npc/guard1a":1,
    __DIR__"obj/jiashan" : 1,
    __DIR__"obj/hole" : 1,
	]));
	setup();
	replace_program(ROOM);
}
