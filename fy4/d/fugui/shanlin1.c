inherit ROOM;

void create()
{
	set("short", "ɽ�����");

	set("long", @LONG
���������ģ������ȥ�����������Լ�����ָ�����¿Ŀİ��Ҳ��֪��
��ȵ�ʲô�������������Ǿ���������·�ĺá�Զ����ͣ�Ĵ�������ɽϪ������
�����ƺ��ڸ����㲻Զ�ĵط������������е�������Դ��
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"east":__DIR__"shanlin2",
		"south":__DIR__"shanlin",
		"west":__DIR__"shanlin",
		"north":__DIR__"shanlin1",
	]) );
	set("coor/x",0);
	set("coor/y",150);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}
