inherit ROOM;

void create()
{
	set("short", "��ʯ��");

	set("long", @LONG
����������ʯ���ɵ�С����������С�ֿ��˲��٣���Ҳ����ƽ����·
�������ľ���޼����������룬ʱ��ʱ���м������ֵ�����·�ɿ�ĳ������ӡ�
LONG);

	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"southeast":__DIR__"shilu3",
		"southwest":__DIR__"shilu1",
	]) );
	set("coor/x",40);
	set("coor/y",90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
