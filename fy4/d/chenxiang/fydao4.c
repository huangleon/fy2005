inherit ROOM;

void create()
{
	set("short", "���Ƶ�");

	set("long", @LONG
��һ��������´ߡ������������[33m������[32m��[33m�Ϻ�[32m�ķ��Ƶ�������ɫ�ĵ�·����
���￪ʼ������չ���������̵����֣�����տ���ĺ�ˮ��һͷ��չ�����У�һͷ��
���������ɭ��ͨ��Զ����Զɽ�������ɫ�п������·������У������������ء�  
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
