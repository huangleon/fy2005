// Room: nilu4.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "����ɽ·");

	set("long", @LONG
������ͨ�������µ�����·���ƺ����¹��꣬ɽ·Ҳ������Ţ���У����һ��
��һ����ǰŬ�����ţ���һ������������������б��ˡ�ǰ�治Զ����"������"�ˣ�
����ǰ�ߣ�ɽ����������󣬵����������޷��������ǰ�Ķ����ˡ�
LONG);
/*	set("long_night", @LONG
����һ��յأ��������Ͼ͸���Ҫָ������ʲô��
LONG);
*/
	//{{ --- by MapMaker
	set("outdoors","shanliu");
	set("exits",([
	"south":__DIR__"qigeban",
	"northwest":__DIR__"nilu5",
	]) );
	//}}
	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}
