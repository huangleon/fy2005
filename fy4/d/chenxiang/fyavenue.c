inherit ROOM;

void create()
{
	set("short", "���Ƶ�");

	set("long", @LONG
��һ��������´ߡ�������ǽ����������ķ��Ƶ�������ɫ�ĵ�·�������￪
ʼ������չ���������̵����֣�����տ���ĺ�ˮ����չ�����С�Զɽ�������ɫ
�п������·������У������������ء�����������򲢲�Զ������һ����ˮ��һ��
���֡�ȴ���ѽ��쳾������ɽ�⡣                                  
LONG);

	set("type","road");
	set("exits",([
		"north":__DIR__"fyhotel",
		"south":__DIR__"cxe2",
		]) );
        set("outdoors", "chenxiang");
	set("coor/x",20);
	set("coor/y",20);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
