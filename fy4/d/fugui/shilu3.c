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
		"south":__DIR__"shilu4",
		"northwest":__DIR__"shilu2",
	]) );
	set("coor/x",50);
	set("coor/y",80);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
