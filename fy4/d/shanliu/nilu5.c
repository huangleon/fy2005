// Room: nilu5.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "����ɽ·");

	set("long", @LONG
������ͨ�������µ�����·���ƺ����¹��꣬ɽ·Ҳ������Ţ���У����һ��
��һ����ǰŬ�����ţ���һ������������������б��ˡ�ǰ�治Զ����"������"�ˣ�
����ǰ�ߣ�ɽ����������󣬵����������޷��������ǰ�Ķ����ˡ�
LONG);
	//{{ --- by MapMaker
	set("outdoors","shanliu");
	set("exits",([
	"southeast":__DIR__"nilu4",
	"northup":__DIR__"nilu6",
	]) );
	//}}
	set("coor/x",-2);
	set("coor/y",35);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}
