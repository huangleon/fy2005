inherit ROOM;

void create()
{
	set("short", "��ʯ��");

	set("long", @LONG
����������ʯ���ɵ�С����������С�ֿ��˲��٣���Ҳ����ƽ����·
�������ľ���޼����������룬ʱ��ʱ���м������ֵ�����·�ɿ�ĳ������ӡ�
�������߾���Զ�������Ľ��ˣ��뵱�����˧��������ʮ�����ڽ�����Ҳ��һ
�������е��֡�
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"south":__DIR__"jinmen",
		"north":__DIR__"shilu3",
	]) );
	set("coor/x",50);
	set("coor/y",70);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
