// Room: nilu6.c --- by MapMaker

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
	"southdown":__DIR__"nilu5",
	"enter":__DIR__"fanyinshi",
	]) );
	//}}
	set("coor/x",-2);
	set("coor/y",40);
	set("coor/z",60);
	setup();
	replace_program(ROOM);
}
