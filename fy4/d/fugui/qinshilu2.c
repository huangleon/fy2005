inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
��������������ʯ��������Ծ���Щ��֪������ľ����;���ͻ��ƣ�ˮ������
������䣬��Ȼ�������Ͼ�ɫ�����ܲ�ľ������Σ������ƽ�����ĿԶ����Զ����
��������ֻ��ǰ�淿���۴��αȣ�ȴ�Ǹ����� 
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"east":__DIR__"qinshilu3",
		"south":__DIR__"qinshilu4",
	]) );
	set("coor/x",10);
	set("coor/y",60);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
