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
		"southwest":__DIR__"birdroad2",
	        "north" : __DIR__"work",	
        ]) );
        set("outdoors", "guanwai");
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
