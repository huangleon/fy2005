inherit ROOM;

void create()
{
	set("short", "���");

	set("long", @LONG
Զ������ʥĸѩ���ˣ�����Ҳ��֮Ϊϲ������ɽ����Ө��ѩ����һ���Ű����
�ɵ������������߲�����������¶��ͷ���������������������ߵİ������ߡ���ԭ
����ϡ��������Ҳ�����ѣ�С·Ҳ����������ʮ�����У���˵��˳�֮Ϊ�������
˼������������ѷɹ����
LONG);
	
	set("type","street");
	set("exits",([
		"southwest":__DIR__"shanjiao",
		"northeast":__DIR__"timetree",
	]) );
        set("outdoors", "guanwai");
	set("coor/x",-20);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
