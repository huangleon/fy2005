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
        "northwest":__DIR__"fydao2",
        "east":		AREA_MANGLIN"plainroad",
		]) );
        set("outdoors", "chenxiang");
	set("coor/x",280);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
